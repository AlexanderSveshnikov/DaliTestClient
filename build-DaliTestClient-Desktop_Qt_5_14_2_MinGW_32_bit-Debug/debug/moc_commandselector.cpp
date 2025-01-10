/****************************************************************************
** Meta object code from reading C++ file 'commandselector.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../DaliTestClient/commandselector.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'commandselector.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CommandSelector_t {
    QByteArrayData data[8];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CommandSelector_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CommandSelector_t qt_meta_stringdata_CommandSelector = {
    {
QT_MOC_LITERAL(0, 0, 15), // "CommandSelector"
QT_MOC_LITERAL(1, 16, 14), // "specChangedSgn"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 23), // "updateDaliDataSetSlider"
QT_MOC_LITERAL(4, 56, 9), // "sliderVal"
QT_MOC_LITERAL(5, 66, 21), // "extCmdsSpecSelChanged"
QT_MOC_LITERAL(6, 88, 22), // "dataDecEditTextChanged"
QT_MOC_LITERAL(7, 111, 22) // "dataHexEditTextChanged"

    },
    "CommandSelector\0specChangedSgn\0\0"
    "updateDaliDataSetSlider\0sliderVal\0"
    "extCmdsSpecSelChanged\0dataDecEditTextChanged\0"
    "dataHexEditTextChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CommandSelector[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   40,    2, 0x08 /* Private */,
       5,    0,   43,    2, 0x08 /* Private */,
       6,    0,   44,    2, 0x08 /* Private */,
       7,    0,   45,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CommandSelector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CommandSelector *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->specChangedSgn(); break;
        case 1: _t->updateDaliDataSetSlider((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->extCmdsSpecSelChanged(); break;
        case 3: _t->dataDecEditTextChanged(); break;
        case 4: _t->dataHexEditTextChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CommandSelector::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CommandSelector::specChangedSgn)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CommandSelector::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_CommandSelector.data,
    qt_meta_data_CommandSelector,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CommandSelector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CommandSelector::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CommandSelector.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int CommandSelector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void CommandSelector::specChangedSgn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
