/****************************************************************************
** Meta object code from reading C++ file 'imageeditorview_wrpr.hpp'
**
** Created: Sun 28. Jul 16:18:29 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/dockwidgets/imageeditorview_wrpr.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageeditorview_wrpr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CImageEditorViewWrpr[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   21,   21,   21, 0x08,
      55,   47,   21,   21, 0x08,
      75,   21,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CImageEditorViewWrpr[] = {
    "CImageEditorViewWrpr\0\0genHistogramBtnClicked()\0"
    "f_image\0updateImage(QImage)\0reloadImage()\0"
};

void CImageEditorViewWrpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CImageEditorViewWrpr *_t = static_cast<CImageEditorViewWrpr *>(_o);
        switch (_id) {
        case 0: _t->genHistogramBtnClicked(); break;
        case 1: _t->updateImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->reloadImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CImageEditorViewWrpr::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CImageEditorViewWrpr::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CImageEditorViewWrpr,
      qt_meta_data_CImageEditorViewWrpr, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CImageEditorViewWrpr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CImageEditorViewWrpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CImageEditorViewWrpr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CImageEditorViewWrpr))
        return static_cast<void*>(const_cast< CImageEditorViewWrpr*>(this));
    if (!strcmp(_clname, "IDckWidget"))
        return static_cast< IDckWidget*>(const_cast< CImageEditorViewWrpr*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CImageEditorViewWrpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE