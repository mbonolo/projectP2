/****************************************************************************
** Meta object code from reading C++ file 'InsertBookWidget.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "InsertBookWidget.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InsertBookWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_InsertBookWidget[] = {

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
      18,   17,   17,   17, 0x08,
      31,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_InsertBookWidget[] = {
    "InsertBookWidget\0\0renderForm()\0"
    "insertItem()\0"
};

void InsertBookWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        InsertBookWidget *_t = static_cast<InsertBookWidget *>(_o);
        switch (_id) {
        case 0: _t->renderForm(); break;
        case 1: _t->insertItem(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData InsertBookWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject InsertBookWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_InsertBookWidget,
      qt_meta_data_InsertBookWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &InsertBookWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *InsertBookWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *InsertBookWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_InsertBookWidget))
        return static_cast<void*>(const_cast< InsertBookWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int InsertBookWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
