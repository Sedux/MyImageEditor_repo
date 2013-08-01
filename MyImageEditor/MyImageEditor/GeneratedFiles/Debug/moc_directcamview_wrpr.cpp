/****************************************************************************
** Meta object code from reading C++ file 'directcamview_wrpr.hpp'
**
** Created: Fri 26. Jul 03:18:40 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/dockwidgets/directcamview_wrpr.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'directcamview_wrpr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDirectCamViewWrpr[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      42,   19,   19,   19, 0x08,
      58,   19,   19,   19, 0x08,
      78,   19,   19,   19, 0x08,
     103,   19,   19,   19, 0x08,
     124,   19,   19,   19, 0x08,
     154,  146,   19,   19, 0x08,
     178,   19,   19,   19, 0x08,
     196,   19,   19,   19, 0x08,
     218,  212,   19,   19, 0x08,
     241,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_CDirectCamViewWrpr[] = {
    "CDirectCamViewWrpr\0\0startStopBtnClicked()\0"
    "clrBtnClicked()\0saveImgBtnClicked()\0"
    "startStopRecBtnClicked()\0openFileBtnClicked()\0"
    "playPauseBtnClicked()\0f_value\0"
    "sliderValueChanged(int)\0sliderDragStart()\0"
    "sliderDragEnd()\0f_res\0camResChanged(QString)\0"
    "updateSeqCtrl()\0"
};

void CDirectCamViewWrpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDirectCamViewWrpr *_t = static_cast<CDirectCamViewWrpr *>(_o);
        switch (_id) {
        case 0: _t->startStopBtnClicked(); break;
        case 1: _t->clrBtnClicked(); break;
        case 2: _t->saveImgBtnClicked(); break;
        case 3: _t->startStopRecBtnClicked(); break;
        case 4: _t->openFileBtnClicked(); break;
        case 5: _t->playPauseBtnClicked(); break;
        case 6: _t->sliderValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->sliderDragStart(); break;
        case 8: _t->sliderDragEnd(); break;
        case 9: _t->camResChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->updateSeqCtrl(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDirectCamViewWrpr::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDirectCamViewWrpr::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CDirectCamViewWrpr,
      qt_meta_data_CDirectCamViewWrpr, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDirectCamViewWrpr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDirectCamViewWrpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDirectCamViewWrpr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDirectCamViewWrpr))
        return static_cast<void*>(const_cast< CDirectCamViewWrpr*>(this));
    if (!strcmp(_clname, "IDckWidget"))
        return static_cast< IDckWidget*>(const_cast< CDirectCamViewWrpr*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CDirectCamViewWrpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
