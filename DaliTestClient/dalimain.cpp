#include "dalimain.h"
#include "ui_dalimain.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QColorDialog>
#include <QThread>
#include <QTime>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>
#include <QFileDialog>
#include <QStandardItem>

DaliMain::DaliMain(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DaliMain),
    m_settings(new SettingsDialog),
    m_serial(new QSerialPort(this))
{
    ui->setupUi(this);

    createTable(&resTabHeaderData, &model, ui->searchResultsTableView, 64);
    ui->searchResultsTableView->setModel(&model);
    ui->searchResultsTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    clearTestSeqTableData();

    diag = new(diagnostics);
    diag->membank_202_init(ui->memBank202TableView);
    diag->membank_203_init(ui->memBank203TableView);
    diag->membank_204_init(ui->memBank204TableView);

    diag->membank_205_init(ui->memBank205TableView);
    diag->membank_206_init(ui->memBank206TableView);
    diag->membank_207_init(ui->memBank207TableView);

    createMemBank0Tab(diag->getMembank0Model());

    connect(ui->readBank0Btn, &QPushButton::clicked, this,  &DaliMain::readBank0BtnClick);
    connect(ui->readBank1Btn, &QPushButton::clicked, this,  &DaliMain::readBank1BtnClick);
    connect(ui->writeFullBank1Btn, &QPushButton::clicked, this,  &DaliMain::writeFullBank1BtnClick);
    connect(ui->writeBank1Btn, &QPushButton::clicked, this,  &DaliMain::writeBank1BtnClick);
    connect(ui->memBank1FlashSaveBtn, &QPushButton::clicked, this,  &DaliMain::memBank1FlashSaveBtnClick);

    createMemBank1Tab(diag->getMembank1Model());

    connect(ui->memBank1TableView, SIGNAL(clicked(const QModelIndex)), this, SLOT(memBank1TableCellSelect(const QModelIndex)));
    ui->memBank1TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->comSetupAction, &QAction::triggered, this, &DaliMain::comSetup);

    connect(m_settings, SIGNAL(applyClicked()), this, SLOT(comConnect()));
    connect(ui->comDisconnectAction, &QAction::triggered, this, &DaliMain::comDisconnect);

    connect(ui->findDeviceButton, &QPushButton::clicked, this, &DaliMain::findMasterDevice);
    connect(ui->clearMonitorWindowButton, &QPushButton::clicked, this, &DaliMain::clearMonitorWindow);
    connect(ui->discoverButton, &QPushButton::clicked, this, &DaliMain::searchAddrStart);
    connect(ui->discoverStopButton, &QPushButton::clicked, this, &DaliMain::exchangeStop);
    connect(ui->clearDiscoveredButton, &QPushButton::clicked, this, &DaliMain::clearDiscovered);

    connect(ui->typeVersionBtn, &QPushButton::clicked, this, &DaliMain::typeVersionBtnClicked);  //debug
    ui->typeVersionBtn->setVisible(false);

    connect(m_serial, &QSerialPort::errorOccurred, this, &DaliMain::comPortHandleError);
    connect(m_serial, &QSerialPort::readyRead, this, &DaliMain::comPortReadData);

    waitRxTimer = new QTimer(this);
    connect(waitRxTimer, SIGNAL(timeout()), this, SLOT(waitRxTimerShot()));
    waitRxTimer->setSingleShot(true);

    exchangeTimer = new QTimer(this);
    connect(exchangeTimer, SIGNAL(timeout()), this, SLOT(exchangeTimerShot()));
    exchangeTimer->setSingleShot(false);

    CommandSelector::populateBySpecs(ui->specSelComboBox);

    connect(ui->specSelComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(specSelChanged()));
    connect(ui->sendExtCmdEnableDeviceType, &QPushButton::clicked, this, &DaliMain::sendExtCmdEnableDeviceTypeClicked);
    connect(ui->addToTestButton, SIGNAL(clicked()), this, SLOT(addToTestButtonClick()));
    connect(ui->addExtendedCmdToTestButton, SIGNAL(clicked()), this, SLOT(addExtendedCmdToTestButtonClick()));
    connect(ui->removeFromTestButton, SIGNAL(clicked()), this, SLOT(removeFromTestButtonClick()));
    connect(ui->clearAllTestButton, SIGNAL(clicked()), this, SLOT(clearAllTestButtonClick()));
    connect(ui->testRunButton, SIGNAL(clicked()), this, SLOT(testRunButtonClick()));
    connect(ui->testStopButton, SIGNAL(clicked()), this, SLOT(testStopButtonClick()));
    connect(ui->loadTestSeqButton, SIGNAL(clicked()), this, SLOT(loadTestSeqButtonClick()));
    connect(ui->saveTestSeqButton, SIGNAL(clicked()), this, SLOT(saveTestSeqButtonClick()));
    connect(ui->addTimeoutToTestButton, SIGNAL(clicked()), this, SLOT(addTimeoutToTestButtonClick()));
    connect(ui->addLoopStartToTestButton, SIGNAL(clicked()), this, SLOT(addLoopStartToTestButtonClick()));
    connect(ui->addLoopEndToTestButton, SIGNAL(clicked()), this, SLOT(addLoopEndToTestButtonClick()));

    commandSel = new CommandSelector(this);
    ui->commandSelectLayout->addWidget(commandSel);
    commandSel->fillByCommands();

    extCommandSel = new CommandSelector(this);
    ui->extCommandSelectLayout->addWidget(extCommandSel);
    extCommandSel->specSelUpdate("207");
    connect(extCommandSel, SIGNAL(specChangedSgn()), this, SLOT(extCmdsSpecSelChanged()));

    testSeqCommandSel = new CommandSelector(this);
    ui->testCommandSelectlLayout->addWidget(testSeqCommandSel);
    testSeqCommandSel->fillByCommands();
    testSeqCommandSel->addExtendedCmdsSelector();

    addrSel = new addressSelector(this);
    ui->commandAddressSetlLayout->addWidget(addrSel);

    extAddrSel = new addressSelector(this);
    ui->extCommandAddressSetlLayout->addWidget(extAddrSel);

    testSeqAddrSel = new addressSelector(this);
    ui->testSeqAddressSetLayout->addWidget(testSeqAddrSel);
    testSeqAddrSel->setVisible(true);

    colourControlWidget = new ColourControl(this);
    ui->colourCtrlLayout->addWidget(colourControlWidget);
    connect(colourControlWidget, SIGNAL(stepWarmerSig()), this, SLOT(stepWarmerSigProc()));
    connect(colourControlWidget, SIGNAL(stepCoolerSig()), this, SLOT(stepCoolerSigProc()));
    connect(colourControlWidget, SIGNAL(setColourValSig()), this, SLOT(setColourValSigProc()));
    connect(colourControlWidget, SIGNAL(queryColorValSig()), this, SLOT(queryColorValSigProc()));

    connect(ui->sendCmdToPushButton, &QPushButton::clicked, this, &DaliMain::sendCmdToPushButtonClicked);
    connect(ui->sendExtCmdToPushButton, &QPushButton::clicked, this, &DaliMain::sendExtCmdToPushButtonClicked);

    ui->tabWidget->setCurrentIndex(1);

   connect(ui->broadcastSlider, SIGNAL(valueChanged(int)), SLOT(updateBroadcastSlider(int)));
   connect(ui->broadcastSlider, SIGNAL(sliderReleased()), SLOT(sliderBroadcastRelease()));

   connect(ui->redSlider, SIGNAL(valueChanged(int)), SLOT(updateRedSlider(int)));
   connect(ui->redSlider, SIGNAL(sliderReleased()), SLOT(sliderRedReleased()));

   connect(ui->greenSlider, SIGNAL(valueChanged(int)), SLOT(updateGreenSlider(int)));
   connect(ui->greenSlider, SIGNAL(sliderReleased()), SLOT(sliderGreenReleased()));

   connect(ui->blueSlider, SIGNAL(valueChanged(int)), SLOT(updateBlueSlider(int)));
   connect(ui->blueSlider, SIGNAL(sliderReleased()), SLOT(sliderBlueReleased()));

   ui->redEdit->setStyleSheet("QLineEdit { background-color: #faa8a5; }");
   ui->greenEdit->setStyleSheet("QLineEdit { background-color: #90ee90; }");
   ui->blueEdit->setStyleSheet("QLineEdit { background-color: #add8e6; }");

   connect(ui->sceneSetButton, &QPushButton::clicked, this, &DaliMain::sceneSetBtnClicked);
   connect(ui->sceneGoToButton, &QPushButton::clicked, this, &DaliMain::sceneGoToBtnClicked);
   connect(ui->sceneQueryLevelButton, &QPushButton::clicked, this, &DaliMain::sceneQueryLvlBtnClicked);
   connect(ui->sceneRemoveButton, &QPushButton::clicked, this, &DaliMain::sceneRemoveBtnClicked);
   connect(ui->fadeTimeSetBtn, &QPushButton::clicked, this, &DaliMain::fadeTimeSetBtnClicked);
   connect(ui->fastFadeTimeSetBtn, &QPushButton::clicked, this, &DaliMain::fastFadeTimeSetBtnClicked);
   connect(ui->extendedFadeTimeSetBtn, &QPushButton::clicked, this, &DaliMain::extendedFadeTimeSetBtnClicked);

   connect(ui->bCastAddrCheckBox, SIGNAL(clicked()), this, SLOT(bCastAddrCheckBoxClicked()));

   connect(ui->memBank202ReadButton, &QPushButton::clicked, this, &DaliMain::mBank202ReadBtnClicked);
   connect(ui->memBank203ReadButton, &QPushButton::clicked, this, &DaliMain::mBank203ReadBtnClicked);
   connect(ui->memBank204ReadButton, &QPushButton::clicked, this, &DaliMain::mBank204ReadBtnClicked);
   connect(ui->memBank202SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank202SetLockBtnClicked);
   connect(ui->memBank203SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank203SetLockBtnClicked);
   connect(ui->memBank204SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank204SetLockBtnClicked);
   connect(ui->memBank205SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank205SetLockBtnClicked);
   connect(ui->memBank206SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank206SetLockBtnClicked);
   connect(ui->memBank207SetLockButton, &QPushButton::clicked, this, &DaliMain::mBank207SetLockBtnClicked);
   connect(ui->memBank202ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank202ClrLockBtnClicked);
   connect(ui->memBank203ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank203ClrLockBtnClicked);
   connect(ui->memBank204ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank204ClrLockBtnClicked);
   connect(ui->memBank205ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank205ClrLockBtnClicked);
   connect(ui->memBank206ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank206ClrLockBtnClicked);
   connect(ui->memBank207ClrLockButton, &QPushButton::clicked, this, &DaliMain::mBank207ClrLockBtnClicked);
   connect(ui->setDevAddrSpinBox_3, SIGNAL(valueChanged(int)), this, SLOT(slotDevAddrChanged_3()));
   ui->pwrEnergyProgressBar->setVisible(false);
   ui->diagProgressBar->setVisible(false);

   connect(ui->mBank205ReadButton, &QPushButton::clicked, this, &DaliMain::mBank205ReadBtnClicked);
   connect(ui->mBank206ReadButton, &QPushButton::clicked, this, &DaliMain::mBank206ReadBtnClicked);
   connect(ui->mBank207ReadButton, &QPushButton::clicked, this, &DaliMain::mBank207ReadBtnClicked);
   connect(ui->setDevAddrSpinBox_2, SIGNAL(valueChanged(int)), this, SLOT(slotDevAddrChanged()));

   enableControl(false);
}

DaliMain::~DaliMain()
{
    delete diag;
    delete ui;
    delete addrSel;
    delete extAddrSel;
    delete testSeqAddrSel;
    delete commandSel;
    delete extCommandSel;
    delete testSeqCommandSel;
}

void DaliMain::extCmdsSpecSelChanged()
{
    QString currTxt = ui->specSelComboBox->currentText();
    if(currTxt == "202")
    {
       ui->sendExtCmdEnableDeviceType->setText("Разр. у-во типа 1 (Self-cont. emerg. lighting)");
    }
    else if(currTxt == "205")
    {
        ui->sendExtCmdEnableDeviceType->setText("Разрешить устройство типа 4 (Лампа накал.)");
    }
    else if(currTxt == "207")
    {
       ui->sendExtCmdEnableDeviceType->setText("Разрешить устройство типа 6 (LED светильник)");
    }
    else if(currTxt == "209")
    {
       ui->sendExtCmdEnableDeviceType->setText("Разрешить устройство типа 8 (Colour control)");
    }
}

