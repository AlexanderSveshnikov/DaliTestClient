#ifndef DALIMAIN_H
#define DALIMAIN_H

#include <QMainWindow>
#include <QSerialPort>
#include <QStandardItemModel>
#include <QTimer>
#include <QLineEdit>

#include "settingsdialog.h"
#include "diagnostics.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DaliMain; }
QT_END_NAMESPACE

//command format: command ID (1 byte), length (1 byte, counts bytes followed, without CRC),
//              command data(up to 3 bytes), CRC(1 byte, sum of all preceeded bytes witn "!" op. to result
//command may be addressed either to master itself (command ID = 0) or to slave(s) via master(command ID = 1)
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

#define MAX_ADDR      0xFFFFFF

#define SEARCH_ADDRESSING_TAB_INDEX     0
#define DALI_COMMANDS_TAB_INDEX         1
#define SCENE_TESTS_TAB_INDEX           2
#define DALI_EXT_COMMANDS_TAB_INDEX     5
#define DALI_MEM_BANKS_TAB_INDEX        6
#define DALI_ENERGY_PWR_TAB_INDEX       7
#define DALI_DIAGNOSTICS_TAB_INDEX      8

#define COMMAND_SEND_TWICE_FLAG         0x80
#define COMMAND_EXPECT_ANSWER_FLAG      0x40
#define COMMAND_SPECIAL_FLAG            0x20

#define GREEN_COLOR     1
#define BLUE_COLOR      2

#define LOCK_BYTE_OFFSET    2

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

public:
    DaliMain(QWidget *parent = nullptr);
    ~DaliMain();

