#ifndef DALIMAIN_H
#define DALIMAIN_H

#include <QMainWindow>
#include <QSerialPort>
#include <QStandardItemModel>
#include <QTimer>
#include <QLineEdit>
#include "daliCommandParcer.h"

#include "settingsdialog.h"
#include "diagnostics.h"
#include "commandselector.h"
#include "addressselector.h"
#include "colourcontrol.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DaliMain; }
QT_END_NAMESPACE

//Command format: command ID (1 byte), length (1 byte, counts bytes followed, without CRC),
//              command data(up to 3 bytes), CRC(1 byte, sum of all preceeded bytes with "!" op. to result
//Command may be addressed either to master itself (command ID = 0) or to slave(s) via master(command ID = 1)
//

#define MASTER_CMD              0x00
#define SLAVE_CMD               0x01
#define SLAVE_EMPTY_CMD         0x02
#define SLAVE_REPLY_TOUT_CMD    0x03

//master sub commands id's
#define MASTER_VID_PID  0x00

//Special commands address bytes
#define TERMINATE_ADDR_BYTE             0xA1
#define DTR0_ADDR_BYTE                  0xA3
#define INTIALISE_ADDR_BYTE             0xA5
#define RANDOMISE_ADDR_BYTE             0xA7
#define COMPARE_ADDR_BYTE               0xA9
#define WITHDRAW_ADDR_BYTE              0xAB
#define PING_ADDR_BYTE                  0xAD
#define SEARCHADDRH_ADDR_BYTE           0xB1
#define SEARCHADDRM_ADDR_BYTE           0xB3
#define SEARCHADDRL_ADDR_BYTE           0xB5
#define PROGRAM_SHORT_ADDR_BYTE         0xB7
#define VERIFY_SHORT_ADDR_BYTE          0xB9
#define QUERY_SHORT_ADDR_BYTE           0xBB
#define ENABLE_DEVICE_TYPE_ADDR_BYTE    0xC1
#define DTR1_ADDR_BYTE                  0xC3
#define DTR2_ADDR_BYTE                  0xC5
#define WRITE_MEM_LOC_ADDR_BYTE         0xC7
#define WRITE_MEM_LOC_NO_RPL_ADDR_BYTE  0xC9

#define DT8_ACTIVATE                    0xE2

#define MAX_ADDR      0xFFFFFF

#define SEARCH_ADDRESSING_TAB_INDEX     0
#define DALI_COMMANDS_TAB_INDEX         1
#define SCENE_TESTS_TAB_INDEX           2
#define DAPC_TAB_INDEX                  3
#define DALI_EXT_COMMANDS_TAB_INDEX     5
#define DALI_MEM_BANKS_TAB_INDEX        6
#define DALI_ENERGY_PWR_TAB_INDEX       7
#define DALI_DIAGNOSTICS_TAB_INDEX      8
#define DALI_TEST_SEQUENSE_TAB_INDEX    9

#define COMMAND_SEND_TWICE_FLAG         0x80
#define COMMAND_EXPECT_ANSWER_FLAG      0x40
#define COMMAND_SPECIAL_FLAG            0x20

#define GREEN_COLOR     1
#define BLUE_COLOR      2

#define LOCK_BYTE_OFFSET    2

#define TEST_SEQUENSE_MAX_COMMAND   128

typedef void(*dali_command_t)(uint8_t opcode);

