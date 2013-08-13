/****************************************************************************
** Meta object code from reading C++ file 'ruler_widget.hpp'
**
** Created: Wed 14. Aug 01:00:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ui/ruler_widget.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ruler_widget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CRulerWidget[] = {

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
      38,   14,   13,   13, 0x0a,
      79,   73,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CRulerWidget[] = {
    "CRulerWidget\0\0f_orgGlobal,f_100Global\0"
    "graphicsViewRedrawn(QPoint,QPoint)\0"
    "f_pos\0setCurrentPos(QPoint)\0"
};

void CRulerWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CRulerWidget *_t = static_cast<CRulerWidget *>(_o);
        switch (_id) {
        case 0: _t->graphicsViewRedrawn((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 1: _t->setCurrentPos((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CRulerWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CRulerWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_CRulerWidget,
      qt_meta_data_CRulerWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CRulerWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CRulerWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CRulerWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CRulerWidget))
        return static_cast<void*>(const_cast< CRulerWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int CRulerWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
