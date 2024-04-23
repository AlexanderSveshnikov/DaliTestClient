/********************************************************************************
** Form generated from reading UI file 'dalimain.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DALIMAIN_H
#define UI_DALIMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DaliMain
{
public:
    QAction *comSetupAction;
    QAction *comConnectAction;
    QAction *comDisconnectAction;
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *adderessingTab;
    QTableView *searchResultsTableView;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *discoverButton;
    QPushButton *discoverStopButton;
    QPushButton *typeVersionBtn;
    QSpacerItem *horizontalSpacer_7;
    QCheckBox *newInitCheckBox;
    QSpacerItem *horizontalSpacer_6;
    QLabel *startAddrLabel;
    QSpinBox *startAddrSpinBox;
    QSpacerItem *horizontalSpacer_14;
    QHBoxLayout *currenLayout_12;
    QLineEdit *devCountEdit;
    QLabel *devCountLabel;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearDiscoveredButton;
    QTextEdit *searchInfoEdit;
    QWidget *daliCommandsTab;
    QGroupBox *daliCoimmandsGroupBox;
    QGroupBox *commandSendGroupBox;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *currenLayout_6;
    QLabel *commandSendDecLabel;
    QLineEdit *commandSendDecEdit;
    QHBoxLayout *currenLayout_7;
    QLabel *commandSendHexLabel;
    QLineEdit *commandSendHexEdit;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *replyGroupBox;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *currenLayout_10;
    QLabel *replyDecLabel;
    QLineEdit *replyDecEdit;
    QHBoxLayout *currenLayout_11;
    QLabel *replyHexLabel;
    QLineEdit *replyHexEdit;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *replyEdit;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_43;
    QHBoxLayout *commandAddressSetlLayout;
    QPushButton *sendCmdToPushButton;
    QWidget *verticalLayoutWidget_12;
    QVBoxLayout *commandSelectLayout;
    QCheckBox *periodSendCheckBox;
    QTextEdit *replyExplaintEdit;
    QWidget *ScenesTab;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_10;
    QLabel *setSceneAddrLabel;
    QCheckBox *bCastAddrCheckBox;
    QSpinBox *sceneAddrSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *setSceneLabel;
    QSpinBox *sceneNmbSpinBox;
    QHBoxLayout *horizontalLayout_9;
    QLabel *sceneValueLabel;
    QSpinBox *sceneValSpinBox;
    QPushButton *sceneSetButton;
    QPushButton *sceneRemoveButton;
    QPushButton *sceneGoToButton;
    QPushButton *sceneQueryLevelButton;
    QSpacerItem *verticalSpacer_6;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_11;
    QLabel *setFadeTimeLabel;
    QSpinBox *fadeTimeSpinBox;
    QPushButton *fadeTimeSetBtn;
    QHBoxLayout *horizontalLayout_16;
    QLabel *setFastFadeTimeLabel;
    QSpinBox *fastFadeTimeSpinBox;
    QPushButton *fastFadeTimeSetBtn;
    QHBoxLayout *horizontalLayout_17;
    QLabel *setExtendedFadeTimeBaseLabel;
    QSpinBox *extFadeTimeBaseSpinBox;
    QHBoxLayout *horizontalLayout_18;
    QLabel *setExtendedFadeTimeMultLabel;
    QSpinBox *extFadeTimeMultSpinBox;
    QPushButton *extendedFadeTimeSetBtn;
    QSpacerItem *verticalSpacer_8;
    QWidget *dapcCommandsTab;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_7;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_2;
    QLabel *maxValLabel;
    QSpacerItem *verticalSpacer;
    QLabel *minValLabel;
    QSpacerItem *verticalSpacer_3;
    QLabel *ValueLabel;
    QSpacerItem *verticalSpacer_4;
    QLabel *addressLabel;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *broadcastGroupBox;
    QSlider *broadcastSlider;
    QLineEdit *broadcastEdit;
    QGroupBox *redGroupBox;
    QSlider *redSlider;
    QLineEdit *redEdit;
    QCheckBox *redCheckBox;
    QSpinBox *redAddrSpinBox;
    QGroupBox *greenGroupBox;
    QSlider *greenSlider;
    QLineEdit *greenEdit;
    QCheckBox *greenCheckBox;
    QSpinBox *greenAddrSpinBox;
    QGroupBox *blueGroupBox;
    QSlider *blueSlider;
    QLineEdit *blueEdit;
    QCheckBox *blueCheckBox;
    QSpinBox *blueAddrSpinBox;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *colourCtrlLayout;
    QWidget *monitorTab;
    QCheckBox *timeStampCheckBox;
    QGroupBox *daliMasterroupBox;
    QWidget *layoutWidget_5;
    QHBoxLayout *currenLayout_13;
    QLabel *vendorIdLabel;
    QLineEdit *vidEdit;
    QWidget *layoutWidget_6;
    QHBoxLayout *currenLayout_14;
    QLabel *productIdLabel;
    QLineEdit *pidEdit;
    QPushButton *findDeviceButton;
    QWidget *verticalLayoutWidget_10;
    QVBoxLayout *verticalLayout_19;
    QLabel *infoLabel;
    QTextEdit *monitorEdit;
    QPushButton *clearMonitorWindowButton;
    QWidget *extCommandsTab;
    QGroupBox *daliExtCmdsGroupBox;
    QGroupBox *extCommandSendGroupBox;
    QWidget *horizontalLayoutWidget_14;
    QHBoxLayout *horizontalLayout_14;
    QHBoxLayout *currenLayout_15;
    QLabel *extCommandSendDecLabel;
    QLineEdit *extCommandSendDecEdit;
    QHBoxLayout *currenLayout_16;
    QLabel *extCommandSendHexLabel;
    QLineEdit *extCommandSendHexEdit;
    QSpacerItem *horizontalSpacer_8;
    QGroupBox *extReplyGroupBox;
    QWidget *horizontalLayoutWidget_15;
    QHBoxLayout *horizontalLayout_15;
    QHBoxLayout *currenLayout_17;
    QLabel *extReplyDecLabel;
    QLineEdit *extReplyDecEdit;
    QHBoxLayout *currenLayout_18;
    QLabel *extReplyHexLabel;
    QLineEdit *extReplyHexEdit;
    QSpacerItem *horizontalSpacer_9;
    QLineEdit *extReplyEdit;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_20;
    QPushButton *sendExtCmdEnableDeviceType;
    QCheckBox *autoPrependCmdCheckBox;
    QVBoxLayout *extCommandSelectLayout;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_44;
    QHBoxLayout *extCommandAddressSetlLayout;
    QPushButton *sendExtCmdToPushButton;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *verticalLayout_6;
    QLabel *specSelLabel;
    QComboBox *specSelComboBox;
    QTextEdit *extReplyExplaintEdit;
    QWidget *memBanksTab;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_19;
    QLabel *setDevAddrLabel;
    QSpinBox *setDevAddrSpinBox;
    QSpacerItem *horizontalSpacer_13;
    QProgressBar *memBanksProgressBar;
    QWidget *horizontalLayoutWidget_21;
    QHBoxLayout *horizontalLayout_35;
    QVBoxLayout *verticalLayout_16;
    QTableView *memBank0TableView;
    QPushButton *readBank0Btn;
    QVBoxLayout *verticalLayout_17;
    QTableView *memBank1TableView;
    QHBoxLayout *horizontalLayout_36;
    QPushButton *readBank1Btn;
    QPushButton *writeFullBank1Btn;
    QPushButton *memBank1FlashSaveBtn;
    QHBoxLayout *horizontalLayout_21;
    QLabel *setBank1AddrLabel;
    QSpinBox *setBank1AddrSpinBox;
    QHBoxLayout *horizontalLayout_22;
    QLabel *bank1ValueLabel;
    QSpinBox *bank1ValueSpinBox;
    QPushButton *writeBank1Btn;
    QWidget *tab;
    QWidget *verticalLayoutWidget_9;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_26;
    QLabel *setDevAddrLabel_3;
    QSpinBox *setDevAddrSpinBox_3;
    QSpacerItem *horizontalSpacer_11;
    QProgressBar *pwrEnergyProgressBar;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_27;
    QVBoxLayout *verticalLayout_7;
    QLabel *memBank202Label;
    QTableView *memBank202TableView;
    QHBoxLayout *horizontalLayout_28;
    QPushButton *memBank202SetLockButton;
    QPushButton *memBank202ClrLockButton;
    QPushButton *memBank202ReadButton;
    QVBoxLayout *verticalLayout_9;
    QLabel *memBank203abel;
    QTableView *memBank203TableView;
    QHBoxLayout *horizontalLayout_29;
    QPushButton *memBank203SetLockButton;
    QPushButton *memBank203ClrLockButton;
    QPushButton *memBank203ReadButton;
    QVBoxLayout *verticalLayout_10;
    QLabel *memBank204abel;
    QTableView *memBank204TableView;
    QHBoxLayout *horizontalLayout_30;
    QPushButton *memBank204SetLockButton;
    QPushButton *memBank204ClrLockButton;
    QPushButton *memBank204ReadButton;
    QWidget *tab_2;
    QWidget *verticalLayoutWidget_6;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_25;
    QLabel *setDevAddrLabel_2;
    QSpinBox *setDevAddrSpinBox_2;
    QSpacerItem *horizontalSpacer_12;
    QProgressBar *diagProgressBar;
    QHBoxLayout *horizontalLayout_31;
    QVBoxLayout *verticalLayout_12;
    QLabel *mBank205Label;
    QTableView *memBank205TableView;
    QHBoxLayout *horizontalLayout_32;
    QPushButton *memBank205SetLockButton;
    QPushButton *memBank205ClrLockButton;
    QPushButton *mBank205ReadButton;
    QVBoxLayout *verticalLayout_13;
    QLabel *mBank206Label;
    QTableView *memBank206TableView;
    QHBoxLayout *horizontalLayout_33;
    QPushButton *memBank206SetLockButton;
    QPushButton *memBank206ClrLockButton;
    QPushButton *mBank206ReadButton;
    QVBoxLayout *verticalLayout_15;
    QLabel *mBank207Label;
    QTableView *memBank207TableView;
    QHBoxLayout *horizontalLayout_34;
    QPushButton *memBank207SetLockButton;
    QPushButton *memBank207ClrLockButton;
    QPushButton *mBank207ReadButton;
    QWidget *testSeqTab;
    QWidget *verticalLayoutWidget_7;
    QVBoxLayout *verticalLayout_18;
    QHBoxLayout *horizontalLayout_39;
    QPushButton *loadTestSeqButton;
    QPushButton *saveTestSeqButton;
    QLabel *selectCmdLabel;
    QVBoxLayout *testCommandSelectlLayout;
    QWidget *verticalLayoutWidget_8;
    QVBoxLayout *verticalLayout_25;
    QPushButton *addToTestButton;
    QPushButton *addExtendedCmdToTestButton;
    QHBoxLayout *horizontalLayout_40;
    QPushButton *addTimeoutToTestButton;
    QDoubleSpinBox *testSeqToutSpinBox;
    QHBoxLayout *horizontalLayout_41;
    QPushButton *addLoopStartToTestButton;
    QPushButton *addLoopEndToTestButton;
    QLabel *iterCntLabel;
    QSpinBox *testSeqIterCntSpinBox;
    QPushButton *testStopButton;
    QSpacerItem *verticalSpacer_9;
    QWidget *layoutWidget1;
    QVBoxLayout *testSeqAddressSetLayout;
    QLabel *sequenseLabel;
    QTableView *testSeqTableView;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_38;
    QPushButton *removeFromTestButton;
    QPushButton *clearAllTestButton;
    QPushButton *testRunButton;
    QMenuBar *menubar;
    QMenu *menuCOM;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *DaliMain)
    {
        if (DaliMain->objectName().isEmpty())
            DaliMain->setObjectName(QString::fromUtf8("DaliMain"));
        DaliMain->resize(932, 628);
        comSetupAction = new QAction(DaliMain);
        comSetupAction->setObjectName(QString::fromUtf8("comSetupAction"));
        comConnectAction = new QAction(DaliMain);
        comConnectAction->setObjectName(QString::fromUtf8("comConnectAction"));
        comDisconnectAction = new QAction(DaliMain);
        comDisconnectAction->setObjectName(QString::fromUtf8("comDisconnectAction"));
        centralwidget = new QWidget(DaliMain);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 10, 921, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(verticalLayoutWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        adderessingTab = new QWidget();
        adderessingTab->setObjectName(QString::fromUtf8("adderessingTab"));
        searchResultsTableView = new QTableView(adderessingTab);
        searchResultsTableView->setObjectName(QString::fromUtf8("searchResultsTableView"));
        searchResultsTableView->setEnabled(true);
        searchResultsTableView->setGeometry(QRect(10, 10, 541, 471));
        horizontalLayoutWidget_10 = new QWidget(adderessingTab);
        horizontalLayoutWidget_10->setObjectName(QString::fromUtf8("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(0, 490, 901, 41));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        discoverButton = new QPushButton(horizontalLayoutWidget_10);
        discoverButton->setObjectName(QString::fromUtf8("discoverButton"));
        discoverButton->setEnabled(false);

        horizontalLayout_8->addWidget(discoverButton);

        discoverStopButton = new QPushButton(horizontalLayoutWidget_10);
        discoverStopButton->setObjectName(QString::fromUtf8("discoverStopButton"));
        discoverStopButton->setEnabled(false);

        horizontalLayout_8->addWidget(discoverStopButton);

        typeVersionBtn = new QPushButton(horizontalLayoutWidget_10);
        typeVersionBtn->setObjectName(QString::fromUtf8("typeVersionBtn"));

        horizontalLayout_8->addWidget(typeVersionBtn);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        newInitCheckBox = new QCheckBox(horizontalLayoutWidget_10);
        newInitCheckBox->setObjectName(QString::fromUtf8("newInitCheckBox"));

        horizontalLayout_8->addWidget(newInitCheckBox);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);

        startAddrLabel = new QLabel(horizontalLayoutWidget_10);
        startAddrLabel->setObjectName(QString::fromUtf8("startAddrLabel"));

        horizontalLayout_8->addWidget(startAddrLabel);

        startAddrSpinBox = new QSpinBox(horizontalLayoutWidget_10);
        startAddrSpinBox->setObjectName(QString::fromUtf8("startAddrSpinBox"));
        startAddrSpinBox->setMaximum(63);

        horizontalLayout_8->addWidget(startAddrSpinBox);

        horizontalSpacer_14 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_14);

        currenLayout_12 = new QHBoxLayout();
        currenLayout_12->setObjectName(QString::fromUtf8("currenLayout_12"));
        devCountEdit = new QLineEdit(horizontalLayoutWidget_10);
        devCountEdit->setObjectName(QString::fromUtf8("devCountEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(devCountEdit->sizePolicy().hasHeightForWidth());
        devCountEdit->setSizePolicy(sizePolicy);

        currenLayout_12->addWidget(devCountEdit);

        devCountLabel = new QLabel(horizontalLayoutWidget_10);
        devCountLabel->setObjectName(QString::fromUtf8("devCountLabel"));
        devCountLabel->setText(QString::fromUtf8("\320\243\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262"));

        currenLayout_12->addWidget(devCountLabel);


        horizontalLayout_8->addLayout(currenLayout_12);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        clearDiscoveredButton = new QPushButton(horizontalLayoutWidget_10);
        clearDiscoveredButton->setObjectName(QString::fromUtf8("clearDiscoveredButton"));

        horizontalLayout_8->addWidget(clearDiscoveredButton);

        searchInfoEdit = new QTextEdit(adderessingTab);
        searchInfoEdit->setObjectName(QString::fromUtf8("searchInfoEdit"));
        searchInfoEdit->setGeometry(QRect(580, 10, 321, 471));
        tabWidget->addTab(adderessingTab, QString());
        daliCommandsTab = new QWidget();
        daliCommandsTab->setObjectName(QString::fromUtf8("daliCommandsTab"));
        daliCoimmandsGroupBox = new QGroupBox(daliCommandsTab);
        daliCoimmandsGroupBox->setObjectName(QString::fromUtf8("daliCoimmandsGroupBox"));
        daliCoimmandsGroupBox->setGeometry(QRect(10, 10, 461, 531));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(daliCoimmandsGroupBox->sizePolicy().hasHeightForWidth());
        daliCoimmandsGroupBox->setSizePolicy(sizePolicy1);
        commandSendGroupBox = new QGroupBox(daliCoimmandsGroupBox);
        commandSendGroupBox->setObjectName(QString::fromUtf8("commandSendGroupBox"));
        commandSendGroupBox->setGeometry(QRect(10, 370, 411, 61));
        horizontalLayoutWidget_5 = new QWidget(commandSendGroupBox);
        horizontalLayoutWidget_5->setObjectName(QString::fromUtf8("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(0, 20, 371, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        currenLayout_6 = new QHBoxLayout();
        currenLayout_6->setObjectName(QString::fromUtf8("currenLayout_6"));
        commandSendDecLabel = new QLabel(horizontalLayoutWidget_5);
        commandSendDecLabel->setObjectName(QString::fromUtf8("commandSendDecLabel"));
        commandSendDecLabel->setText(QString::fromUtf8("DEC"));

        currenLayout_6->addWidget(commandSendDecLabel);

        commandSendDecEdit = new QLineEdit(horizontalLayoutWidget_5);
        commandSendDecEdit->setObjectName(QString::fromUtf8("commandSendDecEdit"));

        currenLayout_6->addWidget(commandSendDecEdit);


        horizontalLayout_3->addLayout(currenLayout_6);

        currenLayout_7 = new QHBoxLayout();
        currenLayout_7->setObjectName(QString::fromUtf8("currenLayout_7"));
        commandSendHexLabel = new QLabel(horizontalLayoutWidget_5);
        commandSendHexLabel->setObjectName(QString::fromUtf8("commandSendHexLabel"));
        commandSendHexLabel->setText(QString::fromUtf8("HEX"));

        currenLayout_7->addWidget(commandSendHexLabel);

        commandSendHexEdit = new QLineEdit(horizontalLayoutWidget_5);
        commandSendHexEdit->setObjectName(QString::fromUtf8("commandSendHexEdit"));

        currenLayout_7->addWidget(commandSendHexEdit);


        horizontalLayout_3->addLayout(currenLayout_7);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        replyGroupBox = new QGroupBox(daliCoimmandsGroupBox);
        replyGroupBox->setObjectName(QString::fromUtf8("replyGroupBox"));
        replyGroupBox->setGeometry(QRect(10, 430, 411, 91));
        horizontalLayoutWidget_7 = new QWidget(replyGroupBox);
        horizontalLayoutWidget_7->setObjectName(QString::fromUtf8("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(0, 50, 371, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        currenLayout_10 = new QHBoxLayout();
        currenLayout_10->setObjectName(QString::fromUtf8("currenLayout_10"));
        replyDecLabel = new QLabel(horizontalLayoutWidget_7);
        replyDecLabel->setObjectName(QString::fromUtf8("replyDecLabel"));
        replyDecLabel->setText(QString::fromUtf8("DEC"));

        currenLayout_10->addWidget(replyDecLabel);

        replyDecEdit = new QLineEdit(horizontalLayoutWidget_7);
        replyDecEdit->setObjectName(QString::fromUtf8("replyDecEdit"));

        currenLayout_10->addWidget(replyDecEdit);


        horizontalLayout_5->addLayout(currenLayout_10);

        currenLayout_11 = new QHBoxLayout();
        currenLayout_11->setObjectName(QString::fromUtf8("currenLayout_11"));
        replyHexLabel = new QLabel(horizontalLayoutWidget_7);
        replyHexLabel->setObjectName(QString::fromUtf8("replyHexLabel"));
        replyHexLabel->setText(QString::fromUtf8("HEX"));

        currenLayout_11->addWidget(replyHexLabel);

        replyHexEdit = new QLineEdit(horizontalLayoutWidget_7);
        replyHexEdit->setObjectName(QString::fromUtf8("replyHexEdit"));

        currenLayout_11->addWidget(replyHexEdit);


        horizontalLayout_5->addLayout(currenLayout_11);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_5);

        replyEdit = new QLineEdit(replyGroupBox);
        replyEdit->setObjectName(QString::fromUtf8("replyEdit"));
        replyEdit->setGeometry(QRect(0, 20, 371, 21));
        horizontalLayoutWidget_3 = new QWidget(daliCoimmandsGroupBox);
        horizontalLayoutWidget_3->setObjectName(QString::fromUtf8("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 180, 441, 181));
        horizontalLayout_43 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        horizontalLayout_43->setContentsMargins(0, 0, 0, 0);
        commandAddressSetlLayout = new QHBoxLayout();
        commandAddressSetlLayout->setObjectName(QString::fromUtf8("commandAddressSetlLayout"));

        horizontalLayout_43->addLayout(commandAddressSetlLayout);

        sendCmdToPushButton = new QPushButton(horizontalLayoutWidget_3);
        sendCmdToPushButton->setObjectName(QString::fromUtf8("sendCmdToPushButton"));
        sendCmdToPushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(sendCmdToPushButton->sizePolicy().hasHeightForWidth());
        sendCmdToPushButton->setSizePolicy(sizePolicy);

        horizontalLayout_43->addWidget(sendCmdToPushButton);

        verticalLayoutWidget_12 = new QWidget(daliCoimmandsGroupBox);
        verticalLayoutWidget_12->setObjectName(QString::fromUtf8("verticalLayoutWidget_12"));
        verticalLayoutWidget_12->setGeometry(QRect(10, 20, 441, 161));
        commandSelectLayout = new QVBoxLayout(verticalLayoutWidget_12);
        commandSelectLayout->setObjectName(QString::fromUtf8("commandSelectLayout"));
        commandSelectLayout->setContentsMargins(0, 0, 0, 0);
        periodSendCheckBox = new QCheckBox(daliCommandsTab);
        periodSendCheckBox->setObjectName(QString::fromUtf8("periodSendCheckBox"));
        periodSendCheckBox->setGeometry(QRect(480, 50, 171, 17));
        replyExplaintEdit = new QTextEdit(daliCommandsTab);
        replyExplaintEdit->setObjectName(QString::fromUtf8("replyExplaintEdit"));
        replyExplaintEdit->setGeometry(QRect(500, 410, 371, 121));
        tabWidget->addTab(daliCommandsTab, QString());
        ScenesTab = new QWidget();
        ScenesTab->setObjectName(QString::fromUtf8("ScenesTab"));
        verticalLayoutWidget_2 = new QWidget(ScenesTab);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 10, 261, 221));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        setSceneAddrLabel = new QLabel(verticalLayoutWidget_2);
        setSceneAddrLabel->setObjectName(QString::fromUtf8("setSceneAddrLabel"));
        QFont font;
        font.setPointSize(10);
        setSceneAddrLabel->setFont(font);
        setSceneAddrLabel->setLineWidth(4);

        horizontalLayout_10->addWidget(setSceneAddrLabel);

        bCastAddrCheckBox = new QCheckBox(verticalLayoutWidget_2);
        bCastAddrCheckBox->setObjectName(QString::fromUtf8("bCastAddrCheckBox"));

        horizontalLayout_10->addWidget(bCastAddrCheckBox);

        sceneAddrSpinBox = new QSpinBox(verticalLayoutWidget_2);
        sceneAddrSpinBox->setObjectName(QString::fromUtf8("sceneAddrSpinBox"));
        sceneAddrSpinBox->setMaximum(63);

        horizontalLayout_10->addWidget(sceneAddrSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_10);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        setSceneLabel = new QLabel(verticalLayoutWidget_2);
        setSceneLabel->setObjectName(QString::fromUtf8("setSceneLabel"));
        setSceneLabel->setFont(font);

        horizontalLayout_4->addWidget(setSceneLabel);

        sceneNmbSpinBox = new QSpinBox(verticalLayoutWidget_2);
        sceneNmbSpinBox->setObjectName(QString::fromUtf8("sceneNmbSpinBox"));
        sceneNmbSpinBox->setMaximum(15);

        horizontalLayout_4->addWidget(sceneNmbSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        sceneValueLabel = new QLabel(verticalLayoutWidget_2);
        sceneValueLabel->setObjectName(QString::fromUtf8("sceneValueLabel"));
        sceneValueLabel->setFont(font);

        horizontalLayout_9->addWidget(sceneValueLabel);

        sceneValSpinBox = new QSpinBox(verticalLayoutWidget_2);
        sceneValSpinBox->setObjectName(QString::fromUtf8("sceneValSpinBox"));
        sceneValSpinBox->setMaximum(254);

        horizontalLayout_9->addWidget(sceneValSpinBox);


        verticalLayout_3->addLayout(horizontalLayout_9);

        sceneSetButton = new QPushButton(verticalLayoutWidget_2);
        sceneSetButton->setObjectName(QString::fromUtf8("sceneSetButton"));
        sceneSetButton->setFont(font);

        verticalLayout_3->addWidget(sceneSetButton);

        sceneRemoveButton = new QPushButton(verticalLayoutWidget_2);
        sceneRemoveButton->setObjectName(QString::fromUtf8("sceneRemoveButton"));
        sceneRemoveButton->setFont(font);

        verticalLayout_3->addWidget(sceneRemoveButton);

        sceneGoToButton = new QPushButton(verticalLayoutWidget_2);
        sceneGoToButton->setObjectName(QString::fromUtf8("sceneGoToButton"));
        sceneGoToButton->setFont(font);

        verticalLayout_3->addWidget(sceneGoToButton);

        sceneQueryLevelButton = new QPushButton(verticalLayoutWidget_2);
        sceneQueryLevelButton->setObjectName(QString::fromUtf8("sceneQueryLevelButton"));
        sceneQueryLevelButton->setFont(font);

        verticalLayout_3->addWidget(sceneQueryLevelButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        verticalLayoutWidget_3 = new QWidget(ScenesTab);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(280, 10, 411, 221));
        verticalLayout_4 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        setFadeTimeLabel = new QLabel(verticalLayoutWidget_3);
        setFadeTimeLabel->setObjectName(QString::fromUtf8("setFadeTimeLabel"));
        setFadeTimeLabel->setFont(font);
        setFadeTimeLabel->setLineWidth(4);

        horizontalLayout_11->addWidget(setFadeTimeLabel);

        fadeTimeSpinBox = new QSpinBox(verticalLayoutWidget_3);
        fadeTimeSpinBox->setObjectName(QString::fromUtf8("fadeTimeSpinBox"));
        fadeTimeSpinBox->setMaximum(15);

        horizontalLayout_11->addWidget(fadeTimeSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_11);

        fadeTimeSetBtn = new QPushButton(verticalLayoutWidget_3);
        fadeTimeSetBtn->setObjectName(QString::fromUtf8("fadeTimeSetBtn"));

        verticalLayout_4->addWidget(fadeTimeSetBtn);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        setFastFadeTimeLabel = new QLabel(verticalLayoutWidget_3);
        setFastFadeTimeLabel->setObjectName(QString::fromUtf8("setFastFadeTimeLabel"));
        setFastFadeTimeLabel->setFont(font);
        setFastFadeTimeLabel->setLineWidth(4);

        horizontalLayout_16->addWidget(setFastFadeTimeLabel);

        fastFadeTimeSpinBox = new QSpinBox(verticalLayoutWidget_3);
        fastFadeTimeSpinBox->setObjectName(QString::fromUtf8("fastFadeTimeSpinBox"));
        fastFadeTimeSpinBox->setMaximum(27);

        horizontalLayout_16->addWidget(fastFadeTimeSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_16);

        fastFadeTimeSetBtn = new QPushButton(verticalLayoutWidget_3);
        fastFadeTimeSetBtn->setObjectName(QString::fromUtf8("fastFadeTimeSetBtn"));

        verticalLayout_4->addWidget(fastFadeTimeSetBtn);

        horizontalLayout_17 = new QHBoxLayout();
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        setExtendedFadeTimeBaseLabel = new QLabel(verticalLayoutWidget_3);
        setExtendedFadeTimeBaseLabel->setObjectName(QString::fromUtf8("setExtendedFadeTimeBaseLabel"));
        setExtendedFadeTimeBaseLabel->setFont(font);
        setExtendedFadeTimeBaseLabel->setLineWidth(4);

        horizontalLayout_17->addWidget(setExtendedFadeTimeBaseLabel);

        extFadeTimeBaseSpinBox = new QSpinBox(verticalLayoutWidget_3);
        extFadeTimeBaseSpinBox->setObjectName(QString::fromUtf8("extFadeTimeBaseSpinBox"));
        extFadeTimeBaseSpinBox->setMaximum(15);

        horizontalLayout_17->addWidget(extFadeTimeBaseSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_17);

        horizontalLayout_18 = new QHBoxLayout();
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        setExtendedFadeTimeMultLabel = new QLabel(verticalLayoutWidget_3);
        setExtendedFadeTimeMultLabel->setObjectName(QString::fromUtf8("setExtendedFadeTimeMultLabel"));
        setExtendedFadeTimeMultLabel->setFont(font);
        setExtendedFadeTimeMultLabel->setLineWidth(4);

        horizontalLayout_18->addWidget(setExtendedFadeTimeMultLabel);

        extFadeTimeMultSpinBox = new QSpinBox(verticalLayoutWidget_3);
        extFadeTimeMultSpinBox->setObjectName(QString::fromUtf8("extFadeTimeMultSpinBox"));
        extFadeTimeMultSpinBox->setMaximum(4);

        horizontalLayout_18->addWidget(extFadeTimeMultSpinBox);


        verticalLayout_4->addLayout(horizontalLayout_18);

        extendedFadeTimeSetBtn = new QPushButton(verticalLayoutWidget_3);
        extendedFadeTimeSetBtn->setObjectName(QString::fromUtf8("extendedFadeTimeSetBtn"));

        verticalLayout_4->addWidget(extendedFadeTimeSetBtn);

        verticalSpacer_8 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_8);

        tabWidget->addTab(ScenesTab, QString());
        dapcCommandsTab = new QWidget();
        dapcCommandsTab->setObjectName(QString::fromUtf8("dapcCommandsTab"));
        horizontalLayoutWidget_9 = new QWidget(dapcCommandsTab);
        horizontalLayoutWidget_9->setObjectName(QString::fromUtf8("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 10, 411, 501));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalSpacer_2 = new QSpacerItem(20, 30, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_2);

        maxValLabel = new QLabel(horizontalLayoutWidget_9);
        maxValLabel->setObjectName(QString::fromUtf8("maxValLabel"));

        verticalLayout_2->addWidget(maxValLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        minValLabel = new QLabel(horizontalLayoutWidget_9);
        minValLabel->setObjectName(QString::fromUtf8("minValLabel"));

        verticalLayout_2->addWidget(minValLabel);

        verticalSpacer_3 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_3);

        ValueLabel = new QLabel(horizontalLayoutWidget_9);
        ValueLabel->setObjectName(QString::fromUtf8("ValueLabel"));

        verticalLayout_2->addWidget(ValueLabel);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_4);

        addressLabel = new QLabel(horizontalLayoutWidget_9);
        addressLabel->setObjectName(QString::fromUtf8("addressLabel"));

        verticalLayout_2->addWidget(addressLabel);

        verticalSpacer_5 = new QSpacerItem(20, 65, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_2->addItem(verticalSpacer_5);


        horizontalLayout_7->addLayout(verticalLayout_2);

        broadcastGroupBox = new QGroupBox(horizontalLayoutWidget_9);
        broadcastGroupBox->setObjectName(QString::fromUtf8("broadcastGroupBox"));
        broadcastSlider = new QSlider(broadcastGroupBox);
        broadcastSlider->setObjectName(QString::fromUtf8("broadcastSlider"));
        broadcastSlider->setGeometry(QRect(20, 30, 22, 351));
        broadcastSlider->setMaximum(254);
        broadcastSlider->setOrientation(Qt::Vertical);
        broadcastEdit = new QLineEdit(broadcastGroupBox);
        broadcastEdit->setObjectName(QString::fromUtf8("broadcastEdit"));
        broadcastEdit->setGeometry(QRect(10, 390, 51, 20));

        horizontalLayout_7->addWidget(broadcastGroupBox);

        redGroupBox = new QGroupBox(horizontalLayoutWidget_9);
        redGroupBox->setObjectName(QString::fromUtf8("redGroupBox"));
        redSlider = new QSlider(redGroupBox);
        redSlider->setObjectName(QString::fromUtf8("redSlider"));
        redSlider->setGeometry(QRect(20, 30, 22, 351));
        redSlider->setMaximum(254);
        redSlider->setOrientation(Qt::Vertical);
        redEdit = new QLineEdit(redGroupBox);
        redEdit->setObjectName(QString::fromUtf8("redEdit"));
        redEdit->setGeometry(QRect(10, 390, 51, 20));
        redCheckBox = new QCheckBox(redGroupBox);
        redCheckBox->setObjectName(QString::fromUtf8("redCheckBox"));
        redCheckBox->setGeometry(QRect(10, 450, 61, 17));
        redAddrSpinBox = new QSpinBox(redGroupBox);
        redAddrSpinBox->setObjectName(QString::fromUtf8("redAddrSpinBox"));
        redAddrSpinBox->setGeometry(QRect(10, 420, 51, 20));
        redAddrSpinBox->setMinimum(0);
        redAddrSpinBox->setMaximum(63);

        horizontalLayout_7->addWidget(redGroupBox);

        greenGroupBox = new QGroupBox(horizontalLayoutWidget_9);
        greenGroupBox->setObjectName(QString::fromUtf8("greenGroupBox"));
        greenSlider = new QSlider(greenGroupBox);
        greenSlider->setObjectName(QString::fromUtf8("greenSlider"));
        greenSlider->setGeometry(QRect(20, 30, 22, 351));
        greenSlider->setMaximum(254);
        greenSlider->setOrientation(Qt::Vertical);
        greenEdit = new QLineEdit(greenGroupBox);
        greenEdit->setObjectName(QString::fromUtf8("greenEdit"));
        greenEdit->setGeometry(QRect(10, 390, 51, 20));
        greenCheckBox = new QCheckBox(greenGroupBox);
        greenCheckBox->setObjectName(QString::fromUtf8("greenCheckBox"));
        greenCheckBox->setGeometry(QRect(10, 450, 61, 17));
        greenAddrSpinBox = new QSpinBox(greenGroupBox);
        greenAddrSpinBox->setObjectName(QString::fromUtf8("greenAddrSpinBox"));
        greenAddrSpinBox->setGeometry(QRect(10, 420, 51, 20));
        greenAddrSpinBox->setMinimum(0);
        greenAddrSpinBox->setMaximum(63);
        greenAddrSpinBox->setValue(1);

        horizontalLayout_7->addWidget(greenGroupBox);

        blueGroupBox = new QGroupBox(horizontalLayoutWidget_9);
        blueGroupBox->setObjectName(QString::fromUtf8("blueGroupBox"));
        blueSlider = new QSlider(blueGroupBox);
        blueSlider->setObjectName(QString::fromUtf8("blueSlider"));
        blueSlider->setGeometry(QRect(20, 30, 22, 351));
        blueSlider->setMaximum(254);
        blueSlider->setOrientation(Qt::Vertical);
        blueEdit = new QLineEdit(blueGroupBox);
        blueEdit->setObjectName(QString::fromUtf8("blueEdit"));
        blueEdit->setGeometry(QRect(10, 390, 51, 20));
        blueCheckBox = new QCheckBox(blueGroupBox);
        blueCheckBox->setObjectName(QString::fromUtf8("blueCheckBox"));
        blueCheckBox->setGeometry(QRect(10, 450, 61, 17));
        blueAddrSpinBox = new QSpinBox(blueGroupBox);
        blueAddrSpinBox->setObjectName(QString::fromUtf8("blueAddrSpinBox"));
        blueAddrSpinBox->setGeometry(QRect(10, 420, 51, 20));
        blueAddrSpinBox->setMinimum(0);
        blueAddrSpinBox->setMaximum(63);
        blueAddrSpinBox->setValue(2);

        horizontalLayout_7->addWidget(blueGroupBox);

        horizontalLayoutWidget = new QWidget(dapcCommandsTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(459, 10, 401, 501));
        colourCtrlLayout = new QHBoxLayout(horizontalLayoutWidget);
        colourCtrlLayout->setObjectName(QString::fromUtf8("colourCtrlLayout"));
        colourCtrlLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget->addTab(dapcCommandsTab, QString());
        monitorTab = new QWidget();
        monitorTab->setObjectName(QString::fromUtf8("monitorTab"));
        timeStampCheckBox = new QCheckBox(monitorTab);
        timeStampCheckBox->setObjectName(QString::fromUtf8("timeStampCheckBox"));
        timeStampCheckBox->setGeometry(QRect(30, 590, 161, 17));
        daliMasterroupBox = new QGroupBox(monitorTab);
        daliMasterroupBox->setObjectName(QString::fromUtf8("daliMasterroupBox"));
        daliMasterroupBox->setGeometry(QRect(570, 40, 151, 151));
        layoutWidget_5 = new QWidget(daliMasterroupBox);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 20, 131, 39));
        currenLayout_13 = new QHBoxLayout(layoutWidget_5);
        currenLayout_13->setObjectName(QString::fromUtf8("currenLayout_13"));
        currenLayout_13->setContentsMargins(0, 0, 0, 0);
        vendorIdLabel = new QLabel(layoutWidget_5);
        vendorIdLabel->setObjectName(QString::fromUtf8("vendorIdLabel"));
        vendorIdLabel->setText(QString::fromUtf8("Vendor ID  "));

        currenLayout_13->addWidget(vendorIdLabel);

        vidEdit = new QLineEdit(layoutWidget_5);
        vidEdit->setObjectName(QString::fromUtf8("vidEdit"));

        currenLayout_13->addWidget(vidEdit);

        layoutWidget_6 = new QWidget(daliMasterroupBox);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 60, 131, 39));
        currenLayout_14 = new QHBoxLayout(layoutWidget_6);
        currenLayout_14->setObjectName(QString::fromUtf8("currenLayout_14"));
        currenLayout_14->setContentsMargins(0, 0, 0, 0);
        productIdLabel = new QLabel(layoutWidget_6);
        productIdLabel->setObjectName(QString::fromUtf8("productIdLabel"));
        productIdLabel->setText(QString::fromUtf8("Product ID"));

        currenLayout_14->addWidget(productIdLabel);

        pidEdit = new QLineEdit(layoutWidget_6);
        pidEdit->setObjectName(QString::fromUtf8("pidEdit"));

        currenLayout_14->addWidget(pidEdit);

        findDeviceButton = new QPushButton(daliMasterroupBox);
        findDeviceButton->setObjectName(QString::fromUtf8("findDeviceButton"));
        findDeviceButton->setGeometry(QRect(10, 110, 131, 23));
        verticalLayoutWidget_10 = new QWidget(monitorTab);
        verticalLayoutWidget_10->setObjectName(QString::fromUtf8("verticalLayoutWidget_10"));
        verticalLayoutWidget_10->setGeometry(QRect(10, 10, 511, 521));
        verticalLayout_19 = new QVBoxLayout(verticalLayoutWidget_10);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        infoLabel = new QLabel(verticalLayoutWidget_10);
        infoLabel->setObjectName(QString::fromUtf8("infoLabel"));

        verticalLayout_19->addWidget(infoLabel);

        monitorEdit = new QTextEdit(verticalLayoutWidget_10);
        monitorEdit->setObjectName(QString::fromUtf8("monitorEdit"));

        verticalLayout_19->addWidget(monitorEdit);

        clearMonitorWindowButton = new QPushButton(verticalLayoutWidget_10);
        clearMonitorWindowButton->setObjectName(QString::fromUtf8("clearMonitorWindowButton"));

        verticalLayout_19->addWidget(clearMonitorWindowButton);

        tabWidget->addTab(monitorTab, QString());
        extCommandsTab = new QWidget();
        extCommandsTab->setObjectName(QString::fromUtf8("extCommandsTab"));
        daliExtCmdsGroupBox = new QGroupBox(extCommandsTab);
        daliExtCmdsGroupBox->setObjectName(QString::fromUtf8("daliExtCmdsGroupBox"));
        daliExtCmdsGroupBox->setGeometry(QRect(10, 10, 481, 531));
        sizePolicy1.setHeightForWidth(daliExtCmdsGroupBox->sizePolicy().hasHeightForWidth());
        daliExtCmdsGroupBox->setSizePolicy(sizePolicy1);
        extCommandSendGroupBox = new QGroupBox(daliExtCmdsGroupBox);
        extCommandSendGroupBox->setObjectName(QString::fromUtf8("extCommandSendGroupBox"));
        extCommandSendGroupBox->setGeometry(QRect(10, 370, 461, 61));
        horizontalLayoutWidget_14 = new QWidget(extCommandSendGroupBox);
        horizontalLayoutWidget_14->setObjectName(QString::fromUtf8("horizontalLayoutWidget_14"));
        horizontalLayoutWidget_14->setGeometry(QRect(10, 20, 441, 31));
        horizontalLayout_14 = new QHBoxLayout(horizontalLayoutWidget_14);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(0, 0, 0, 0);
        currenLayout_15 = new QHBoxLayout();
        currenLayout_15->setObjectName(QString::fromUtf8("currenLayout_15"));
        extCommandSendDecLabel = new QLabel(horizontalLayoutWidget_14);
        extCommandSendDecLabel->setObjectName(QString::fromUtf8("extCommandSendDecLabel"));
        extCommandSendDecLabel->setText(QString::fromUtf8("DEC"));

        currenLayout_15->addWidget(extCommandSendDecLabel);

        extCommandSendDecEdit = new QLineEdit(horizontalLayoutWidget_14);
        extCommandSendDecEdit->setObjectName(QString::fromUtf8("extCommandSendDecEdit"));

        currenLayout_15->addWidget(extCommandSendDecEdit);


        horizontalLayout_14->addLayout(currenLayout_15);

        currenLayout_16 = new QHBoxLayout();
        currenLayout_16->setObjectName(QString::fromUtf8("currenLayout_16"));
        extCommandSendHexLabel = new QLabel(horizontalLayoutWidget_14);
        extCommandSendHexLabel->setObjectName(QString::fromUtf8("extCommandSendHexLabel"));
        extCommandSendHexLabel->setText(QString::fromUtf8("HEX"));

        currenLayout_16->addWidget(extCommandSendHexLabel);

        extCommandSendHexEdit = new QLineEdit(horizontalLayoutWidget_14);
        extCommandSendHexEdit->setObjectName(QString::fromUtf8("extCommandSendHexEdit"));

        currenLayout_16->addWidget(extCommandSendHexEdit);


        horizontalLayout_14->addLayout(currenLayout_16);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_8);

        extReplyGroupBox = new QGroupBox(daliExtCmdsGroupBox);
        extReplyGroupBox->setObjectName(QString::fromUtf8("extReplyGroupBox"));
        extReplyGroupBox->setGeometry(QRect(10, 440, 461, 81));
        horizontalLayoutWidget_15 = new QWidget(extReplyGroupBox);
        horizontalLayoutWidget_15->setObjectName(QString::fromUtf8("horizontalLayoutWidget_15"));
        horizontalLayoutWidget_15->setGeometry(QRect(10, 50, 441, 31));
        horizontalLayout_15 = new QHBoxLayout(horizontalLayoutWidget_15);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        currenLayout_17 = new QHBoxLayout();
        currenLayout_17->setObjectName(QString::fromUtf8("currenLayout_17"));
        extReplyDecLabel = new QLabel(horizontalLayoutWidget_15);
        extReplyDecLabel->setObjectName(QString::fromUtf8("extReplyDecLabel"));
        extReplyDecLabel->setText(QString::fromUtf8("DEC"));

        currenLayout_17->addWidget(extReplyDecLabel);

        extReplyDecEdit = new QLineEdit(horizontalLayoutWidget_15);
        extReplyDecEdit->setObjectName(QString::fromUtf8("extReplyDecEdit"));

        currenLayout_17->addWidget(extReplyDecEdit);


        horizontalLayout_15->addLayout(currenLayout_17);

        currenLayout_18 = new QHBoxLayout();
        currenLayout_18->setObjectName(QString::fromUtf8("currenLayout_18"));
        extReplyHexLabel = new QLabel(horizontalLayoutWidget_15);
        extReplyHexLabel->setObjectName(QString::fromUtf8("extReplyHexLabel"));
        extReplyHexLabel->setText(QString::fromUtf8("HEX"));

        currenLayout_18->addWidget(extReplyHexLabel);

        extReplyHexEdit = new QLineEdit(horizontalLayoutWidget_15);
        extReplyHexEdit->setObjectName(QString::fromUtf8("extReplyHexEdit"));

        currenLayout_18->addWidget(extReplyHexEdit);


        horizontalLayout_15->addLayout(currenLayout_18);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_15->addItem(horizontalSpacer_9);

        extReplyEdit = new QLineEdit(extReplyGroupBox);
        extReplyEdit->setObjectName(QString::fromUtf8("extReplyEdit"));
        extReplyEdit->setGeometry(QRect(10, 20, 441, 21));
        verticalLayoutWidget_4 = new QWidget(daliExtCmdsGroupBox);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(10, 20, 471, 201));
        verticalLayout_8 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        sendExtCmdEnableDeviceType = new QPushButton(verticalLayoutWidget_4);
        sendExtCmdEnableDeviceType->setObjectName(QString::fromUtf8("sendExtCmdEnableDeviceType"));

        horizontalLayout_20->addWidget(sendExtCmdEnableDeviceType);

        autoPrependCmdCheckBox = new QCheckBox(verticalLayoutWidget_4);
        autoPrependCmdCheckBox->setObjectName(QString::fromUtf8("autoPrependCmdCheckBox"));
        autoPrependCmdCheckBox->setChecked(true);

        horizontalLayout_20->addWidget(autoPrependCmdCheckBox);


        verticalLayout_8->addLayout(horizontalLayout_20);

        extCommandSelectLayout = new QVBoxLayout();
        extCommandSelectLayout->setObjectName(QString::fromUtf8("extCommandSelectLayout"));

        verticalLayout_8->addLayout(extCommandSelectLayout);

        horizontalLayoutWidget_4 = new QWidget(daliExtCmdsGroupBox);
        horizontalLayoutWidget_4->setObjectName(QString::fromUtf8("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 220, 471, 151));
        horizontalLayout_44 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_44->setContentsMargins(0, 0, 0, 0);
        extCommandAddressSetlLayout = new QHBoxLayout();
        extCommandAddressSetlLayout->setObjectName(QString::fromUtf8("extCommandAddressSetlLayout"));

        horizontalLayout_44->addLayout(extCommandAddressSetlLayout);

        sendExtCmdToPushButton = new QPushButton(horizontalLayoutWidget_4);
        sendExtCmdToPushButton->setObjectName(QString::fromUtf8("sendExtCmdToPushButton"));
        sendExtCmdToPushButton->setEnabled(false);
        sizePolicy.setHeightForWidth(sendExtCmdToPushButton->sizePolicy().hasHeightForWidth());
        sendExtCmdToPushButton->setSizePolicy(sizePolicy);

        horizontalLayout_44->addWidget(sendExtCmdToPushButton);

        verticalLayoutWidget_5 = new QWidget(extCommandsTab);
        verticalLayoutWidget_5->setObjectName(QString::fromUtf8("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(530, 30, 181, 80));
        verticalLayout_6 = new QVBoxLayout(verticalLayoutWidget_5);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        specSelLabel = new QLabel(verticalLayoutWidget_5);
        specSelLabel->setObjectName(QString::fromUtf8("specSelLabel"));
        specSelLabel->setFont(font);

        verticalLayout_6->addWidget(specSelLabel);

        specSelComboBox = new QComboBox(verticalLayoutWidget_5);
        specSelComboBox->setObjectName(QString::fromUtf8("specSelComboBox"));
        QFont font1;
        font1.setPointSize(12);
        specSelComboBox->setFont(font1);

        verticalLayout_6->addWidget(specSelComboBox);

        extReplyExplaintEdit = new QTextEdit(extCommandsTab);
        extReplyExplaintEdit->setObjectName(QString::fromUtf8("extReplyExplaintEdit"));
        extReplyExplaintEdit->setGeometry(QRect(530, 440, 371, 91));
        tabWidget->addTab(extCommandsTab, QString());
        memBanksTab = new QWidget();
        memBanksTab->setObjectName(QString::fromUtf8("memBanksTab"));
        layoutWidget = new QWidget(memBanksTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 851, 23));
        horizontalLayout_19 = new QHBoxLayout(layoutWidget);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        horizontalLayout_19->setContentsMargins(0, 0, 0, 0);
        setDevAddrLabel = new QLabel(layoutWidget);
        setDevAddrLabel->setObjectName(QString::fromUtf8("setDevAddrLabel"));
        setDevAddrLabel->setFont(font);
        setDevAddrLabel->setLineWidth(4);

        horizontalLayout_19->addWidget(setDevAddrLabel);

        setDevAddrSpinBox = new QSpinBox(layoutWidget);
        setDevAddrSpinBox->setObjectName(QString::fromUtf8("setDevAddrSpinBox"));
        setDevAddrSpinBox->setMaximum(63);

        horizontalLayout_19->addWidget(setDevAddrSpinBox);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_19->addItem(horizontalSpacer_13);

        memBanksProgressBar = new QProgressBar(layoutWidget);
        memBanksProgressBar->setObjectName(QString::fromUtf8("memBanksProgressBar"));
        memBanksProgressBar->setValue(0);

        horizontalLayout_19->addWidget(memBanksProgressBar);

        horizontalLayoutWidget_21 = new QWidget(memBanksTab);
        horizontalLayoutWidget_21->setObjectName(QString::fromUtf8("horizontalLayoutWidget_21"));
        horizontalLayoutWidget_21->setGeometry(QRect(0, 20, 911, 511));
        horizontalLayout_35 = new QHBoxLayout(horizontalLayoutWidget_21);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(0, 0, 0, 0);
        verticalLayout_16 = new QVBoxLayout();
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        memBank0TableView = new QTableView(horizontalLayoutWidget_21);
        memBank0TableView->setObjectName(QString::fromUtf8("memBank0TableView"));

        verticalLayout_16->addWidget(memBank0TableView);

        readBank0Btn = new QPushButton(horizontalLayoutWidget_21);
        readBank0Btn->setObjectName(QString::fromUtf8("readBank0Btn"));
        readBank0Btn->setEnabled(false);

        verticalLayout_16->addWidget(readBank0Btn);


        horizontalLayout_35->addLayout(verticalLayout_16);

        verticalLayout_17 = new QVBoxLayout();
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        memBank1TableView = new QTableView(horizontalLayoutWidget_21);
        memBank1TableView->setObjectName(QString::fromUtf8("memBank1TableView"));

        verticalLayout_17->addWidget(memBank1TableView);

        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        readBank1Btn = new QPushButton(horizontalLayoutWidget_21);
        readBank1Btn->setObjectName(QString::fromUtf8("readBank1Btn"));
        readBank1Btn->setEnabled(false);

        horizontalLayout_36->addWidget(readBank1Btn);

        writeFullBank1Btn = new QPushButton(horizontalLayoutWidget_21);
        writeFullBank1Btn->setObjectName(QString::fromUtf8("writeFullBank1Btn"));
        writeFullBank1Btn->setEnabled(false);

        horizontalLayout_36->addWidget(writeFullBank1Btn);

        memBank1FlashSaveBtn = new QPushButton(horizontalLayoutWidget_21);
        memBank1FlashSaveBtn->setObjectName(QString::fromUtf8("memBank1FlashSaveBtn"));
        memBank1FlashSaveBtn->setEnabled(false);

        horizontalLayout_36->addWidget(memBank1FlashSaveBtn);


        verticalLayout_17->addLayout(horizontalLayout_36);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        setBank1AddrLabel = new QLabel(horizontalLayoutWidget_21);
        setBank1AddrLabel->setObjectName(QString::fromUtf8("setBank1AddrLabel"));
        setBank1AddrLabel->setFont(font);
        setBank1AddrLabel->setLineWidth(4);

        horizontalLayout_21->addWidget(setBank1AddrLabel);

        setBank1AddrSpinBox = new QSpinBox(horizontalLayoutWidget_21);
        setBank1AddrSpinBox->setObjectName(QString::fromUtf8("setBank1AddrSpinBox"));
        setBank1AddrSpinBox->setMaximum(255);

        horizontalLayout_21->addWidget(setBank1AddrSpinBox);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        bank1ValueLabel = new QLabel(horizontalLayoutWidget_21);
        bank1ValueLabel->setObjectName(QString::fromUtf8("bank1ValueLabel"));
        bank1ValueLabel->setFont(font);
        bank1ValueLabel->setLineWidth(4);

        horizontalLayout_22->addWidget(bank1ValueLabel);

        bank1ValueSpinBox = new QSpinBox(horizontalLayoutWidget_21);
        bank1ValueSpinBox->setObjectName(QString::fromUtf8("bank1ValueSpinBox"));
        bank1ValueSpinBox->setMaximum(255);

        horizontalLayout_22->addWidget(bank1ValueSpinBox);


        horizontalLayout_21->addLayout(horizontalLayout_22);

        writeBank1Btn = new QPushButton(horizontalLayoutWidget_21);
        writeBank1Btn->setObjectName(QString::fromUtf8("writeBank1Btn"));
        writeBank1Btn->setEnabled(false);

        horizontalLayout_21->addWidget(writeBank1Btn);


        verticalLayout_17->addLayout(horizontalLayout_21);


        horizontalLayout_35->addLayout(verticalLayout_17);

        tabWidget->addTab(memBanksTab, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayoutWidget_9 = new QWidget(tab);
        verticalLayoutWidget_9->setObjectName(QString::fromUtf8("verticalLayoutWidget_9"));
        verticalLayoutWidget_9->setGeometry(QRect(0, 0, 911, 541));
        verticalLayout_11 = new QVBoxLayout(verticalLayoutWidget_9);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        setDevAddrLabel_3 = new QLabel(verticalLayoutWidget_9);
        setDevAddrLabel_3->setObjectName(QString::fromUtf8("setDevAddrLabel_3"));
        setDevAddrLabel_3->setFont(font);
        setDevAddrLabel_3->setLineWidth(4);

        horizontalLayout_26->addWidget(setDevAddrLabel_3);

        setDevAddrSpinBox_3 = new QSpinBox(verticalLayoutWidget_9);
        setDevAddrSpinBox_3->setObjectName(QString::fromUtf8("setDevAddrSpinBox_3"));
        setDevAddrSpinBox_3->setMaximum(63);

        horizontalLayout_26->addWidget(setDevAddrSpinBox_3);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_11);

        pwrEnergyProgressBar = new QProgressBar(verticalLayoutWidget_9);
        pwrEnergyProgressBar->setObjectName(QString::fromUtf8("pwrEnergyProgressBar"));
        pwrEnergyProgressBar->setValue(0);

        horizontalLayout_26->addWidget(pwrEnergyProgressBar);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_26->addItem(horizontalSpacer_10);


        verticalLayout_11->addLayout(horizontalLayout_26);

        horizontalLayout_27 = new QHBoxLayout();
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        memBank202Label = new QLabel(verticalLayoutWidget_9);
        memBank202Label->setObjectName(QString::fromUtf8("memBank202Label"));

        verticalLayout_7->addWidget(memBank202Label);

        memBank202TableView = new QTableView(verticalLayoutWidget_9);
        memBank202TableView->setObjectName(QString::fromUtf8("memBank202TableView"));

        verticalLayout_7->addWidget(memBank202TableView);

        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        memBank202SetLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank202SetLockButton->setObjectName(QString::fromUtf8("memBank202SetLockButton"));

        horizontalLayout_28->addWidget(memBank202SetLockButton);

        memBank202ClrLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank202ClrLockButton->setObjectName(QString::fromUtf8("memBank202ClrLockButton"));

        horizontalLayout_28->addWidget(memBank202ClrLockButton);

        memBank202ReadButton = new QPushButton(verticalLayoutWidget_9);
        memBank202ReadButton->setObjectName(QString::fromUtf8("memBank202ReadButton"));

        horizontalLayout_28->addWidget(memBank202ReadButton);


        verticalLayout_7->addLayout(horizontalLayout_28);


        horizontalLayout_27->addLayout(verticalLayout_7);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        memBank203abel = new QLabel(verticalLayoutWidget_9);
        memBank203abel->setObjectName(QString::fromUtf8("memBank203abel"));

        verticalLayout_9->addWidget(memBank203abel);

        memBank203TableView = new QTableView(verticalLayoutWidget_9);
        memBank203TableView->setObjectName(QString::fromUtf8("memBank203TableView"));

        verticalLayout_9->addWidget(memBank203TableView);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        memBank203SetLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank203SetLockButton->setObjectName(QString::fromUtf8("memBank203SetLockButton"));

        horizontalLayout_29->addWidget(memBank203SetLockButton);

        memBank203ClrLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank203ClrLockButton->setObjectName(QString::fromUtf8("memBank203ClrLockButton"));

        horizontalLayout_29->addWidget(memBank203ClrLockButton);

        memBank203ReadButton = new QPushButton(verticalLayoutWidget_9);
        memBank203ReadButton->setObjectName(QString::fromUtf8("memBank203ReadButton"));

        horizontalLayout_29->addWidget(memBank203ReadButton);


        verticalLayout_9->addLayout(horizontalLayout_29);


        horizontalLayout_27->addLayout(verticalLayout_9);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        memBank204abel = new QLabel(verticalLayoutWidget_9);
        memBank204abel->setObjectName(QString::fromUtf8("memBank204abel"));

        verticalLayout_10->addWidget(memBank204abel);

        memBank204TableView = new QTableView(verticalLayoutWidget_9);
        memBank204TableView->setObjectName(QString::fromUtf8("memBank204TableView"));

        verticalLayout_10->addWidget(memBank204TableView);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        memBank204SetLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank204SetLockButton->setObjectName(QString::fromUtf8("memBank204SetLockButton"));

        horizontalLayout_30->addWidget(memBank204SetLockButton);

        memBank204ClrLockButton = new QPushButton(verticalLayoutWidget_9);
        memBank204ClrLockButton->setObjectName(QString::fromUtf8("memBank204ClrLockButton"));

        horizontalLayout_30->addWidget(memBank204ClrLockButton);

        memBank204ReadButton = new QPushButton(verticalLayoutWidget_9);
        memBank204ReadButton->setObjectName(QString::fromUtf8("memBank204ReadButton"));

        horizontalLayout_30->addWidget(memBank204ReadButton);


        verticalLayout_10->addLayout(horizontalLayout_30);


        horizontalLayout_27->addLayout(verticalLayout_10);


        verticalLayout_11->addLayout(horizontalLayout_27);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayoutWidget_6 = new QWidget(tab_2);
        verticalLayoutWidget_6->setObjectName(QString::fromUtf8("verticalLayoutWidget_6"));
        verticalLayoutWidget_6->setGeometry(QRect(0, 0, 911, 541));
        verticalLayout_14 = new QVBoxLayout(verticalLayoutWidget_6);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        setDevAddrLabel_2 = new QLabel(verticalLayoutWidget_6);
        setDevAddrLabel_2->setObjectName(QString::fromUtf8("setDevAddrLabel_2"));
        setDevAddrLabel_2->setFont(font);
        setDevAddrLabel_2->setLineWidth(4);

        horizontalLayout_25->addWidget(setDevAddrLabel_2);

        setDevAddrSpinBox_2 = new QSpinBox(verticalLayoutWidget_6);
        setDevAddrSpinBox_2->setObjectName(QString::fromUtf8("setDevAddrSpinBox_2"));
        setDevAddrSpinBox_2->setMaximum(63);

        horizontalLayout_25->addWidget(setDevAddrSpinBox_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_25->addItem(horizontalSpacer_12);

        diagProgressBar = new QProgressBar(verticalLayoutWidget_6);
        diagProgressBar->setObjectName(QString::fromUtf8("diagProgressBar"));
        diagProgressBar->setValue(0);

        horizontalLayout_25->addWidget(diagProgressBar);


        verticalLayout_14->addLayout(horizontalLayout_25);

        horizontalLayout_31 = new QHBoxLayout();
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        verticalLayout_12 = new QVBoxLayout();
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        mBank205Label = new QLabel(verticalLayoutWidget_6);
        mBank205Label->setObjectName(QString::fromUtf8("mBank205Label"));
        mBank205Label->setFont(font);

        verticalLayout_12->addWidget(mBank205Label);

        memBank205TableView = new QTableView(verticalLayoutWidget_6);
        memBank205TableView->setObjectName(QString::fromUtf8("memBank205TableView"));

        verticalLayout_12->addWidget(memBank205TableView);

        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        memBank205SetLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank205SetLockButton->setObjectName(QString::fromUtf8("memBank205SetLockButton"));

        horizontalLayout_32->addWidget(memBank205SetLockButton);

        memBank205ClrLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank205ClrLockButton->setObjectName(QString::fromUtf8("memBank205ClrLockButton"));

        horizontalLayout_32->addWidget(memBank205ClrLockButton);

        mBank205ReadButton = new QPushButton(verticalLayoutWidget_6);
        mBank205ReadButton->setObjectName(QString::fromUtf8("mBank205ReadButton"));

        horizontalLayout_32->addWidget(mBank205ReadButton);


        verticalLayout_12->addLayout(horizontalLayout_32);


        horizontalLayout_31->addLayout(verticalLayout_12);

        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        mBank206Label = new QLabel(verticalLayoutWidget_6);
        mBank206Label->setObjectName(QString::fromUtf8("mBank206Label"));
        mBank206Label->setFont(font);

        verticalLayout_13->addWidget(mBank206Label);

        memBank206TableView = new QTableView(verticalLayoutWidget_6);
        memBank206TableView->setObjectName(QString::fromUtf8("memBank206TableView"));

        verticalLayout_13->addWidget(memBank206TableView);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        memBank206SetLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank206SetLockButton->setObjectName(QString::fromUtf8("memBank206SetLockButton"));

        horizontalLayout_33->addWidget(memBank206SetLockButton);

        memBank206ClrLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank206ClrLockButton->setObjectName(QString::fromUtf8("memBank206ClrLockButton"));

        horizontalLayout_33->addWidget(memBank206ClrLockButton);

        mBank206ReadButton = new QPushButton(verticalLayoutWidget_6);
        mBank206ReadButton->setObjectName(QString::fromUtf8("mBank206ReadButton"));

        horizontalLayout_33->addWidget(mBank206ReadButton);


        verticalLayout_13->addLayout(horizontalLayout_33);


        horizontalLayout_31->addLayout(verticalLayout_13);

        verticalLayout_15 = new QVBoxLayout();
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        mBank207Label = new QLabel(verticalLayoutWidget_6);
        mBank207Label->setObjectName(QString::fromUtf8("mBank207Label"));
        mBank207Label->setFont(font);

        verticalLayout_15->addWidget(mBank207Label);

        memBank207TableView = new QTableView(verticalLayoutWidget_6);
        memBank207TableView->setObjectName(QString::fromUtf8("memBank207TableView"));

        verticalLayout_15->addWidget(memBank207TableView);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        memBank207SetLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank207SetLockButton->setObjectName(QString::fromUtf8("memBank207SetLockButton"));

        horizontalLayout_34->addWidget(memBank207SetLockButton);

        memBank207ClrLockButton = new QPushButton(verticalLayoutWidget_6);
        memBank207ClrLockButton->setObjectName(QString::fromUtf8("memBank207ClrLockButton"));

        horizontalLayout_34->addWidget(memBank207ClrLockButton);

        mBank207ReadButton = new QPushButton(verticalLayoutWidget_6);
        mBank207ReadButton->setObjectName(QString::fromUtf8("mBank207ReadButton"));

        horizontalLayout_34->addWidget(mBank207ReadButton);


        verticalLayout_15->addLayout(horizontalLayout_34);


        horizontalLayout_31->addLayout(verticalLayout_15);


        verticalLayout_14->addLayout(horizontalLayout_31);

        tabWidget->addTab(tab_2, QString());
        testSeqTab = new QWidget();
        testSeqTab->setObjectName(QString::fromUtf8("testSeqTab"));
        verticalLayoutWidget_7 = new QWidget(testSeqTab);
        verticalLayoutWidget_7->setObjectName(QString::fromUtf8("verticalLayoutWidget_7"));
        verticalLayoutWidget_7->setGeometry(QRect(530, 10, 351, 251));
        verticalLayout_18 = new QVBoxLayout(verticalLayoutWidget_7);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        verticalLayout_18->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_39 = new QHBoxLayout();
        horizontalLayout_39->setSpacing(0);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        loadTestSeqButton = new QPushButton(verticalLayoutWidget_7);
        loadTestSeqButton->setObjectName(QString::fromUtf8("loadTestSeqButton"));

        horizontalLayout_39->addWidget(loadTestSeqButton);

        saveTestSeqButton = new QPushButton(verticalLayoutWidget_7);
        saveTestSeqButton->setObjectName(QString::fromUtf8("saveTestSeqButton"));

        horizontalLayout_39->addWidget(saveTestSeqButton);


        verticalLayout_18->addLayout(horizontalLayout_39);

        selectCmdLabel = new QLabel(verticalLayoutWidget_7);
        selectCmdLabel->setObjectName(QString::fromUtf8("selectCmdLabel"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(selectCmdLabel->sizePolicy().hasHeightForWidth());
        selectCmdLabel->setSizePolicy(sizePolicy2);
        selectCmdLabel->setFont(font);

        verticalLayout_18->addWidget(selectCmdLabel);

        testCommandSelectlLayout = new QVBoxLayout();
        testCommandSelectlLayout->setObjectName(QString::fromUtf8("testCommandSelectlLayout"));

        verticalLayout_18->addLayout(testCommandSelectlLayout);

        verticalLayoutWidget_8 = new QWidget(testSeqTab);
        verticalLayoutWidget_8->setObjectName(QString::fromUtf8("verticalLayoutWidget_8"));
        verticalLayoutWidget_8->setGeometry(QRect(530, 400, 374, 152));
        verticalLayout_25 = new QVBoxLayout(verticalLayoutWidget_8);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        addToTestButton = new QPushButton(verticalLayoutWidget_8);
        addToTestButton->setObjectName(QString::fromUtf8("addToTestButton"));

        verticalLayout_25->addWidget(addToTestButton);

        addExtendedCmdToTestButton = new QPushButton(verticalLayoutWidget_8);
        addExtendedCmdToTestButton->setObjectName(QString::fromUtf8("addExtendedCmdToTestButton"));

        verticalLayout_25->addWidget(addExtendedCmdToTestButton);

        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        addTimeoutToTestButton = new QPushButton(verticalLayoutWidget_8);
        addTimeoutToTestButton->setObjectName(QString::fromUtf8("addTimeoutToTestButton"));

        horizontalLayout_40->addWidget(addTimeoutToTestButton);

        testSeqToutSpinBox = new QDoubleSpinBox(verticalLayoutWidget_8);
        testSeqToutSpinBox->setObjectName(QString::fromUtf8("testSeqToutSpinBox"));
        testSeqToutSpinBox->setMinimum(0.050000000000000);
        testSeqToutSpinBox->setSingleStep(0.050000000000000);

        horizontalLayout_40->addWidget(testSeqToutSpinBox);


        verticalLayout_25->addLayout(horizontalLayout_40);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        addLoopStartToTestButton = new QPushButton(verticalLayoutWidget_8);
        addLoopStartToTestButton->setObjectName(QString::fromUtf8("addLoopStartToTestButton"));

        horizontalLayout_41->addWidget(addLoopStartToTestButton);

        addLoopEndToTestButton = new QPushButton(verticalLayoutWidget_8);
        addLoopEndToTestButton->setObjectName(QString::fromUtf8("addLoopEndToTestButton"));
        addLoopEndToTestButton->setEnabled(true);

        horizontalLayout_41->addWidget(addLoopEndToTestButton);

        iterCntLabel = new QLabel(verticalLayoutWidget_8);
        iterCntLabel->setObjectName(QString::fromUtf8("iterCntLabel"));

        horizontalLayout_41->addWidget(iterCntLabel);

        testSeqIterCntSpinBox = new QSpinBox(verticalLayoutWidget_8);
        testSeqIterCntSpinBox->setObjectName(QString::fromUtf8("testSeqIterCntSpinBox"));
        testSeqIterCntSpinBox->setMinimum(1);
        testSeqIterCntSpinBox->setMaximum(255);

        horizontalLayout_41->addWidget(testSeqIterCntSpinBox);


        verticalLayout_25->addLayout(horizontalLayout_41);

        testStopButton = new QPushButton(verticalLayoutWidget_8);
        testStopButton->setObjectName(QString::fromUtf8("testStopButton"));
        testStopButton->setEnabled(false);
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        testStopButton->setFont(font2);

        verticalLayout_25->addWidget(testStopButton);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_25->addItem(verticalSpacer_9);

        layoutWidget1 = new QWidget(testSeqTab);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(530, 260, 351, 141));
        testSeqAddressSetLayout = new QVBoxLayout(layoutWidget1);
        testSeqAddressSetLayout->setObjectName(QString::fromUtf8("testSeqAddressSetLayout"));
        testSeqAddressSetLayout->setContentsMargins(0, 0, 0, 0);
        sequenseLabel = new QLabel(testSeqTab);
        sequenseLabel->setObjectName(QString::fromUtf8("sequenseLabel"));
        sequenseLabel->setGeometry(QRect(0, 0, 221, 21));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(sequenseLabel->sizePolicy().hasHeightForWidth());
        sequenseLabel->setSizePolicy(sizePolicy3);
        testSeqTableView = new QTableView(testSeqTab);
        testSeqTableView->setObjectName(QString::fromUtf8("testSeqTableView"));
        testSeqTableView->setGeometry(QRect(0, 20, 521, 461));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(testSeqTableView->sizePolicy().hasHeightForWidth());
        testSeqTableView->setSizePolicy(sizePolicy4);
        layoutWidget2 = new QWidget(testSeqTab);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(0, 480, 521, 31));
        horizontalLayout_38 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        horizontalLayout_38->setContentsMargins(0, 0, 0, 0);
        removeFromTestButton = new QPushButton(layoutWidget2);
        removeFromTestButton->setObjectName(QString::fromUtf8("removeFromTestButton"));

        horizontalLayout_38->addWidget(removeFromTestButton);

        clearAllTestButton = new QPushButton(layoutWidget2);
        clearAllTestButton->setObjectName(QString::fromUtf8("clearAllTestButton"));

        horizontalLayout_38->addWidget(clearAllTestButton);

        testRunButton = new QPushButton(testSeqTab);
        testRunButton->setObjectName(QString::fromUtf8("testRunButton"));
        testRunButton->setGeometry(QRect(0, 510, 521, 24));
        testRunButton->setFont(font2);
        tabWidget->addTab(testSeqTab, QString());

        verticalLayout->addWidget(tabWidget);

        DaliMain->setCentralWidget(centralwidget);
        menubar = new QMenuBar(DaliMain);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 932, 21));
        menuCOM = new QMenu(menubar);
        menuCOM->setObjectName(QString::fromUtf8("menuCOM"));
        DaliMain->setMenuBar(menubar);
        statusbar = new QStatusBar(DaliMain);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        DaliMain->setStatusBar(statusbar);

        menubar->addAction(menuCOM->menuAction());
        menuCOM->addSeparator();
        menuCOM->addAction(comSetupAction);
        menuCOM->addAction(comDisconnectAction);

        retranslateUi(DaliMain);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(DaliMain);
    } // setupUi

    void retranslateUi(QMainWindow *DaliMain)
    {
        DaliMain->setWindowTitle(QCoreApplication::translate("DaliMain", "DaliMain", nullptr));
        comSetupAction->setText(QCoreApplication::translate("DaliMain", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        comConnectAction->setText(QCoreApplication::translate("DaliMain", "\320\237\320\276\320\264\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        comDisconnectAction->setText(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\272\320\273\321\216\321\207\320\270\321\202\321\214", nullptr));
        discoverButton->setText(QCoreApplication::translate("DaliMain", "\320\235\320\260\321\207\320\260\321\202\321\214 \320\277\320\276\320\270\321\201\320\272/\320\260\320\264\321\200\320\265\321\201\320\260\321\206\320\270\321\216", nullptr));
        discoverStopButton->setText(QCoreApplication::translate("DaliMain", "\320\241\321\202\320\276\320\277", nullptr));
        typeVersionBtn->setText(QCoreApplication::translate("DaliMain", "\320\242\320\270\320\277/\320\222\320\265\321\200\321\201(Debug)", nullptr));
        newInitCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\235\320\276\320\262\320\260\321\217 \320\270\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267.", nullptr));
        startAddrLabel->setText(QCoreApplication::translate("DaliMain", "\320\235\320\260\321\207. \320\260\320\264\321\200\320\265\321\201:", nullptr));
        clearDiscoveredButton->setText(QCoreApplication::translate("DaliMain", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(adderessingTab), QCoreApplication::translate("DaliMain", "\320\237\320\276\320\270\321\201\320\272/\320\260\320\264\321\200\320\265\321\201\320\260\321\206\320\270\321\217", nullptr));
        daliCoimmandsGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203", nullptr));
        commandSendGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        replyGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        sendCmdToPushButton->setText(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        periodSendCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\277\321\200\320\260\320\262\320\273\321\217\321\202\321\214 \320\277\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\321\201\320\272\320\270", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(daliCommandsTab), QCoreApplication::translate("DaliMain", "\320\232\320\276\320\274\320\260\320\275\320\264\321\213 DALI", nullptr));
        setSceneAddrLabel->setText(QCoreApplication::translate("DaliMain", "\320\220\320\264\321\200\320\265\321\201", nullptr));
        bCastAddrCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\222\321\201\320\265\320\274", nullptr));
        setSceneLabel->setText(QCoreApplication::translate("DaliMain", "\320\241\321\206\320\265\320\275\320\260 \342\204\226", nullptr));
        sceneValueLabel->setText(QCoreApplication::translate("DaliMain", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        sceneSetButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \321\201\321\206\320\265\320\275\321\203 (Set Scene)", nullptr));
        sceneRemoveButton->setText(QCoreApplication::translate("DaliMain", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \321\201\321\206\320\265\320\275\321\203 (Remove From Scene)", nullptr));
        sceneGoToButton->setText(QCoreApplication::translate("DaliMain", "\320\237\320\265\321\200\320\265\321\205\320\276\320\264 \320\272 \321\201\321\206\320\265\320\275\320\265(GoTo Scene)", nullptr));
        sceneQueryLevelButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\321\200\320\276\321\201 \320\243\321\200\320\276\320\262\320\275\321\217 (Query Scene Level)", nullptr));
        setFadeTimeLabel->setText(QCoreApplication::translate("DaliMain", "\320\222\321\200\320\265\320\274\321\217 \320\277\320\276\321\202\321\203\321\201\320\272\320\275\320\265\320\275\320\270\321\217 (Fade Time)", nullptr));
        fadeTimeSetBtn->setText(QCoreApplication::translate("DaliMain", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 Fade Time", nullptr));
        setFastFadeTimeLabel->setText(QCoreApplication::translate("DaliMain", "\320\221\321\213\321\201\321\202\321\200\320\276\320\265 \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\321\202\321\203\321\201\320\272\320\275\320\265\320\275\320\270\321\217 (Fast Fade Time)", nullptr));
        fastFadeTimeSetBtn->setText(QCoreApplication::translate("DaliMain", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214  Fast Fade Time", nullptr));
        setExtendedFadeTimeBaseLabel->setText(QCoreApplication::translate("DaliMain", "\320\240\320\260\321\201\321\210\320\270\321\200. \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\321\202\321\203\321\201\320\272\320\275. (Extended Fade Time), Base", nullptr));
        setExtendedFadeTimeMultLabel->setText(QCoreApplication::translate("DaliMain", "\320\240\320\260\321\201\321\210\320\270\321\200. \320\262\321\200\320\265\320\274\321\217 \320\277\320\276\321\202\321\203\321\201\320\272\320\275. (Extended Fade Time), Mult", nullptr));
        extendedFadeTimeSetBtn->setText(QCoreApplication::translate("DaliMain", "\320\243\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214  Extended Fade Time", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(ScenesTab), QCoreApplication::translate("DaliMain", "\320\241\321\206\320\265\320\275\321\213(Scenes)+Fade", nullptr));
        maxValLabel->setText(QCoreApplication::translate("DaliMain", "          254-", nullptr));
        minValLabel->setText(QCoreApplication::translate("DaliMain", "              0-", nullptr));
        ValueLabel->setText(QCoreApplication::translate("DaliMain", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265\320\265", nullptr));
        addressLabel->setText(QCoreApplication::translate("DaliMain", "DALI \320\260\320\264\321\200\320\265\321\201", nullptr));
        broadcastGroupBox->setTitle(QCoreApplication::translate("DaliMain", "Broadcast", nullptr));
        broadcastEdit->setText(QCoreApplication::translate("DaliMain", "0", nullptr));
        redGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\232\321\200\320\260\321\201\320\275\321\213\320\271", nullptr));
        redEdit->setText(QCoreApplication::translate("DaliMain", "0", nullptr));
        redCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\263\321\200\321\203\320\277\320\277\320\260", nullptr));
        greenGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\227\320\265\320\273\320\265\320\275\321\213\320\271", nullptr));
        greenEdit->setText(QCoreApplication::translate("DaliMain", "0", nullptr));
        greenCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\263\321\200\321\203\320\277\320\277\320\260", nullptr));
        blueGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\241\320\270\320\275\320\270\320\271", nullptr));
        blueEdit->setText(QCoreApplication::translate("DaliMain", "0", nullptr));
        blueCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\263\321\200\321\203\320\277\320\277\320\260", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(dapcCommandsTab), QCoreApplication::translate("DaliMain", "\320\232\320\276\320\274\320\260\320\275\320\264\321\213 DAPC", nullptr));
        timeStampCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\274\320\265\321\202\320\272\321\203 \320\262\321\200\320\265\320\274\320\265\320\275\320\270", nullptr));
        daliMasterroupBox->setTitle(QCoreApplication::translate("DaliMain", "DALI \320\274\320\260\321\201\321\202\320\265\321\200", nullptr));
        findDeviceButton->setText(QCoreApplication::translate("DaliMain", "\320\237\320\276\320\270\321\201\320\272 \321\203\321\201-\320\262\320\260", nullptr));
        infoLabel->setText(QCoreApplication::translate("DaliMain", "Info:", nullptr));
        clearMonitorWindowButton->setText(QCoreApplication::translate("DaliMain", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(monitorTab), QCoreApplication::translate("DaliMain", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200\320\270\320\275\320\263", nullptr));
        daliExtCmdsGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203", nullptr));
        extCommandSendGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", nullptr));
        extReplyGroupBox->setTitle(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\262\320\265\321\202", nullptr));
        sendExtCmdEnableDeviceType->setText(QCoreApplication::translate("DaliMain", "\320\240\320\260\320\267\321\200\320\265\321\210\320\270\321\202\321\214 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276 \321\202\320\270\320\277\320\260 6 (LED \321\201\320\262\320\265\321\202\320\270\320\273\321\214\320\275\320\270\320\272)", nullptr));
        autoPrependCmdCheckBox->setText(QCoreApplication::translate("DaliMain", "\320\220\320\262\321\202\320\276\320\274\320\260\321\202. \320\277\320\276\321\201\321\213\320\273\320\260\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203 \320\277\320\265\321\200\320\265\320\264", nullptr));
        sendExtCmdToPushButton->setText(QCoreApplication::translate("DaliMain", "\320\236\321\202\320\277\321\200\320\260\320\262\320\270\321\202\321\214", nullptr));
        specSelLabel->setText(QCoreApplication::translate("DaliMain", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214 \321\201\320\277\320\265\321\206\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\216:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(extCommandsTab), QCoreApplication::translate("DaliMain", "\320\240\320\260\321\201\321\210\320\270\321\200. \320\232\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        setDevAddrLabel->setText(QCoreApplication::translate("DaliMain", "\320\220\320\264\321\200\320\265\321\201 \321\203-\320\262\320\260", nullptr));
        readBank0Btn->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 \320\221\320\260\320\275\320\272 0", nullptr));
        readBank1Btn->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 \320\221\320\260\320\275\320\272 1", nullptr));
        writeFullBank1Btn->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262\320\265\321\201\321\214 \320\261\320\260\320\275\320\272 1", nullptr));
        memBank1FlashSaveBtn->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\320\270\321\201\321\214 \320\262 NVM", nullptr));
        setBank1AddrLabel->setText(QCoreApplication::translate("DaliMain", "\320\220\320\264\321\200\320\265\321\201 \320\262 \320\277\320\260\320\274\321\217\321\202\320\270", nullptr));
        bank1ValueLabel->setText(QCoreApplication::translate("DaliMain", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        writeBank1Btn->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\320\270\321\201\321\214 1 \320\261\320\260\320\271\321\202\320\260 \320\262 \320\221\320\260\320\275\320\272 1", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(memBanksTab), QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272\320\270 \320\277\320\260\320\274\321\217\321\202\320\270", nullptr));
        setDevAddrLabel_3->setText(QCoreApplication::translate("DaliMain", "\320\220\320\264\321\200\320\265\321\201 \321\203-\320\262\320\260", nullptr));
        memBank202Label->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 \320\277\320\260\320\274\321\217\321\202\320\270 202 (Actine EnergyPower)", nullptr));
        memBank202SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank202ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        memBank202ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 ", nullptr));
        memBank203abel->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 \320\277\320\260\320\274\321\217\321\202\320\270 203 (Apparent EnergyPower)", nullptr));
        memBank203SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank203ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        memBank203ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 ", nullptr));
        memBank204abel->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 \320\277\320\260\320\274\321\217\321\202\320\270 204 (LoadSide EnergyPower)", nullptr));
        memBank204SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank204ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        memBank204ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("DaliMain", "\320\255\320\275\320\265\321\200\320\263\320\270\321\217 (\321\201\320\277.252)", nullptr));
        setDevAddrLabel_2->setText(QCoreApplication::translate("DaliMain", "\320\220\320\264\321\200\320\265\321\201 \321\203-\320\262\320\260", nullptr));
        mBank205Label->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 205 (\320\272\320\276\320\275\321\202\321\200. \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\276)", nullptr));
        memBank205SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank205ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        mBank205ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 ", nullptr));
        mBank206Label->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 206 (\320\270\321\201\321\202\320\276\321\207\320\275\320\270\320\272 \321\201\320\262\320\265\321\202\320\260)", nullptr));
        memBank206SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank206ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        mBank206ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 ", nullptr));
        mBank207Label->setText(QCoreApplication::translate("DaliMain", "\320\221\320\260\320\275\320\272 207 (\321\201\320\262\320\265\321\202\320\270\320\273\321\214\320\275\320\270\320\272)", nullptr));
        memBank207SetLockButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\321\211\320\270\321\202\320\260 \320\276\321\202 \320\267\320\260\320\277\320\270\321\201\320\270", nullptr));
        memBank207ClrLockButton->setText(QCoreApplication::translate("DaliMain", " \320\241\320\275\321\217\321\202\321\214 \320\267\320\260\321\211\320\270\321\202\321\203", nullptr));
        mBank207ReadButton->setText(QCoreApplication::translate("DaliMain", "\320\247\320\270\321\202\320\260\321\202\321\214 ", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("DaliMain", "\320\224\320\270\320\260\320\263\320\275\320\276\321\201\321\202\320\270\320\272\320\260 (\321\201\320\277.253)", nullptr));
        loadTestSeqButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", nullptr));
        saveTestSeqButton->setText(QCoreApplication::translate("DaliMain", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        selectCmdLabel->setText(QCoreApplication::translate("DaliMain", "     \320\232\320\276\320\274\320\260\320\275\320\264\321\213", nullptr));
        addToTestButton->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203 \320\262 \321\202\320\265\321\201\321\202", nullptr));
        addExtendedCmdToTestButton->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\200\320\260\321\201\321\210\320\270\321\200\320\265\320\275\320\275\321\203\321\216 \320\272\320\276\320\274\320\260\320\275\320\264\321\203 \320\262 \321\202\320\265\321\201\321\202", nullptr));
        addTimeoutToTestButton->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\202\320\260\320\271\320\274\320\260\321\203\321\202 (\321\201\320\265\320\272)->", nullptr));
        addLoopStartToTestButton->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\275\320\260\321\207\320\260\320\273\320\276 \321\206\320\270\320\272\320\273\320\260", nullptr));
        addLoopEndToTestButton->setText(QCoreApplication::translate("DaliMain", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\276\320\275\320\265\321\206 \321\206\320\270\320\272\320\273\320\260", nullptr));
        iterCntLabel->setText(QCoreApplication::translate("DaliMain", "\320\230\321\202\320\265\321\200\320\260\321\206\320\270\320\271:", nullptr));
        testStopButton->setText(QCoreApplication::translate("DaliMain", "\320\236\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \321\202\320\265\321\201\321\202", nullptr));
        sequenseLabel->setText(QCoreApplication::translate("DaliMain", "\320\237\320\276\321\201\320\273\320\265\320\264\320\276\320\262\320\260\321\202\320\265\320\273\321\214\320\275\320\276\321\201\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264 \320\264\320\273\321\217 \321\202\320\265\321\201\321\202\320\260", nullptr));
        removeFromTestButton->setText(QCoreApplication::translate("DaliMain", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\272\320\276\320\274\320\260\320\275\320\264\321\203 \320\270\320\267 \321\202\320\265\321\201\321\202\320\260", nullptr));
        clearAllTestButton->setText(QCoreApplication::translate("DaliMain", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\222\321\201\320\265", nullptr));
        testRunButton->setText(QCoreApplication::translate("DaliMain", "\320\227\320\260\320\277\321\203\321\201\321\202\320\270\321\202\321\214 \321\202\320\265\321\201\321\202", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(testSeqTab), QCoreApplication::translate("DaliMain", "\320\242\320\265\321\201\321\202\320\276\320\262\321\213\320\265 \320\277\320\276\321\201\320\273. \320\272\320\276\320\274\320\260\320\275\320\264", nullptr));
        menuCOM->setTitle(QCoreApplication::translate("DaliMain", "COM \320\277\320\276\321\200\321\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DaliMain: public Ui_DaliMain {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DALIMAIN_H
