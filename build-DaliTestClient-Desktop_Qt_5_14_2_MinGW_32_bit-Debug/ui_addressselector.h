/********************************************************************************
** Form generated from reading UI file 'addressselector.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDRESSSELECTOR_H
#define UI_ADDRESSSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_addressSelector
{
public:
    QGroupBox *sendCmdToGroupBox;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_18;
    QRadioButton *broadcastSendRadioButton;
    QRadioButton *broadcastUnaddrSendRadioButton;
    QHBoxLayout *groupSendLayout;
    QRadioButton *groupSendRadioButton;
    QSpinBox *groupSendSpinBox;
    QHBoxLayout *addressSendlLayout;
    QRadioButton *addressSendRadioButton;
    QSpinBox *addressSendSpinBox;

    void setupUi(QWidget *addressSelector)
    {
        if (addressSelector->objectName().isEmpty())
            addressSelector->setObjectName(QString::fromUtf8("addressSelector"));
        addressSelector->resize(355, 142);
        sendCmdToGroupBox = new QGroupBox(addressSelector);
        sendCmdToGroupBox->setObjectName(QString::fromUtf8("sendCmdToGroupBox"));
        sendCmdToGroupBox->setGeometry(QRect(10, 10, 338, 121));
        verticalLayoutWidget_7 = new QWidget(sendCmdToGroupBox);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(0, 20, 321, 101));
        verticalLayout_18 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        broadcastSendRadioButton = new QRadioButton(verticalLayoutWidget_7);
        broadcastSendRadioButton->setObjectName(QString::fromUtf8("broadcastSendRadioButton"));
        broadcastSendRadioButton->setChecked(true);

        verticalLayout_18->addWidget(broadcastSendRadioButton);

        broadcastUnaddrSendRadioButton = new QRadioButton(verticalLayoutWidget_7);
        broadcastUnaddrSendRadioButton->setObjectName(QString::fromUtf8("broadcastUnaddrSendRadioButton"));
        broadcastUnaddrSendRadioButton->setChecked(false);

        verticalLayout_18->addWidget(broadcastUnaddrSendRadioButton);

        groupSendLayout = new QHBoxLayout();
        groupSendLayout->setObjectName(QString::fromUtf8("groupSendLayout"));
        groupSendRadioButton = new QRadioButton(verticalLayoutWidget_7);
        groupSendRadioButton->setObjectName(QString::fromUtf8("groupSendRadioButton"));

        groupSendLayout->addWidget(groupSendRadioButton);

        groupSendSpinBox = new QSpinBox(verticalLayoutWidget_7);
        groupSendSpinBox->setObjectName(QString::fromUtf8("groupSendSpinBox"));
        groupSendSpinBox->setMaximum(15);

        groupSendLayout->addWidget(groupSendSpinBox);


        verticalLayout_18->addLayout(groupSendLayout);

        addressSendlLayout = new QHBoxLayout();
        addressSendlLayout->setObjectName(QString::fromUtf8("addressSendlLayout"));
        addressSendRadioButton = new QRadioButton(verticalLayoutWidget_7);
        addressSendRadioButton->setObjectName(QString::fromUtf8("addressSendRadioButton"));
        addressSendRadioButton->setChecked(false);

        addressSendlLayout->addWidget(addressSendRadioButton);

        addressSendSpinBox = new QSpinBox(verticalLayoutWidget_7);
        addressSendSpinBox->setObjectName(QString::fromUtf8("addressSendSpinBox"));
        addressSendSpinBox->setMaximum(254);

        addressSendlLayout->addWidget(addressSendSpinBox);


        verticalLayout_18->addLayout(addressSendlLayout);


        retranslateUi(addressSelector);

        QMetaObject::connectSlotsByName(addressSelector);
    } // setupUi

    void retranslateUi(QWidget *addressSelector)
    {
        addressSelector->setWindowTitle(QCoreApplication::translate("addressSelector", "Form", nullptr));
        sendCmdToGroupBox->setTitle(QCoreApplication::translate("addressSelector", "\320\232\321\203\320\264\320\260 \320\276\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203", nullptr));
        broadcastSendRadioButton->setText(QCoreApplication::translate("addressSelector", "\320\222\321\201\320\265\320\274 (Broadcast)", nullptr));
        broadcastUnaddrSendRadioButton->setText(QCoreApplication::translate("addressSelector", "\320\222\321\201\320\265\320\274 \320\261\320\265\320\267 \320\260\320\264\321\200\320\265\321\201\320\260 (Broadcast Unaddressed)", nullptr));
        groupSendRadioButton->setText(QCoreApplication::translate("addressSelector", "\320\223\321\200\321\203\320\277\320\277\320\265", nullptr));
        addressSendRadioButton->setText(QCoreApplication::translate("addressSelector", "\320\237\320\276 \320\260\320\264\321\200\320\265\321\201\321\203", nullptr));
    } // retranslateUi

};

namespace Ui {
    class addressSelector: public Ui_addressSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDRESSSELECTOR_H
