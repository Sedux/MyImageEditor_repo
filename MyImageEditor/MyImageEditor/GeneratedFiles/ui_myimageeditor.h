/********************************************************************************
** Form generated from reading UI file 'myimageeditor.ui'
**
** Created: Sun 11. Aug 03:23:38 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYIMAGEEDITOR_H
#define UI_MYIMAGEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>
#include "..\include\dockwidgets\directcamview_wrpr.hpp"
#include "..\include\dockwidgets\histogramview_wrpr.hpp"
#include "..\include\dockwidgets\imageeditorview_wrpr.hpp"
#include "..\include\dockwidgets\imageprocessingtoolsview_wrpr.hpp"
#include "..\include\dockwidgets\loggingview_wrpr.hpp"

QT_BEGIN_NAMESPACE

class Ui_CMyImageEditorUI
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    CHistogramViewWrpr *m_histogramView;
    QWidget *dockWidgetContents_2;
    CDirectCamViewWrpr *m_directCamView;
    QWidget *dockWidgetContents;
    CLoggingViewWrpr *m_loggingView;
    QWidget *dockWidgetContents_3;
    CImageEditorViewWrpr *m_imageEditorView;
    QWidget *dockWidgetContents_4;
    CImageProcessingToolsViewWrpr *m_imageProcessingToolsView;
    QWidget *dockWidgetContents_5;

    void setupUi(QMainWindow *CMyImageEditorUI)
    {
        if (CMyImageEditorUI->objectName().isEmpty())
            CMyImageEditorUI->setObjectName(QString::fromUtf8("CMyImageEditorUI"));
        CMyImageEditorUI->resize(1049, 793);
        centralwidget = new QWidget(CMyImageEditorUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        CMyImageEditorUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CMyImageEditorUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1049, 26));
        CMyImageEditorUI->setMenuBar(menubar);
        statusbar = new QStatusBar(CMyImageEditorUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CMyImageEditorUI->setStatusBar(statusbar);
        m_histogramView = new CHistogramViewWrpr(CMyImageEditorUI);
        m_histogramView->setObjectName(QString::fromUtf8("m_histogramView"));
        m_histogramView->setFloating(false);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        m_histogramView->setWidget(dockWidgetContents_2);
        CMyImageEditorUI->addDockWidget(static_cast<Qt::DockWidgetArea>(8), m_histogramView);
        m_directCamView = new CDirectCamViewWrpr(CMyImageEditorUI);
        m_directCamView->setObjectName(QString::fromUtf8("m_directCamView"));
        m_directCamView->setAllowedAreas(Qt::AllDockWidgetAreas);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        m_directCamView->setWidget(dockWidgetContents);
        CMyImageEditorUI->addDockWidget(static_cast<Qt::DockWidgetArea>(1), m_directCamView);
        m_loggingView = new CLoggingViewWrpr(CMyImageEditorUI);
        m_loggingView->setObjectName(QString::fromUtf8("m_loggingView"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        m_loggingView->setWidget(dockWidgetContents_3);
        CMyImageEditorUI->addDockWidget(static_cast<Qt::DockWidgetArea>(8), m_loggingView);
        m_imageEditorView = new CImageEditorViewWrpr(CMyImageEditorUI);
        m_imageEditorView->setObjectName(QString::fromUtf8("m_imageEditorView"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        m_imageEditorView->setWidget(dockWidgetContents_4);
        CMyImageEditorUI->addDockWidget(static_cast<Qt::DockWidgetArea>(2), m_imageEditorView);
        m_imageProcessingToolsView = new CImageProcessingToolsViewWrpr(CMyImageEditorUI);
        m_imageProcessingToolsView->setObjectName(QString::fromUtf8("m_imageProcessingToolsView"));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QString::fromUtf8("dockWidgetContents_5"));
        m_imageProcessingToolsView->setWidget(dockWidgetContents_5);
        CMyImageEditorUI->addDockWidget(static_cast<Qt::DockWidgetArea>(8), m_imageProcessingToolsView);

        retranslateUi(CMyImageEditorUI);

        QMetaObject::connectSlotsByName(CMyImageEditorUI);
    } // setupUi

    void retranslateUi(QMainWindow *CMyImageEditorUI)
    {
        CMyImageEditorUI->setWindowTitle(QApplication::translate("CMyImageEditorUI", "My Image Editor", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CMyImageEditorUI: public Ui_CMyImageEditorUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYIMAGEEDITOR_H
