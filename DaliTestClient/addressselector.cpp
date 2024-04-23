#include "addressselector.h"
#include "ui_addressselector.h"

addressSelector::addressSelector(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addressSelector)
{
    ui->setupUi(this);

    connect(ui->broadcastSendRadioButton, SIGNAL(clicked()), this, SLOT(broadcastSendRadioButtonClick()));
    connect(ui->broadcastUnaddrSendRadioButton, SIGNAL(clicked()), this, SLOT(broadcastUnaddrSendRadioButtonClick()));
    connect(ui->groupSendRadioButton, SIGNAL(clicked()), this, SLOT(groupSendRadioButtonClick()));
    connect(ui->addressSendRadioButton, SIGNAL(clicked()), this, SLOT(addressSendRadioButtonClick()));
}

addressSelector::~addressSelector()
{
    delete ui;
}

void addressSelector::broadcastSendRadioButtonClick()
{
    ui->addressSendRadioButton->setChecked(false);
    ui->groupSendRadioButton->setChecked(false);
    ui->broadcastUnaddrSendRadioButton->setChecked(false);
    addrType = BROADCAST_ADDR;
    emit addrTypeChange();
}

void addressSelector::broadcastUnaddrSendRadioButtonClick()
{
    ui->addressSendRadioButton->setChecked(false);
    ui->groupSendRadioButton->setChecked(false);
    ui->broadcastSendRadioButton->setChecked(false);
    addrType = BROADCAST_UNADDRESSED;
    emit addrTypeChange();
}

void addressSelector::groupSendRadioButtonClick()
{
    ui->addressSendRadioButton->setChecked(false);
    ui->broadcastSendRadioButton->setChecked(false);
    ui->broadcastUnaddrSendRadioButton->setChecked(false);
    addrType = GROUP_ADDR;
    emit addrTypeChange();
}

void addressSelector::addressSendRadioButtonClick()
{
    ui->groupSendRadioButton->setChecked(false);
    ui->broadcastSendRadioButton->setChecked(false);
    ui->broadcastUnaddrSendRadioButton->setChecked(false);
    addrType = INDIVIDUAL_ADDR;
    emit addrTypeChange();
}

uint8_t addressSelector::getAddrType()
{
    return addrType;
}

uint8_t addressSelector::getGroupAddress()
{
    return ui->groupSendSpinBox->text().toInt();
}

uint8_t addressSelector::getAddress()
{
    return  ui->addressSendSpinBox->text().toInt();
}
