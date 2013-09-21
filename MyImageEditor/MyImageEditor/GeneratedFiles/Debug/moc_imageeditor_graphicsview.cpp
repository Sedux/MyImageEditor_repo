/****************************************************************************
** Meta object code from reading C++ file 'imageeditor_graphicsview.hpp'
**
** Created: Mon 9. Sep 00:10:12 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ui/imageeditor_graphicsview.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageeditor_graphicsview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CImageEditorGraphicsView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      53,   26,   25,   25, 0x05,
     105,   88,   25,   25, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_CImageEditorGraphicsView[] = {
    "CImageEditorGraphicsView\0\0"
    "f_originGlobal,f_100Global\0"
    "graphicsViewRedrawn(QPoint,QPoint)\0"
    "f_mousePosGlobal\0curMousePos(QPoint)\0"
};

void CImageEditorGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CImageEditorGraphicsView *_t = static_cast<CImageEditorGraphicsView *>(_o);
        switch (_id) {
        case 0: _t->graphicsViewRedrawn((*reinterpret_cast< const QPoint(*)>(_a[1])),(*reinterpret_cast< const QPoint(*)>(_a[2]))); break;
        case 1: _t->curMousePos((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CImageEditorGraphicsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CImageEditorGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_CImageEditorGraphicsView,
      qt_meta_data_CImageEditorGraphicsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CImageEditorGraphicsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CImageEditorGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CImageEditorGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CImageEditorGraphicsView))
        return static_cast<void*>(const_cast< CImageEditorGraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int CImageEditorGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CImageEditorGraphicsView::graphicsViewRedrawn(const QPoint & _t1, const QPoint & _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CImageEditorGraphicsView::curMousePos(const QPoint & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
