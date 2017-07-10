/****************************************************************************
** Meta object code from reading C++ file 'ViewBookWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ViewBookWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ViewBookWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ViewBookWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      16,   15,   15,   15, 0x08,
      29,   15,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ViewBookWidget[] = {
    "ViewBookWidget\0\0removeItem()\0endLoan()\0"
};

void ViewBookWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ViewBookWidget *_t = static_cast<ViewBookWidget *>(_o);
        switch (_id) {
        case 0: _t->removeItem(); break;
        case 1: _t->endLoan(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData ViewBookWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ViewBookWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ViewBookWidget,
      qt_meta_data_ViewBookWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ViewBookWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ViewBookWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ViewBookWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ViewBookWidget))
        return static_cast<void*>(const_cast< ViewBookWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int ViewBookWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
