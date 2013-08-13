

#include "dockwidgets\loggingview_wrpr.hpp"

CLoggingViewWrpr::CLoggingViewWrpr(QWidget* f_parent, Qt::WFlags f_flag) :
QDockWidget(f_parent, f_flag),
m_loggingView_ui()
{
    m_logFile = QDir::currentPath() + QString("/MyImageEditor.txt");
    QFile fileHandler(m_logFile);
    if(false == fileHandler.isOpen())
    {
        fileHandler.open(QIODevice::Append);
    }

    fileHandler.write("\n\n\n------------------------------------------------------------------------------\r\n");
    fileHandler.write      ("-----------------------------------Start of Log-------------------------------\r\n");
    fileHandler.write      (QString("Date: " + QDate::currentDate().toString("dd:MM:yyyy") + "\r\n").toLocal8Bit().data());
    fileHandler.close();

    m_clearAllAction = new QAction("Clear All", this);
}

CLoggingViewWrpr::~CLoggingViewWrpr()
{
    QFile fileHandler(m_logFile);
    if(false == fileHandler.isOpen())
    {
        fileHandler.open(QIODevice::Append);
    }

    
    fileHandler.write("-------------------------------End of Log------------------------------------\r\n");
    fileHandler.write("------------------------------------------------------------------------------\r\n");
    fileHandler.close();
}

void CLoggingViewWrpr::init(IMyImageEditor* f_int)
{
     this->setMyImageEditorInt(f_int);
     m_loggingView_ui.m_logTable->setColumnWidth(1, 1000);
}

void CLoggingViewWrpr::setWidget(QWidget* f_widget)
{
    m_loggingView_ui.setupUi(this);
    this->addAction(m_clearAllAction);
    connect(m_clearAllAction, SIGNAL(triggered()), this, SLOT(clearAll()));
    this->setContextMenuPolicy(Qt::ActionsContextMenu);
}

void CLoggingViewWrpr::closeEvent(QCloseEvent *event)
 {
     emit closed();
 }

