#include "colourcontrol.h"
#include "ui_colourcontrol.h"

ColourControl::ColourControl(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ColourControl)
{
    ui->setupUi(this);
}

ColourControl::~ColourControl()
{
    delete ui;
}
