/********************************************************************************
** Form generated from reading UI file 'histogramview_dckwgt.ui'
**
** Created: Fri 26. Jul 03:05:30 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOGRAMVIEW_DCKWGT_H
#define UI_HISTOGRAMVIEW_DCKWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>
#include "qwt_plot.h"

QT_BEGIN_NAMESPACE

class Ui_CHistogramView
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QwtPlot *m_qwtPlot;

    void setupUi(QDockWidget *CHistogramView)
    {
        if (CHistogramView->objectName().isEmpty())
            CHistogramView->setObjectName(QString::fromUtf8("CHistogramView"));
        CHistogramView->resize(565, 267);
        CHistogramView->setMinimumSize(QSize(50, 50));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        m_qwtPlot = new QwtPlot(dockWidgetContents);
        m_qwtPlot->setObjectName(QString::fromUtf8("m_qwtPlot"));

        gridLayout->addWidget(m_qwtPlot, 0, 0, 1, 1);

        CHistogramView->setWidget(dockWidgetContents);

        retranslateUi(CHistogramView);

        QMetaObject::connectSlotsByName(CHistogramView);
    } // setupUi

    void retranslateUi(QDockWidget *CHistogramView)
    {
        CHistogramView->setWindowTitle(QApplication::translate("CHistogramView", "Histogram View", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CHistogramView: public Ui_CHistogramView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOGRAMVIEW_DCKWGT_H