void DaliMain::buildCmd(daliCommandParcer* parcer, uint8_t data, QString cmdStr,
                        uint8_t addrType, uint8_t groupDest,  uint8_t addrDest)
{
    int delimIx = cmdStr.indexOf(' ');
    cmdStr.chop(cmdStr.size() - delimIx);

    bool dapcFlag = false;
    if(cmdStr == "-") //DAPC
    {
        dapcFlag = true;
    }
    else
    {
        cmdId = cmdStr.toInt();
    }

    if((cmdId <= 0xFF) || dapcFlag)  //standart commands
    {
        uint8_t cmdType = TYPE_BROADCAST;
        uint8_t destination = 0;
        if(addrType == addressSelector::GROUP_ADDR)
        {
            cmdType = TYPE_GROUP;
            destination = groupDest;
        }
        else if(addrType == addressSelector::BROADCAST_UNADDRESSED)
        {
            cmdType = TYPE_BROADCAST_UNADDR;
        }
        else if(addrType == addressSelector::INDIVIDUAL_ADDR)
        {
            cmdType = TYPE_ADDRESS;
            destination = addrDest;
        }
        address_byte = parcer->getStandartCmdAddrByte(cmdType, destination, dapcFlag);
        if(dapcFlag)
        {
            opcode_byte = data;
        }
        else
        {
            opcode_byte = cmdId;
        }
    }
    else        //special commands
    {
        address_byte = parcer->getSpecialCmdAddrByteFromNumber(cmdId);
        opcode_byte = parcer->getSpecialCmdOpcodeByte(cmdId, data);
    }

}

void DaliMain::sendCmd(uint8_t data, QString cmdStr, uint8_t addrType,
                       uint8_t groupDest, uint8_t addrDest,
                       QLineEdit* cmdSendDecEdit, QLineEdit* cmdSendHexEdit, quint8 specification)
{
    qDebug() << "tabSelected:" << QString::number(ui->tabWidget->currentIndex());

    daliCommandParcer parcer;

    buildCmd(&parcer, data, cmdStr, addrType, groupDest, addrDest);

    cmdSendDecEdit->setText(QString::number(address_byte) + " " + QString::number(opcode_byte));
    cmdSendHexEdit->setText(QString("%1").arg(address_byte, 2, 16, QLatin1Char( '0' )) + " " + QString("%1").arg(opcode_byte, 2, 16, QLatin1Char( '0' )));

    bool set_twice = parcer.checkCmdIssueTwice(cmdId, specification);
    bool answer = parcer.checkCmdNeedAnswer(cmdId, specification);
    bool is_special = parcer.checkCmdSpecial(cmdId);

    if((ui->periodSendCheckBox->isChecked()) && (!answer))
    {
        exchangeTimer->start(100);
        slaveCmd(address_byte, opcode_byte, EXCHANGE_STATE_SEND_PERIODICALLY, set_twice, answer, is_special);
    }
    else
    {
        exchangeTimer->start(700);
        slaveCmd(address_byte, opcode_byte, EXCHANGE_STATE_IDLE, set_twice, answer, is_special);
    }
}

quint8 DaliMain::getSpec(QString text)
{
    quint8 rval = 0;
    if(text == "207")
        rval = SPEC_LED_LAMP;
    else if(text == "202")
        rval = SPEC_SELF_CONTAINED_EMERGENCY_LIGHTNING;
    else if(text == "205")
        rval = SPEC_INCANDESCENT_LAMP;
    else if(text == "209")
        rval = SPEC_COLOUR_CONTROL;
    return rval;
}

void DaliMain::sendCmdToPushButtonClicked()
{
    uint8_t data = commandSel->getValue(); //ui->dataDecEdit->text().toInt();
    QString cmdStr; // = ui->daliCommandsComboBox->currentText();
    commandSel->getCommand(&cmdStr);
    uint8_t addrType = addrSel->getAddrType();
    uint8_t groupDest = addrSel->getGroupAddress();
    uint8_t addrDest =  addrSel->getAddress();
    QLineEdit* cmdSendDecEdit = ui->commandSendDecEdit;
    QLineEdit* cmdSendHexEdit = ui->commandSendHexEdit;
    quint8 spec = getSpec(ui->specSelComboBox->currentText());
    sendCmd(data, cmdStr, addrType,  groupDest, addrDest, cmdSendDecEdit, cmdSendHexEdit, spec);
}

void DaliMain::sendExtendedCommand()
{
    uint8_t data = extCommandSel->getValue(); //ui->dataExtCmdsDecEdit->text().toInt();
    QString cmdStr; // = ui->daliExtCmdsComboBox->currentText();
    extCommandSel->getCommand(&cmdStr);
    uint8_t addrType = extAddrSel->getAddrType();
    uint8_t groupDest = extAddrSel->getGroupAddress();
    uint8_t addrDest =  extAddrSel->getAddress();
    QLineEdit* cmdSendDecEdit = ui->extCommandSendDecEdit;
    QLineEdit* cmdSendHexEdit = ui->extCommandSendHexEdit;
    quint8 spec = getSpec(ui->specSelComboBox->currentText());
    sendCmd(data, cmdStr, addrType, groupDest, addrDest, cmdSendDecEdit, cmdSendHexEdit, spec);
}

void DaliMain::sendExtCmdToPushButtonClicked()
{
    if(ui->autoPrependCmdCheckBox->isChecked())
    {
        quint8 gearType = 6;
        int spec = getSpec(ui->specSelComboBox->currentText());
        if(205 == spec)
            gearType = 4;
        else if(202 == spec)
            gearType = 1;
        else if(209 == spec)
            gearType = 8;
        else if(0 == spec) //Error!
            return;
        slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, gearType, EXCHANGE_STATE_SEND_EXTEND_CMD, false, false, true);
        exchangeTimer->stop();
        exchangeTimer->start(700);
    }
    else
    {
        sendExtendedCommand();
    }
}

void DaliMain::sendEnableDeviceType(quint8 gearType)
{
    QString cmdStr = "272 ENABLE DEVICE TYPE 6";
    uint8_t addrType = addrSel->getAddrType();
    uint8_t groupDest = addrSel->getGroupAddress();
    uint8_t addrDest =  addrSel->getAddress();
    QLineEdit* cmdSendDecEdit = ui->extCommandSendDecEdit;
    QLineEdit* cmdSendHexEdit = ui->extCommandSendHexEdit;
    sendCmd(gearType, cmdStr, addrType, groupDest, addrDest, cmdSendDecEdit, cmdSendHexEdit, SPEC_LED_LAMP);
}

void DaliMain::sendExtCmdEnableDeviceTypeClicked()
{
   quint8 gearType = 6;
   if(205 == getSpec(ui->specSelComboBox->currentText()))
       gearType = 4;
   else if(202 == getSpec(ui->specSelComboBox->currentText()))
       gearType = 1;
   else if(209 == getSpec(ui->specSelComboBox->currentText()))
       gearType = 8;
   sendEnableDeviceType(gearType);
}

void DaliMain::getAddressStr(quint8 addrByte, QString* res)
{
    if((addrByte & 0xFE) == 0xFE)
    {
        *res = "BroadCast";
    }
    else if(((addrByte & 0xFD) == 0xFD) || ((addrByte & 0xFD) == 0xFC))
    {
        *res = "BrCast UnAddr.";
    }
    else if((addrByte & 0xE0) == 0x80)
    {
        addrByte = (addrByte >> 1) & 0x0F;
        *res = "Group Addr: " + QString::number(addrByte);
    }
    else
    {
       addrByte = (addrByte >> 1) & 0x3F;
       *res = QString::number(addrByte);
    }
}

void DaliMain::updateTestSequenseTable()
{
    QString addrStr;
    for(int i = 0; i < testSeqCmds.size(); i++)
    {
        if(testSeqCmds[i].commandDefStr.contains("Timeout"))
        {
            addrStr = "(value in ms)";
        }
        else if ((testSeqCmds[i].commandDefStr.contains("LoopStart")) || (testSeqCmds[i].commandDefStr.contains("LoopEnd")))
        {
            addrStr = "";
        }
        else
        {
            if(!testSeqCmds[i].is_special)
            {
                getAddressStr(testSeqCmds[i].addrByte, &addrStr);
            }
            else
            {
                addrStr = "Special";
            }
        }
        testTabModel.setData(testTabModel.index(i, 1, QModelIndex()), addrStr);
        QString commandRowData = testSeqCmds[i].commandDefStr;
        if((!testSeqCmds[i].commandDefStr.contains("Timeout")) &&\
           (!testSeqCmds[i].commandDefStr.contains("LoopStart")) &&\
           (!testSeqCmds[i].commandDefStr.contains("LoopEnd")))
              commandRowData += \
                " 0x" + QString("%1").arg(testSeqCmds[i].addrByte, 2, 16, QLatin1Char('0')) + \
                " 0x" + QString("%1").arg(testSeqCmds[i].opcodeByte, 2, 16, QLatin1Char('0'));
        testTabModel.setData(testTabModel.index(i, 2, QModelIndex()), commandRowData);
    }
    ui->testSeqTableView->setModel(&testTabModel);
}

void DaliMain::loadTestSeqButtonClick()
{
    QString  fileName = QFileDialog::getOpenFileName(this, QObject::tr("New File"), "C:/", QObject::tr("Files (*.dat)"));
    if (fileName.isEmpty())
    {
        qDebug() << "file name is empty";
        return;
    }
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::ReadOnly)) {   //|QFile::Truncate
            qDebug() << "file open error";
            return;
        }
        QDataStream in(&file);
        testSeqCmds.clear();
        while(!in.atEnd())
        {
            test_seq_cmd_t newTestSeqCmd;
            in >> newTestSeqCmd.elementID;
            in >> newTestSeqCmd.addrByte;
            in >> newTestSeqCmd.opcodeByte;
            in >> newTestSeqCmd.commandDefStr;
            in >> newTestSeqCmd.set_twice;
            in >> newTestSeqCmd.answer;
            in >> newTestSeqCmd.is_special;;
            testSeqCmds.append(newTestSeqCmd);
        }
        file.close();
        clearTestSeqTableData();
        updateTestSequenseTable();
    }
}

void DaliMain::saveTestSeqButtonClick()
{
    QString  fileName = QFileDialog::getSaveFileName(this, QObject::tr("New File"), "C:/", QObject::tr("Files (*.dat)"));
    if (fileName.isEmpty())
    {
           qDebug() << "file name is empty";
           return;
    }
    else
    {
        QFile file(fileName);
        if(!file.open(QIODevice::WriteOnly)) {   //QIODevice::Append||QFile::Truncate
            qDebug() << "file open error";
            return;
        }
        QDataStream out(&file);
        for(auto i = 0; i < testSeqCmds.size(); i++)
        {
            out << testSeqCmds[i].elementID;
            out << testSeqCmds[i].addrByte;
            out << testSeqCmds[i].opcodeByte;
            out << testSeqCmds[i].commandDefStr;
            out << testSeqCmds[i].set_twice;
            out << testSeqCmds[i].answer;
            out << testSeqCmds[i]. is_special;
        }
        file.close();
    }
}

void DaliMain::addToTestButtonClick()
{
    if(testSeqCmds.size() >= TEST_SEQUENSE_MAX_COMMAND)
    {
        QMessageBox msg;
        msg.setText("Макс. кол-во команд определено. Больше нельзя добавить");
        msg.exec();
        return;
    }

    daliCommandParcer parcer;

    uint8_t data = testSeqCommandSel->getValue();
    QString cmdStr;
    testSeqCommandSel->getCommand(&cmdStr);

    uint8_t addrType = testSeqAddrSel->getAddrType();
    uint8_t groupDest = testSeqAddrSel->getGroupAddress();
    uint8_t addrDest =  testSeqAddrSel->getAddress();

    int delimIx = cmdStr.indexOf(' ');
    QString cmdIDStr = cmdStr;
    cmdIDStr.chop(cmdStr.size() - delimIx);
    int cmd_id = cmdIDStr.toInt();

    buildCmd(&parcer, data, cmdStr, addrType, groupDest, addrDest);

    test_seq_cmd_t cmd;
    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    cmd.commandDefStr = cmdStr.right(cmdStr.size() - delimIx - 1);
    cmd.addrByte = address_byte;
    cmd.opcodeByte = opcode_byte;
    cmd.set_twice = parcer.checkCmdIssueTwice(cmd_id, 207);
    cmd.answer = parcer.checkCmdNeedAnswer(cmd_id, 207);
    cmd.is_special = parcer.checkCmdSpecial(cmd_id);
    testSeqCmds.append(cmd);
    updateTestSequenseTable();
}

