/********************************************************************************
** Form generated from reading UI file 'imageeditorview_dckwgt.ui'
**
** Created: Thu 8. Aug 23:06:07 2013
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
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "..\include\ui\imageeditor_graphicsview.hpp"

QT_BEGIN_NAMESPACE

class Ui_CImageEditorView
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QCheckBox *m_convertToMonochkBx;
    CImageEditorGraphicsView *m_graphicsView;
    QPushButton *m_genHistogram_btn;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_convertToGrayScale_chkBx;
    QLabel *label;
    QComboBox *m_grayScaleMethod_comBx;

    void setupUi(QDockWidget *CImageEditorView)
    {
        if (CImageEditorView->objectName().isEmpty())
            CImageEditorView->setObjectName(QString::fromUtf8("CImageEditorView"));
        CImageEditorView->resize(562, 545);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_convertToMonochkBx = new QCheckBox(dockWidgetContents);
        m_convertToMonochkBx->setObjectName(QString::fromUtf8("m_convertToMonochkBx"));

        verticalLayout->addWidget(m_convertToMonochkBx);


        gridLayout->addLayout(verticalLayout, 6, 0, 1, 1);

        m_graphicsView = new CImageEditorGraphicsView(dockWidgetContents);
        m_graphicsView->setObjectName(QString::fromUtf8("m_graphicsView"));

        gridLayout->addWidget(m_graphicsView, 0, 0, 1, 1);

        m_genHistogram_btn = new QPushButton(dockWidgetContents);
        m_genHistogram_btn->setObjectName(QString::fromUtf8("m_genHistogram_btn"));

        gridLayout->addWidget(m_genHistogram_btn, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        m_convertToGrayScale_chkBx = new QCheckBox(dockWidgetContents);
        m_convertToGrayScale_chkBx->setObjectName(QString::fromUtf8("m_convertToGrayScale_chkBx"));

        horizontalLayout->addWidget(m_convertToGrayScale_chkBx);

        label = new QLabel(dockWidgetContents);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        m_grayScaleMethod_comBx = new QComboBox(dockWidgetContents);
        m_grayScaleMethod_comBx->setObjectName(QString::fromUtf8("m_grayScaleMethod_comBx"));

        horizontalLayout->addWidget(m_grayScaleMethod_comBx);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);

        CImageEditorView->setWidget(dockWidgetContents);

        retranslateUi(CImageEditorView);

        QMetaObject::connectSlotsByName(CImageEditorView);
    } // setupUi

    void retranslateUi(QDockWidget *CImageEditorView)
    {
        CImageEditorView->setWindowTitle(QApplication::translate("CImageEditorView", "Image Editor View", 0, QApplication::UnicodeUTF8));
        m_convertToMonochkBx->setText(QApplication::translate("CImageEditorView", "Convert to MonoChrome", 0, QApplication::UnicodeUTF8));
        m_genHistogram_btn->setText(QApplication::translate("CImageEditorView", "Generate Histogram", 0, QApplication::UnicodeUTF8));
        m_convertToGrayScale_chkBx->setText(QApplication::translate("CImageEditorView", "Convert to Gray Scale", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CImageEditorView", "Method:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CImageEditorView: public Ui_CImageEditorView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEDITORVIEW_DCKWGT_H
