/********************************************************************************
** Form generated from reading UI file 'imageeditorview_dckwgt.ui'
**
** Created: Wed 14. Aug 00:22:56 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEEDITORVIEW_DCKWGT_H
#define UI_IMAGEEDITORVIEW_DCKWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "..\include\ui\imageeditor_graphicsview.hpp"
#include "..\include\ui\ruler_widget.hpp"

QT_BEGIN_NAMESPACE

class Ui_CImageEditorView
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    CRulerWidget *m_horRuler_wdgt;
    CImageEditorGraphicsView *m_graphicsView;
    CRulerWidget *m_verRuler_wdgt;

    void setupUi(QDockWidget *CImageEditorView)
    {
        if (CImageEditorView->objectName().isEmpty())
            CImageEditorView->setObjectName(QString::fromUtf8("CImageEditorView"));
        CImageEditorView->resize(779, 679);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_horRuler_wdgt = new CRulerWidget(dockWidgetContents);
        m_horRuler_wdgt->setObjectName(QString::fromUtf8("m_horRuler_wdgt"));
        m_horRuler_wdgt->setMinimumSize(QSize(50, 20));

        gridLayout->addWidget(m_horRuler_wdgt, 0, 1, 1, 1);

        m_graphicsView = new CImageEditorGraphicsView(dockWidgetContents);
        m_graphicsView->setObjectName(QString::fromUtf8("m_graphicsView"));

        gridLayout->addWidget(m_graphicsView, 1, 1, 1, 1);

        m_verRuler_wdgt = new CRulerWidget(dockWidgetContents);
        m_verRuler_wdgt->setObjectName(QString::fromUtf8("m_verRuler_wdgt"));
        m_verRuler_wdgt->setMinimumSize(QSize(40, 50));

        gridLayout->addWidget(m_verRuler_wdgt, 1, 0, 1, 1);

        CImageEditorView->setWidget(dockWidgetContents);

        retranslateUi(CImageEditorView);

        QMetaObject::connectSlotsByName(CImageEditorView);
    } // setupUi

    void retranslateUi(QDockWidget *CImageEditorView)
    {
        CImageEditorView->setWindowTitle(QApplication::translate("CImageEditorView", "Image Editor View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CImageEditorView: public Ui_CImageEditorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEDITORVIEW_DCKWGT_H