void DaliMain::addExtendedCmdToTestButtonClick()
{
    if(testSeqCmds.size() >= TEST_SEQUENSE_MAX_COMMAND)
    {
        QMessageBox msg;
        msg.setText("Макс. кол-во команд определено. Больше нельзя добавить");
        msg.exec();
        return;
    }
    daliCommandParcer parcer;
    test_seq_cmd_t cmd;

    //1. Send "Enable device type ..." command
    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    cmd.commandDefStr = " ";
    cmd.addrByte = ENABLE_DEVICE_TYPE_OPCODE;

    cmd.opcodeByte = testSeqCommandSel->extendedCmdsGetOpCode();

    cmd.commandDefStr = "Enable device type " + QString::number(cmd.opcodeByte);

    cmd.set_twice = false;
    cmd.answer = false;
    cmd.is_special = true;
    testSeqCmds.append(cmd);
    updateTestSequenseTable();

    //2. Send command itself
    uint8_t data = testSeqCommandSel->getValue(); // ui->dataTestCmdsDecEdit->text().toInt();
    QString cmdStr;
    testSeqCommandSel->getExtendedCommand(&cmdStr);

    uint8_t addrType = testSeqAddrSel->getAddrType();
    uint8_t groupDest = testSeqAddrSel->getGroupAddress();
    uint8_t addrDest = testSeqAddrSel->getAddress();

    int delimIx = cmdStr.indexOf(' ');
    QString cmdIDStr = cmdStr;
    cmdIDStr.chop(cmdStr.size() - delimIx);
    int cmd_id = cmdIDStr.toInt();

    buildCmd(&parcer, data, cmdStr, addrType, groupDest, addrDest);

    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    cmd.commandDefStr = cmdStr.right(cmdStr.size() - delimIx - 1);
    cmd.addrByte = address_byte;
    cmd.opcodeByte = opcode_byte;
    cmd.set_twice = parcer.checkCmdIssueTwice(cmd_id, 207);
    cmd.answer = parcer.checkCmdNeedAnswer(cmd_id, 207);
    cmd.is_special = parcer.checkCmdSpecial(cmd_id);
    testSeqCmds.append(cmd);
    updateTestSequenseTable();
}

void DaliMain::addTimeoutToTestButtonClick()
{
    test_seq_cmd_t cmd;
    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    float tOutVal = ui->testSeqToutSpinBox->value();
    cmd.commandDefStr = "Timeout " + QString::number(tOutVal*1000);
    cmd.addrByte = 0;
    cmd.opcodeByte = 0;
    cmd.set_twice = false;
    cmd.answer = false;
    cmd.is_special = false;
    testSeqCmds.append(cmd);
    updateTestSequenseTable();
}

void DaliMain::addLoopStartToTestButtonClick()
{
    test_seq_cmd_t cmd;
    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    int IterCntVal = ui->testSeqIterCntSpinBox->value();
    cmd.commandDefStr = "LoopStart " + QString::number(IterCntVal);
    cmd.addrByte = 0;
    cmd.opcodeByte = 0;
    cmd.set_twice = false;
    cmd.answer = false;
    cmd.is_special = false;
    testSeqCmds.append(cmd);
    updateTestSequenseTable();

    //ui->addLoopStartToTestButton->setEnabled(false);
    //ui->addLoopEndToTestButton->setEnabled(true);
}

void DaliMain::addLoopEndToTestButtonClick()
{
    test_seq_cmd_t cmd;
    cmd.elementID = nextTestSeqElemID;
    nextTestSeqElemID++;
    cmd.commandDefStr = "LoopEnd";
    cmd.addrByte = 0;
    cmd.opcodeByte = 0;
    cmd.set_twice = false;
    cmd.answer = false;
    cmd.is_special = false;
    testSeqCmds.append(cmd);
    updateTestSequenseTable();

    //ui->addLoopStartToTestButton->setEnabled(true);
    //ui->addLoopEndToTestButton->setEnabled(false);
}

void DaliMain::removeFromTestButtonClick()
{
    QMessageBox Warning;
    auto rowList = ui->testSeqTableView->selectionModel()->selectedRows();
    if(rowList.count() > 0)
    {
        int rowNumber = rowList.constFirst().row();
        if(rowNumber < testSeqCmds.size())
        {
            test_seq_cmd_t cmdToRemove = testSeqCmds.at(rowNumber);
          //  if(cmdToRemove.commandDefStr.contains("LoopStart"))
          //  {
          //      ui->addLoopStartToTestButton->setEnabled(true);
          //      ui->addLoopEndToTestButton->setEnabled(false);
          //  }
           // if(cmdToRemove.commandDefStr.contains("LoopEnd"))
          //  {
          //      ui->addLoopStartToTestButton->setEnabled(false);
          //      ui->addLoopEndToTestButton->setEnabled(true);
           // }
            testSeqCmds.removeAt(rowNumber);
            clearTestSeqTableData();
            updateTestSequenseTable();
        }
        else
        {
            Warning.setText("Empty row selected!");
            Warning.exec();
        }
    }
    else
    {

       Warning.setText("Select row first!");
       Warning.exec();
    }
}

void DaliMain::clearTestSeqTableData()
{
    testTabModel.clear();
    createTable(&testTabHeaderData, &testTabModel, ui->testSeqTableView, TEST_SEQUENSE_MAX_COMMAND);
    ui->testSeqTableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->testSeqTableView->setSelectionMode(QAbstractItemView::SingleSelection);  //Only one row could be selected
    ui->testSeqTableView->setModel(&testTabModel);
    ui->testSeqTableView->setColumnWidth(0, 90);
    ui->testSeqTableView->setColumnWidth(1, 120);
    ui->testSeqTableView->setColumnWidth(2, 200);
    ui->testSeqTableView->setColumnWidth(3, 70);
    ui->testSeqTableView->setSizePolicy(QSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding));
    ui->testSeqTableView->setMinimumWidth(510);
    ui->testSeqTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void DaliMain::clearAllTestButtonClick()
{
    clearTestSeqTableData();
    testSeqCmds.clear();

   // ui->addLoopStartToTestButton->setEnabled(true);
   // ui->addLoopEndToTestButton->setEnabled(false);
}

void DaliMain::testRunButtonClick()
{
    testLoopStartCmdId.clear();
    testLoopIterationCnt.clear();

    ui->testRunButton->setEnabled(false);
    ui->testStopButton->setEnabled(true);

    if(ui->tabWidget->currentIndex() != DALI_TEST_SEQUENSE_TAB_INDEX)
    {
        qDebug() << "ERROR!!! Wrong tabSeq Tab =" << QString::number(ui->tabWidget->currentIndex());
        return;
    }
    else if(testSeqCmds[0].commandDefStr.contains("LoopEnd"))
    {
        qDebug() << "ERROR!!! Wrong LoopEnd Command";
        return;
    }
    else if(testSeqCmds[0].commandDefStr.contains("LoopStart"))
    {
        int delimIx = testSeqCmds[0].commandDefStr.indexOf(' ');
        QString IterCntStr = \
            testSeqCmds[0].commandDefStr.right(testSeqCmds[0].commandDefStr.size() - delimIx - 1);
        testLoopIterationCnt.append(IterCntStr.toInt());
        testLoopStartCmdId.append(0);  //List with "LoopStart" indexes (for nested loops)
        exchangeState = EXCHANGE_STATE_LOOP_TEST_SEQUENSE;
        exchangeTimer->start(10);
    }
    else
    {
        slaveCmd(testSeqCmds[0].addrByte, testSeqCmds[0].opcodeByte, EXCHANGE_STATE_SEND_TEST_SEQUENSE,\
            testSeqCmds[0].set_twice, testSeqCmds[0].answer, testSeqCmds[0].is_special);
        QTime currTm = QTime::currentTime();
        testTabModel.setData(testTabModel.index(0, 0, QModelIndex()), currTm.toString("hh:mm:ss,zzz"));

        exchangeTimer->start(1000);
    }
    nextTestSeqCmd = 0;
    testSeqSetNextHighLightBackGround(nextTestSeqCmd+1);
}

void DaliMain::testStopButtonClick()
{
    ui->testRunButton->setEnabled(true);
    ui->testStopButton->setEnabled(false);

    testLoopStartCmdId.clear();
    testLoopIterationCnt.clear();
    exchangeTimer->stop();
}

void DaliMain::testSeqProcessReply()
{
    QString replyStr = QString("%1").arg(replyByte, 2, 16, QLatin1Char('0'));
    testTabModel.setData(testTabModel.index(nextTestSeqCmd - 1, 3, QModelIndex()), replyStr);
}

void DaliMain::testSeqProcessTimeout()
{
   testTabModel.setData(testTabModel.index(nextTestSeqCmd - 1, 3, QModelIndex()), "TimeOut");
}

void DaliMain::testSeqProcessNoReply()
{
   testTabModel.setData(testTabModel.index(nextTestSeqCmd - 1, 3, QModelIndex()), "No Reply");
}

void DaliMain::createTable(QStringList* headerData, QStandardItemModel* model, QTableView* tabView, quint32 rowCount)
{
    model->setColumnCount(headerData->size());
    model->setRowCount(rowCount);  //maximal bus nodes
    for(quint8 i = 0; i < headerData->size(); i++)
    {
        model->setHeaderData(i, Qt::Horizontal, headerData->at(i));
    }

    //ui->searchResultsTableView
    tabView->setStyleSheet("QHeaderView::section { background-color:lightGray }");
    tabView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
}

void DaliMain::getTabModelCellStr(QStandardItemModel* model, quint8 offset, quint8 len, QString* resStr)
{
    *resStr = "";
    for(int i = 0; i < len; i++)
    {
        QString hexStr = model->index(i+offset, 2).data().toString().right(2);
        bool ok;
        char symb = (char)(hexStr.toInt(&ok, 16));
        *resStr += QString(symb);
    }
}

void DaliMain::stepWarmerSigProc()
{
    slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, 8, EXCHANGE_STATE_SEND_COLOUR_CMD, false, false, true);

    address_byte = colourControlWidget->getDaliAddress();  //next(main) command definitions
    opcode_byte = 233;

    exchangeTimer->stop();
    exchangeTimer->start(700);
}

void DaliMain::stepCoolerSigProc()
{
    slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, 8, EXCHANGE_STATE_SEND_COLOUR_CMD, false, false, true);

    address_byte = colourControlWidget->getDaliAddress();  //next(main) command definitions
    opcode_byte = 232;

    exchangeTimer->stop();
    exchangeTimer->start(150);
}

void DaliMain::setColourValSigProc()
{
    quint16 colorTemp = colourControlWidget->getColourTemperature();

    quint8 dtr0 = (quint8)colorTemp;
    dtr1 = (quint8)(colorTemp>>8);

    address_byte = colourControlWidget->getDaliAddress();
    opcode_byte = 231;

    slaveCmd(DTR0_ADDR_BYTE, dtr0, EXCHANGE_STATE_SEND_COLOUR_CTRL_CMD, false, false, true);
    exchangeTimer->stop();
    exchangeTimer->start(150);
}

void DaliMain::queryColorValSigProc()
{
    address_byte = colourControlWidget->getDaliAddress();
    opcode_byte = 250;

    slaveCmd(DTR0_ADDR_BYTE, 2, EXCHANGE_STATE_SEND_ENABLE_TYPE8_CMD, false, false, true); //write "2" to DTR0
    exchangeTimer->stop();
    exchangeTimer->start(150);
}

