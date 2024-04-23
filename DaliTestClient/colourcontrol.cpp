#include "colourcontrol.h"
#include "ui_colourcontrol.h"
#include <QtMath>
#include <QDebug>

ColourControl::ColourControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColourControl)
{
    ui->setupUi(this);
    for(quint8 i = 0; i < colourTypes.size(); i++)
        ui->colourTypeComboBox->addItem(colourTypes[i]);

    connect(ui->warmerButton, &QPushButton::clicked, this, &ColourControl::warmerButtonClick);
    connect(ui->coolerButton, &QPushButton::clicked, this, &ColourControl::coolerButtonClick);

    connect(ui->colourTempSlider, SIGNAL(valueChanged(int)), SLOT(updateColourTempSlider(int)));
    connect(ui->colourTempSlider, SIGNAL(sliderReleased()), SLOT(colourTempSliderReleased()));

    connect(ui->queryColorValButton, &QPushButton::clicked, this, &ColourControl::queryColorValClick);

    connect(ui->sendButton, &QPushButton::clicked, this, &ColourControl::sendButtonClick);


    ui->colorLabel->setAutoFillBackground(true);

    ui->mirekEdit->setText("154 MIREK");
    ui->kelvinEdit->setText("6500 K");
    ui->colorLabel->setAutoFillBackground(true);

}

ColourControl::~ColourControl()
{
    delete ui;
}

void ColourControl::setEnabled(bool isEnabled)
{
    ui->colourTempSlider->setEnabled(isEnabled);
    ui->warmerButton->setEnabled(isEnabled);
    ui->coolerButton->setEnabled(isEnabled);
    ui->queryColorValButton->setEnabled(isEnabled);
    ui->sendButton->setEnabled(isEnabled);
}

void ColourControl::updateColourTempSlider(int sliderVal)
{
    mirekVal = sliderVal;
    int kelvinVal = 1000000/sliderVal;
    ui->mirekEdit->setText(QString::number(sliderVal) + " MIREK");
    ui->kelvinEdit->setText(QString::number(kelvinVal) + " K");

    QColor color;
    colorTemperatureToRGB(kelvinVal, &color);
    QPalette pal;
    pal.setColor(QPalette::Window, color);
    ui->colorLabel->setPalette(pal);
}

quint8 ColourControl::getDaliAddress()
{
    if(ui->daliBroadCastCheckBox->isChecked())
        return 0xFF;
    uint8_t addr = ui->daliAddrSpinBox->value();
    return (addr<<1)|0x01;
}

quint16 ColourControl::getColourTemperature()
{
    return mirekVal;
}

void ColourControl::warmerButtonClick()
{
    if(mirekVal < MIN_COLOUR_TEMP_TC)
    {
        return;
    }
    mirekVal--;
    ui->colourTempSlider->setValue(mirekVal);
    ui->mirekEdit->setText(QString::number(mirekVal) + " MIREK");
    int kelvinVal = 1000000/mirekVal;
    ui->kelvinEdit->setText(QString::number(kelvinVal) + " K");
    emit stepWarmerSig();
}

void ColourControl::coolerButtonClick()
{
    if(mirekVal > MAX_COLOUR_TEMP_TC)
    {
        return;
    }
    mirekVal++;
    ui->colourTempSlider->setValue(mirekVal);
    ui->mirekEdit->setText(QString::number(mirekVal) + " MIREK");
    int kelvinVal = 1000000/mirekVal;
    ui->kelvinEdit->setText(QString::number(kelvinVal) + " K");
    emit stepCoolerSig();
}

float ColourControl::clamp(float x, float min, float max)
{
    if(x<min){ return min; }
    if(x>max){ return max; }
    return x;
}

void ColourControl::colorTemperatureToRGB(quint32 kelvin, QColor* resColor)
{
    float temp = (10000 - kelvin) / 100;
    float red, green, blue;

    if( temp <= 66 ){
        red = 255;
        green = temp;
        green = 99.4708025861 * log(green) - 161.1195681661;

        if( temp <= 19){
            blue = 0;
        }
        else{
            blue = temp - 10;
            blue = 138.5177312231 * log(blue) - 305.0447927307;
        }

    }
    else{
        red = temp - 60;
        red = 329.698727446 * pow(red, -0.1332047592);

        green = temp - 60;
        green = 288.1221695283 * pow(green, -0.0755148492 );

        blue = 255;
    }

    int r = clamp(red,   0, 255);
    int g = clamp(green, 0, 255);
    int b = clamp(blue,  0, 255);
    resColor->setRed(r);
    resColor->setGreen(g);
    resColor->setBlue(b);
}


void ColourControl::colourTempSliderReleased()
{
    emit setColourValSig();
}

void ColourControl::queryColorValClick()
{
    queryFlag = true;
    tmpColourVal = 0;
    emit queryColorValSig();
}

void ColourControl::receiveColourValue(quint8 replyByte)
{
    if(queryFlag)
    {
        queryFlag = false;
        tmpColourVal = ((quint16)replyByte)<<8;
        //qDebug() << "1-st rx:" + QString::number(tmpColourVal);
    }
    else
    {
        tmpColourVal |= replyByte;
        //qDebug() << "2-nd rx:" + QString::number(replyByte) + "res:" + QString::number(tmpColourVal);
        mirekVal = tmpColourVal;
        ui->colourTempSlider->setValue(mirekVal);
        ui->mirekEdit->setText(QString::number(mirekVal) + " MIREK");
        if(mirekVal == 0)
        {
            qDebug() << "1error receiving data!";
            return;
        }
        int kelvinVal = 1000000/mirekVal;
        ui->kelvinEdit->setText(QString::number(kelvinVal) + " K");
    }
}

void ColourControl::colorValSetup(quint16 val)
{
   ui->colourTempSlider->setValue(val);
}

void ColourControl::sendButtonClick()
{
    emit setColourValSig();
}


