/****************************************************************************
** Meta object code from reading C++ file 'Control.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/Control.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Control.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Control_t {
    QByteArrayData data[17];
    char stringdata0[257];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Control_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Control_t qt_meta_stringdata_Control = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Control"
QT_MOC_LITERAL(1, 8, 14), // "start_mem_test"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 14), // "start_usb_test"
QT_MOC_LITERAL(4, 39, 14), // "start_net_test"
QT_MOC_LITERAL(5, 54, 15), // "start_edid_test"
QT_MOC_LITERAL(6, 70, 14), // "start_cpu_test"
QT_MOC_LITERAL(7, 85, 14), // "start_hdd_test"
QT_MOC_LITERAL(8, 100, 14), // "start_fan_test"
QT_MOC_LITERAL(9, 115, 15), // "start_wifi_test"
QT_MOC_LITERAL(10, 131, 16), // "start_sound_test"
QT_MOC_LITERAL(11, 148, 18), // "start_display_test"
QT_MOC_LITERAL(12, 167, 17), // "start_bright_test"
QT_MOC_LITERAL(13, 185, 17), // "start_camera_test"
QT_MOC_LITERAL(14, 203, 17), // "start_stress_test"
QT_MOC_LITERAL(15, 221, 16), // "start_upload_log"
QT_MOC_LITERAL(16, 238, 18) // "start_next_process"

    },
    "Control\0start_mem_test\0\0start_usb_test\0"
    "start_net_test\0start_edid_test\0"
    "start_cpu_test\0start_hdd_test\0"
    "start_fan_test\0start_wifi_test\0"
    "start_sound_test\0start_display_test\0"
    "start_bright_test\0start_camera_test\0"
    "start_stress_test\0start_upload_log\0"
    "start_next_process"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Control[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x0a /* Public */,
       3,    0,   90,    2, 0x0a /* Public */,
       4,    0,   91,    2, 0x0a /* Public */,
       5,    0,   92,    2, 0x0a /* Public */,
       6,    0,   93,    2, 0x0a /* Public */,
       7,    0,   94,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    0,   98,    2, 0x0a /* Public */,
      12,    0,   99,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    0,  101,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      16,    0,  103,    2, 0x0a /* Public */,

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

       0        // eod
};

void Control::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Control *_t = static_cast<Control *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->start_mem_test(); break;
        case 1: _t->start_usb_test(); break;
        case 2: _t->start_net_test(); break;
        case 3: _t->start_edid_test(); break;
        case 4: _t->start_cpu_test(); break;
        case 5: _t->start_hdd_test(); break;
        case 6: _t->start_fan_test(); break;
        case 7: _t->start_wifi_test(); break;
        case 8: _t->start_sound_test(); break;
        case 9: _t->start_display_test(); break;
        case 10: _t->start_bright_test(); break;
        case 11: _t->start_camera_test(); break;
        case 12: _t->start_stress_test(); break;
        case 13: _t->start_upload_log(); break;
        case 14: _t->start_next_process(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Control::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Control.data,
      qt_meta_data_Control,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Control::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Control::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Control.stringdata0))
        return static_cast<void*>(const_cast< Control*>(this));
    return QObject::qt_metacast(_clname);
}

int Control::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