void DaliMain::memBank1TableCellSelect(const QModelIndex index)
{
    quint32 row = index.row();
    quint32 col = index.column();
    qDebug() << "Sel row:" << QString::number(row) << " col:" << QString::number(col);
    if(col != 2)
        return;
    bool ok;

    QStandardItemModel* mdl = diag->getMembank1Model();
    if(row < 36)
    {
        QVariant prvVal = mdl->data(mdl->index(row, col));
        QString text = QInputDialog::getText(this, tr("Параметр 1 байт"),
                                                    tr("Записать в ячейку:"), QLineEdit::Normal,
                                                    prvVal.toString(), &ok);
        if (ok && !text.isEmpty())
        {
            int base = 10;
            int resVal = 0;
            QRegExp hexMatcher("0x[0-9a-fA-F]{2}$");
            if(hexMatcher.exactMatch(text)) //check for hex input
            {
                bool bStatus = false;
                resVal = text.right(2).toUInt(&bStatus,16);
            }
            else        //check for decimal input
            {
                resVal = text.toInt(&ok, base);
                if(!ok)
                {
                    QMessageBox messageBox(this);
                    messageBox.setText("Wrong Input, Try Again");
                    messageBox.exec();
                }
                else
                {
                    QString hexText;
                    hexText.setNum(resVal, 16);//convert number into hex
                    text = "0x" + hexText;
                }
            }
            if(ok)
            {
                if(resVal < 256)
                    mdl->setData(mdl->index(row, col, QModelIndex()), text);
                else
                {
                    QMessageBox messageBox(this);
                    messageBox.setText("Wrong Input, Try Again");
                    messageBox.exec();
                }
            }
        }
    }
    else if((row >= 36) && (row < 60))  //input of luminaire color - string up to 24 symbols
    {
        QString oldText = "";
        getTabModelCellStr(mdl, 36, 24, &oldText);

        QString text = QInputDialog::getText(this, tr("Цвет(Luminaire color)"),
                       tr("Строка до 24 симв.:"), QLineEdit::Normal, oldText, &ok);
        if(ok)
        {
            for(int i = 36; i < 60; i++)
            {
                //QString symbString = text.mid(i-36, 1);
                if(text.size() > (i - 36))
                {
                    quint8 chr = text.at(i - 36).toLatin1();
                    QString hexText;
                    hexText.setNum(chr, 16);//convert number into hex
                    hexText = "0x" + hexText;
                    mdl->setData(mdl->index(i, col, QModelIndex()), hexText);
                }
            }
        }
    }
    else if((row >= 60) && (row < 120)) //input of luminaire identificator - string up to 60 symbols
    {
        QString oldText = "";
        getTabModelCellStr(mdl, 60, 60, &oldText);

        QString text = QInputDialog::getText(this, tr("Идентификатор"),
                       tr("Строка до 60 симв.:"), QLineEdit::Normal, oldText, &ok);
        if(ok)
        {
            for(int i = 60; i < 120; i++)
            {
                //QString symbString = text.mid(i-60, 1);
                if(text.size() > i - 60)
                {
                    quint8 chr = text.at(i - 60).toLatin1();
                    QString hexText;
                    hexText.setNum(chr, 16);//convert number into hex
                    hexText = "0x" + hexText;
                    mdl->setData(mdl->index(i, col, QModelIndex()), hexText);
                }
            }
        }
    }
    ui->memBank1TableView->setModel(mdl);
}

