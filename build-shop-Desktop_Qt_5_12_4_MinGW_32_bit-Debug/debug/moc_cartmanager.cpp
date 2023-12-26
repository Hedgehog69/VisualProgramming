/****************************************************************************
** Meta object code from reading C++ file 'cartmanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shopy(26.11.2023)/cartmanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cartmanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CartManager_t {
    QByteArrayData data[13];
    char stringdata0[202];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CartManager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CartManager_t qt_meta_stringdata_CartManager = {
    {
QT_MOC_LITERAL(0, 0, 11), // "CartManager"
QT_MOC_LITERAL(1, 12, 11), // "cartUpdated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 12), // "itemsRemoved"
QT_MOC_LITERAL(4, 38, 17), // "QMap<QString,int>"
QT_MOC_LITERAL(5, 56, 13), // "itemsToRemove"
QT_MOC_LITERAL(6, 70, 22), // "startBuyGoodsFormTimer"
QT_MOC_LITERAL(7, 93, 12), // "milliseconds"
QT_MOC_LITERAL(8, 106, 23), // "on_removeButton_clicked"
QT_MOC_LITERAL(9, 130, 16), // "openBuyGoodsForm"
QT_MOC_LITERAL(10, 147, 14), // "updateProgress"
QT_MOC_LITERAL(11, 162, 17), // "handleDataChanged"
QT_MOC_LITERAL(12, 180, 21) // "on_doneButton_clicked"

    },
    "CartManager\0cartUpdated\0\0itemsRemoved\0"
    "QMap<QString,int>\0itemsToRemove\0"
    "startBuyGoodsFormTimer\0milliseconds\0"
    "on_removeButton_clicked\0openBuyGoodsForm\0"
    "updateProgress\0handleDataChanged\0"
    "on_doneButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CartManager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,
       3,    1,   55,    2, 0x06 /* Public */,
       6,    1,   58,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   61,    2, 0x08 /* Private */,
       9,    0,   62,    2, 0x08 /* Private */,
      10,    0,   63,    2, 0x08 /* Private */,
      11,    0,   64,    2, 0x0a /* Public */,
      12,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CartManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CartManager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cartUpdated(); break;
        case 1: _t->itemsRemoved((*reinterpret_cast< const QMap<QString,int>(*)>(_a[1]))); break;
        case 2: _t->startBuyGoodsFormTimer((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_removeButton_clicked(); break;
        case 4: _t->openBuyGoodsForm(); break;
        case 5: _t->updateProgress(); break;
        case 6: _t->handleDataChanged(); break;
        case 7: _t->on_doneButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (CartManager::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CartManager::cartUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (CartManager::*)(const QMap<QString,int> & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CartManager::itemsRemoved)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (CartManager::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&CartManager::startBuyGoodsFormTimer)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CartManager::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_CartManager.data,
    qt_meta_data_CartManager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CartManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CartManager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CartManager.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CartManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void CartManager::cartUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void CartManager::itemsRemoved(const QMap<QString,int> & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CartManager::startBuyGoodsFormTimer(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
