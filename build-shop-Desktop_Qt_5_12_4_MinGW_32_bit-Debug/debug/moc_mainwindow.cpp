/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../shopy(26.11.2023)/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[245];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 15), // "openYouTubeLink"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "openVkLink"
QT_MOC_LITERAL(4, 39, 10), // "openTgLink"
QT_MOC_LITERAL(5, 50, 15), // "showPrinterForm"
QT_MOC_LITERAL(6, 66, 17), // "showCartridgeForm"
QT_MOC_LITERAL(7, 84, 11), // "showInkForm"
QT_MOC_LITERAL(8, 96, 6), // "goBack"
QT_MOC_LITERAL(9, 103, 12), // "loadSettings"
QT_MOC_LITERAL(10, 116, 12), // "saveSettings"
QT_MOC_LITERAL(11, 129, 9), // "About_uss"
QT_MOC_LITERAL(12, 139, 6), // "Helper"
QT_MOC_LITERAL(13, 146, 8), // "FeedBack"
QT_MOC_LITERAL(14, 155, 8), // "OurShops"
QT_MOC_LITERAL(15, 164, 32), // "on_actionOpenTableForm_triggered"
QT_MOC_LITERAL(16, 197, 19), // "onCartButtonClicked"
QT_MOC_LITERAL(17, 217, 19), // "onUserAuthenticated"
QT_MOC_LITERAL(18, 237, 7) // "isAdmin"

    },
    "MainWindow\0openYouTubeLink\0\0openVkLink\0"
    "openTgLink\0showPrinterForm\0showCartridgeForm\0"
    "showInkForm\0goBack\0loadSettings\0"
    "saveSettings\0About_uss\0Helper\0FeedBack\0"
    "OurShops\0on_actionOpenTableForm_triggered\0"
    "onCartButtonClicked\0onUserAuthenticated\0"
    "isAdmin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x08 /* Private */,
       6,    0,   98,    2, 0x08 /* Private */,
       7,    0,   99,    2, 0x08 /* Private */,
       8,    0,  100,    2, 0x08 /* Private */,
       9,    0,  101,    2, 0x08 /* Private */,
      10,    0,  102,    2, 0x08 /* Private */,
      11,    0,  103,    2, 0x08 /* Private */,
      12,    0,  104,    2, 0x08 /* Private */,
      13,    0,  105,    2, 0x08 /* Private */,
      14,    0,  106,    2, 0x08 /* Private */,
      15,    0,  107,    2, 0x08 /* Private */,
      16,    0,  108,    2, 0x08 /* Private */,
      17,    1,  109,    2, 0x08 /* Private */,

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
    QMetaType::Void, QMetaType::Bool,   18,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->openYouTubeLink(); break;
        case 1: _t->openVkLink(); break;
        case 2: _t->openTgLink(); break;
        case 3: _t->showPrinterForm(); break;
        case 4: _t->showCartridgeForm(); break;
        case 5: _t->showInkForm(); break;
        case 6: _t->goBack(); break;
        case 7: _t->loadSettings(); break;
        case 8: _t->saveSettings(); break;
        case 9: _t->About_uss(); break;
        case 10: _t->Helper(); break;
        case 11: _t->FeedBack(); break;
        case 12: _t->OurShops(); break;
        case 13: _t->on_actionOpenTableForm_triggered(); break;
        case 14: _t->onCartButtonClicked(); break;
        case 15: _t->onUserAuthenticated((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
