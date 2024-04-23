/****************************************************************************
** Meta object code from reading C++ file 'dalimain.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DaliTestClient/dalimain.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dalimain.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DaliMain_t {
    QByteArrayData data[80];
    char stringdata0[1684];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DaliMain_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DaliMain_t qt_meta_stringdata_DaliMain = {
    {
QT_MOC_LITERAL(0, 0, 8), // "DaliMain"
QT_MOC_LITERAL(1, 9, 8), // "comSetup"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 10), // "comConnect"
QT_MOC_LITERAL(4, 30, 13), // "comDisconnect"
QT_MOC_LITERAL(5, 44, 15), // "waitRxTimerShot"
QT_MOC_LITERAL(6, 60, 16), // "findMasterDevice"
QT_MOC_LITERAL(7, 77, 18), // "clearMonitorWindow"
QT_MOC_LITERAL(8, 96, 17), // "exchangeTimerShot"
QT_MOC_LITERAL(9, 114, 15), // "searchAddrStart"
QT_MOC_LITERAL(10, 130, 12), // "exchangeStop"
QT_MOC_LITERAL(11, 143, 15), // "clearDiscovered"
QT_MOC_LITERAL(12, 159, 21), // "typeVersionBtnClicked"
QT_MOC_LITERAL(13, 181, 15), // "exchangeProcess"
QT_MOC_LITERAL(14, 197, 20), // "addToTestButtonClick"
QT_MOC_LITERAL(15, 218, 31), // "addExtendedCmdToTestButtonClick"
QT_MOC_LITERAL(16, 250, 27), // "addTimeoutToTestButtonClick"
QT_MOC_LITERAL(17, 278, 29), // "addLoopStartToTestButtonClick"
QT_MOC_LITERAL(18, 308, 27), // "addLoopEndToTestButtonClick"
QT_MOC_LITERAL(19, 336, 22), // "loadTestSeqButtonClick"
QT_MOC_LITERAL(20, 359, 22), // "saveTestSeqButtonClick"
QT_MOC_LITERAL(21, 382, 25), // "removeFromTestButtonClick"
QT_MOC_LITERAL(22, 408, 23), // "clearAllTestButtonClick"
QT_MOC_LITERAL(23, 432, 18), // "testRunButtonClick"
QT_MOC_LITERAL(24, 451, 19), // "testStopButtonClick"
QT_MOC_LITERAL(25, 471, 26), // "sendCmdToPushButtonClicked"
QT_MOC_LITERAL(26, 498, 29), // "sendExtCmdToPushButtonClicked"
QT_MOC_LITERAL(27, 528, 18), // "generateRandomByte"
QT_MOC_LITERAL(28, 547, 7), // "uint8_t"
QT_MOC_LITERAL(29, 555, 21), // "updateBroadcastSlider"
QT_MOC_LITERAL(30, 577, 9), // "sliderVal"
QT_MOC_LITERAL(31, 587, 22), // "sliderBroadcastRelease"
QT_MOC_LITERAL(32, 610, 15), // "updateRedSlider"
QT_MOC_LITERAL(33, 626, 17), // "sliderRedReleased"
QT_MOC_LITERAL(34, 644, 17), // "updateGreenSlider"
QT_MOC_LITERAL(35, 662, 19), // "sliderGreenReleased"
QT_MOC_LITERAL(36, 682, 16), // "updateBlueSlider"
QT_MOC_LITERAL(37, 699, 18), // "sliderBlueReleased"
QT_MOC_LITERAL(38, 718, 18), // "sceneSetBtnClicked"
QT_MOC_LITERAL(39, 737, 19), // "sceneGoToBtnClicked"
QT_MOC_LITERAL(40, 757, 23), // "sceneQueryLvlBtnClicked"
QT_MOC_LITERAL(41, 781, 21), // "sceneRemoveBtnClicked"
QT_MOC_LITERAL(42, 803, 21), // "fadeTimeSetBtnClicked"
QT_MOC_LITERAL(43, 825, 25), // "fastFadeTimeSetBtnClicked"
QT_MOC_LITERAL(44, 851, 29), // "extendedFadeTimeSetBtnClicked"
QT_MOC_LITERAL(45, 881, 33), // "sendExtCmdEnableDeviceTypeCli..."
QT_MOC_LITERAL(46, 915, 17), // "readBank0BtnClick"
QT_MOC_LITERAL(47, 933, 17), // "readBank1BtnClick"
QT_MOC_LITERAL(48, 951, 22), // "writeFullBank1BtnClick"
QT_MOC_LITERAL(49, 974, 18), // "writeBank1BtnClick"
QT_MOC_LITERAL(50, 993, 25), // "memBank1FlashSaveBtnClick"
QT_MOC_LITERAL(51, 1019, 14), // "specSelChanged"
QT_MOC_LITERAL(52, 1034, 23), // "memBank1TableCellSelect"
QT_MOC_LITERAL(53, 1058, 11), // "QModelIndex"
QT_MOC_LITERAL(54, 1070, 22), // "mBank202ReadBtnClicked"
QT_MOC_LITERAL(55, 1093, 22), // "mBank203ReadBtnClicked"
QT_MOC_LITERAL(56, 1116, 22), // "mBank204ReadBtnClicked"
QT_MOC_LITERAL(57, 1139, 22), // "mBank205ReadBtnClicked"
QT_MOC_LITERAL(58, 1162, 22), // "mBank206ReadBtnClicked"
QT_MOC_LITERAL(59, 1185, 22), // "mBank207ReadBtnClicked"
QT_MOC_LITERAL(60, 1208, 18), // "slotDevAddrChanged"
QT_MOC_LITERAL(61, 1227, 20), // "slotDevAddrChanged_3"
QT_MOC_LITERAL(62, 1248, 25), // "mBank202SetLockBtnClicked"
QT_MOC_LITERAL(63, 1274, 25), // "mBank203SetLockBtnClicked"
QT_MOC_LITERAL(64, 1300, 25), // "mBank204SetLockBtnClicked"
QT_MOC_LITERAL(65, 1326, 25), // "mBank205SetLockBtnClicked"
QT_MOC_LITERAL(66, 1352, 25), // "mBank206SetLockBtnClicked"
QT_MOC_LITERAL(67, 1378, 25), // "mBank207SetLockBtnClicked"
QT_MOC_LITERAL(68, 1404, 25), // "mBank202ClrLockBtnClicked"
QT_MOC_LITERAL(69, 1430, 25), // "mBank203ClrLockBtnClicked"
QT_MOC_LITERAL(70, 1456, 25), // "mBank204ClrLockBtnClicked"
QT_MOC_LITERAL(71, 1482, 25), // "mBank205ClrLockBtnClicked"
QT_MOC_LITERAL(72, 1508, 25), // "mBank206ClrLockBtnClicked"
QT_MOC_LITERAL(73, 1534, 25), // "mBank207ClrLockBtnClicked"
QT_MOC_LITERAL(74, 1560, 24), // "bCastAddrCheckBoxClicked"
QT_MOC_LITERAL(75, 1585, 21), // "extCmdsSpecSelChanged"
QT_MOC_LITERAL(76, 1607, 17), // "stepWarmerSigProc"
QT_MOC_LITERAL(77, 1625, 17), // "stepCoolerSigProc"
QT_MOC_LITERAL(78, 1643, 19), // "setColourValSigProc"
QT_MOC_LITERAL(79, 1663, 20) // "queryColorValSigProc"

    },
    "DaliMain\0comSetup\0\0comConnect\0"
    "comDisconnect\0waitRxTimerShot\0"
    "findMasterDevice\0clearMonitorWindow\0"
    "exchangeTimerShot\0searchAddrStart\0"
    "exchangeStop\0clearDiscovered\0"
    "typeVersionBtnClicked\0exchangeProcess\0"
    "addToTestButtonClick\0"
    "addExtendedCmdToTestButtonClick\0"
    "addTimeoutToTestButtonClick\0"
    "addLoopStartToTestButtonClick\0"
    "addLoopEndToTestButtonClick\0"
    "loadTestSeqButtonClick\0saveTestSeqButtonClick\0"
    "removeFromTestButtonClick\0"
    "clearAllTestButtonClick\0testRunButtonClick\0"
    "testStopButtonClick\0sendCmdToPushButtonClicked\0"
    "sendExtCmdToPushButtonClicked\0"
    "generateRandomByte\0uint8_t\0"
    "updateBroadcastSlider\0sliderVal\0"
    "sliderBroadcastRelease\0updateRedSlider\0"
    "sliderRedReleased\0updateGreenSlider\0"
    "sliderGreenReleased\0updateBlueSlider\0"
    "sliderBlueReleased\0sceneSetBtnClicked\0"
    "sceneGoToBtnClicked\0sceneQueryLvlBtnClicked\0"
    "sceneRemoveBtnClicked\0fadeTimeSetBtnClicked\0"
    "fastFadeTimeSetBtnClicked\0"
    "extendedFadeTimeSetBtnClicked\0"
    "sendExtCmdEnableDeviceTypeClicked\0"
    "readBank0BtnClick\0readBank1BtnClick\0"
    "writeFullBank1BtnClick\0writeBank1BtnClick\0"
    "memBank1FlashSaveBtnClick\0specSelChanged\0"
    "memBank1TableCellSelect\0QModelIndex\0"
    "mBank202ReadBtnClicked\0mBank203ReadBtnClicked\0"
    "mBank204ReadBtnClicked\0mBank205ReadBtnClicked\0"
    "mBank206ReadBtnClicked\0mBank207ReadBtnClicked\0"
    "slotDevAddrChanged\0slotDevAddrChanged_3\0"
    "mBank202SetLockBtnClicked\0"
    "mBank203SetLockBtnClicked\0"
    "mBank204SetLockBtnClicked\0"
    "mBank205SetLockBtnClicked\0"
    "mBank206SetLockBtnClicked\0"
    "mBank207SetLockBtnClicked\0"
    "mBank202ClrLockBtnClicked\0"
    "mBank203ClrLockBtnClicked\0"
    "mBank204ClrLockBtnClicked\0"
    "mBank205ClrLockBtnClicked\0"
    "mBank206ClrLockBtnClicked\0"
    "mBank207ClrLockBtnClicked\0"
    "bCastAddrCheckBoxClicked\0extCmdsSpecSelChanged\0"
    "stepWarmerSigProc\0stepCoolerSigProc\0"
    "setColourValSigProc\0queryColorValSigProc"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DaliMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      75,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  389,    2, 0x08 /* Private */,
       3,    0,  390,    2, 0x08 /* Private */,
       4,    0,  391,    2, 0x08 /* Private */,
       5,    0,  392,    2, 0x08 /* Private */,
       6,    0,  393,    2, 0x08 /* Private */,
       7,    0,  394,    2, 0x08 /* Private */,
       8,    0,  395,    2, 0x08 /* Private */,
       9,    0,  396,    2, 0x08 /* Private */,
      10,    0,  397,    2, 0x08 /* Private */,
      11,    0,  398,    2, 0x08 /* Private */,
      12,    0,  399,    2, 0x08 /* Private */,
      13,    0,  400,    2, 0x08 /* Private */,
      14,    0,  401,    2, 0x08 /* Private */,
      15,    0,  402,    2, 0x08 /* Private */,
      16,    0,  403,    2, 0x08 /* Private */,
      17,    0,  404,    2, 0x08 /* Private */,
      18,    0,  405,    2, 0x08 /* Private */,
      19,    0,  406,    2, 0x08 /* Private */,
      20,    0,  407,    2, 0x08 /* Private */,
      21,    0,  408,    2, 0x08 /* Private */,
      22,    0,  409,    2, 0x08 /* Private */,
      23,    0,  410,    2, 0x08 /* Private */,
      24,    0,  411,    2, 0x08 /* Private */,
      25,    0,  412,    2, 0x08 /* Private */,
      26,    0,  413,    2, 0x08 /* Private */,
      27,    0,  414,    2, 0x08 /* Private */,
      29,    1,  415,    2, 0x08 /* Private */,
      31,    0,  418,    2, 0x08 /* Private */,
      32,    1,  419,    2, 0x08 /* Private */,
      33,    0,  422,    2, 0x08 /* Private */,
      34,    1,  423,    2, 0x08 /* Private */,
      35,    0,  426,    2, 0x08 /* Private */,
      36,    1,  427,    2, 0x08 /* Private */,
      37,    0,  430,    2, 0x08 /* Private */,
      38,    0,  431,    2, 0x08 /* Private */,
      39,    0,  432,    2, 0x08 /* Private */,
      40,    0,  433,    2, 0x08 /* Private */,
      41,    0,  434,    2, 0x08 /* Private */,
      42,    0,  435,    2, 0x08 /* Private */,
      43,    0,  436,    2, 0x08 /* Private */,
      44,    0,  437,    2, 0x08 /* Private */,
      45,    0,  438,    2, 0x08 /* Private */,
      46,    0,  439,    2, 0x08 /* Private */,
      47,    0,  440,    2, 0x08 /* Private */,
      48,    0,  441,    2, 0x08 /* Private */,
      49,    0,  442,    2, 0x08 /* Private */,
      50,    0,  443,    2, 0x08 /* Private */,
      51,    0,  444,    2, 0x08 /* Private */,
      52,    1,  445,    2, 0x08 /* Private */,
      54,    0,  448,    2, 0x08 /* Private */,
      55,    0,  449,    2, 0x08 /* Private */,
      56,    0,  450,    2, 0x08 /* Private */,
      57,    0,  451,    2, 0x08 /* Private */,
      58,    0,  452,    2, 0x08 /* Private */,
      59,    0,  453,    2, 0x08 /* Private */,
      60,    0,  454,    2, 0x08 /* Private */,
      61,    0,  455,    2, 0x08 /* Private */,
      62,    0,  456,    2, 0x08 /* Private */,
      63,    0,  457,    2, 0x08 /* Private */,
      64,    0,  458,    2, 0x08 /* Private */,
      65,    0,  459,    2, 0x08 /* Private */,
      66,    0,  460,    2, 0x08 /* Private */,
      67,    0,  461,    2, 0x08 /* Private */,
      68,    0,  462,    2, 0x08 /* Private */,
      69,    0,  463,    2, 0x08 /* Private */,
      70,    0,  464,    2, 0x08 /* Private */,
      71,    0,  465,    2, 0x08 /* Private */,
      72,    0,  466,    2, 0x08 /* Private */,
      73,    0,  467,    2, 0x08 /* Private */,
      74,    0,  468,    2, 0x08 /* Private */,
      75,    0,  469,    2, 0x08 /* Private */,
      76,    0,  470,    2, 0x08 /* Private */,
      77,    0,  471,    2, 0x08 /* Private */,
      78,    0,  472,    2, 0x08 /* Private */,
      79,    0,  473,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 28,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   30,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 53,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DaliMain::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DaliMain *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->comSetup(); break;
        case 1: _t->comConnect(); break;
        case 2: _t->comDisconnect(); break;
        case 3: _t->waitRxTimerShot(); break;
        case 4: _t->findMasterDevice(); break;
        case 5: _t->clearMonitorWindow(); break;
        case 6: _t->exchangeTimerShot(); break;
        case 7: _t->searchAddrStart(); break;
        case 8: _t->exchangeStop(); break;
        case 9: _t->clearDiscovered(); break;
        case 10: _t->typeVersionBtnClicked(); break;
        case 11: _t->exchangeProcess(); break;
        case 12: _t->addToTestButtonClick(); break;
        case 13: _t->addExtendedCmdToTestButtonClick(); break;
        case 14: _t->addTimeoutToTestButtonClick(); break;
        case 15: _t->addLoopStartToTestButtonClick(); break;
        case 16: _t->addLoopEndToTestButtonClick(); break;
        case 17: _t->loadTestSeqButtonClick(); break;
        case 18: _t->saveTestSeqButtonClick(); break;
        case 19: _t->removeFromTestButtonClick(); break;
        case 20: _t->clearAllTestButtonClick(); break;
        case 21: _t->testRunButtonClick(); break;
        case 22: _t->testStopButtonClick(); break;
        case 23: _t->sendCmdToPushButtonClicked(); break;
        case 24: _t->sendExtCmdToPushButtonClicked(); break;
        case 25: { uint8_t _r = _t->generateRandomByte();
            if (_a[0]) *reinterpret_cast< uint8_t*>(_a[0]) = std::move(_r); }  break;
        case 26: _t->updateBroadcastSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->sliderBroadcastRelease(); break;
        case 28: _t->updateRedSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->sliderRedReleased(); break;
        case 30: _t->updateGreenSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->sliderGreenReleased(); break;
        case 32: _t->updateBlueSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->sliderBlueReleased(); break;
        case 34: _t->sceneSetBtnClicked(); break;
        case 35: _t->sceneGoToBtnClicked(); break;
        case 36: _t->sceneQueryLvlBtnClicked(); break;
        case 37: _t->sceneRemoveBtnClicked(); break;
        case 38: _t->fadeTimeSetBtnClicked(); break;
        case 39: _t->fastFadeTimeSetBtnClicked(); break;
        case 40: _t->extendedFadeTimeSetBtnClicked(); break;
        case 41: _t->sendExtCmdEnableDeviceTypeClicked(); break;
        case 42: _t->readBank0BtnClick(); break;
        case 43: _t->readBank1BtnClick(); break;
        case 44: _t->writeFullBank1BtnClick(); break;
        case 45: _t->writeBank1BtnClick(); break;
        case 46: _t->memBank1FlashSaveBtnClick(); break;
        case 47: _t->specSelChanged(); break;
        case 48: _t->memBank1TableCellSelect((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 49: _t->mBank202ReadBtnClicked(); break;
        case 50: _t->mBank203ReadBtnClicked(); break;
        case 51: _t->mBank204ReadBtnClicked(); break;
        case 52: _t->mBank205ReadBtnClicked(); break;
        case 53: _t->mBank206ReadBtnClicked(); break;
        case 54: _t->mBank207ReadBtnClicked(); break;
        case 55: _t->slotDevAddrChanged(); break;
        case 56: _t->slotDevAddrChanged_3(); break;
        case 57: _t->mBank202SetLockBtnClicked(); break;
        case 58: _t->mBank203SetLockBtnClicked(); break;
        case 59: _t->mBank204SetLockBtnClicked(); break;
        case 60: _t->mBank205SetLockBtnClicked(); break;
        case 61: _t->mBank206SetLockBtnClicked(); break;
        case 62: _t->mBank207SetLockBtnClicked(); break;
        case 63: _t->mBank202ClrLockBtnClicked(); break;
        case 64: _t->mBank203ClrLockBtnClicked(); break;
        case 65: _t->mBank204ClrLockBtnClicked(); break;
        case 66: _t->mBank205ClrLockBtnClicked(); break;
        case 67: _t->mBank206ClrLockBtnClicked(); break;
        case 68: _t->mBank207ClrLockBtnClicked(); break;
        case 69: _t->bCastAddrCheckBoxClicked(); break;
        case 70: _t->extCmdsSpecSelChanged(); break;
        case 71: _t->stepWarmerSigProc(); break;
        case 72: _t->stepCoolerSigProc(); break;
        case 73: _t->setColourValSigProc(); break;
        case 74: _t->queryColorValSigProc(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DaliMain::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_DaliMain.data,
    qt_meta_data_DaliMain,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DaliMain::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DaliMain::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DaliMain.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int DaliMain::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 75)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 75;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 75)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 75;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
