/****************************************************************************
** Meta object code from reading C++ file 'imageprocessingtoolsview_wrpr.hpp'
**
** Created: Sun 11. Aug 22:28:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/dockwidgets/imageprocessingtoolsview_wrpr.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'imageprocessingtoolsview_wrpr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CImageProcessingToolsViewWrpr[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      49,   31,   30,   30, 0x05,

 // slots: signature, parameters, type, tag, flags
      79,   30,   30,   30, 0x08,
     104,   30,   30,   30, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CImageProcessingToolsViewWrpr[] = {
    "CImageProcessingToolsViewWrpr\0\0"
    "f_imageEditParams\0reloadImage(CImageEditParams)\0"
    "genHistogramBtnClicked()\0doReloadImage()\0"
};

void CImageProcessingToolsViewWrpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CImageProcessingToolsViewWrpr *_t = static_cast<CImageProcessingToolsViewWrpr *>(_o);
        switch (_id) {
        case 0: _t->reloadImage((*reinterpret_cast< const CImageEditParams(*)>(_a[1]))); break;
        case 1: _t->genHistogramBtnClicked(); break;
        case 2: _t->doReloadImage(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CImageProcessingToolsViewWrpr::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CImageProcessingToolsViewWrpr::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CImageProcessingToolsViewWrpr,
      qt_meta_data_CImageProcessingToolsViewWrpr, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CImageProcessingToolsViewWrpr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CImageProcessingToolsViewWrpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CImageProcessingToolsViewWrpr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CImageProcessingToolsViewWrpr))
        return static_cast<void*>(const_cast< CImageProcessingToolsViewWrpr*>(this));
    if (!strcmp(_clname, "IDckWidget"))
        return static_cast< IDckWidget*>(const_cast< CImageProcessingToolsViewWrpr*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CImageProcessingToolsViewWrpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void CImageProcessingToolsViewWrpr::reloadImage(const CImageEditParams & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
