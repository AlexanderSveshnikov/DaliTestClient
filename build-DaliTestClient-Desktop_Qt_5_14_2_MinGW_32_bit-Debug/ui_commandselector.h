/********************************************************************************
** Form generated from reading UI file 'commandselector.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDSELECTOR_H
#define UI_COMMANDSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandSelector
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_3;
    QComboBox *daliCommandsComboBox;
    QHBoxLayout *extensionslLayout;
    QVBoxLayout *verticalLayout_24;
    QLabel *selectExtendedCmdLabel;
    QComboBox *daliExtendedTestCmdsComboBox;
    QVBoxLayout *verticalLayout_23;
    QLabel *testSeqSpecSelLabel;
    QComboBox *testSeqSpecSelComboBox;
    QLabel *dataValueLabel;
    QSlider *daliDataSetSlider;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *currenLayout_4;
    QLabel *decLabel;
    QLineEdit *dataDecEdit;
    QHBoxLayout *currenLayout_5;
    QLabel *hexLabel;
    QLineEdit *dataHexEdit;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *CommandSelector)
    {
        if (CommandSelector->objectName().isEmpty())
            CommandSelector->setObjectName(QString::fromUtf8("CommandSelector"));
        CommandSelector->resize(351, 180);
        verticalLayoutWidget = new QWidget(CommandSelector);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 331, 161));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        daliCommandsComboBox = new QComboBox(verticalLayoutWidget);
        daliCommandsComboBox->setObjectName(QString::fromUtf8("daliCommandsComboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(daliCommandsComboBox->sizePolicy().hasHeightForWidth());
        daliCommandsComboBox->setSizePolicy(sizePolicy);

        verticalLayout_3->addWidget(daliCommandsComboBox);

        extensionslLayout = new QHBoxLayout();
        extensionslLayout->setObjectName(QString::fromUtf8("extensionslLayout"));
        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        selectExtendedCmdLabel = new QLabel(verticalLayoutWidget);
        selectExtendedCmdLabel->setObjectName(QString::fromUtf8("selectExtendedCmdLabel"));
        sizePolicy.setHeightForWidth(selectExtendedCmdLabel->sizePolicy().hasHeightForWidth());
        selectExtendedCmdLabel->setSizePolicy(sizePolicy);

        verticalLayout_24->addWidget(selectExtendedCmdLabel);

        daliExtendedTestCmdsComboBox = new QComboBox(verticalLayoutWidget);
        daliExtendedTestCmdsComboBox->setObjectName(QString::fromUtf8("daliExtendedTestCmdsComboBox"));
        sizePolicy.setHeightForWidth(daliExtendedTestCmdsComboBox->sizePolicy().hasHeightForWidth());
        daliExtendedTestCmdsComboBox->setSizePolicy(sizePolicy);

        verticalLayout_24->addWidget(daliExtendedTestCmdsComboBox);


        extensionslLayout->addLayout(verticalLayout_24);

        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        testSeqSpecSelLabel = new QLabel(verticalLayoutWidget);
        testSeqSpecSelLabel->setObjectName(QString::fromUtf8("testSeqSpecSelLabel"));
        sizePolicy.setHeightForWidth(testSeqSpecSelLabel->sizePolicy().hasHeightForWidth());
        testSeqSpecSelLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(8);
        testSeqSpecSelLabel->setFont(font);

        verticalLayout_23->addWidget(testSeqSpecSelLabel);

        testSeqSpecSelComboBox = new QComboBox(verticalLayoutWidget);
        testSeqSpecSelComboBox->setObjectName(QString::fromUtf8("testSeqSpecSelComboBox"));
        sizePolicy.setHeightForWidth(testSeqSpecSelComboBox->sizePolicy().hasHeightForWidth());
        testSeqSpecSelComboBox->setSizePolicy(sizePolicy);
        testSeqSpecSelComboBox->setFont(font);

        verticalLayout_23->addWidget(testSeqSpecSelComboBox);


        extensionslLayout->addLayout(verticalLayout_23);


        verticalLayout_3->addLayout(extensionslLayout);

        dataValueLabel = new QLabel(verticalLayoutWidget);
        dataValueLabel->setObjectName(QString::fromUtf8("dataValueLabel"));

        verticalLayout_3->addWidget(dataValueLabel);

        daliDataSetSlider = new QSlider(verticalLayoutWidget);
        daliDataSetSlider->setObjectName(QString::fromUtf8("daliDataSetSlider"));
        daliDataSetSlider->setMaximum(255);
        daliDataSetSlider->setOrientation(Qt::Horizontal);

        verticalLayout_3->addWidget(daliDataSetSlider);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        currenLayout_4 = new QHBoxLayout();
        currenLayout_4->setObjectName(QString::fromUtf8("currenLayout_4"));
        decLabel = new QLabel(verticalLayoutWidget);
        decLabel->setObjectName(QString::fromUtf8("decLabel"));
        decLabel->setText(QString::fromUtf8("DEC"));

        currenLayout_4->addWidget(decLabel);

        dataDecEdit = new QLineEdit(verticalLayoutWidget);
        dataDecEdit->setObjectName(QString::fromUtf8("dataDecEdit"));

        currenLayout_4->addWidget(dataDecEdit);


        horizontalLayout->addLayout(currenLayout_4);

        currenLayout_5 = new QHBoxLayout();
        currenLayout_5->setObjectName(QString::fromUtf8("currenLayout_5"));
        hexLabel = new QLabel(verticalLayoutWidget);
        hexLabel->setObjectName(QString::fromUtf8("hexLabel"));
        hexLabel->setText(QString::fromUtf8("HEX"));

        currenLayout_5->addWidget(hexLabel);

        dataHexEdit = new QLineEdit(verticalLayoutWidget);
        dataHexEdit->setObjectName(QString::fromUtf8("dataHexEdit"));

        currenLayout_5->addWidget(dataHexEdit);


        horizontalLayout->addLayout(currenLayout_5);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(CommandSelector);

        QMetaObject::connectSlotsByName(CommandSelector);
    } // setupUi

    void retranslateUi(QWidget *CommandSelector)
    {
        CommandSelector->setWindowTitle(QCoreApplication::translate("CommandSelector", "Form", nullptr));
        selectExtendedCmdLabel->setText(QCoreApplication::translate("CommandSelector", "\320\240\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\213\320\265 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        testSeqSpecSelLabel->setText(QCoreApplication::translate("CommandSelector", "C\320\277\320\265\321\206\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217:", nullptr));
        dataValueLabel->setText(QCoreApplication::translate("CommandSelector", "\320\224\320\260\320\275\320\275\321\213\320\265", nullptr));
        dataDecEdit->setText(QCoreApplication::translate("CommandSelector", "0", nullptr));
        dataHexEdit->setText(QCoreApplication::translate("CommandSelector", "00", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandSelector: public Ui_CommandSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDSELECTOR_H
