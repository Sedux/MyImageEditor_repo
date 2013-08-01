

#ifndef LOGGER_DEFINES_HPP
#define LOGGER_DEFINES_HPP

#include <QtGui\QtGui>

#define QDEBUG_MSG(MSG)   qDebug()    << QString::number(__LINE__) + QString("__LINE__") + QString(__FILE__) + QString("__FILE__") + QString(MSG)
#define QWARNING_MSG(MSG) qWarning()  << QString::number(__LINE__) + QString("__LINE__") + QString(__FILE__) + QString("__FILE__") + QString(MSG)
#define QERROR_MSG(MSG)   qCritical() << QString::number(__LINE__) + QString("__LINE__") + QString(__FILE__) + QString("__FILE__") + QString(MSG)

#endif //LOGGER_DEFINES_HPP