/********************************************************************************
** Form generated from reading UI file 'loggingview_dckwgt.ui'
**
** Created: Mon 19. Aug 23:16:29 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGGINGVIEW_DCKWGT_H
#define UI_LOGGINGVIEW_DCKWGT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QTableWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CLoggingView
{
public:
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QTableWidget *m_logTable;

    void setupUi(QDockWidget *CLoggingView)
    {
        if (CLoggingView->objectName().isEmpty())
            CLoggingView->setObjectName(QString::fromUtf8("CLoggingView"));
        CLoggingView->resize(874, 135);
        CLoggingView->setStyleSheet(QString::fromUtf8("QDockWidget::title {\n"
"	background-color: rgb(174, 174, 220);\n"
"	color: rgb(45, 45, 45);\n"
"	 border: 1px solid black;\n"
"     border-top: 3px solid qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 black, stop: 1  rgb(174, 174, 220));\n"
"     border-radius: 2px;\n"
" }"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_logTable = new QTableWidget(dockWidgetContents);
        if (m_logTable->columnCount() < 4)
            m_logTable->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        m_logTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        m_logTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        m_logTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        m_logTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        m_logTable->setObjectName(QString::fromUtf8("m_logTable"));
        m_logTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        m_logTable->setAlternatingRowColors(true);
        m_logTable->verticalHeader()->setVisible(false);

        verticalLayout->addWidget(m_logTable);

        CLoggingView->setWidget(dockWidgetContents);

        retranslateUi(CLoggingView);

        QMetaObject::connectSlotsByName(CLoggingView);
    } // setupUi

    void retranslateUi(QDockWidget *CLoggingView)
    {
        CLoggingView->setWindowTitle(QApplication::translate("CLoggingView", "Log View", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = m_logTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("CLoggingView", "TimeStamp", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = m_logTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("CLoggingView", "Message", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = m_logTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("CLoggingView", "Line Number", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = m_logTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("CLoggingView", "File Name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CLoggingView: public Ui_CLoggingView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGGINGVIEW_DCKWGT_H