void DaliMain::createMemBank0Tab(QStandardItemModel* model)
{
    model->setColumnCount(3);
    model->setRowCount(27);
    for(quint8 i = 0; i < memBank0HeaderData.size(); i++)
    {
        model->setHeaderData(i, Qt::Horizontal, memBank0HeaderData.at(i));
    }

    for(quint8 i = 0; i < model->rowCount(); i++)
    {
        model->setData(model->index(i, 0, QModelIndex()), "0x" + QString("%1").arg(i, 2, 16, QLatin1Char('0'))); //Address
        model->setData(model->index(i, 1, QModelIndex()), memBank0DescData.at(i)); //Description
    }
    ui->memBank0TableView->setStyleSheet("QHeaderView::section { background-color:lightGray }");
    ui->memBank0TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->memBank0TableView->setModel(diag->getMembank0Model());
    ui->memBank0TableView->setColumnWidth(0, 10);
    ui->memBank0TableView->setColumnWidth(1, 200);
    ui->memBank0TableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

//If executed, the answer shall be the content of the memory location identified by “DTR0”
//within memory bank “DTR1”.
//If the addressed location is below location 0xFF, the control gear shall increment “DTR0” by
//one.
void DaliMain::readBankBtnClick(uint8_t id, uint8_t* bank, uint8_t size)
{
    slaveCmd(DTR1_ADDR_BYTE, id, EXCHANGE_STATE_SEND_DTR0_MEM_CMD, false, false, true);
    memBankSize = size;
    memBankCounter = 0;
    memBankId = id;
    memBankWriteFlag = false;
    memset(bank, 0, size);
    exchangeTimer->stop();
    exchangeTimer->start(700);
    enableControl(false);
}

void DaliMain::readBank0BtnClick()
{
    ui->memBanksProgressBar->setVisible(true);
    ui->memBanksProgressBar->setValue(0);
    readBankBtnClick(0, memBank0Data, sizeof(memBank0Data));
}

void DaliMain::readBank1BtnClick()
{
    ui->memBanksProgressBar->setVisible(true);
    ui->memBanksProgressBar->setValue(0);
    readBankBtnClick(1, memBank1Data, sizeof(memBank1Data));
}

void DaliMain::writeBankBtnClick(quint8 id, quint8 offset)
{
   if(memBankId == 1)
   {
        QStandardItemModel* mBankModel = diag->getMembank1Model();
        quint8 valToWrite = ui->bank1ValueSpinBox->value();
        mBankModel->setData(mBankModel->index(offset, 2, QModelIndex()), "0x" + QString("%1").arg(valToWrite, 2, 16, QLatin1Char('0')));
        ui->memBank1TableView->setModel(mBankModel);
   }
   slaveCmd(DTR1_ADDR_BYTE, id, EXCHANGE_STATE_SEND_DTR0_MEM_CMD, false, false, true);
   memBankId = id;
   memBankOffset = offset;
   memBankWriteFlag = true;
   memBank1FullWriteFlag = false;
   exchangeTimer->stop();
   exchangeTimer->start(700);
   enableControl(false);
}

void DaliMain::writeFullBank1BtnClick()
{
    ui->memBanksProgressBar->setVisible(true);
    ui->memBanksProgressBar->setValue(0);
    writeBankBtnClick(1, 0);
    memBank1FullWriteIndex = 0;
    memBank1FullWriteFlag = true;
}

void DaliMain::writeBank1BtnClick()
{
    quint8 offset = ui->setBank1AddrSpinBox->value();
    writeBankBtnClick(1, offset);
}

void DaliMain::memBank1FlashSaveBtnClick()
{
    quint8 addr = ui->setDevAddrSpinBox->value();
    addr = (addr<<1)|0x01;
    slaveCmd(addr, SAVE_PERSISTENT_VARIABLES, EXCHANGE_STATE_IDLE, true, false, false);
}

void DaliMain::createMemBank1Tab(QStandardItemModel* model)
{
    model->setColumnCount(3);
    model->setRowCount(120);
    for(quint8 i = 0; i < memBank1HeaderData.size(); i++)
    {
        model->setHeaderData(i, Qt::Horizontal, memBank1HeaderData.at(i));
    }

    for(quint8 i = 0; i < model->rowCount(); i++)
    {
        model->setData(model->index(i, 0, QModelIndex()), "0x" + QString("%1").arg(i, 2, 16, QLatin1Char('0'))); //Address
        model->setData(model->index(i, 1, QModelIndex()), memBank1DescData.at(i)); //Description
    }
    ui->memBank1TableView->setStyleSheet("QHeaderView::section { background-color:lightGray }");
    ui->memBank1TableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->memBank1TableView->setModel(model);
    ui->memBank1TableView->setColumnWidth(0, 10);
    ui->memBank1TableView->setColumnWidth(1, 200);
}

void DaliMain::updateMemBankTable()
{
    quint8* pData = NULL;
    QTableView* tabView = NULL;
    if(memBankId == 0)
    {
        pData = memBank0Data;
        tabView = ui->memBank0TableView;
    }
    else if(memBankId == 1)
    {
        pData = memBank1Data;
        tabView = ui->memBank1TableView;
    }
    else if(memBankId == 202)
    {
         pData = memBank202Data;
         tabView = ui->memBank202TableView;
    }
    else if(memBankId == 203)
    {
         pData = memBank203Data;
         tabView = ui->memBank203TableView;
    }
    else if(memBankId == 204)
    {
         pData = memBank204Data;
         tabView = ui->memBank204TableView;
    }
    else if(memBankId == 205)
    {
         pData = memBank205Data;
         tabView = ui->memBank205TableView;
    }
    else if(memBankId == 206)
    {
         pData = memBank206Data;
         tabView = ui->memBank206TableView;
    }
    else if(memBankId == 207)
    {
         pData = memBank207Data;
         tabView = ui->memBank207TableView;
    }
    QStandardItemModel* mdl = diag->fillModel(memBankId, pData);
    if((tabView != NULL) && (mdl != NULL))
        tabView->setModel(mdl);
}

bool DaliMain::openSerialPort()
{
    bool rval = true;
    const SettingsDialog::Settings p = m_settings->settings();
    m_serial->setPortName(p.name);

    if(!m_serial->setBaudRate(QSerialPort::Baud9600))
        qDebug() << "Error baudrate setup";
    if(!m_serial->setDataBits(QSerialPort::Data8))
        qDebug() << "Error databits setup";
    if(!m_serial->setParity(QSerialPort::NoParity))
        qDebug() <<"Error parity setup";
    if(!m_serial->setStopBits(QSerialPort::OneStop))
        qDebug() << "Error stopbits setup";
    if(!m_serial->setFlowControl(QSerialPort::NoFlowControl))
        qDebug() << "Error FlowControl setup";

    if (m_serial->open(QIODevice::ReadWrite)) {

        qDebug() << p.name << " open, baud 9600";
        ui->monitorEdit->append(p.name + " opened");
        enableControl(true);
    }
    else{
        qDebug() << "Open error";
        rval = false;
    }

    QByteArray dummy;
    dummy = m_serial->readAll();

    return rval;
}

void DaliMain::comPortHandleError(QSerialPort::SerialPortError error){

    if (error == QSerialPort::ResourceError) {
        qDebug() << "Critical COM Port Error";
        if (m_serial->isOpen())
            m_serial->close();
    }
}

void DaliMain::comPortReadData()
{
    int bts = m_serial->bytesAvailable();
    if(bts > 3)
    {
        rdData.clear();
        rdData = m_serial->readAll();
        QString reply;
        reply.clear();


        reply = "got " + QString::number(bts) + " bytes, ";
        for(int i = 0; i < bts; i++)
        {
            QString rxBt = QString("%1").arg(rdData.at(i), 2, 16, QLatin1Char( '0' ));
            if(rxBt.size() > 2)
            {
                rxBt = rxBt.right(2);
            }
            reply += rxBt + " ";
        }
        qDebug() << reply;
        if(ui->timeStampCheckBox->isChecked())
        {
            QTime currTm = QTime::currentTime();
            reply.prepend(currTm.toString() + "->");
        }
        ui->monitorEdit->append(reply);

        if(comPortProcessData())
        {
            int timeRemain = waitRxTimer->remainingTime();
            qDebug() << "TimeRemain = " + QString::number(timeRemain);
            waitRxTimer->stop();
        }
    }
}

void DaliMain::comSetup()
{
    m_settings->fillPortsInfo();
    m_settings->show();
}

void DaliMain::comConnect()
{
    if (!m_serial->isOpen())
    {
        if(!openSerialPort())
        {
            ui->monitorEdit->append("port open error");
            qDebug() << "can't open port";
            return;
        }
    }
}

void DaliMain::enableControl(bool isConnect)
{
    QList<QPushButton*>controlButtons  = {ui->discoverButton, ui->readBank0Btn,
                                          ui->readBank1Btn, ui->writeFullBank1Btn, ui->writeBank1Btn,
                                          ui->sendCmdToPushButton, ui->sendExtCmdToPushButton,
                                          ui->sceneSetButton, ui->sceneRemoveButton,
                                          ui->sceneGoToButton, ui->sceneQueryLevelButton,
                                          ui->fadeTimeSetBtn, ui->fastFadeTimeSetBtn,
                                          ui->extendedFadeTimeSetBtn, ui->findDeviceButton,
                                           ui->memBank1FlashSaveBtn,                            //ui->colorButton,
                                          ui->memBank202ReadButton, ui->memBank203ReadButton,
                                          ui->memBank204ReadButton, ui->mBank205ReadButton,
                                          ui->mBank206ReadButton, ui->mBank207ReadButton,
                                          ui->memBank202SetLockButton,ui->memBank203SetLockButton,
                                          ui->memBank204SetLockButton, ui->memBank205SetLockButton,
                                          ui->memBank206SetLockButton, ui->memBank207SetLockButton,
                                          ui->memBank202ClrLockButton, ui->memBank203ClrLockButton,
                                          ui->memBank204ClrLockButton, ui->memBank205ClrLockButton,
                                          ui->memBank206ClrLockButton, ui->memBank207ClrLockButton,
                                          ui->testRunButton};

    QList<QPushButton*>::iterator ctrlBtnsIterator;
    for (ctrlBtnsIterator = controlButtons.begin(); ctrlBtnsIterator != controlButtons.end(); ctrlBtnsIterator++)
    {
        QPushButton* btn = *ctrlBtnsIterator;
        btn->setEnabled(isConnect);
    }

    QList<QSlider*>controlSliders = {ui->broadcastSlider, ui->redSlider, ui->greenSlider, ui->blueSlider,
                                     }; //ui->hueSlider, ui->saturationSlider, ui->valueSlider

    QList<QSlider*>::iterator ctrlSlidersIterator;
    for (ctrlSlidersIterator = controlSliders.begin(); ctrlSlidersIterator != controlSliders.end(); ctrlSlidersIterator++)
    {
        QSlider* sldr = *ctrlSlidersIterator;
        sldr->setEnabled(isConnect);
    }
    colourControlWidget->setEnabled(isConnect);
}

void DaliMain::comDisconnect()
{
    if (m_serial->isOpen())
    {
        m_serial->close();
        enableControl(false);
    }
}

void DaliMain::replyFromMaster(QByteArray* data)
{
    uint8_t len = data->at(1);
    uint8_t sub_reply_id = data->at(2);
    switch(sub_reply_id)
    {
        case MASTER_VID_PID:
            {
                if(len != 6)
                {
                    qDebug() << "ERROR master vid pid len";
                }
                uint16_t vid = data->at(3);
                vid += ((uint16_t)data->at(4)) * 256;
                ui->vidEdit->setText(QString("%1").arg(vid, 4, 16, QLatin1Char( '0' )));

                uint16_t pid = data->at(5);
                pid += ((uint16_t)data->at(6)) * 256;
                ui->pidEdit->setText(QString("%1").arg(pid, 4, 16, QLatin1Char( '0' )));
            }
            break;
        default:

            break;
    }
}

uint8_t DaliMain::replyFromSlave(QByteArray* data)
{
    uint8_t rd_crc = rdData.at(data->size() - 1);
    uint8_t crc = calcCrc(data, data->size() - 1);
    if(crc != rd_crc)
    {
        qDebug() << "ERROR slave reply crc calc";
        return 0;
    }
   // uint8_t len = data->at(1);
    return data->at(2);
}

bool DaliMain::comPortProcessData()
{
    if(rdData.size() == 0)
    {
        qDebug() << "ERROR receiving data";
        return false;
    }
    uint8_t rd_crc = rdData.at(rdData.size() - 1);
    uint8_t crc = calcCrc(&rdData, rdData.size() - 1);
    if(crc != rd_crc)
    {
        qDebug() << "ERROR crc calc";
        return false;
    }
    replyId = rdData.at(0);

    int tabIndex = ui->tabWidget->currentIndex();
    qDebug() << "rx: tab IX = " + QString::number(tabIndex);

    switch(replyId)
    {
        case MASTER_CMD:
            replyFromMaster(&rdData);
            break;
        case SLAVE_CMD:
            replyByte = replyFromSlave(&rdData);

            if(tabIndex == DALI_COMMANDS_TAB_INDEX)
            {
                if(0xFF == replyByte)
                {
                    if((cmdId >= QUERY_SCENE_LEVEL_0) && (cmdId <= QUERY_SCENE_LEVEL_15))
                    {
                        ui->replyEdit->setText("MASK");
                    }
                    else if((cmdId >= QUERY_ACTUAL_LEVEL) && (cmdId <= QUERY_SYSTEM_FAILURE_LEVEL))
                    {
                        ui->replyEdit->setText("level = 255");
                    }
                    else if((cmdId >= QUERY_RANDOM_ADDR_H) && (cmdId <= QUERY_RANDOM_ADDR_L))
                    {
                        ui->replyEdit->setText("0xFF(255)");
                    }
                    else if (cmdId == QUERY_FADE_TIME_RATE)
                    {
                        ui->replyEdit->setText("rawdata:0xFF");
                    }
                    else
                    {
                        ui->replyEdit->setText("Yes");
                    }
                }
                else
                    ui->replyEdit->setText(QString("%1").arg(replyByte, 2, 16, QLatin1Char('0')));
                ui->replyDecEdit->setText(QString::number(replyByte));
                ui->replyHexEdit->setText("0x" + QString("%1").arg(replyByte, 2, 16, QLatin1Char('0')));

                daliCommandParcer parcer;
                QString explainStr;
                parcer.explainReply(cmdId, replyByte, &explainStr);
                ui->replyExplaintEdit->setText(explainStr);

                if(ui->periodSendCheckBox->isChecked())
                   sendCmdToPushButtonClicked();
            }
            else if(tabIndex == DALI_EXT_COMMANDS_TAB_INDEX)
            {
                if(0xFF == replyByte)
                    ui->extReplyEdit->setText("Yes");
                else
                    ui->extReplyEdit->setText(QString("%1").arg(replyByte, 2, 16, QLatin1Char('0')));
                ui->extReplyDecEdit->setText(QString::number(replyByte));
                ui->extReplyHexEdit->setText("0x" + QString("%1").arg(replyByte, 2, 16, QLatin1Char('0')));

                daliCommandParcer parcer;
                QString explainStr;
                quint8 spec = getSpec(ui->specSelComboBox->currentText());
                parcer.explainExtReply(cmdId, replyByte, &explainStr, spec);
                ui->extReplyExplaintEdit->setText(explainStr);
            }
            else if(tabIndex == SCENE_TESTS_TAB_INDEX)
            {
                ui->sceneValSpinBox->setValue(replyByte);
            }
            else if(tabIndex == DAPC_TAB_INDEX)
            {
                if(opcode_byte == 250)
                {
                    colourControlWidget->receiveColourValue(replyByte);
                }
            }
            else if(tabIndex == SEARCH_ADDRESSING_TAB_INDEX)
            {
                qDebug() << "search/addressing";
                if(query_type == QUERY_DEVICE_TYPE)
                {
                    gear[gear_idx].type = replyByte;
                    qDebug() << "save type devId=" + QString::number(gear_idx) + " type=" + QString::number(replyByte);

                }
                else if(query_type == QUERY_VERSION_NUMBER)
                {
                   gear[gear_idx].version = replyByte;
                   qDebug() << "save version devId=" + QString::number(gear_idx) + " ver=" + QString::number(replyByte);
                   gear_idx++;
                   shortAddress++;
                   if(shortAddress == 64)
                       shortAddress = 0;
                }
            }
            else if(tabIndex == DALI_MEM_BANKS_TAB_INDEX)
            {
                if(exchangeState == EXCHANGE_STATE_READ_MEM_CMD) //before read mem commands we sent dtr0, dtr1 defs
                {
                    if(memBankId == 0)
                    {
                        qDebug() << "save membank0 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank0Data[memBankCounter-1] =  rdData.at(2);
                    }
                    else if(memBankId == 1)
                    {
                        qDebug() << "save membank1 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank1Data[memBankCounter-1] =  rdData.at(2);
                    }
                }
            }
            else if(tabIndex == DALI_ENERGY_PWR_TAB_INDEX)
            {
                if(exchangeState == EXCHANGE_STATE_READ_MEM_CMD) //before read mem commands we sent dtr0, dtr1 defs
                {
                    if(memBankId == 202)
                    {
                        qDebug() << "save membank202 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank202Data[memBankCounter-1] =  rdData.at(2);
                    }
                    else if(memBankId == 203)
                    {
                        qDebug() << "save membank203 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank203Data[memBankCounter-1] =  rdData.at(2);
                    }
                    else if(memBankId == 204)
                    {
                        qDebug() << "save membank204 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank204Data[memBankCounter-1] =  rdData.at(2);
                    }
                }
            }
            else if(tabIndex == DALI_DIAGNOSTICS_TAB_INDEX)
            {
                if(exchangeState == EXCHANGE_STATE_READ_MEM_CMD) //before read mem commands we sent dtr0, dtr1 defs
                {
                    if(memBankId == 205)
                    {
                        qDebug() << "save membank205 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank205Data[memBankCounter-1] =  rdData.at(2);
                    }
                    else if(memBankId == 206)
                    {
                        qDebug() << "save membank206 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank206Data[memBankCounter-1] =  rdData.at(2);
                    }
                    else if(memBankId == 207)
                    {
                        qDebug() << "save membank207 Id=" + QString::number(memBankCounter-1) + " Data:" + QString::number(rdData.at(2));
                        memBank207Data[memBankCounter-1] =  rdData.at(2);
                    }
                }
            }
            else if(tabIndex == DALI_TEST_SEQUENSE_TAB_INDEX)
            {
                testSeqProcessReply();
                exchangeTimer->stop();
                exchangeTimer->start(125); //next step after 125 mS
            }
            else
            {
                qDebug() << "tab Ix = " + QString::number(tabIndex);
            }
            break;
        case SLAVE_EMPTY_CMD:
            if(tabIndex == DALI_COMMANDS_TAB_INDEX)
            {
                ui->replyEdit->setText("");
                ui->replyDecEdit->setText("");
                ui->replyHexEdit->setText("");
            }
            else if(tabIndex == SEARCH_ADDRESSING_TAB_INDEX)
            {
                exchangeTimer->stop();
                exchangeTimer->start(125); //next step after 125 mS
            }
            else if(tabIndex == DALI_EXT_COMMANDS_TAB_INDEX)
            {
                ui->extReplyEdit->setText("");
                ui->extReplyDecEdit->setText("");
                ui->extReplyHexEdit->setText("");
            }
            else if(tabIndex == DALI_TEST_SEQUENSE_TAB_INDEX)
            {
                testSeqProcessNoReply();
                exchangeTimer->stop();
                exchangeTimer->start(125); //next step after 125 mS
            }
            else if(tabIndex == DALI_TEST_SEQUENSE_TAB_INDEX)
            {
                testSeqProcessNoReply();
                exchangeTimer->stop();
                exchangeTimer->start(125); //next step after 125 mS
            }
            qDebug() << "SLAVE_EMPTY_CMD";
            break;
        case SLAVE_REPLY_TOUT_CMD:
            if(tabIndex == DALI_COMMANDS_TAB_INDEX)
            {
                ui->replyEdit->setText("Timeout");
                ui->replyDecEdit->setText("");
                ui->replyHexEdit->setText("");
            }
            else if(tabIndex == DALI_EXT_COMMANDS_TAB_INDEX)
            {
                ui->extReplyEdit->setText("Timeout");
                ui->extReplyDecEdit->setText("");
                ui->extReplyHexEdit->setText("");
            }
            else if(tabIndex == DALI_MEM_BANKS_TAB_INDEX)
            {
                if(exchangeState == EXCHANGE_STATE_READ_MEM_CMD)
                {
                    qDebug() << "Membanks read command fails";
                    //memBankCounter = 255; //Stop exchange
                }
            }
            else if(tabIndex == SEARCH_ADDRESSING_TAB_INDEX)
            {
                if((exchangeState == EXCHANGE_STATE_GET_VERSION) || (exchangeState == EXCHANGE_STATE_GET_TYPE))
                {
                    qDebug() << "Can't get gear type/version";
                    gear_idx = gear_max_idx; //Stop searching
                }
            }
            if(tabIndex == DALI_TEST_SEQUENSE_TAB_INDEX)
            {
                testSeqProcessTimeout();
                exchangeTimer->stop();
                exchangeTimer->start(125); //next step after 125 mS
            }
            qDebug() << "SLAVE_REPLY_TOUT_CMD";
            break;
        default:
            ui->replyEdit->setText("Wrong Id");
            qDebug() << "ERROR wrong reply ID";
            break;
    }
    return true;
}

void DaliMain::waitRxTimerShot(){

    if(!waitRx)
       return;

    waitRx = false;
    if(ui->tabWidget->currentIndex() == DALI_COMMANDS_TAB_INDEX)
    {
         ui->replyEdit->setText("No");
    }

    qDebug() << "waitRxTimerShot";
}

uint8_t DaliMain::calcCrc(QByteArray* data, uint8_t len)
{
    uint8_t crc = 0;
    for(uint8_t i = 0; i < len; i++)
    {
        crc += data->at(i);
    }
    return ~crc;
}

void DaliMain::findMasterDevice()
{
    QByteArray data;
    data.append((char)MASTER_CMD);
    data.append(0x01);  //length
    data.append((char)MASTER_VID_PID); //master command "request to master vid&pid"
    uint8_t crc = calcCrc(&data, data.size());
    data.append(crc);

    m_serial->write(data);

    waitRxTimer->stop();//reload timer
    waitRx = true;      //expect for reply from master
    rdData.clear();
    waitRxTimer->start(1000);
}

void DaliMain::clearMonitorWindow()
{
    ui->monitorEdit->clear();
}

void DaliMain::slaveCmd(quint8 addrByte, quint8 opCode, discover_state_e next_state, bool setTwice, bool answer, bool is_special)
{
    QByteArray data;

    char cmdId = (char)SLAVE_CMD;
    if(setTwice)
        cmdId |= COMMAND_SEND_TWICE_FLAG;
    if(answer)
        cmdId |= COMMAND_EXPECT_ANSWER_FLAG;
    if(is_special)
        cmdId |= COMMAND_SPECIAL_FLAG;

    data.append(cmdId);
    data.append(0x03);  //length
    data.append((char)addrByte); //
    data.append((char)opCode); //
    uint8_t crc = calcCrc(&data, data.size());
    data.append(crc);
    m_serial->write(data);

    waitRxTimer->stop();//reload timer
    waitRx = true;      //expect for reply from master
    rdData.clear();
    waitRxTimer->start(600);
    qDebug() << "start waitRx, 600 mS";

    QString request = "send: " ;
    for(int i = 0; i < 5; i++)
    {
        QString txBt = QString("%1").arg(data.at(i), 2, 16, QLatin1Char( '0' ));
        if(txBt.size() > 2)
        {
           txBt = txBt.right(2);
        }
        request += txBt + " ";
    }
    ui->monitorEdit->append(request);

    exchangeState = next_state;
}

void DaliMain::searchAddrStart()
{
    exchangeState = EXCHANGE_STATE_TERMINATE_CMD;
    query_type = 0;
    ui->discoverButton->setEnabled(false);
    ui->discoverStopButton->setEnabled(true);

    shortAddr = ui->startAddrSpinBox->value();
    shortAddress = shortAddr;

    if(ui->newInitCheckBox->isChecked())
    {
       clearTable();
    }
    exchangeTimer->start(700);
}

void DaliMain::exchangeStop()
{
    exchangeState = EXCHANGE_STATE_IDLE;
    ui->discoverButton->setEnabled(true);
    ui->discoverStopButton->setEnabled(false);
    exchangeTimer->stop();
}

void DaliMain::clearDiscovered()
{
    ui->searchInfoEdit->clear();
}

void DaliMain::typeVersionBtnClicked()
{
    exchangeState = EXCHANGE_STATE_GET_TYPE;
    gear_idx = 0;
    gear_max_idx = 3;
    exchangeTimer->start(100);
}

void DaliMain::exchangeTimerShot(){
    exchangeProcess();
}

uint8_t DaliMain::generateRandomByte()
{
    QRandomGenerator rndGen;
    quint32 rnd = rndGen.bounded(0, 63);
    return (uint8_t)rnd;
}

//"Short Address", "Random Address", "Type", "Version", "Connected"
void DaliMain::addFoundedGearToTable(uint32_t searchAddress, uint8_t shortAddress)
{
    model.setData(model.index(tableEmptyRow, 0, QModelIndex()), "0x" + QString("%1").arg(shortAddress, 2, 16, QLatin1Char('0')));
    model.setData(model.index(tableEmptyRow, 1, QModelIndex()), "0x" + QString("%1").arg(searchAddress, 6, 16, QLatin1Char('0')));
    model.setData(model.index(tableEmptyRow, 2, QModelIndex()), QString::number(type));
    model.setData(model.index(tableEmptyRow, 3, QModelIndex()), QString::number(version));
    QString isConnStr;
    if(connected == false)
        isConnStr = "Disconnected";
    else
        isConnStr = "Connected";
    model.setData(model.index(tableEmptyRow, 4, QModelIndex()), isConnStr);
    tableEmptyRow++;
    ui->searchResultsTableView->setModel(&model);
}

void DaliMain::gearTypeStrGet(uint8_t type, QString* typeStr)
{
    QString gearTypes[] = {"Fluorescent lamp", "Self-cont. emergency", "HID lamp",
                           "Low volt. Halogen lamp", "Incandescent lamp dim.",
                           "Conv. to DC (0/1-10 V)", "LED module", "Switching",
                           "Colour control"};
    if(type > sizeof(gearTypes)/sizeof(gearTypes[0]))
    {
        qDebug() << "Wrong Gear Type";
        return;
    }
    *typeStr = gearTypes[type];
}

void DaliMain::addTypeVersionToTable()
{
    for(int i = 0; i < gear_idx; i++)
    {
        QString gearTypeStr;
        gearTypeStrGet(gear[i].type, &gearTypeStr);
        model.setData(model.index(i, 2, QModelIndex()), gearTypeStr);
        uint8_t ver_major = gear[i].version >> 2;
        uint8_t ver_minor = gear[i].version & 0x03;
        model.setData(model.index(i, 3, QModelIndex()), QString::number(ver_major) + "." + QString::number(ver_minor));
        model.setData(model.index(i, 4, QModelIndex()), "Connected");
    }
    ui->searchResultsTableView->setModel(&model);
}

void DaliMain::clearTable()
{
    for(quint8 i = 0; i < tableEmptyRow; i++)
    {
        model.setData(model.index(i, 0, QModelIndex()), "");
        model.setData(model.index(i, 1, QModelIndex()), "");
        model.setData(model.index(i, 2, QModelIndex()), "");
        model.setData(model.index(i, 3, QModelIndex()), "");
        model.setData(model.index(i, 4, QModelIndex()), "");
    }
    tableEmptyRow = 0;
}

void DaliMain::storeGearParams()
{
    gear[shortAddr].random_addr = searchAddress;
}


void DaliMain::testSeqSetNextHighLightBackGround(quint16 next)
{
    int currItemID = nextTestSeqCmd;
    if(nextTestSeqCmd > 0)
        currItemID = nextTestSeqCmd - 1;
    QStandardItem* currItem = testTabModel.item(currItemID, 2);
    currItem->setBackground(Qt::white);
    nextTestSeqCmd = next;
    if(nextTestSeqCmd > 0)
        currItemID = nextTestSeqCmd - 1;
    if(nextTestSeqCmd < testSeqCmds.size())
    {
        currItem = testTabModel.item(currItemID, 2);
        currItem->setBackground(Qt::green); //(QColor(0,0,0,0)); //(Qt::yellow);

    }
}

void DaliMain::exchangeProcess()
{
    QByteArray data;
    uint8_t cmdType = TYPE_BROADCAST;
    uint8_t destination = 0;
    daliCommandParcer parcer;

    //Address byte of INITIALISE command:
    //0x00 - All control gear shall react - Normal Initialise,
    //0xFF - Control gear without “shortAddress” shall react - initialize on missing short address,
    //0AAAAAA1b Device(s) with “shortAddress” equal to 00AAAAAAb - initialize if own short address recognized
    quint8 opCode = 0x00;

    switch(exchangeState)
    {
        case EXCHANGE_STATE_IDLE:

            break;
        case EXCHANGE_STATE_TERMINATE_CMD:
            slaveCmd(TERMINATE_ADDR_BYTE, opCode, EXCHANGE_STATE_RESET_CMD, false, false, true);
            break;
        case EXCHANGE_STATE_RESET_CMD:
            address_byte = parcer.getStandartCmdAddrByte(TYPE_BROADCAST, 0, false);
            slaveCmd(address_byte, RESET_OPCODE, EXCHANGE_STATE_OFF_CMD, true, false, false);
        break;
        case EXCHANGE_STATE_OFF_CMD:
            address_byte = parcer.getStandartCmdAddrByte(cmdType, destination, false);
            slaveCmd(address_byte, OFF_OPCODE, EXCHANGE_STATE_INITIALISE_CMD, false, false, false);
        break;
        case EXCHANGE_STATE_INITIALISE_CMD:
            slaveCmd(INTIALISE_ADDR_BYTE, opCode, EXCHANGE_STATE_RANDOMISE_CMD, true, false, true);
            break;
        case EXCHANGE_STATE_RANDOMISE_CMD:
            minAddress = 0;
            maxAddress = MAX_ADDR;
            searchAddress = (maxAddress + minAddress)/2;

            ui->searchInfoEdit->append("Start Assigning From: " + QString::number(shortAddr) + "\r\n");
            replyByte = 0x00;
            slaveCmd(RANDOMISE_ADDR_BYTE, opCode, EXCHANGE_STATE_SEARCHADDRH_CMD, true, false, true);
            break;
        case EXCHANGE_STATE_SEARCHADDRH_CMD:
            slaveCmd(SEARCHADDRH_ADDR_BYTE, (uint8_t)(searchAddress>>16), EXCHANGE_STATE_SEARCHADDRM_CMD, false, false, true);
            break;
        case EXCHANGE_STATE_SEARCHADDRM_CMD:
            slaveCmd(SEARCHADDRM_ADDR_BYTE, (uint8_t)(searchAddress>>8), EXCHANGE_STATE_SEARCHADDRL_CMD, false, false, true);
            break;
        case EXCHANGE_STATE_SEARCHADDRL_CMD:
            slaveCmd(SEARCHADDRL_ADDR_BYTE, (uint8_t)(searchAddress), EXCHANGE_STATE_COMPARE_CMD, false, false, true);
            if(saveSearchFlag)
            {
                ui->searchInfoEdit->append("skip compare");
                saveSearchFlag = false;
                exchangeState =  EXCHANGE_STATE_PROG2_SHORT_ADDR_CMD;
            }
            break;
        case EXCHANGE_STATE_COMPARE_CMD:
            slaveCmd(COMPARE_ADDR_BYTE, (uint8_t)(0x00), EXCHANGE_STATE_PROGRAM_SHORT_ADDR_CMD, false, true, true);
            break;
        case EXCHANGE_STATE_PROGRAM_SHORT_ADDR_CMD:
            if(replyId == SLAVE_CMD)
            {
                if(replyByte == 0xFF) //“randomAddress” < “searchAddress”: YES;
                {
                    ui->searchInfoEdit->append("YES, max = search");
                    maxAddress = searchAddress;
                }
            }
            else if(replyId == SLAVE_EMPTY_CMD) //Unexpected reply - repeat
            {
                ui->searchInfoEdit->append("Unexpected reply to COMPARE command");
            }
            else if(replyId == SLAVE_REPLY_TOUT_CMD)//slave replies "NO":“randomAddress” > “searchAddress”
            {
                ui->searchInfoEdit->append("NO, min = search"); //Reply timeout means NO
                minAddress = searchAddress;
            }
            if(maxAddress - minAddress < 2)
            {
               if(replyByte == 0xFF)
               {
                    ui->searchInfoEdit->append("Found luminaire!! (case 1)");
                    addFoundedGearToTable(searchAddress, shortAddress);

                    ui->searchInfoEdit->append("prog short case 1 short=" + QString::number(shortAddress));

                    quint8 prog_addr = (shortAddress<<1)|0x01;
                    if(prog_addr & 0x80)
                        prog_addr &= ~0x80;
                    slaveCmd(PROGRAM_SHORT_ADDR_BYTE, prog_addr, EXCHANGE_STATE_VERIFY_SHORT_ADDR_CMD, false, false, true);
               }
               else
               {
                   if(searchAddress == MAX_ADDR - 1) //ALL GEARS FOUND
                   {
                        //Stop the search process with "Terminate"
                        quint8 prog_addr = (shortAddress<<1)|0x01;
                        if(prog_addr & 0x80)
                            prog_addr &= ~0x80;
                        slaveCmd(TERMINATE_ADDR_BYTE, prog_addr, EXCHANGE_STATE_GET_TYPE, false, false, true);
                        gear_idx = 0;
                        if(shortAddress > shortAddr)
                            gear_max_idx = shortAddress - shortAddr;
                        else
                            gear_max_idx = 64 - (shortAddr - shortAddress);

                        shortAddress = shortAddr;  //one more loop

                        qDebug() << "gear idx = " + QString::number(gear_idx) + "gear max idx = " + QString::number(gear_max_idx);

                        ui->devCountEdit->setText(QString::number(gear_max_idx));
                        ui->searchInfoEdit->append("No more gear found, read type/version"); //terminate");
                   }
                   else
                   {
                       ui->searchInfoEdit->append("Found luminaire!! (case 2)");
                       searchAddress++;     //address is bigger by 1, because of "No" reply
                       addFoundedGearToTable(searchAddress, shortAddress);
                       saveSearchFlag = true;
                       cmd_repeat_cntr = 0;
                       exchangeState =  EXCHANGE_STATE_SEARCHADDRH_CMD;  //save search address to gear, withdraw command fails otherwise
                   }
               }
            }
            else
            {
                searchAddress = (maxAddress + minAddress)/2;
                ui->searchInfoEdit->append("New search addr: " + QString("%1").arg(searchAddress, 6, 16, QLatin1Char('0')));
                exchangeState = EXCHANGE_STATE_SEARCHADDRH_CMD;
            }
            replyByte = 0x00;
            break;
        case EXCHANGE_STATE_GET_TYPE:
            if(gear_idx == gear_max_idx)
            {
                qDebug() << "gear idx = gear max idx";
                addTypeVersionToTable();
                gear_idx = 0;
                exchangeStop();
                exchangeState = EXCHANGE_STATE_IDLE;
            }
            else
            {
                query_type = QUERY_DEVICE_TYPE;
                quint8 prog_addr = (shortAddress<<1)|0x01;
                if(prog_addr & 0x80)
                    prog_addr &= ~0x80;
                slaveCmd(prog_addr, QUERY_DEVICE_TYPE, EXCHANGE_STATE_GET_VERSION, false, true, false);

                qDebug() << "Get version, shortAddress = " + QString::number(shortAddress);

                exchangeTimer->stop();
                exchangeTimer->start(700);
            }
            break;
        case EXCHANGE_STATE_GET_VERSION:
            {
                query_type = QUERY_VERSION_NUMBER;
                quint8 prog_addr = (shortAddress<<1)|0x01;
                if(prog_addr & 0x80)
                    prog_addr &= ~0x80;
                slaveCmd(prog_addr, QUERY_VERSION_NUMBER, EXCHANGE_STATE_GET_TYPE, false, true, false);

            }
            break;
        case EXCHANGE_STATE_PROG2_SHORT_ADDR_CMD:
            {
                ui->searchInfoEdit->append("prog short case 2 short=" + QString::number(shortAddress));
                quint8 prog_addr = (shortAddress<<1)|0x01;
                if(prog_addr & 0x80)
                    prog_addr &= ~0x80;
                slaveCmd(PROGRAM_SHORT_ADDR_BYTE, prog_addr, EXCHANGE_STATE_VERIFY_SHORT_ADDR_CMD, false, false, true);
            }
            break;
        case EXCHANGE_STATE_VERIFY_SHORT_ADDR_CMD:
            {
                //If executed, the answer shall be YES if “shortAddress” is equal to 00AAAAAAb for data given
                //    by 0AAAAAA1b, and NO otherwise.
                quint8 prog_addr = (shortAddress<<1)|0x01;
                if(prog_addr & 0x80)
                    prog_addr &= ~0x80;
                ui->searchInfoEdit->append("Send verify short to addr " + QString::number(shortAddress));
                slaveCmd(VERIFY_SHORT_ADDR_BYTE, prog_addr, EXCHANGE_STATE_WITHDRAW_CMD, false, true, true);
            }
            break;
        case EXCHANGE_STATE_WITHDRAW_CMD:
            if(replyByte == 0xFF)
            {
                storeGearParams();
                minAddress = searchAddress + 1; //found minimal bus address, next probably found is bigger
                maxAddress = MAX_ADDR;
                searchAddress = (minAddress + maxAddress)/2;
                ui->searchInfoEdit->append("Send WITHDRAW");
                ui->searchInfoEdit->append("New search addr: " + QString("%1").arg(searchAddress, 6, 16, QLatin1Char('0')));
                slaveCmd(WITHDRAW_ADDR_BYTE, (uint8_t)(0x00), EXCHANGE_STATE_SEARCHADDRH_CMD, false, false, true); //search next gear

                if(shortAddress < 64)
                    shortAddress++;
                else
                    shortAddress = 0;

            }
            else if(replyId == SLAVE_REPLY_TOUT_CMD)
            {
                if(cmd_repeat_cntr >= 3)
                {
                    cmd_repeat_cntr = 0;
                    ui->searchInfoEdit->append("Stop searching, verify short replies NO 3 times");
                    exchangeStop();
                }
                else
                {
                   cmd_repeat_cntr++;
                   ui->searchInfoEdit->append("one's more");
                   exchangeState = EXCHANGE_STATE_VERIFY_SHORT_ADDR_CMD;
                }
            }
            else
            {
                ui->searchInfoEdit->append("Stop searching");
                exchangeStop();
            }
            break;
        case EXCHANGE_STATE_SET_SCENE_CMD:
            {
                quint8 addr = ui->sceneAddrSpinBox->value();
                addr = (addr<<1)|0x01;
                quint8 opcodeBase = 0x40;
                quint8 sceneNumber = ui->sceneNmbSpinBox->value();
                quint8 opcode = opcodeBase + sceneNumber;
                slaveCmd(addr, opcode, EXCHANGE_STATE_IDLE, true, false, false);
            }
            break;
        case EXCHANGE_STATE_SET_FADE_TIME_CMD:
            {
                quint8 addr = ui->sceneAddrSpinBox->value();
                if(ui->bCastAddrCheckBox->isChecked())
                {
                    addr = 0xFF;
                }
                else
                {
                    addr = (addr<<1)|0x01;
                }
                slaveCmd(addr, SET_FADE_TIME_OPCODE, EXCHANGE_STATE_IDLE, true, false, false);
            }
            break;
        case EXCHANGE_STATE_SET_DEVICE_TYPE_6_CMD:
            slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, 6, EXCHANGE_STATE_SET_FAST_FADE_TIME_CMD, false, false, true);
            break;
        case EXCHANGE_STATE_SET_FAST_FADE_TIME_CMD:
            {
                quint8 addr = ui->sceneAddrSpinBox->value();
                if(ui->bCastAddrCheckBox->isChecked())
                {
                    addr = 0xFF;
                }
                else
                {
                    addr = (addr<<1)|0x01;
                }
                slaveCmd(addr, SPEC_207_SET_FAST_FADE_TIME, EXCHANGE_STATE_IDLE, true, false, false);
            }
            break;
        case EXCHANGE_STATE_SET_EXTENDED_FADE_TIME_CMD:
            {
                quint8 addr = ui->sceneAddrSpinBox->value();
                if(ui->bCastAddrCheckBox->isChecked())
                {
                    addr = 0xFF;
                }
                else
                {
                    addr = (addr<<1)|0x01;
                }
                slaveCmd(addr, SET_EXTENDED_FADE_TIME_OPCODE, EXCHANGE_STATE_IDLE, true, false, false);
            }
            break;
        case EXCHANGE_STATE_SEND_EXTEND_CMD:
            sendExtendedCommand(); //next state IDLE defined inside func body
            break;
        case EXCHANGE_STATE_SEND_COLOUR_CTRL_CMD:
            slaveCmd(DTR1_ADDR_BYTE, dtr1, EXCHANGE_STATE_SEND_ENABLE_TYPE8_CMD, false, false, true);
            exchangeTimer->start(150);
            break;
        case EXCHANGE_STATE_SEND_ENABLE_TYPE8_CMD:
            slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, 8, EXCHANGE_STATE_SEND_COLOUR_CMD, false, false, true);
            exchangeTimer->start(150);
            break;
        case EXCHANGE_STATE_SEND_COLOUR_CMD:
            if(opcode_byte == 250)
            {
                slaveCmd(address_byte, opcode_byte, EXCHANGE_STATE_GET_DTR, false, true, false);
            }
            else
            {
                if(opcode_byte != 231)
                    slaveCmd(address_byte, opcode_byte, EXCHANGE_STATE_IDLE, false, false, true);//next state IDLE defined inside func body
                else
                    slaveCmd(address_byte, opcode_byte, EXCHANGE_STATE_DT8_ACTIVATE, false, false, true);
            }
            exchangeTimer->start(150);
            break;
        case EXCHANGE_STATE_GET_DTR:
            slaveCmd(address_byte, QUERY_CONTENT_DTR0, EXCHANGE_STATE_IDLE, false, true, false);
            break;
        case EXCHANGE_STATE_DT8_ACTIVATE:
            slaveCmd(ENABLE_DEVICE_TYPE_OPCODE, 8, EXCHANGE_STATE_SEND_ACTIVATE_CMD, false, false, true);
            exchangeTimer->start(150);
            break;
        case EXCHANGE_STATE_SEND_ACTIVATE_CMD:
            slaveCmd(address_byte, DT8_ACTIVATE, EXCHANGE_STATE_IDLE, false, false, false);
            break;
        case EXCHANGE_STATE_SEND_DAPC_CMD:
            if(nextToSend == GREEN_COLOR)
            {
                quint8 addrByte = ui->greenAddrSpinBox->value();
                sendDAPCData(addrByte, green);
                exchangeTimer->stop();
                exchangeTimer->start(500);
                exchangeState = EXCHANGE_STATE_SEND_DAPC_CMD;
                nextToSend = BLUE_COLOR;
            }
            else if(nextToSend == BLUE_COLOR)
            {
                quint8 addrByte = ui->blueAddrSpinBox->value();
                exchangeState = EXCHANGE_STATE_IDLE;
                sendDAPCData(addrByte, blue);
            }
            else  //unexpected value
            {
                exchangeState = EXCHANGE_STATE_IDLE;
            }
            break;
        case EXCHANGE_STATE_READ_MEM_CMD:
            {
                quint8 addr = ui->setDevAddrSpinBox->value();
                addr = (addr<<1)|0x01;

                if(memBankCounter >= memBankSize)
                {
                    ui->pwrEnergyProgressBar->setVisible(false);
                    ui->diagProgressBar->setVisible(false);
                    ui->memBanksProgressBar->setVisible(false);
                    if(memBankCounter == 255)
                    {
                       qDebug() << "Error timeout!!!";
                    }
                    else
                    {
                        enableControl(true);
                        updateMemBankTable();
                    }
                    exchangeStop();
                }
                else
                {
                    if(memBankId == 0)
                    {
                        ui->memBanksProgressBar->setValue(memBankCounter*4);
                    }
                    else if(memBankId == 1)
                    {
                       ui->memBanksProgressBar->setValue(memBankCounter);
                    }
                    else if((memBankId == 202) || (memBankId == 203) || (memBankId == 204))
                    {
                        ui->pwrEnergyProgressBar->setValue(memBankCounter*6);
                    }
                    else if(memBankId == 205)
                    {
                       ui->diagProgressBar->setValue(memBankCounter*4);
                    }
                    else if(memBankId == 206)
                    {
                       ui->diagProgressBar->setValue(memBankCounter*3);
                    }
                    else if(memBankId == 207)
                    {
                       ui->diagProgressBar->setValue(memBankCounter*14);
                    }
                    slaveCmd(addr, READ_MEMORY_LOCATION, EXCHANGE_STATE_READ_MEM_CMD, false, true, false);
                    memBankCounter++;
                }
            }
            break;
        case EXCHANGE_STATE_ENABLE_WRITE_MEM_CMD:
            {
                quint8 addr = ui->setDevAddrSpinBox->value();
                addr = (addr<<1)|0x01;
                slaveCmd(addr, ENABLE_WRITE_MEMORY, EXCHANGE_STATE_WRITE_MEM_CMD, true, false, false); //send twice
            }
            break;
        case EXCHANGE_STATE_WRITE_MEM_CMD:
            {
                quint8 valToWrite = 0;
                if(memBank1FullWriteFlag)  //write full memory bank using table data
                {
                    ui->memBanksProgressBar->setValue(memBank1FullWriteIndex);

                    QStandardItemModel* mdl = diag->getMembank1Model();
                    QString dataStr = mdl->data(mdl->index(memBank1FullWriteIndex, 2)).toString();
                    bool bStatus = false;
                    valToWrite = dataStr.right(2).toUInt(&bStatus,16);

                    qDebug() << "MultiWrite," + QString::number(valToWrite);

                    if(memBank1FullWriteIndex == memBank1DescData.size()-1) //maximal
                    {
                        slaveCmd(WRITE_MEM_LOC_NO_RPL_ADDR_BYTE, valToWrite, EXCHANGE_STATE_IDLE, false, false, true);
                        ui->memBanksProgressBar->setVisible(false);
                        enableControl(true);
                    }
                    else
                    {
                        slaveCmd(WRITE_MEM_LOC_NO_RPL_ADDR_BYTE, valToWrite, EXCHANGE_STATE_WRITE_MEM_CMD, false, false, true);
                        memBank1FullWriteIndex++;
                    }
                }
                else
                {
                    if(memBankId == 1)
                        valToWrite = ui->bank1ValueSpinBox->value();
                    else if((memBankId == 202) || (memBankId == 203) || (memBankId == 204)\
                            || (memBankId == 205) || (memBankId == 206) || (memBankId == 207))
                    {
                        valToWrite = memBankLock;  //protect/unprotect membank from internal write operations
                    }
                    qDebug() << "SingleWrite," + QString::number(valToWrite);

                    slaveCmd(WRITE_MEM_LOC_NO_RPL_ADDR_BYTE, valToWrite, EXCHANGE_STATE_IDLE, false, false, true);
                    enableControl(true);
                }
            }
            break;
        case EXCHANGE_STATE_SEND_DTR0_MEM_CMD:
            if(memBankWriteFlag == false)
            {
                slaveCmd(DTR0_ADDR_BYTE, 0, EXCHANGE_STATE_READ_MEM_CMD, false, false, true);
            }
            else
            {
                slaveCmd(DTR0_ADDR_BYTE, memBankOffset, EXCHANGE_STATE_ENABLE_WRITE_MEM_CMD, false, false, true);
            }
            break;
        case EXCHANGE_STATE_SEND_PERIODICALLY:
            sendCmdToPushButtonClicked();
            break;
        case EXCHANGE_STATE_SEND_TEST_SEQUENSE:
            if(nextTestSeqCmd < testSeqCmds.size())
            {
                if(testSeqCmds[nextTestSeqCmd].commandDefStr.contains("LoopStart")) //nested loop
                {
                    int delimIx = testSeqCmds[nextTestSeqCmd].commandDefStr.indexOf(' ');
                    QString IterCntStr = \
                    testSeqCmds[nextTestSeqCmd].commandDefStr.right(testSeqCmds[nextTestSeqCmd].commandDefStr.size() - delimIx - 1);

                    testLoopIterationCnt.append(IterCntStr.toInt());
                    testLoopStartCmdId.append(nextTestSeqCmd + 1);

                    testSeqSetNextHighLightBackGround(nextTestSeqCmd+1);

                    exchangeTimer->start(10);
                }
                else if(testSeqCmds[nextTestSeqCmd].commandDefStr.contains("LoopEnd"))
                {
                    testLoopIterationCnt.last()--;
                    if(testLoopIterationCnt.last() == 0)
                    {
                        testLoopIterationCnt.removeLast();
                        testLoopStartCmdId.removeLast();

                        testSeqSetNextHighLightBackGround(nextTestSeqCmd+1);

                        exchangeTimer->start(10);
                    }
                    else
                    {
                        testSeqSetNextHighLightBackGround(testLoopStartCmdId.last());

                        slaveCmd(testSeqCmds[nextTestSeqCmd].addrByte, testSeqCmds[nextTestSeqCmd].opcodeByte, EXCHANGE_STATE_SEND_TEST_SEQUENSE,\
                            testSeqCmds[nextTestSeqCmd].set_twice, testSeqCmds[nextTestSeqCmd].answer, testSeqCmds[nextTestSeqCmd].is_special);
                        QTime currTm = QTime::currentTime();
                        testTabModel.setData(testTabModel.index(nextTestSeqCmd, 0, QModelIndex()), currTm.toString("hh:mm:ss,zzz"));
                        exchangeTimer->start(1000);
                    }
                }
                else if(testSeqCmds[nextTestSeqCmd].commandDefStr.contains("Timeout"))
                {
                    int delimIx = testSeqCmds[nextTestSeqCmd].commandDefStr.indexOf(' ');
                    QString testSeqTimeoutStr = \
                    testSeqCmds[nextTestSeqCmd].commandDefStr.right(testSeqCmds[nextTestSeqCmd].commandDefStr.size() - delimIx - 1);
                    int testSeqTimeout = testSeqTimeoutStr.toInt();

                    testSeqSetNextHighLightBackGround(nextTestSeqCmd+1);

                    exchangeTimer->start(testSeqTimeout);
                }
                else
                {
                    slaveCmd(testSeqCmds[nextTestSeqCmd].addrByte, testSeqCmds[nextTestSeqCmd].opcodeByte, EXCHANGE_STATE_SEND_TEST_SEQUENSE,\
                        testSeqCmds[nextTestSeqCmd].set_twice, testSeqCmds[nextTestSeqCmd].answer, testSeqCmds[nextTestSeqCmd].is_special);
                    QTime currTm = QTime::currentTime();
                    testTabModel.setData(testTabModel.index(nextTestSeqCmd, 0, QModelIndex()), currTm.toString("hh:mm:ss,zzz"));

                    testSeqSetNextHighLightBackGround(nextTestSeqCmd+1);

                    exchangeTimer->start(1000);
                }
            }
            else
            {
                qDebug() << "End of test sequense";
                ui->testRunButton->setEnabled(true);
                ui->testStopButton->setEnabled(false);
                exchangeTimer->stop();
            }
            break;
        default:

            break;

    }
}

