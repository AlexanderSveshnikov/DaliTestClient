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
    QByteArrayData data[73];
    char stringdata0[1525];
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
QT_MOC_LITERAL(14, 197, 23), // "updateDaliDataSetSlider"
QT_MOC_LITERAL(15, 221, 9), // "sliderVal"
QT_MOC_LITERAL(16, 231, 30), // "updateExtCmdsDaliDataSetSlider"
QT_MOC_LITERAL(17, 262, 29), // "broadcastSendRadioButtonClick"
QT_MOC_LITERAL(18, 292, 25), // "groupSendRadioButtonClick"
QT_MOC_LITERAL(19, 318, 27), // "addressSendRadioButtonClick"
QT_MOC_LITERAL(20, 346, 26), // "sendCmdToPushButtonClicked"
QT_MOC_LITERAL(21, 373, 29), // "sendExtCmdToPushButtonClicked"
QT_MOC_LITERAL(22, 403, 18), // "generateRandomByte"
QT_MOC_LITERAL(23, 422, 7), // "uint8_t"
QT_MOC_LITERAL(24, 430, 21), // "updateBroadcastSlider"
QT_MOC_LITERAL(25, 452, 22), // "sliderBroadcastRelease"
QT_MOC_LITERAL(26, 475, 15), // "updateRedSlider"
QT_MOC_LITERAL(27, 491, 17), // "sliderRedReleased"
QT_MOC_LITERAL(28, 509, 17), // "updateGreenSlider"
QT_MOC_LITERAL(29, 527, 19), // "sliderGreenReleased"
QT_MOC_LITERAL(30, 547, 16), // "updateBlueSlider"
QT_MOC_LITERAL(31, 564, 18), // "sliderBlueReleased"
QT_MOC_LITERAL(32, 583, 16), // "colorButtonClick"
QT_MOC_LITERAL(33, 600, 17), // "updateValueSlider"
QT_MOC_LITERAL(34, 618, 15), // "updateHueSlider"
QT_MOC_LITERAL(35, 634, 22), // "updateSaturationSlider"
QT_MOC_LITERAL(36, 657, 25), // "sliderValHueSaturReleased"
QT_MOC_LITERAL(37, 683, 18), // "sceneSetBtnClicked"
QT_MOC_LITERAL(38, 702, 19), // "sceneGoToBtnClicked"
QT_MOC_LITERAL(39, 722, 23), // "sceneQueryLvlBtnClicked"
QT_MOC_LITERAL(40, 746, 21), // "sceneRemoveBtnClicked"
QT_MOC_LITERAL(41, 768, 21), // "fadeTimeSetBtnClicked"
QT_MOC_LITERAL(42, 790, 25), // "fastFadeTimeSetBtnClicked"
QT_MOC_LITERAL(43, 816, 29), // "extendedFadeTimeSetBtnClicked"
QT_MOC_LITERAL(44, 846, 33), // "sendExtCmdEnableDeviceTypeCli..."
QT_MOC_LITERAL(45, 880, 17), // "readBank0BtnClick"
QT_MOC_LITERAL(46, 898, 17), // "readBank1BtnClick"
QT_MOC_LITERAL(47, 916, 22), // "writeFullBank1BtnClick"
QT_MOC_LITERAL(48, 939, 18), // "writeBank1BtnClick"
QT_MOC_LITERAL(49, 958, 25), // "memBank1FlashSaveBtnClick"
QT_MOC_LITERAL(50, 984, 14), // "specSelChanged"
QT_MOC_LITERAL(51, 999, 23), // "memBank1TableCellSelect"
QT_MOC_LITERAL(52, 1023, 11), // "QModelIndex"
QT_MOC_LITERAL(53, 1035, 22), // "mBank202ReadBtnClicked"
QT_MOC_LITERAL(54, 1058, 22), // "mBank203ReadBtnClicked"
QT_MOC_LITERAL(55, 1081, 22), // "mBank204ReadBtnClicked"
QT_MOC_LITERAL(56, 1104, 22), // "mBank205ReadBtnClicked"
QT_MOC_LITERAL(57, 1127, 22), // "mBank206ReadBtnClicked"
QT_MOC_LITERAL(58, 1150, 22), // "mBank207ReadBtnClicked"
QT_MOC_LITERAL(59, 1173, 18), // "slotDevAddrChanged"
QT_MOC_LITERAL(60, 1192, 20), // "slotDevAddrChanged_3"
QT_MOC_LITERAL(61, 1213, 25), // "mBank202SetLockBtnClicked"
QT_MOC_LITERAL(62, 1239, 25), // "mBank203SetLockBtnClicked"
QT_MOC_LITERAL(63, 1265, 25), // "mBank204SetLockBtnClicked"
QT_MOC_LITERAL(64, 1291, 25), // "mBank205SetLockBtnClicked"
QT_MOC_LITERAL(65, 1317, 25), // "mBank206SetLockBtnClicked"
QT_MOC_LITERAL(66, 1343, 25), // "mBank207SetLockBtnClicked"
QT_MOC_LITERAL(67, 1369, 25), // "mBank202ClrLockBtnClicked"
QT_MOC_LITERAL(68, 1395, 25), // "mBank203ClrLockBtnClicked"
QT_MOC_LITERAL(69, 1421, 25), // "mBank204ClrLockBtnClicked"
QT_MOC_LITERAL(70, 1447, 25), // "mBank205ClrLockBtnClicked"
QT_MOC_LITERAL(71, 1473, 25), // "mBank206ClrLockBtnClicked"
QT_MOC_LITERAL(72, 1499, 25) // "mBank207ClrLockBtnClicked"

    },
    "DaliMain\0comSetup\0\0comConnect\0"
    "comDisconnect\0waitRxTimerShot\0"
    "findMasterDevice\0clearMonitorWindow\0"
    "exchangeTimerShot\0searchAddrStart\0"
    "exchangeStop\0clearDiscovered\0"
    "typeVersionBtnClicked\0exchangeProcess\0"
    "updateDaliDataSetSlider\0sliderVal\0"
    "updateExtCmdsDaliDataSetSlider\0"
    "broadcastSendRadioButtonClick\0"
    "groupSendRadioButtonClick\0"
    "addressSendRadioButtonClick\0"
    "sendCmdToPushButtonClicked\0"
    "sendExtCmdToPushButtonClicked\0"
    "generateRandomByte\0uint8_t\0"
    "updateBroadcastSlider\0sliderBroadcastRelease\0"
    "updateRedSlider\0sliderRedReleased\0"
    "updateGreenSlider\0sliderGreenReleased\0"
    "updateBlueSlider\0sliderBlueReleased\0"
    "colorButtonClick\0updateValueSlider\0"
    "updateHueSlider\0updateSaturationSlider\0"
    "sliderValHueSaturReleased\0sceneSetBtnClicked\0"
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
    "mBank207ClrLockBtnClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DaliMain[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      68,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  354,    2, 0x08 /* Private */,
       3,    0,  355,    2, 0x08 /* Private */,
       4,    0,  356,    2, 0x08 /* Private */,
       5,    0,  357,    2, 0x08 /* Private */,
       6,    0,  358,    2, 0x08 /* Private */,
       7,    0,  359,    2, 0x08 /* Private */,
       8,    0,  360,    2, 0x08 /* Private */,
       9,    0,  361,    2, 0x08 /* Private */,
      10,    0,  362,    2, 0x08 /* Private */,
      11,    0,  363,    2, 0x08 /* Private */,
      12,    0,  364,    2, 0x08 /* Private */,
      13,    0,  365,    2, 0x08 /* Private */,
      14,    1,  366,    2, 0x08 /* Private */,
      16,    1,  369,    2, 0x08 /* Private */,
      17,    0,  372,    2, 0x08 /* Private */,
      18,    0,  373,    2, 0x08 /* Private */,
      19,    0,  374,    2, 0x08 /* Private */,
      20,    0,  375,    2, 0x08 /* Private */,
      21,    0,  376,    2, 0x08 /* Private */,
      22,    0,  377,    2, 0x08 /* Private */,
      24,    1,  378,    2, 0x08 /* Private */,
      25,    0,  381,    2, 0x08 /* Private */,
      26,    1,  382,    2, 0x08 /* Private */,
      27,    0,  385,    2, 0x08 /* Private */,
      28,    1,  386,    2, 0x08 /* Private */,
      29,    0,  389,    2, 0x08 /* Private */,
      30,    1,  390,    2, 0x08 /* Private */,
      31,    0,  393,    2, 0x08 /* Private */,
      32,    0,  394,    2, 0x08 /* Private */,
      33,    1,  395,    2, 0x08 /* Private */,
      34,    1,  398,    2, 0x08 /* Private */,
      35,    1,  401,    2, 0x08 /* Private */,
      36,    0,  404,    2, 0x08 /* Private */,
      37,    0,  405,    2, 0x08 /* Private */,
      38,    0,  406,    2, 0x08 /* Private */,
      39,    0,  407,    2, 0x08 /* Private */,
      40,    0,  408,    2, 0x08 /* Private */,
      41,    0,  409,    2, 0x08 /* Private */,
      42,    0,  410,    2, 0x08 /* Private */,
      43,    0,  411,    2, 0x08 /* Private */,
      44,    0,  412,    2, 0x08 /* Private */,
      45,    0,  413,    2, 0x08 /* Private */,
      46,    0,  414,    2, 0x08 /* Private */,
      47,    0,  415,    2, 0x08 /* Private */,
      48,    0,  416,    2, 0x08 /* Private */,
      49,    0,  417,    2, 0x08 /* Private */,
      50,    0,  418,    2, 0x08 /* Private */,
      51,    1,  419,    2, 0x08 /* Private */,
      53,    0,  422,    2, 0x08 /* Private */,
      54,    0,  423,    2, 0x08 /* Private */,
      55,    0,  424,    2, 0x08 /* Private */,
      56,    0,  425,    2, 0x08 /* Private */,
      57,    0,  426,    2, 0x08 /* Private */,
      58,    0,  427,    2, 0x08 /* Private */,
      59,    0,  428,    2, 0x08 /* Private */,
      60,    0,  429,    2, 0x08 /* Private */,
      61,    0,  430,    2, 0x08 /* Private */,
      62,    0,  431,    2, 0x08 /* Private */,
      63,    0,  432,    2, 0x08 /* Private */,
      64,    0,  433,    2, 0x08 /* Private */,
      65,    0,  434,    2, 0x08 /* Private */,
      66,    0,  435,    2, 0x08 /* Private */,
      67,    0,  436,    2, 0x08 /* Private */,
      68,    0,  437,    2, 0x08 /* Private */,
      69,    0,  438,    2, 0x08 /* Private */,
      70,    0,  439,    2, 0x08 /* Private */,
      71,    0,  440,    2, 0x08 /* Private */,
      72,    0,  441,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    0x80000000 | 23,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
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
    QMetaType::Void, 0x80000000 | 52,    2,
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
        case 12: _t->updateDaliDataSetSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->updateExtCmdsDaliDataSetSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->broadcastSendRadioButtonClick(); break;
        case 15: _t->groupSendRadioButtonClick(); break;
        case 16: _t->addressSendRadioButtonClick(); break;
        case 17: _t->sendCmdToPushButtonClicked(); break;
        case 18: _t->sendExtCmdToPushButtonClicked(); break;
        case 19: { uint8_t _r = _t->generateRandomByte();
            if (_a[0]) *reinterpret_cast< uint8_t*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->updateBroadcastSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->sliderBroadcastRelease(); break;
        case 22: _t->updateRedSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->sliderRedReleased(); break;
        case 24: _t->updateGreenSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->sliderGreenReleased(); break;
        case 26: _t->updateBlueSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->sliderBlueReleased(); break;
        case 28: _t->colorButtonClick(); break;
        case 29: _t->updateValueSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->updateHueSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->updateSaturationSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->sliderValHueSaturReleased(); break;
        case 33: _t->sceneSetBtnClicked(); break;
        case 34: _t->sceneGoToBtnClicked(); break;
        case 35: _t->sceneQueryLvlBtnClicked(); break;
        case 36: _t->sceneRemoveBtnClicked(); break;
        case 37: _t->fadeTimeSetBtnClicked(); break;
        case 38: _t->fastFadeTimeSetBtnClicked(); break;
        case 39: _t->extendedFadeTimeSetBtnClicked(); break;
        case 40: _t->sendExtCmdEnableDeviceTypeClicked(); break;
        case 41: _t->readBank0BtnClick(); break;
        case 42: _t->readBank1BtnClick(); break;
        case 43: _t->writeFullBank1BtnClick(); break;
        case 44: _t->writeBank1BtnClick(); break;
        case 45: _t->memBank1FlashSaveBtnClick(); break;
        case 46: _t->specSelChanged(); break;
        case 47: _t->memBank1TableCellSelect((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 48: _t->mBank202ReadBtnClicked(); break;
        case 49: _t->mBank203ReadBtnClicked(); break;
        case 50: _t->mBank204ReadBtnClicked(); break;
        case 51: _t->mBank205ReadBtnClicked(); break;
        case 52: _t->mBank206ReadBtnClicked(); break;
        case 53: _t->mBank207ReadBtnClicked(); break;
        case 54: _t->slotDevAddrChanged(); break;
        case 55: _t->slotDevAddrChanged_3(); break;
        case 56: _t->mBank202SetLockBtnClicked(); break;
        case 57: _t->mBank203SetLockBtnClicked(); break;
        case 58: _t->mBank204SetLockBtnClicked(); break;
        case 59: _t->mBank205SetLockBtnClicked(); break;
        case 60: _t->mBank206SetLockBtnClicked(); break;
        case 61: _t->mBank207SetLockBtnClicked(); break;
        case 62: _t->mBank202ClrLockBtnClicked(); break;
        case 63: _t->mBank203ClrLockBtnClicked(); break;
        case 64: _t->mBank204ClrLockBtnClicked(); break;
        case 65: _t->mBank205ClrLockBtnClicked(); break;
        case 66: _t->mBank206ClrLockBtnClicked(); break;
        case 67: _t->mBank207ClrLockBtnClicked(); break;
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
        if (_id < 68)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 68;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 68)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 68;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