private:
    Ui::DaliMain *ui;
    SettingsDialog *m_settings = nullptr;
    QSerialPort *m_serial = nullptr;

    QStandardItemModel model;
    QStringList resTabHeaderData = {"Short Address", "Random Address", "Type", "Version", "Connected"};

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

    int red, green, blue;
    uint8_t nextToSend;
    int hue, sat, val;

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

    discover_state_e exchangeState = EXCHANGE_STATE_IDLE;

    QList<QString>daliCommandsStrList =
    {
        "0 OFF", "1 UP", "2 DOWN", "3 STEP UP", "4 STEP DOWN",
        "5 RECALL MAX LEVEL", "6 RECALL MIN LEVEL",
        "7 STEP DOWN AND OFF", "8 ON AND STEP UP",
        "9 ENABLE DAPC SEQUENCE", "10 GO TO LAST ACTIVE LEVEL",
        "16 GO TO SCENE 0", "17 GO TO SCENE 1", "18 GO TO SCENE 2", "19 GO TO SCENE 3",
        "20 GO TO SCENE 4", "21 GO TO SCENE 5", "22 GO TO SCENE 6", "23 GO TO SCENE 7",
        "24 GO TO SCENE 8", "25 GO TO SCENE 9", "26 GO TO SCENE 10", "27 GO TO SCENE 11",
        "28 GO TO SCENE 12", "29 GO TO SCENE 13", "30 GO TO SCENE 14", "31 GO TO SCENE 15",
        "32 RESET", "33 STORE ACTUAL LEVEL IN THE DTR", "34 SAVE PERSISTENT VARIABLES",
        "35 SET DTR0 AS OPERATING MODE", "36 RESET MEMORY BANK (DTR0)",
        "37 IDENTIFY DEVICE", "42 STORE THE DTR AS MAX LEVEL",
        "43 STORE THE DTR AS MIN LEVEL", "44 STORE THE DTR AS SYSTEM FAILURE LEVEL",
        "45 STORE THE DTR AS POWERON LEVEL", "46 STORE THE DTR AS FADE TIME",
        "47 STORE THE DTR AS FADE RATE", "48 STORE THE DTR AS EXTENDED FADE TIME",
        "64 STORE THE DTR AS SCENE 0", "65 STORE THE DTR AS SCENE 1", "66 STORE THE DTR AS SCENE 2",
        "67 STORE THE DTR AS SCENE 3", "68 STORE THE DTR AS SCENE 4", "69 STORE THE DTR AS SCENE 5",
        "70 STORE THE DTR AS SCENE 6", "71 STORE THE DTR AS SCENE 7", "72 STORE THE DTR AS SCENE 8",
        "73 STORE THE DTR AS SCENE 9", "74 STORE THE DTR AS SCENE 10", "75 STORE THE DTR AS SCENE 11",
        "76 STORE THE DTR AS SCENE 12", "77 STORE THE DTR AS SCENE 13", "78 STORE THE DTR AS SCENE 14",
        "79 STORE THE DTR AS SCENE 15", "80 REMOVE FROM SCENE 0", "81 REMOVE FROM SCENE 1",
        "82 REMOVE FROM SCENE 2", "83 REMOVE FROM SCENE 3", "84 REMOVE FROM SCENE 4",
        "85 REMOVE FROM SCENE 5", "86 REMOVE FROM SCENE 6", "87 REMOVE FROM SCENE 7",
        "88 REMOVE FROM SCENE 8", "89 REMOVE FROM SCENE 9", "90 REMOVE FROM SCENE 10",
        "91 REMOVE FROM SCENE 11", "92 REMOVE FROM SCENE 12", "93 REMOVE FROM SCENE 13",
        "94 REMOVE FROM SCENE 14", "95 REMOVE FROM SCENE 15", "96 ADD TO GROUP 0",
        "97 ADD TO GROUP 1", "98 ADD TO GROUP 2", "99 ADD TO GROUP 3", "100 ADD TO GROUP 4",
        "101 ADD TO GROUP 5", "102 ADD TO GROUP 6", "103 ADD TO GROUP 7", "104 ADD TO GROUP 8",
        "105 ADD TO GROUP 9", "106 ADD TO GROUP 10", "107 ADD TO GROUP 11", "108 ADD TO GROUP 12",
        "109 ADD TO GROUP 13", "110 ADD TO GROUP 14", "111 ADD TO GROUP 15",
        "112 REMOVE FROM GROUP 0", "113 REMOVE FROM GROUP 1", "114 REMOVE FROM GROUP 2",
        "115 REMOVE FROM GROUP 3", "116 REMOVE FROM GROUP 4", "117 REMOVE FROM GROUP 5",
        "118 REMOVE FROM GROUP 6", "119 REMOVE FROM GROUP 7", "120 REMOVE FROM GROUP 8",
        "121 REMOVE FROM GROUP 9", "122 REMOVE FROM GROUP 10", "123 REMOVE FROM GROUP 11",
        "124 REMOVE FROM GROUP 12", "125 REMOVE FROM GROUP 13", "126 REMOVE FROM GROUP 14",
        "127 REMOVE FROM GROUP 15", "128 STORE DTR AS SHORT ADDRESS", "129 ENABLE WRITE MEMORY",
        "144 QUERY STATUS", "145 QUERY CONTROIL GEAR", "146 QUERY LAMP FAILKURE",
        "147 QUERY LAMP POWER ON", "148 QUERY LIMIT ERROR", "149 QUERY RESET STATE",
        "150 QUERY MISSING SHORT ADDRESS", "151 QUERY VERSION NUMBER", "152 QUERY CONTENT DTR",
        "153 QUERY DEVICE TYPE", "154 QUERY PHYSICAL MINIMUM LEVEL", "155 QUERY POWER FAILURE",
        "156 QUERY CONTENT DTR1", "157 QUERY CONTENT DTR2", "158 QUERY OPERATING MODE",
        "159 QUERY LIGHT SOURCE TYPE", "160 QUERY ACTUAL LEVEL",
        "161 QUERY MAX LEVEL", "162 QUERY MIN LEVEL", "163 QUERY POWERON LEVEL",
        "164 QUERY SYSTEM FAILURE LEVEL", "165 QUERY FADE TIME/FADE RATE",
        "166 QUERY MANUFACTURER SPECIFIC MODE", "167 QUERY NEXT DEVICE TYPE", "168 QUERY EXTENDED FADE RATE",
        "170 QUERY CONTROL GEAR FAMILY", "176 QUERY SCENE LEVEL 0",
        "177 QUERY SCENE LEVEL 1", "178 QUERY SCENE LEVEL 2", "179 QUERY SCENE LEVEL 3",
        "180 QUERY SCENE LEVEL 4", "181 QUERY SCENE LEVEL 5", "182 QUERY SCENE LEVEL 6",
        "183 QUERY SCENE LEVEL 7", "184 QUERY SCENE LEVEL 8", "185 QUERY SCENE LEVEL 9",
        "186 QUERY SCENE LEVEL 10", "187 QUERY SCENE LEVEL 11", "188 QUERY SCENE LEVEL 12",
        "189 QUERY SCENE LEVEL 13", "190 QUERY SCENE LEVEL 14", "191 QUERY SCENE LEVEL 15",
        "192 QUERY GROUPS 0-7", "193 QUERY GROUPS 8-15", "194 QUERY RANDOM ADDRESS H",
        "195 QUERY RANDOM ADDRESS M", "196 QUERY RANDOM ADDRESS L", "197 READ MEMORY LOCATION",
        "255 QUERY EXTENDED VERSION NUM", "256 TERMINATE", "257 DTR0", "258 INITIALISE",
        "259 RANDOMISE", "260 COMPARE", "261 WITHDRAW", "264 SEARCHADDRH",
        "265 SEARCHADDRM", "266 SEARCHADDRL", "267 PROGRAM SHORT ADDRESS",
        "268 VERIFY SHORT ADDRESS", "269 QUERY SHORT ADDRESS",
        "272 ENABLE DEVICE TYPE X", "273 DTR1", "274 DTR2", "275 WRITE MEMORY LOCATION",
        "276 WRITE MEMORY LOCATION - NO REPLY",
    };

    QList<QString>daliSpec207ExtCommandsStrList =
    {
       "224 REFERENCE SYSTEM POWER", "225 ENABLE CURRENT PROTECTOR", "226 DISABLE CURRENT PROTECTOR",
       "227 SELECT DIMMING CURVE", "228 STORE DTR AS FAST FADE TIME", "237 QUERY GEAR TYPE",
       "238 QUERY DIMMING CURVE", "239 QUERY POSSIBLE OPERATING MODES", "240 QUERY FEATURES",
       "241 QUERY FAILURE STATUS", "242 QUERY SHORT CIRCUIT", "243 QUERY OPEN CIRCUIT",
       "244 QUERY LOAD DECREASE", "245 QUERY LOAD INCREASE", "246 QUERY CURRENT PROTECTOR ACTIVE",
       "247 QUERY THERMAL SHUT DOWN", "248 QUERY THERMAL OVERLOAD", "249 QUERY REFERENCE RUNNING",
       "250 QUERY REFERENCE MEASUREMENT FAILED", "251 QUERY CURRENT PROTECTOR ENABLED", "252 QUERY OPERATING MODE",
       "253 QUERY FAST FADE TIME", "254 QUERY MIN FAST FADE TIME",  "255 QUERY EXTENDED VERSION NUMBER",
    };

    QList<QString>daliSpec205ExtCommandsStrList =
    {
       "224 REFERENCE SYSTEM POWER", "225 SELECT DIMMING CURVE", "238 QUERY_DIMMING_CURVE",
       "239 QUERY DIMMER STATUS", "240 QUERY FEATURES", "241 QUERY FAILURE STATUS",
       "242 QUERY DIMMER TEMPERATURE", "243 QUERY RMS SUPPLY VOLTAGE", "244 QUERY SUPPLY FREQUENCY",
       "245 QUERY RMS LOAD VOLTAGE", "246 QUERY RMS LOAD CURRENT", "247 QUERY REAL LOAD POWER",
       "248 QUERY LOAD RATING", "249 QUERY REFERENCE RUNNING", "250 QUERY REFERENCE MEASUREMENT FAILED",
       "255 QUERY EXTENDED VERSION NUMBER",
    };

    // "272 ENABLE DEVICE TYPE 6",
    diagnostics* diag;
    void enableControl(bool isConect);
    bool openSerialPort();
    void comPortHandleError(QSerialPort::SerialPortError error);
    void comPortReadData();
    bool comPortProcessData();
    void createTable(QStandardItemModel* model);
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
    void sendCmd(uint8_t data, QString cmdStr,
                           bool isGroupBtnChk, uint8_t groupDest, bool isAddrBtnChk, uint8_t addrDest,
                           QLineEdit* cmdSendDecEdit, QLineEdit* cmdSendHexEdit, quint8 specification);
    void sendEnableDeviceType(quint8 gearType);
    void sendExtendedCommand();
    void storeGearParams();
    void setRGBVals();
    void updateMemBankTable();
    quint8 getSpec(QString text);
    void readBankBtnClick(uint8_t id, uint8_t* bank, uint8_t size);
    void getTabModelCellStr(QStandardItemModel* model, quint8 offset, quint8 len, QString* resStr);
    void writeBankBtnClick(quint8 id, quint8 offset);
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
    void updateDaliDataSetSlider(int sliderVal);
    void updateExtCmdsDaliDataSetSlider(int sliderVal);
    void broadcastSendRadioButtonClick();
    void groupSendRadioButtonClick();
    void addressSendRadioButtonClick();
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
    void colorButtonClick();
    void updateValueSlider(int);
    void updateHueSlider(int);
    void updateSaturationSlider(int);
    void sliderValHueSaturReleased();
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
};
#endif // DALIMAIN_H
