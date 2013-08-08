/****************************************************************************
** Meta object code from reading C++ file 'loggingview_wrpr.hpp'
**
** Created: Thu 8. Aug 23:16:33 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/dockwidgets/loggingview_wrpr.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loggingview_wrpr.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CLoggingViewWrpr[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   27,   17,   17, 0x0a,
      79,   73,   17,   17, 0x0a,
     104,   17,   17,   17, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CLoggingViewWrpr[] = {
    "CLoggingViewWrpr\0\0closed()\0f_msgType,f_msg\0"
    "addMessage(QtMsgType,QString)\0event\0"
    "closeEvent(QCloseEvent*)\0clearAll()\0"
};

void CLoggingViewWrpr::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CLoggingViewWrpr *_t = static_cast<CLoggingViewWrpr *>(_o);
        switch (_id) {
        case 0: _t->closed(); break;
        case 1: _t->addMessage((*reinterpret_cast< QtMsgType(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        case 3: _t->clearAll(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CLoggingViewWrpr::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CLoggingViewWrpr::staticMetaObject = {
    { &QDockWidget::staticMetaObject, qt_meta_stringdata_CLoggingViewWrpr,
      qt_meta_data_CLoggingViewWrpr, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CLoggingViewWrpr::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CLoggingViewWrpr::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CLoggingViewWrpr::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CLoggingViewWrpr))
        return static_cast<void*>(const_cast< CLoggingViewWrpr*>(this));
    if (!strcmp(_clname, "IDckWidget"))
        return static_cast< IDckWidget*>(const_cast< CLoggingViewWrpr*>(this));
    return QDockWidget::qt_metacast(_clname);
}

int CLoggingViewWrpr::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDockWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void CLoggingViewWrpr::closed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
