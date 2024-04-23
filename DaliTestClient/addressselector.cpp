#include "addressselector.h"
#include "ui_addressselector.h"

addressSelector::addressSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addressSelector)
{
    ui->setupUi(this);
}

addressSelector::~addressSelector()
{
    delete ui;
}
