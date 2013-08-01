

#include "myimageeditor\settings.hpp"
#include "myimageeditor\myimageeditor.hpp"
#include "myimageeditor\logger_defines.hpp"

CSettings* CSettings::m_instance = 0;

CSettings::CSettings(CMyImageEditor* f_imageEditor) : QObject(),
    m_iniFileName(),
    m_imageEditor(f_imageEditor)
{
}

CSettings::~CSettings()
{
}

CSettings* CSettings::getInstance(CMyImageEditor* f_imageEditor)
{
    //thread synchronisation
    static QMutex mutex;
    QMutexLocker locker(&mutex);

    if (0 == m_instance)
    {
        m_instance = new CSettings(f_imageEditor);
    }

    return m_instance;
}

void CSettings::restoreSettings(QString iniFileName)
{
    m_iniFileName = iniFileName;
    QDEBUG_MSG("Init File:" + iniFileName);
    m_settings = new  QSettings(m_iniFileName, QSettings::IniFormat);

    this->restoreGUIStateAndGeometry();
}
 
void CSettings::storeSettings()
{
    m_settings->setValue("MainWindow/State", m_imageEditor->saveState());
    m_settings->setValue("MainWindow/Geometry", m_imageEditor->saveGeometry());
    m_settings->sync();
}

void CSettings::restoreGUIStateAndGeometry()
{
    m_imageEditor->restoreState(m_settings->value("MainWindow/State").toByteArray());
    m_imageEditor->restoreGeometry(m_settings->value("MainWindow/Geometry").toByteArray());
}


