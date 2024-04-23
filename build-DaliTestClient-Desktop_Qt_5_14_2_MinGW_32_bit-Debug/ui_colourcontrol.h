/********************************************************************************
** Form generated from reading UI file 'colourcontrol.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COLOURCONTROL_H
#define UI_COLOURCONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ColourControl
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *colorManageLabel;
    QLabel *colourTypelabel;
    QComboBox *colourTypeComboBox;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *warmerButton;
    QSlider *colourTempSlider;
    QPushButton *coolerButton;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QLineEdit *mirekEdit;
    QLineEdit *kelvinEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *daliAddrLabel;
    QSpinBox *daliAddrSpinBox;
    QSpacerItem *horizontalSpacer_3;
    QCheckBox *daliBroadCastCheckBox;
    QSpacerItem *verticalSpacer;
    QPushButton *queryColorValButton;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *sendButton;
    QLabel *colorLabel;

    void setupUi(QWidget *ColourControl)
    {
        if (ColourControl->objectName().isEmpty())
            ColourControl->setObjectName(QString::fromUtf8("ColourControl"));
        ColourControl->resize(351, 461);
        verticalLayoutWidget = new QWidget(ColourControl);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 331, 441));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        colorManageLabel = new QLabel(verticalLayoutWidget);
        colorManageLabel->setObjectName(QString::fromUtf8("colorManageLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(colorManageLabel->sizePolicy().hasHeightForWidth());
        colorManageLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(11);
        colorManageLabel->setFont(font);

        verticalLayout->addWidget(colorManageLabel);

        colourTypelabel = new QLabel(verticalLayoutWidget);
        colourTypelabel->setObjectName(QString::fromUtf8("colourTypelabel"));
        sizePolicy.setHeightForWidth(colourTypelabel->sizePolicy().hasHeightForWidth());
        colourTypelabel->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        colourTypelabel->setFont(font1);

        verticalLayout->addWidget(colourTypelabel);

        colourTypeComboBox = new QComboBox(verticalLayoutWidget);
        colourTypeComboBox->setObjectName(QString::fromUtf8("colourTypeComboBox"));
        sizePolicy.setHeightForWidth(colourTypeComboBox->sizePolicy().hasHeightForWidth());
        colourTypeComboBox->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(colourTypeComboBox);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        warmerButton = new QPushButton(verticalLayoutWidget);
        warmerButton->setObjectName(QString::fromUtf8("warmerButton"));

        horizontalLayout->addWidget(warmerButton);

        colourTempSlider = new QSlider(verticalLayoutWidget);
        colourTempSlider->setObjectName(QString::fromUtf8("colourTempSlider"));
        colourTempSlider->setMinimum(154);
        colourTempSlider->setMaximum(370);
        colourTempSlider->setOrientation(Qt::Horizontal);
        colourTempSlider->setTickPosition(QSlider::TicksBelow);

        horizontalLayout->addWidget(colourTempSlider);

        coolerButton = new QPushButton(verticalLayoutWidget);
        coolerButton->setObjectName(QString::fromUtf8("coolerButton"));

        horizontalLayout->addWidget(coolerButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        mirekEdit = new QLineEdit(verticalLayoutWidget);
        mirekEdit->setObjectName(QString::fromUtf8("mirekEdit"));

        horizontalLayout_3->addWidget(mirekEdit);

        kelvinEdit = new QLineEdit(verticalLayoutWidget);
        kelvinEdit->setObjectName(QString::fromUtf8("kelvinEdit"));

        horizontalLayout_3->addWidget(kelvinEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        daliAddrLabel = new QLabel(verticalLayoutWidget);
        daliAddrLabel->setObjectName(QString::fromUtf8("daliAddrLabel"));

        horizontalLayout_4->addWidget(daliAddrLabel);

        daliAddrSpinBox = new QSpinBox(verticalLayoutWidget);
        daliAddrSpinBox->setObjectName(QString::fromUtf8("daliAddrSpinBox"));
        daliAddrSpinBox->setMaximum(63);

        horizontalLayout_4->addWidget(daliAddrSpinBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        daliBroadCastCheckBox = new QCheckBox(verticalLayoutWidget);
        daliBroadCastCheckBox->setObjectName(QString::fromUtf8("daliBroadCastCheckBox"));

        horizontalLayout_4->addWidget(daliBroadCastCheckBox);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer = new QSpacerItem(20, 120, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout->addItem(verticalSpacer);

        queryColorValButton = new QPushButton(verticalLayoutWidget);
        queryColorValButton->setObjectName(QString::fromUtf8("queryColorValButton"));

        verticalLayout->addWidget(queryColorValButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        sendButton = new QPushButton(verticalLayoutWidget);
        sendButton->setObjectName(QString::fromUtf8("sendButton"));

        horizontalLayout_2->addWidget(sendButton);

        colorLabel = new QLabel(verticalLayoutWidget);
        colorLabel->setObjectName(QString::fromUtf8("colorLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorLabel->sizePolicy().hasHeightForWidth());
        colorLabel->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(colorLabel);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(ColourControl);

        QMetaObject::connectSlotsByName(ColourControl);
    } // setupUi

    void retranslateUi(QWidget *ColourControl)
    {
        ColourControl->setWindowTitle(QCoreApplication::translate("ColourControl", "Form", nullptr));
        colorManageLabel->setText(QCoreApplication::translate("ColourControl", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \321\206\320\262\320\265\321\202\320\260\320\274\320\270 (\321\202\320\276\320\273\321\214\320\272\320\276 DT8!)", nullptr));
        colourTypelabel->setText(QCoreApplication::translate("ColourControl", "\320\242\320\270\320\277 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217 \321\206\320\262\320\265\321\202\320\276\320\274:", nullptr));
        warmerButton->setText(QCoreApplication::translate("ColourControl", "<<\320\242\320\225\320\237\320\233\320\225\320\225", nullptr));
        coolerButton->setText(QCoreApplication::translate("ColourControl", "\320\245\320\236\320\233\320\236\320\224\320\235\320\225\320\225>>", nullptr));
        daliAddrLabel->setText(QCoreApplication::translate("ColourControl", "DALI \320\260\320\264\321\200\320\265\321\201", nullptr));
        daliBroadCastCheckBox->setText(QCoreApplication::translate("ColourControl", "\320\222\321\201\320\265\320\274", nullptr));
        queryColorValButton->setText(QCoreApplication::translate("ColourControl", "\320\227\320\260\320\277\321\200\320\276\321\201\320\270\321\202\321\214 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265 \321\206\320\262\320\265\321\202\320\260", nullptr));
        sendButton->setText(QCoreApplication::translate("ColourControl", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\206\320\262\320\265\321\202", nullptr));
        colorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class ColourControl: public Ui_ColourControl {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COLOURCONTROL_H
