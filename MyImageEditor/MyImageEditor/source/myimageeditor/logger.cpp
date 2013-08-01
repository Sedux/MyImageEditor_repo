

#include "myimageeditor\logger.hpp"

CLogger* CLogger::m_loggerInstance = 0;

CLogger::CLogger()
{
}

CLogger::CLogger(const CLogger& f_rhs)
{
}

CLogger* CLogger::getInstance()
{
    //thread synchronisation
    static QMutex mutex;
    QMutexLocker locker(&mutex);

    if (0 == m_loggerInstance)
    {
        m_loggerInstance = new CLogger();
    }

    return m_loggerInstance;
}

//called from Qt framework when logging is done using QDebug, QWarning, QFatal
void CLogger::logMessageOutput(QtMsgType f_type, const char* f_msg)
{
    //thread synchronisation
    static QMutex mutex;
    QMutexLocker locker(&mutex);

    QString sMsg = f_msg;

    emit getInstance()->logMessage(f_type, sMsg); //for updating the message into logging window
}

