/********************************************************************************
** Form generated from reading UI file 'directcamview_dckwgt.ui'
**
** Created: Wed 14. Aug 02:52:50 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIRECTCAMVIEW_DCKWGT_H
#define UI_DIRECTCAMVIEW_DCKWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "..\include\ui\directcam_graphicsview.hpp"
#include "..\include\ui\ruler_widget.hpp"

QT_BEGIN_NAMESPACE

class Ui_CDirectCamView
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    CDirectCamGraphicsView *m_graphicsView;
    CRulerWidget *m_horRuler_wdgt;
    CRulerWidget *m_verRuler_wdgt;
    QSlider *m_frameSlider;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *m_firstFrame_btn;
    QPushButton *m_prevFrame_btn;
    QPushButton *m_playPause_btn;
    QPushButton *m_nextFrame_btn;
    QPushButton *m_lastFrame_btn;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_3;
    QPushButton *m_startStop_btn;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QComboBox *m_camRes_comBx;
    QVBoxLayout *verticalLayout_4;
    QPushButton *m_openFile_btn;
    QPushButton *m_saveImage_btn;
    QPushButton *m_startStopRec_btn;
    QPushButton *m_clr_btn;

    void setupUi(QDockWidget *CDirectCamView)
    {
        if (CDirectCamView->objectName().isEmpty())
            CDirectCamView->setObjectName(QString::fromUtf8("CDirectCamView"));
        CDirectCamView->resize(638, 608);
        CDirectCamView->setMinimumSize(QSize(343, 371));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_graphicsView = new CDirectCamGraphicsView(dockWidgetContents);
        m_graphicsView->setObjectName(QString::fromUtf8("m_graphicsView"));

        gridLayout->addWidget(m_graphicsView, 1, 1, 1, 1);

        m_horRuler_wdgt = new CRulerWidget(dockWidgetContents);
        m_horRuler_wdgt->setObjectName(QString::fromUtf8("m_horRuler_wdgt"));
        m_horRuler_wdgt->setMinimumSize(QSize(50, 20));

        gridLayout->addWidget(m_horRuler_wdgt, 0, 1, 1, 1);

        m_verRuler_wdgt = new CRulerWidget(dockWidgetContents);
        m_verRuler_wdgt->setObjectName(QString::fromUtf8("m_verRuler_wdgt"));
        m_verRuler_wdgt->setMinimumSize(QSize(40, 50));

        gridLayout->addWidget(m_verRuler_wdgt, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        m_frameSlider = new QSlider(dockWidgetContents);
        m_frameSlider->setObjectName(QString::fromUtf8("m_frameSlider"));
        m_frameSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(m_frameSlider);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, -1, -1, -1);
        m_firstFrame_btn = new QPushButton(dockWidgetContents);
        m_firstFrame_btn->setObjectName(QString::fromUtf8("m_firstFrame_btn"));

        horizontalLayout_6->addWidget(m_firstFrame_btn);

        m_prevFrame_btn = new QPushButton(dockWidgetContents);
        m_prevFrame_btn->setObjectName(QString::fromUtf8("m_prevFrame_btn"));

        horizontalLayout_6->addWidget(m_prevFrame_btn);

        m_playPause_btn = new QPushButton(dockWidgetContents);
        m_playPause_btn->setObjectName(QString::fromUtf8("m_playPause_btn"));

        horizontalLayout_6->addWidget(m_playPause_btn);

        m_nextFrame_btn = new QPushButton(dockWidgetContents);
        m_nextFrame_btn->setObjectName(QString::fromUtf8("m_nextFrame_btn"));

        horizontalLayout_6->addWidget(m_nextFrame_btn);

        m_lastFrame_btn = new QPushButton(dockWidgetContents);
        m_lastFrame_btn->setObjectName(QString::fromUtf8("m_lastFrame_btn"));

        horizontalLayout_6->addWidget(m_lastFrame_btn);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_startStop_btn = new QPushButton(dockWidgetContents);
        m_startStop_btn->setObjectName(QString::fromUtf8("m_startStop_btn"));

        verticalLayout_3->addWidget(m_startStop_btn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        m_camRes_comBx = new QComboBox(dockWidgetContents);
        m_camRes_comBx->setObjectName(QString::fromUtf8("m_camRes_comBx"));

        horizontalLayout_2->addWidget(m_camRes_comBx);


        verticalLayout_3->addLayout(horizontalLayout_2);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_openFile_btn = new QPushButton(dockWidgetContents);
        m_openFile_btn->setObjectName(QString::fromUtf8("m_openFile_btn"));

        verticalLayout_4->addWidget(m_openFile_btn);

        m_saveImage_btn = new QPushButton(dockWidgetContents);
        m_saveImage_btn->setObjectName(QString::fromUtf8("m_saveImage_btn"));

        verticalLayout_4->addWidget(m_saveImage_btn);


        horizontalLayout->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout);

        m_startStopRec_btn = new QPushButton(dockWidgetContents);
        m_startStopRec_btn->setObjectName(QString::fromUtf8("m_startStopRec_btn"));

        verticalLayout->addWidget(m_startStopRec_btn);

        m_clr_btn = new QPushButton(dockWidgetContents);
        m_clr_btn->setObjectName(QString::fromUtf8("m_clr_btn"));

        verticalLayout->addWidget(m_clr_btn);

        CDirectCamView->setWidget(dockWidgetContents);

        retranslateUi(CDirectCamView);

        QMetaObject::connectSlotsByName(CDirectCamView);
    } // setupUi

    void retranslateUi(QDockWidget *CDirectCamView)
    {
        CDirectCamView->setWindowTitle(QApplication::translate("CDirectCamView", "Direct Cam View", 0, QApplication::UnicodeUTF8));
        m_firstFrame_btn->setText(QString());
        m_prevFrame_btn->setText(QString());
        m_playPause_btn->setText(QString());
        m_nextFrame_btn->setText(QString());
        m_lastFrame_btn->setText(QString());
        m_startStop_btn->setText(QApplication::translate("CDirectCamView", "Start Streaming", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CDirectCamView", "Select Cam Resolution:", 0, QApplication::UnicodeUTF8));
        m_openFile_btn->setText(QApplication::translate("CDirectCamView", "Open File", 0, QApplication::UnicodeUTF8));
        m_saveImage_btn->setText(QApplication::translate("CDirectCamView", "Save Image", 0, QApplication::UnicodeUTF8));
        m_startStopRec_btn->setText(QApplication::translate("CDirectCamView", "Start Recording", 0, QApplication::UnicodeUTF8));
        m_clr_btn->setText(QApplication::translate("CDirectCamView", "Clear", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CDirectCamView: public Ui_CDirectCamView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIRECTCAMVIEW_DCKWGT_H
