#ifndef COLOURCONTROL_H
#define COLOURCONTROL_H

#include <QWidget>
#include <QColorDialog>

namespace Ui {
class ColourControl;
}

class ColourControl : public QWidget
{
    Q_OBJECT

#define MIN_COLOUR_TEMP_TC      154
#define MAX_COLOUR_TEMP_TC      370

public:
    explicit ColourControl(QWidget *parent = nullptr);
    ~ColourControl();
    void colorTemperatureToRGB(quint32 kelvin, QColor* resColor);
    quint8 getDaliAddress();
    quint16 getColourTemperature();
    void setEnabled(bool isEnabled);
    void colorValSetup(quint16 val);
    void receiveColourValue(quint8 replyByte);
private:
    QStringList colourTypes = {"Цветовая температура Tc"}; //, "X-Y координаты", "RGBWAF"};

    Ui::ColourControl *ui;
    int mirekVal = MIN_COLOUR_TEMP_TC;
    quint16 tmpColourVal = 0;
    bool queryFlag = false;
    float clamp(float x, float min, float max);
    void setHueSatVal();
    void colorButtonProc(int* red, int* green, int* blue);
    void sliderValHueSaturOnRelease(int* red, int* green, int* blue);
signals:
    void stepWarmerSig();
    void stepCoolerSig();
    void setColourValSig();
    void queryColorValSig();
private slots:
    void updateColourTempSlider(int);
    void colourTempSliderReleased();
    void warmerButtonClick();
    void coolerButtonClick();
    void sendButtonClick();
    void queryColorValClick();
};

#endif // COLOURCONTROL_H