void DaliMain::sendDAPCData(uint8_t addr, uint8_t opcode)
{
    quint8 addrByte = addr;
    addrByte = (addrByte << 1) & 0xFE; //DAPC, Short addressing
    slaveCmd(addrByte, opcode, EXCHANGE_STATE_IDLE, false, false, false);
}

void DaliMain::updateBroadcastSlider(int sliderVal)
{
    ui->redSlider->setValue(sliderVal);
    ui->greenSlider->setValue(sliderVal);
    ui->blueSlider->setValue(sliderVal);

    ui->broadcastEdit->setText(QString::number(sliderVal));
    ui->redEdit->setText(QString::number(sliderVal));
    ui->greenEdit->setText(QString::number(sliderVal));
    ui->blueEdit->setText(QString::number(sliderVal));
}

void DaliMain::sliderBroadcastRelease()
{
    int val = ui->broadcastEdit->text().toInt();
    if(val >= 255)
        val = 254;
    quint8 addrByte = 0xFF;
    sendDAPCData(addrByte, val);
}

void DaliMain::updateRedSlider(int sliderVal)
{
     ui->redEdit->setText(QString::number(sliderVal));
}

void DaliMain::sliderRedReleased()
{
    int val = ui->redEdit->text().toInt();
    quint8 addrByte = ui->redAddrSpinBox->value();
    sendDAPCData(addrByte, val);
}