void CLoggingViewWrpr::addMessage(QtMsgType f_msgType, QString f_msg)
{
    QTableWidget* logTable = m_loggingView_ui.m_logTable;

    QString time = QTime::currentTime().toString("hh:mm:ss");
    QTableWidgetItem* time_item = new QTableWidgetItem();
    QTableWidgetItem* msg_item  = new QTableWidgetItem();
    QTableWidgetItem* line_item  = new QTableWidgetItem();
    QTableWidgetItem* file_item  = new QTableWidgetItem();
        
    int rowCount = logTable->rowCount();
    logTable->insertRow(rowCount);
    logTable->setRowHeight(rowCount, 20);

    if (time.isEmpty() || logTable == NULL) 
        return;

    QFile fileHandler(m_logFile);
    if(false == fileHandler.isOpen())
    {
        fileHandler.open(QIODevice::Append);
    }

    SLogMsgInfo l_logMsgInfo = this->decodeLogMsg(f_msg);

    switch (f_msgType)
    {
    case QtDebugMsg:
        time_item->setIcon(QApplication::style()->standardIcon( QStyle::SP_MessageBoxInformation ));
        time_item->setText(time);
        msg_item->setTextColor(QColor(0,0,255));
        msg_item->setText(l_logMsgInfo.m_message);
        msg_item->setToolTip(l_logMsgInfo.m_message);
        line_item->setText(QString::number(l_logMsgInfo.m_lineNum));
        file_item->setText(l_logMsgInfo.m_fileName);
        logTable->setItem(rowCount, 0, time_item);
        logTable->setItem(rowCount, 1, msg_item);
        logTable->setItem(rowCount, 2, line_item);
        logTable->setItem(rowCount, 3, file_item);
        logTable->scrollToBottom();

        fileHandler.write(QString("Debug: \t" + time + "\t" + f_msg + "\r\n").toLocal8Bit().data());
        fileHandler.close();
        break;

    case QtWarningMsg:
        time_item->setIcon(QApplication::style()->standardIcon( QStyle::SP_MessageBoxWarning ));
        time_item->setText(time);
        msg_item->setTextColor(QColor(200,0,100));
        msg_item->setText(l_logMsgInfo.m_message);
        msg_item->setToolTip(l_logMsgInfo.m_message);
        line_item->setText(QString::number(l_logMsgInfo.m_lineNum));
        file_item->setText(l_logMsgInfo.m_fileName);
        logTable->setItem(rowCount, 0, time_item);
        logTable->setItem(rowCount, 1, msg_item);
        logTable->setItem(rowCount, 2, line_item);
        logTable->setItem(rowCount, 3, file_item);
        logTable->scrollToBottom();

        fileHandler.write(QString("Warning: \t" + time + "\t" + f_msg + "\r\n").toLocal8Bit().data());
        fileHandler.close();
        break;

    case QtCriticalMsg:
        time_item->setIcon(QApplication::style()->standardIcon( QStyle::SP_MessageBoxCritical ));
        time_item->setText(time);
        msg_item->setTextColor(QColor(255,0,0));
        msg_item->setText(l_logMsgInfo.m_message);
        msg_item->setToolTip(l_logMsgInfo.m_message);
        line_item->setText(QString::number(l_logMsgInfo.m_lineNum));
        file_item->setText(l_logMsgInfo.m_fileName);
        logTable->setItem(rowCount, 0, time_item);
        logTable->setItem(rowCount, 1, msg_item);
        logTable->setItem(rowCount, 2, line_item);
        logTable->setItem(rowCount, 3, file_item);
        logTable->scrollToBottom();

        fileHandler.write(QString("Error: \t" + time + "\t" + f_msg + "\r\n").toLocal8Bit().data());
        fileHandler.close();
        break;

    case QtFatalMsg:
        fprintf(stderr, "Fatal: %s \n", f_msg );
        time_item->setIcon(QApplication::style()->standardIcon( QStyle::SP_MessageBoxCritical ));
        time_item->setText(time);
        msg_item->setTextColor(QColor(128,0,64));
        msg_item->setText(l_logMsgInfo.m_message);
        msg_item->setToolTip(l_logMsgInfo.m_message);
        line_item->setText(QString::number(l_logMsgInfo.m_lineNum));
        file_item->setText(l_logMsgInfo.m_fileName);
        logTable->setItem(rowCount, 0, time_item);
        logTable->setItem(rowCount, 1, msg_item);
        logTable->setItem(rowCount, 2, line_item);
        logTable->setItem(rowCount, 3, file_item);
        logTable->scrollToBottom();

        fileHandler.write(QString("Fatal: \t" + time + "\t" + f_msg + "\r\n").toLocal8Bit().data());
        fileHandler.close();
    }
}

CLoggingViewWrpr::SLogMsgInfo CLoggingViewWrpr::decodeLogMsg(const QString& f_msg)
{
    SLogMsgInfo l_logMsgInfo;
    QStringList list1 = f_msg.split("__LINE__");

    if(list1.size() < 2)
    {
        l_logMsgInfo.m_message = f_msg;
        return l_logMsgInfo;
    }

    l_logMsgInfo.m_lineNum = list1[0].remove("\"").toInt();
    QStringList list2 = list1[1].split("__FILE__");

    if(list2.size() < 2)
    {
        l_logMsgInfo.m_message = f_msg;
        return l_logMsgInfo;
    }

    l_logMsgInfo.m_fileName = list2[0];
    l_logMsgInfo.m_message = list2[1].remove("\"");
    return l_logMsgInfo;
}

void CLoggingViewWrpr::clearAll()
{
    int rowCount = m_loggingView_ui.m_logTable->rowCount();

    for(int count = 0; count < rowCount; count++)
    {
        m_loggingView_ui.m_logTable->removeRow(0);
    }
}

