/****************************************************************************
** Meta object code from reading C++ file 'directcam_graphicsview.hpp'
**
** Created: Thu 8. Aug 23:06:04 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../include/ui/directcam_graphicsview.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'directcam_graphicsview.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_CDirectCamGraphicsView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      24,   23,   23,   23, 0x05,
      48,   40,   23,   23, 0x05,

 // slots: signature, parameters, type, tag, flags
      78,   23,   23,   23, 0x0a,
      91,   23,   23,   23, 0x0a,
      98,   23,   23,   23, 0x0a,
     117,  106,   23,   23, 0x0a,
     131,   23,   23,   23, 0x0a,
     146,   23,   23,   23, 0x0a,
     161,   23,   23,   23, 0x0a,
     177,   23,   23,   23, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_CDirectCamGraphicsView[] = {
    "CDirectCamGraphicsView\0\0updateSeqCtrl()\0"
    "f_image\0updateImageEditorView(QImage)\0"
    "tmrTimeOut()\0play()\0pause()\0f_frameNum\0"
    "getFrame(int)\0getNextFrame()\0"
    "getPrevFrame()\0getFirstFrame()\0"
    "getLastFrame()\0"
};

void CDirectCamGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        CDirectCamGraphicsView *_t = static_cast<CDirectCamGraphicsView *>(_o);
        switch (_id) {
        case 0: _t->updateSeqCtrl(); break;
        case 1: _t->updateImageEditorView((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 2: _t->tmrTimeOut(); break;
        case 3: _t->play(); break;
        case 4: _t->pause(); break;
        case 5: _t->getFrame((*reinterpret_cast< const int(*)>(_a[1]))); break;
        case 6: _t->getNextFrame(); break;
        case 7: _t->getPrevFrame(); break;
        case 8: _t->getFirstFrame(); break;
        case 9: _t->getLastFrame(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData CDirectCamGraphicsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject CDirectCamGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_CDirectCamGraphicsView,
      qt_meta_data_CDirectCamGraphicsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &CDirectCamGraphicsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *CDirectCamGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *CDirectCamGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CDirectCamGraphicsView))
        return static_cast<void*>(const_cast< CDirectCamGraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int CDirectCamGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void CDirectCamGraphicsView::updateSeqCtrl()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void CDirectCamGraphicsView::updateImageEditorView(const QImage & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
