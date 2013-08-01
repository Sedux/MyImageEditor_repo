

#include <QtGui\QtGui>

#include "myimageeditor\myimageeditor.hpp"

int main(int argc, char *argv[])
{
    QApplication   m_mainApp(argc, argv);
    CMyImageEditor m_myImageEditor;
    m_myImageEditor.show();
    return m_mainApp.exec();
}

