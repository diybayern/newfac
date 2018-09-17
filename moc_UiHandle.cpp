/****************************************************************************
** Meta object code from reading C++ file 'UiHandle.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/UiHandle.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'UiHandle.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UiHandle_t {
    QByteArrayData data[8];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_UiHandle_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_UiHandle_t qt_meta_stringdata_UiHandle = {
    {
QT_MOC_LITERAL(0, 0, 8), // "UiHandle"
QT_MOC_LITERAL(1, 9, 24), // "to_draw_main_test_window"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 22), // "need_to_show_main_test"
QT_MOC_LITERAL(4, 58, 12), // "print_result"
QT_MOC_LITERAL(5, 71, 4), // "func"
QT_MOC_LITERAL(6, 76, 6), // "result"
QT_MOC_LITERAL(7, 83, 3) // "log"

    },
    "UiHandle\0to_draw_main_test_window\0\0"
    "need_to_show_main_test\0print_result\0"
    "func\0result\0log"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UiHandle[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,
       4,    3,   31,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,    5,    6,    7,

       0        // eod
};

void UiHandle::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        UiHandle *_t = static_cast<UiHandle *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->to_draw_main_test_window(); break;
        case 1: _t->need_to_show_main_test(); break;
        case 2: _t->print_result((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (UiHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiHandle::to_draw_main_test_window)) {
                *result = 0;
            }
        }
        {
            typedef void (UiHandle::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiHandle::need_to_show_main_test)) {
                *result = 1;
            }
        }
        {
            typedef void (UiHandle::*_t)(QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&UiHandle::print_result)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject UiHandle::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_UiHandle.data,
      qt_meta_data_UiHandle,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *UiHandle::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UiHandle::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_UiHandle.stringdata0))
        return static_cast<void*>(const_cast< UiHandle*>(this));
    return QObject::qt_metacast(_clname);
}

int UiHandle::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UiHandle::to_draw_main_test_window()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void UiHandle::need_to_show_main_test()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void UiHandle::print_result(QString _t1, QString _t2, QString _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
