#ifndef ADDRESSSELECTOR_H
#define ADDRESSSELECTOR_H

#include <QWidget>

namespace Ui {
class addressSelector;
}

class addressSelector : public QWidget
{
    Q_OBJECT
public:
    explicit addressSelector(QWidget *parent = nullptr);
    ~addressSelector();
    uint8_t getAddrType();
    uint8_t getAddress();
    uint8_t getGroupAddress();
    typedef enum
        {
            BROADCAST_ADDR,
            BROADCAST_UNADDRESSED,
            GROUP_ADDR,
            INDIVIDUAL_ADDR
        }addr_type_t;
private:
    Ui::addressSelector *ui;
    addr_type_t addrType;
signals:
    void addrTypeChange();
private slots:
    void broadcastSendRadioButtonClick();
    void broadcastUnaddrSendRadioButtonClick();
    void groupSendRadioButtonClick();
    void addressSendRadioButtonClick();
};

#endif // ADDRESSSELECTOR_H