typedef enum
{
    EXCHANGE_STATE_IDLE,
    EXCHANGE_STATE_TERMINATE_CMD,
    EXCHANGE_STATE_RESET_CMD,
    EXCHANGE_STATE_OFF_CMD,
    EXCHANGE_STATE_INITIALISE_CMD,
    EXCHANGE_STATE_RANDOMISE_CMD,
    EXCHANGE_STATE_SEARCHADDRH_CMD,
    EXCHANGE_STATE_SEARCHADDRM_CMD,
    EXCHANGE_STATE_SEARCHADDRL_CMD,
    EXCHANGE_STATE_COMPARE_CMD,
    EXCHANGE_STATE_PROGRAM_SHORT_ADDR_CMD,
    EXCHANGE_STATE_VERIFY_SHORT_ADDR_CMD,
    EXCHANGE_STATE_WITHDRAW_CMD,
    EXCHANGE_STATE_PROG2_SHORT_ADDR_CMD,
    EXCHANGE_STATE_SET_SCENE_CMD,
    EXCHANGE_STATE_SET_FADE_TIME_CMD,
    EXCHANGE_STATE_SET_DEVICE_TYPE_6_CMD,
    EXCHANGE_STATE_SET_FAST_FADE_TIME_CMD,
    EXCHANGE_STATE_SET_EXTENDED_FADE_TIME_CMD,
    EXCHANGE_STATE_SEND_EXTEND_CMD,
    EXCHANGE_STATE_GET_TYPE,
    EXCHANGE_STATE_GET_VERSION,
    EXCHANGE_STATE_SEND_DAPC_CMD,
    EXCHANGE_STATE_SEND_DTR0_MEM_CMD,
    EXCHANGE_STATE_READ_MEM_CMD,
    EXCHANGE_STATE_ENABLE_WRITE_MEM_CMD,
    EXCHANGE_STATE_WRITE_MEM_CMD,
    EXCHANGE_STATE_SEND_PERIODICALLY,
    EXCHANGE_STATE_SEND_TEST_SEQUENSE,
    EXCHANGE_STATE_LOOP_TEST_SEQUENSE,
    EXCHANGE_STATE_SEND_COLOUR_CMD,
    EXCHANGE_STATE_SEND_COLOUR_CTRL_CMD,
    EXCHANGE_STATE_SEND_ENABLE_TYPE8_CMD,
    EXCHANGE_STATE_DT8_ACTIVATE,
    EXCHANGE_STATE_SEND_ACTIVATE_CMD,
    EXCHANGE_STATE_GET_DTR,
}discover_state_e;

typedef struct
{
    uint32_t random_addr;
    uint8_t type;
    uint8_t version;
    bool connected;
}gear_t;

class DaliMain : public QMainWindow
{
    Q_OBJECT

    uint16_t nextTestSeqElemID = 0;
    typedef struct
    {
       uint16_t elementID;
       uint8_t addrByte;
       uint8_t opcodeByte;
       QString commandDefStr;
       bool set_twice;
       bool answer;
       bool is_special;
    }test_seq_cmd_t;

public:
    DaliMain(QWidget *parent = nullptr);
    ~DaliMain();

private:
    Ui::DaliMain *ui;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

    QStandardItemModel model;
    QStringList resTabHeaderData = {"Short Address", "Random Address", "Type", "Version", "Connected"};

    QList<quint16> testLoopIterationCnt;
    QList<quint16> testLoopStartCmdId;
    QStandardItemModel testTabModel;
    QStringList testTabHeaderData = {"Время", "Адрес", "Команда", "Ответ"};

    uint16_t nextTestSeqCmd = 0;
    QList<test_seq_cmd_t> testSeqCmds;

    //QStandardItemModel memBank0Model;
    QStringList memBank0HeaderData = {"Адрес", "Описание", "Значение"};
    QStringList memBank0DescData = {"Addr last acces mem location", "Reserved", "Nmb of last acces mem bank", "GTIN byte 0 (MSB)", "GTIN byte 1",\
                                    "GTIN byte 2", "GTIN byte 3", "GTIN byte 4", "GTIN byte 5 (LSB)", "FW Version (major)", "FW Version (minor)",\
                                    "Ident num byte 0 (MSB)", "Ident num byte 1", "Ident num byte 2", "Ident num byte 3", "Ident num byte 4",\
                                    "Ident num byte 5", "Ident num byte 6", "Ident num byte 7 (LSB)", "HW Version (major)", "HW Version (minor)",\
                                    "101 vers nmb", "102 vers nmb of all integr ctrl gear", "103 vers nmb of all integr ctrl gev",\
                                    "Nmb of logical ctrl dev units", "Nmb of logical ctrl gear units", "Idx nmb of this logical ctrl gear unit"};