void DaliMain::updateGreenSlider(int sliderVal)
{
    ui->greenEdit->setText(QString::number(sliderVal));
}

void DaliMain::sliderGreenReleased()
{
    int val = ui->greenEdit->text().toInt();
    quint8 addrByte = ui->greenAddrSpinBox->value();
    sendDAPCData(addrByte, val);
}

void DaliMain::updateBlueSlider(int sliderVal)
{
    ui->blueEdit->setText(QString::number(sliderVal));
}

void DaliMain::sliderBlueReleased()
{
    int val = ui->blueEdit->text().toInt();
    quint8 addrByte = ui->blueAddrSpinBox->value();
    sendDAPCData(addrByte, val);
}

//first we need to write scene value using DTR0
void DaliMain::sceneSetBtnClicked()
{
    quint8 sceneVal = ui->sceneValSpinBox->value();
    slaveCmd(DTR0_ADDR_BYTE, sceneVal, EXCHANGE_STATE_SET_SCENE_CMD, false, false, true); //search next gear
    exchangeTimer->start(700);
}

//
void DaliMain::sceneGoToBtnClicked()
{
    quint8 addr = ui->sceneAddrSpinBox->value();
    addr = (addr<<1)|0x01;
    quint8 opcodeBase = 0x10;
    quint8 sceneNumber = ui->sceneNmbSpinBox->value();

    slaveCmd(addr, opcodeBase + sceneNumber, EXCHANGE_STATE_IDLE, false, false, false); //
}

