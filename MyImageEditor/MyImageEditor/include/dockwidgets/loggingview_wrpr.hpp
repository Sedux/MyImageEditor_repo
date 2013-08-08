
#ifndef LOGGING_VIEW_HPP
#define LOGGING_VIEW_HPP

#include <QtGui\QtGui>

#include "ui_loggingview_dckwgt.h"

#include "dockwidgets\dockwidget_base.hpp"

class CLoggingViewWrpr : public QDockWidget, public IDckWidget
{
    Q_OBJECT

public:
    CLoggingViewWrpr(QWidget* f_parent = 0, Qt::WFlags f_flag = 0);
    ~CLoggingViewWrpr();

    void init(IMyImageEditor* f_int);

    void setWidget(QWidget* f_widget);

private:
    Ui::CLoggingView    m_loggingView_ui;
    QString             m_logFile;
    QAction*            m_clearAllAction;

    struct SLogMsgInfo
    {
        SLogMsgInfo() : m_lineNum(0), m_fileName("NA"), m_message()
        {
        }

        int      m_lineNum;
        QString  m_fileName;
        QString  m_message;
    };

    SLogMsgInfo decodeLogMsg(const QString& f_msg);
  
signals:
    void closed();  

public slots:
    void addMessage(QtMsgType f_msgType, QString f_msg);
    void closeEvent(QCloseEvent *event);
    void clearAll();
};

#endif // LOGGING_VIEW_HPP

