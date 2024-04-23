/********************************************************************************
** Form generated from reading UI file 'colorctrl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLORCTRL_H
#define UI_COLORCTRL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_colorCtrl
{
public:
    QGroupBox *colorManageGrpBox;

    void setupUi(QWidget *colorCtrl)
    {
        if (colorCtrl->objectName().isEmpty())
            colorCtrl->setObjectName(QString::fromUtf8("colorCtrl"));
        colorCtrl->resize(369, 411);
        colorManageGrpBox = new QGroupBox(colorCtrl);
        colorManageGrpBox->setObjectName(QString::fromUtf8("colorManageGrpBox"));
        colorManageGrpBox->setGeometry(QRect(20, 20, 329, 369));
        QFont font;
        font.setPointSize(10);
        colorManageGrpBox->setFont(font);

        retranslateUi(colorCtrl);

        QMetaObject::connectSlotsByName(colorCtrl);
    } // setupUi

    void retranslateUi(QWidget *colorCtrl)
    {
        colorCtrl->setWindowTitle(QCoreApplication::translate("colorCtrl", "Form", nullptr));
        colorManageGrpBox->setTitle(QCoreApplication::translate("colorCtrl", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\206\320\262\320\265\321\202\320\260\320\274\320\270 ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class colorCtrl: public Ui_colorCtrl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLORCTRL_H