void DaliMain::sceneQueryLvlBtnClicked()
{
    quint8 addr = ui->sceneAddrSpinBox->value();
    addr = (addr<<1)|0x01;
    quint8 opcodeBase = 0xB0;
    quint8 sceneNumber = ui->sceneNmbSpinBox->value();

    slaveCmd(addr, opcodeBase + sceneNumber, EXCHANGE_STATE_IDLE, false, true, false); //
}

//“sceneX” shall be set to MASK.
void DaliMain::sceneRemoveBtnClicked()
{
    quint8 addr = ui->sceneAddrSpinBox->value();
    addr = (addr<<1)|0x01;
    quint8 opcodeBase = 0x50;
    quint8 sceneNumber = ui->sceneNmbSpinBox->value();
    slaveCmd(addr, opcodeBase + sceneNumber, EXCHANGE_STATE_IDLE, true, false, false); //
}

void DaliMain::bCastAddrCheckBoxClicked()
{
    if(ui->bCastAddrCheckBox->isChecked())
    {
       ui->sceneAddrSpinBox->setEnabled(false);
    }
    else
    {
       ui->sceneAddrSpinBox->setEnabled(true);
    }
}
void DaliMain::fadeTimeSetBtnClicked()
{
    quint8 fadeTimeVal = ui->fadeTimeSpinBox->value();
    slaveCmd(DTR0_ADDR_BYTE, fadeTimeVal, EXCHANGE_STATE_SET_FADE_TIME_CMD, false, false, true); //
    exchangeTimer->start(700);
}

void DaliMain::fastFadeTimeSetBtnClicked()
{
    quint8 fastFadeTimeVal = ui->fastFadeTimeSpinBox->value();
    slaveCmd(DTR0_ADDR_BYTE, fastFadeTimeVal, EXCHANGE_STATE_SET_DEVICE_TYPE_6_CMD, false, false, true); //
    exchangeTimer->start(700);
}

void DaliMain::extendedFadeTimeSetBtnClicked()
{
    quint8 extendedFadeTimeBase = ui->extFadeTimeBaseSpinBox->value();
    quint8 extendedFadeTimeMult = ui->extFadeTimeMultSpinBox->value();
    quint8 extendedFadeTime = extendedFadeTimeBase | (extendedFadeTimeMult << 4);
    slaveCmd(DTR0_ADDR_BYTE, extendedFadeTime, EXCHANGE_STATE_SET_EXTENDED_FADE_TIME_CMD, false, false, true); //
    exchangeTimer->start(700);
}

void DaliMain::specSelChanged()
{
    QString currTxt = ui->specSelComboBox->currentText();
    extCommandSel->specSelUpdate(currTxt);
}

void DaliMain::mBank202ReadBtnClicked()
{
    ui->pwrEnergyProgressBar->setVisible(true);
    ui->pwrEnergyProgressBar->setValue(0);
    readBankBtnClick(202, memBank202Data, sizeof(memBank202Data));
}

void DaliMain::mBank203ReadBtnClicked()
{
    ui->pwrEnergyProgressBar->setVisible(true);
    ui->pwrEnergyProgressBar->setValue(0);
    readBankBtnClick(203, memBank203Data, sizeof(memBank203Data));
}

void DaliMain::mBank204ReadBtnClicked()
{
    ui->pwrEnergyProgressBar->setVisible(true);
    ui->pwrEnergyProgressBar->setValue(0);
    readBankBtnClick(204, memBank204Data, sizeof(memBank204Data));
}

void DaliMain::mBank205ReadBtnClicked()
{
    ui->diagProgressBar->setVisible(true);
    ui->diagProgressBar->setValue(0);
    readBankBtnClick(205, memBank205Data, sizeof(memBank205Data));
}

void DaliMain::mBank206ReadBtnClicked()
{
    ui->diagProgressBar->setVisible(true);
    ui->diagProgressBar->setValue(0);
    readBankBtnClick(206, memBank206Data, sizeof(memBank206Data));
}

void DaliMain::mBank207ReadBtnClicked()
{
    ui->diagProgressBar->setVisible(true);
    ui->diagProgressBar->setValue(0);
    readBankBtnClick(207, memBank207Data, sizeof(memBank207Data));
}

void DaliMain::mBank202SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(202, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank203SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(203, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank204SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(204, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank205SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(205, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank206SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(206, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank207SetLockBtnClicked()
{
    memBankLock = 0xAA;
    writeBankBtnClick(207, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank202ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(202, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank203ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(203, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank204ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(204, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank205ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(205, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank206ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(206, LOCK_BYTE_OFFSET);
}

void DaliMain::mBank207ClrLockBtnClicked()
{
    memBankLock = 0xFF;
    writeBankBtnClick(207, LOCK_BYTE_OFFSET);
}

void DaliMain::slotDevAddrChanged()
{
    int addr = ui->setDevAddrSpinBox_2->value();
    ui->setDevAddrSpinBox->setValue(addr);
    ui->setDevAddrSpinBox_3->setValue(addr);
}

void DaliMain::slotDevAddrChanged_3()
{
    int addr = ui->setDevAddrSpinBox_3->value();
    ui->setDevAddrSpinBox->setValue(addr);
    ui->setDevAddrSpinBox_2->setValue(addr);
}
