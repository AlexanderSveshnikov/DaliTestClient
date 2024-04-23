#ifndef COLOURCONTROL_H
#define COLOURCONTROL_H

#include <QWidget>

namespace Ui {
class ColourControl;
}

class ColourControl : public QWidget
{
    Q_OBJECT

public:
    explicit ColourControl(QWidget *parent = nullptr);
    ~ColourControl();

private:
    Ui::ColourControl *ui;
};

#endif // COLOURCONTROL_H
