

#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <QtGui\QtGui>

class CLogger : public QObject
{
    Q_OBJECT

private:
    //singleton class has private const and dest
    CLogger();
    CLogger(const CLogger& f_rhs);

    //The CLogger is made singleton to have a common logger across various threads
    static CLogger* m_loggerInstance;   

public:
    static CLogger* getInstance();
    static void     logMessageOutput(QtMsgType f_type, const char* f_msg); //called from Qt framework when logging is done using QDebug, QWarning, QFatal

signals:
    void logMessage(QtMsgType f_type, QString f_message);//for updating the message into logging window
};

#endif // LOGGER_HPP