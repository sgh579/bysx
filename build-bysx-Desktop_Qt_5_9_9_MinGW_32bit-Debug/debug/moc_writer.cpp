/****************************************************************************
** Meta object code from reading C++ file 'writer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../bysx/writer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'writer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_writer_t {
    QByteArrayData data[8];
    char stringdata0[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_writer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_writer_t qt_meta_stringdata_writer = {
    {
QT_MOC_LITERAL(0, 0, 6), // "writer"
QT_MOC_LITERAL(1, 7, 18), // "handleBytesWritten"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "bytes"
QT_MOC_LITERAL(4, 33, 13), // "handleTimeout"
QT_MOC_LITERAL(5, 47, 11), // "handleError"
QT_MOC_LITERAL(6, 59, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(7, 88, 5) // "error"

    },
    "writer\0handleBytesWritten\0\0bytes\0"
    "handleTimeout\0handleError\0"
    "QSerialPort::SerialPortError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_writer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    1,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void writer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        writer *_t = static_cast<writer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->handleBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->handleTimeout(); break;
        case 2: _t->handleError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject writer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_writer.data,
      qt_meta_data_writer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *writer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *writer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_writer.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int writer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_WARNING_POP
QT_END_MOC_NAMESPACE
