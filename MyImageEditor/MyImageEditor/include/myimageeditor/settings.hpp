
#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QtCore\QtCore>

class CMyImageEditor;

class CSettings : public QObject
{
Q_OBJECT

public:
    
    ~CSettings();

    static CSettings* getInstance(CMyImageEditor* f_imageEditor = 0);

    void restoreSettings(QString iniFileName = QDir::currentPath() + QString("/MyImageEditor.ini"));
    void storeSettings();

    void restoreGUIStateAndGeometry();

private:
    static CSettings* m_instance;
    CMyImageEditor*   m_imageEditor;
    QString    m_iniFileName;
    QSettings* m_settings;

    CSettings(CMyImageEditor* f_imageEditor = 0);
    CSettings(const CSettings& f_rhs) {}
};

#endif //SETTINGS_HPP
