/****************************************************************************
** Meta object code from reading C++ file 'messageform.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inc/messageform.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'messageform.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MessageForm_t {
    QByteArrayData data[10];
    char stringdata0[91];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MessageForm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MessageForm_t qt_meta_stringdata_MessageForm = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MessageForm"
QT_MOC_LITERAL(1, 12, 8), // "setTitle"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "title"
QT_MOC_LITERAL(4, 28, 7), // "setText"
QT_MOC_LITERAL(5, 36, 3), // "str"
QT_MOC_LITERAL(6, 40, 8), // "setLabel"
QT_MOC_LITERAL(7, 49, 11), // "proButtonOK"
QT_MOC_LITERAL(8, 61, 13), // "proButtonFail"
QT_MOC_LITERAL(9, 75, 15) // "proButtonCancel"

    },
    "MessageForm\0setTitle\0\0title\0setText\0"
    "str\0setLabel\0proButtonOK\0proButtonFail\0"
    "proButtonCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MessageForm[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x0a /* Public */,
       4,    1,   47,    2, 0x0a /* Public */,
       6,    1,   50,    2, 0x0a /* Public */,
       7,    0,   53,    2, 0x08 /* Private */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MessageForm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MessageForm *_t = static_cast<MessageForm *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setText((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setLabel((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->proButtonOK(); break;
        case 4: _t->proButtonFail(); break;
        case 5: _t->proButtonCancel(); break;
        default: ;
        }
    }
}

const QMetaObject MessageForm::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_MessageForm.data,
      qt_meta_data_MessageForm,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MessageForm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MessageForm::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MessageForm.stringdata0))
        return static_cast<void*>(const_cast< MessageForm*>(this));
    return QDialog::qt_metacast(_clname);
}

int MessageForm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
