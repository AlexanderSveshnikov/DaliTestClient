#ifndef MEMORYBANK_H
#define MEMORYBANK_H

#include <QWidget>
#include <QStandardItemModel>
#include <QProgressBar>

namespace Ui {
class memoryBank;
}

class memoryBank : public QWidget
{
    Q_OBJECT

public:
    explicit memoryBank(QWidget *parent, quint32 rowCnt);
    ~memoryBank();

private:
    Ui::memoryBank *ui;
    QStandardItemModel model;

    void readBankBtnClick(QProgressBar* progressBar, uint8_t id, uint8_t* bank, uint8_t size);

private slots:
    void mBankReadBtnClicked();
    void mBankSetLockBtnClicked();
    void mBankClrLockBtnClicked();
signals:
    void readBankBtnSig();
    void setLockBtnSig();
    void clrLockBtnSig();
};

#endif // MEMORYBANK_H
