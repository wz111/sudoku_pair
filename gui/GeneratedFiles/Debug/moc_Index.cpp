/****************************************************************************
** Meta object code from reading C++ file 'Index.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Index.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Index.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Index_t {
    QByteArrayData data[20];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Index_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Index_t qt_meta_stringdata_Index = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Index"
QT_MOC_LITERAL(1, 6, 8), // "hideMain"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 10), // "sudokuShow"
QT_MOC_LITERAL(4, 27, 8), // "showMain"
QT_MOC_LITERAL(5, 36, 10), // "sudokuHide"
QT_MOC_LITERAL(6, 47, 8), // "startNew"
QT_MOC_LITERAL(7, 56, 8), // "backMain"
QT_MOC_LITERAL(8, 65, 9), // "showIntro"
QT_MOC_LITERAL(9, 75, 9), // "hideIntro"
QT_MOC_LITERAL(10, 85, 11), // "showSetting"
QT_MOC_LITERAL(11, 97, 11), // "hideSetting"
QT_MOC_LITERAL(12, 109, 14), // "changeBtnGroup"
QT_MOC_LITERAL(13, 124, 2), // "id"
QT_MOC_LITERAL(14, 127, 8), // "showMode"
QT_MOC_LITERAL(15, 136, 13), // "showModeStart"
QT_MOC_LITERAL(16, 150, 9), // "backQuery"
QT_MOC_LITERAL(17, 160, 10), // "updateTime"
QT_MOC_LITERAL(18, 171, 10), // "startTimer"
QT_MOC_LITERAL(19, 182, 9) // "stopTimer"

    },
    "Index\0hideMain\0\0sudokuShow\0showMain\0"
    "sudokuHide\0startNew\0backMain\0showIntro\0"
    "hideIntro\0showSetting\0hideSetting\0"
    "changeBtnGroup\0id\0showMode\0showModeStart\0"
    "backQuery\0updateTime\0startTimer\0"
    "stopTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Index[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    0,  103,    2, 0x0a /* Public */,
       7,    0,  104,    2, 0x0a /* Public */,
       8,    0,  105,    2, 0x0a /* Public */,
       9,    0,  106,    2, 0x0a /* Public */,
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    1,  109,    2, 0x0a /* Public */,
      14,    0,  112,    2, 0x0a /* Public */,
      15,    0,  113,    2, 0x0a /* Public */,
      16,    0,  114,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,
      18,    0,  116,    2, 0x0a /* Public */,
      19,    0,  117,    2, 0x0a /* Public */,

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
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Index::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Index *_t = static_cast<Index *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->hideMain(); break;
        case 1: _t->sudokuShow(); break;
        case 2: _t->showMain(); break;
        case 3: _t->sudokuHide(); break;
        case 4: _t->startNew(); break;
        case 5: _t->backMain(); break;
        case 6: _t->showIntro(); break;
        case 7: _t->hideIntro(); break;
        case 8: _t->showSetting(); break;
        case 9: _t->hideSetting(); break;
        case 10: _t->changeBtnGroup((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->showMode(); break;
        case 12: _t->showModeStart(); break;
        case 13: _t->backQuery(); break;
        case 14: _t->updateTime(); break;
        case 15: _t->startTimer(); break;
        case 16: _t->stopTimer(); break;
        default: ;
        }
    }
}

const QMetaObject Index::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Index.data,
      qt_meta_data_Index,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Index::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Index::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Index.stringdata0))
        return static_cast<void*>(const_cast< Index*>(this));
    return QObject::qt_metacast(_clname);
}

int Index::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
