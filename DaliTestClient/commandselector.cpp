#include "commandselector.h"
#include "ui_commandselector.h"

CommandSelector::CommandSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSelector)
{
    ui->setupUi(this);

    ui->selectExtendedCmdLabel->setVisible(false);
    ui->daliExtendedTestCmdsComboBox->setVisible(false);
    ui->testSeqSpecSelLabel->setVisible(false);
    ui->testSeqSpecSelComboBox->setVisible(false);

    connect(ui->daliDataSetSlider, SIGNAL(valueChanged(int)), SLOT(updateDaliDataSetSlider(int)));
    connect(ui->dataDecEdit, SIGNAL(textEdited(const QString &)), SLOT(dataDecEditTextChanged()));
    connect(ui->dataHexEdit, SIGNAL(textEdited(const QString &)), SLOT(dataHexEditTextChanged()));
}

CommandSelector::~CommandSelector()
{
    delete ui;
}

void CommandSelector::populateBySpecs(QComboBox* combo)
{
    combo->addItem("207");
    combo->addItem("202");
    combo->addItem("205");
    combo->addItem("209");
    combo->setCurrentIndex(0); //Select Spec. 207
}

void CommandSelector::addExtendedCmdsSelector()
{
    ui->selectExtendedCmdLabel->setVisible(true);
    ui->daliExtendedTestCmdsComboBox->setVisible(true);
    ui->testSeqSpecSelLabel->setVisible(true);
    ui->testSeqSpecSelComboBox->setVisible(true);

    for(int i = 0; i < daliSpec207ExtCommandsStrList.size(); i++)
    {
        ui->daliExtendedTestCmdsComboBox->addItem(daliSpec207ExtCommandsStrList[i]);
    }
    populateBySpecs(ui->testSeqSpecSelComboBox);
    connect(ui->testSeqSpecSelComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(extCmdsSpecSelChanged()));
}

quint8 CommandSelector::extendedCmdsGetOpCode()
{
    quint8 rval = 0;
    if(ui->testSeqSpecSelComboBox->currentText() == "207")
        rval = 6;
    else if(ui->testSeqSpecSelComboBox->currentText() == "202")
        rval = 1;
    else if(ui->testSeqSpecSelComboBox->currentText() == "205")
        rval = 4;
    else if(ui->testSeqSpecSelComboBox->currentText() == "209")
        rval = 8;
    return rval;
}
void CommandSelector::updateDaliDataSetSlider(int sliderVal)
{
    ui->dataDecEdit->setText(QString::number(sliderVal));
    ui->dataHexEdit->setText(QString("%1").arg(sliderVal, 2, 16, QLatin1Char( '0' )));
}

void CommandSelector::dataDecEditTextChanged()
{
    QMessageBox msg;
    QString resValStr = ui->dataDecEdit->text();
    if(resValStr == "")
    {
        int sliderVal = ui->daliDataSetSlider->value();
        ui->dataDecEdit->setText(QString::number(sliderVal));
        ui->dataHexEdit->setText(QString("%1").arg(sliderVal, 2, 16, QLatin1Char( '0' )));
        return;
    }
    QRegularExpression regExpr1("\\d\\d\\d");
    QRegularExpression regExpr2("\\d\\d");
    QRegularExpression regExpr3("\\d");
    QRegularExpressionMatch match1 = regExpr1.match(resValStr, 0, QRegularExpression::NormalMatch);
    QRegularExpressionMatch match2 = regExpr2.match(resValStr, 0, QRegularExpression::NormalMatch);
    QRegularExpressionMatch match3 = regExpr3.match(resValStr, 0, QRegularExpression::NormalMatch);
    if((!match1.hasMatch()) && (!match2.hasMatch()) && (!match3.hasMatch()))
    {
        msg.setText("Неверный ввод!");
        msg.exec();
    }
    else
    {
        int resVal = resValStr.toInt();
        if(resVal > 255)
        {
            msg.setText("Слишком большое число! (>255)");
            msg.exec();
        }
        else
        {
            ui->daliDataSetSlider->setValue(resVal);
            ui->dataHexEdit->setText(QString("%1").arg(resVal, 2, 16, QLatin1Char( '0' )));
        }
    }
}

void CommandSelector::dataHexEditTextChanged()
{
    QMessageBox msg;
    QString resValStr = ui->dataHexEdit->text();
    if(resValStr == "")
        return;
    QRegularExpression regExpr("[0-9a-fA-F]");
    QRegularExpressionMatch match = regExpr.match(resValStr, 0, QRegularExpression::NormalMatch);

    if(!match.hasMatch())
    {
        msg.setText("Неверный ввод!");
        msg.exec();
    }
    else
    {
        bool bStatus = false;
        int resVal = resValStr.toUInt(&bStatus, 16);
        if(resVal > 255)
        {
            msg.setText("Слишком большое число! (>255)");
            msg.exec();
        }
        else
        {
            ui->daliDataSetSlider->setValue(resVal);
            ui->dataDecEdit->setText(QString::number(resVal));
        }
    }
}

uint8_t CommandSelector::getValue()
{
    return ui->dataDecEdit->text().toInt();
}

void CommandSelector::fillByCommands()
{
    for(int i = 0; i < daliCommandsStrList.size(); i++)
    {
        ui->daliCommandsComboBox->addItem(daliCommandsStrList[i]);
    }
}

void CommandSelector::setSpecificationCommands(QString currSpec, QComboBox* dstCombo)
{
    if(currSpec == "205")
    {
        dstCombo->clear();
        for(int i = 0; i < daliSpec205ExtCommandsStrList.size(); i++)
            dstCombo->addItem(daliSpec205ExtCommandsStrList[i]);
    }
    else if(currSpec == "202")
    {
       dstCombo->clear();
       for(int i = 0; i < daliSpec202ExtCommandsStrList.size(); i++)
           dstCombo->addItem(daliSpec202ExtCommandsStrList[i]);
    }
    else if(currSpec == "207")
    {
       dstCombo->clear();
       for(int i = 0; i < daliSpec207ExtCommandsStrList.size(); i++)
           dstCombo->addItem(daliSpec207ExtCommandsStrList[i]);
    }
    else if(currSpec == "209")
    {
       dstCombo->clear();
       for(int i = 0; i < daliSpec209ExtCommandsStrList.size(); i++)
           dstCombo->addItem(daliSpec209ExtCommandsStrList[i]);
    }
}

void CommandSelector::specSelUpdate(QString currSpec)
{
    setSpecificationCommands(currSpec, ui->daliCommandsComboBox);
    emit specChangedSgn();
}

void CommandSelector::extCmdsSpecSelChanged()
{
    QString currTxt = ui->testSeqSpecSelComboBox->currentText();
    setSpecificationCommands(currTxt, ui->daliExtendedTestCmdsComboBox);
}

void CommandSelector::getCommand(QString *dstStr)
{
    *dstStr = ui->daliCommandsComboBox->currentText();
}

void CommandSelector::getExtendedCommand(QString *dstStr)
{
    *dstStr = ui->daliExtendedTestCmdsComboBox->currentText();
}

void CommandSelector::getCommand(quint16 *cmdId, qint8* err)
{
    QString cmdStr = ui->daliCommandsComboBox->currentText();
    int delimIx = cmdStr.indexOf(' ');
    cmdStr.chop(cmdStr.size() - delimIx);

    if(cmdStr == "-") //DAPC
    {
        *cmdId = 0;
        *err = -1;
        return; // false;
    }
    else
    {
        *cmdId = cmdStr.toInt();
        *err = 0;
    }
}

