#include "memorybank.h"
#include "ui_memorybank.h"

memoryBank::memoryBank(QWidget *parent, quint32 rowCnt) :
    QWidget(parent),
    ui(new Ui::memoryBank)
{
    parent = nullptr;
    ui->setupUi(this);

    model.setColumnCount(4);
    model.setRowCount(rowCnt);  //maximal bus nodes
    model.setHeaderData(0, Qt::Horizontal, "Адрес");
    model.setHeaderData(1, Qt::Horizontal, "Описание");
    model.setHeaderData(2, Qt::Horizontal, "Данные");
    model.setHeaderData(3, Qt::Horizontal, "Парам.");
    ui->memBankTableView->setStyleSheet("QHeaderView::section { background-color:lightGray }");
    ui->memBankTableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->memBankTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

   connect(ui->memBankReadButton, &QPushButton::clicked, this, &memoryBank::mBankReadBtnClicked);
   connect(ui->memBankSetLockButton, &QPushButton::clicked, this, &memoryBank::mBankSetLockBtnClicked);
   connect(ui->memBankClrLockButton, &QPushButton::clicked, this, &memoryBank::mBankClrLockBtnClicked);

   ui->progressBar->setVisible(false);
}

memoryBank::~memoryBank()
{
    delete ui;
}

void memoryBank::readBankBtnClick(QProgressBar* progressBar, uint8_t id, uint8_t* bank, uint8_t size)
{

    ui->progressBar->setVisible(true);
    ui->progressBar->setValue(0);

   // slaveCmd(DTR1_ADDR_BYTE, id, EXCHANGE_STATE_SEND_DTR0_MEM_CMD, false, false, true);
   // memBankSize = size;
   // memBankCounter = 0;
   // memBankId = id;
   // memBankWriteFlag = false;
   // memset(bank, 0, size);
   // exchangeTimer->stop();
   // exchangeTimer->start(700);
   // enableControl(false);
}

void memoryBank::mBankReadBtnClicked()
{
     emit readBankBtnSig();
   // readBankBtnClick(202, memBankData, sizeof(memBankData));
}

void memoryBank::mBankSetLockBtnClicked()
{
    emit setLockBtnSig();
}

void memoryBank::mBankClrLockBtnClicked()
{
     emit clrLockBtnSig();
}
