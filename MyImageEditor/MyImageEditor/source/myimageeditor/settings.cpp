

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
    //synchronisation when accessing from multiple threads
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
    m_settings = new  QSettings(m_iniFileName, QSettings::IniFormat);
    this->restoreGUIStateAndGeometry();
}
 
void CSettings::storeSettings()
{
    m_settings->setValue("MyImageEditor_State", m_imageEditor->saveState());
    m_settings->setValue("MyImageEditor_Geometry", m_imageEditor->saveGeometry());
    m_settings->sync();
}

void CSettings::restoreGUIStateAndGeometry()
{
    m_imageEditor->restoreState(m_settings->value("MyImageEditor_State").toByteArray());
    m_imageEditor->restoreGeometry(m_settings->value("MyImageEditor_Geometry").toByteArray());
}