    //QStandardItemModel memBank1Model;
    QStringList memBank1HeaderData = {"Адрес", "Описание", "Значение"};
    QStringList memBank1DescData = {"Addr last acces mem location", "Indic byte", "Lock Byte", "OEM GTIN byte 0 (MSB)", "OEM GTIN byte 1",\
                                    "OEM GTIN byte 2", "OEM GTIN byte 3", "OEM GTIN byte 4", "OEM GTIN byte 5 (LSB)", "OEM Ident num byte 0 (MSB)",\
                                    "OEM Ident num byte 1", "OEM Ident num byte 2", "OEM Ident num byte 3", "OEM Ident num byte 4",\
                                    "OEM Ident num byte 5", "OEM Ident num byte 6", "OEM Ident num byte 7", "Content Format ID (MSB)",\
                                    "Content Format IDa(LSB)", "Year of manufacture [YY]", "Week of manufacture [WW]", "Nominal Input Power [W] (MSB)",\
                                    "Nominal Input Power[W](LSB)", "Power at min dim level[W](MSB)", "Power at min dim level[W](LSB)",
                                    "Nominal Min AC mains volt[V](MSB)", "Nominal Min AC mains volt[V](LSB)",
                                    "Nominal Max AC mains volt[V](MSB)", "Nominal Max AC mains volt[V](LSB)", "Nominal light output [Lm] (MSB)",\
                                    "Nominal light output [Lm]", "Nominal light output [Lm] (LSB)", "CRI", "CCT [K] (MSB)", "CCT [K] (LSB)",\
                                    "Light Distribution Type", "Luminaire color(start)", "Luminaire color", "Luminaire color", "Luminaire color",\
                                    "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color",\
                                    "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color",\
                                    "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color", "Luminaire color",\
                                    "Luminaire color", "Luminaire color(end)", "Luminaire ident.(start)", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.", "Luminaire ident.",\
                                    "Luminaire ident.", "Luminaire ident.(end)",};

    CommandSelector* commandSel;
    CommandSelector* extCommandSel;
    CommandSelector* testSeqCommandSel;

    addressSelector* addrSel;
    addressSelector* extAddrSel;
    addressSelector* testSeqAddrSel;

    ColourControl* colourControlWidget;

    quint8 memBankSize;
    quint8 memBankCounter;
    quint8 memBankId;
    quint8 memBankOffset;
    quint8 memBankLock;
    quint8 memBank0Data[27];
    quint8 memBank1Data[120];  //spec 251
    quint8 memBank202Data[16];  //spec 252
    quint8 memBank203Data[16];  //spec 252
    quint8 memBank204Data[16];  //spec 252
    quint8 memBank205Data[29];  //spec 253
    quint8 memBank206Data[33];  //spec 253
    quint8 memBank207Data[8];  //spec 253

    bool memBankWriteFlag;
    bool memBank1FullWriteFlag = false;
    quint8 memBank1FullWriteIndex = 0;

    quint16 cmdId = 0;
    quint8 cmd_repeat_cntr = 0;
    uint8_t address_byte = 0;
    uint8_t opcode_byte = 0;
    QByteArray rdData;
    gear_t gear[64];
    uint8_t gear_idx;
    uint8_t gear_max_idx;
    uint8_t query_type;

    QTimer* waitRxTimer;
    bool waitRx = false;

    QTimer* exchangeTimer;

    uint8_t nextToSend;
    int red, green, blue;

    uint32_t searchAddress;
    uint8_t shortAddress = 0;
    bool saveSearchFlag = false;

    uint32_t type = 0;
    uint32_t version = 0;
    bool connected = false;

    uint32_t minAddress;
    uint32_t maxAddress;
    uint8_t shortAddr = 0;
    uint8_t tableEmptyRow = 0;
    uint8_t replyByte;
    uint8_t replyId;
    uint8_t dtr1;
    discover_state_e exchangeState = EXCHANGE_STATE_IDLE;



    // "272 ENABLE DEVICE TYPE 6",
    diagnostics* diag;
    void enableControl(bool isConect);
    void getAddressStr(quint8 addrByte, QString* res);
    void updateTestSequenseTable();
    bool openSerialPort();
    void comPortHandleError(QSerialPort::SerialPortError error);
    void comPortReadData();
    bool comPortProcessData();
    void createTable(QStringList* headerData, QStandardItemModel* model, QTableView* tabView, quint32 rowCount);
    void createMemBank0Tab(QStandardItemModel* model);
    void createMemBank1Tab(QStandardItemModel* model);
    uint8_t calcCrc(QByteArray* data, uint8_t len);
    void replyFromMaster(QByteArray* data);
    uint8_t replyFromSlave(QByteArray* data);
    void slaveCmd(quint8 addrByte, quint8 opCode, discover_state_e next_state, bool setTwice, bool answer, bool is_special);
    void addFoundedGearToTable(uint32_t searchAddress, uint8_t shortAddress);
    void gearTypeStrGet(uint8_t type, QString* typeStr);
    void addTypeVersionToTable();
    void clearTable();
    void sendDAPCData(uint8_t addr, uint8_t opcode);
    void buildCmd(daliCommandParcer* parcer, uint8_t data, QString cmdStr,
                  uint8_t addrType, uint8_t groupDest,  uint8_t addrDest);
    void sendCmd(uint8_t data, QString cmdStr, uint8_t addrType,
                 uint8_t groupDest, uint8_t addrDest,
                 QLineEdit* cmdSendDecEdit, QLineEdit* cmdSendHexEdit, quint8 specification);
    void sendEnableDeviceType(quint8 gearType);
    void sendExtendedCommand();
    void storeGearParams();
    void updateMemBankTable();
    quint8 getSpec(QString text);
    void readBankBtnClick(uint8_t id, uint8_t* bank, uint8_t size);
    void getTabModelCellStr(QStandardItemModel* model, quint8 offset, quint8 len, QString* resStr);
    void writeBankBtnClick(quint8 id, quint8 offset);
    void testSeqProcessReply();
    void testSeqProcessTimeout();
    void testSeqProcessNoReply();
    void clearTestSeqTableData();
    void testSeqSetNextHighLightBackGround(quint16 next);
private slots:
    void comSetup();
    void comConnect();
    void comDisconnect();
    void waitRxTimerShot();
    void findMasterDevice();
    void clearMonitorWindow();
    void exchangeTimerShot();
    void searchAddrStart();
    void exchangeStop();
    void clearDiscovered();
    void typeVersionBtnClicked();
    void exchangeProcess();
    void addToTestButtonClick();
    void addExtendedCmdToTestButtonClick();
    void addTimeoutToTestButtonClick();
    void addLoopStartToTestButtonClick();
    void addLoopEndToTestButtonClick();
    void loadTestSeqButtonClick();
    void saveTestSeqButtonClick();
    void removeFromTestButtonClick();
    void clearAllTestButtonClick();
    void testRunButtonClick();
    void testStopButtonClick();
    void sendCmdToPushButtonClicked();
    void sendExtCmdToPushButtonClicked();
    uint8_t generateRandomByte();
    void updateBroadcastSlider(int sliderVal);
    void sliderBroadcastRelease();
    void updateRedSlider(int sliderVal);
    void sliderRedReleased();
    void updateGreenSlider(int sliderVal);
    void sliderGreenReleased();
    void updateBlueSlider(int sliderVal);
    void sliderBlueReleased();
    void sceneSetBtnClicked();
    void sceneGoToBtnClicked();
    void sceneQueryLvlBtnClicked();
    void sceneRemoveBtnClicked();
    void fadeTimeSetBtnClicked();
    void fastFadeTimeSetBtnClicked();
    void extendedFadeTimeSetBtnClicked();
    void sendExtCmdEnableDeviceTypeClicked();
    void readBank0BtnClick();
    void readBank1BtnClick();
    void writeFullBank1BtnClick();
    void writeBank1BtnClick();
    void memBank1FlashSaveBtnClick();
    void specSelChanged();
    void memBank1TableCellSelect(const QModelIndex);
    void mBank202ReadBtnClicked();
    void mBank203ReadBtnClicked();
    void mBank204ReadBtnClicked();
    void mBank205ReadBtnClicked();
    void mBank206ReadBtnClicked();
    void mBank207ReadBtnClicked();
    void slotDevAddrChanged();
    void slotDevAddrChanged_3();
    void mBank202SetLockBtnClicked();
    void mBank203SetLockBtnClicked();
    void mBank204SetLockBtnClicked();
    void mBank205SetLockBtnClicked();
    void mBank206SetLockBtnClicked();
    void mBank207SetLockBtnClicked();
    void mBank202ClrLockBtnClicked();
    void mBank203ClrLockBtnClicked();
    void mBank204ClrLockBtnClicked();
    void mBank205ClrLockBtnClicked();
    void mBank206ClrLockBtnClicked();
    void mBank207ClrLockBtnClicked();
    void bCastAddrCheckBoxClicked();
    void extCmdsSpecSelChanged();

    void stepWarmerSigProc();
    void stepCoolerSigProc();
    void setColourValSigProc();
    void queryColorValSigProc();
};
#endif // DALIMAIN_H
