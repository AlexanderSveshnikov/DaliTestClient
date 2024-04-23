#include "commandselector.h"
#include "ui_commandselector.h"

CommandSelector::CommandSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommandSelector)
{
    ui->setupUi(this);
}

CommandSelector::~CommandSelector()
{
    delete ui;
}
