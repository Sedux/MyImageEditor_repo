/********************************************************************************
** Form generated from reading UI file 'imageprocessingtools_dckwgt.ui'
**
** Created: Sun 11. Aug 23:03:35 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESSINGTOOLS_DCKWGT_H
#define UI_IMAGEPROCESSINGTOOLS_DCKWGT_H

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
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CImageProcessingToolsView
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_convertToGrayScale_chkBx;
    QLabel *label;
    QComboBox *m_grayScaleMethod_comBx;
    QCheckBox *m_convertToMono_chkBx;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *m_detectEdges_chkBx;
    QLabel *label_2;
    QComboBox *m_detectEdges_comBx;
    QPushButton *m_genHistogram_btn;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *m_reverseImageVer_chkBx;
    QCheckBox *m_reverseImageHor_chkBx;

    void setupUi(QDockWidget *CImageProcessingToolsView)
    {
        if (CImageProcessingToolsView->objectName().isEmpty())
            CImageProcessingToolsView->setObjectName(QString::fromUtf8("CImageProcessingToolsView"));
        CImageProcessingToolsView->resize(496, 194);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
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


        gridLayout->addLayout(horizontalLayout, 3, 0, 1, 1);

        m_convertToMono_chkBx = new QCheckBox(dockWidgetContents);
        m_convertToMono_chkBx->setObjectName(QString::fromUtf8("m_convertToMono_chkBx"));

        gridLayout->addWidget(m_convertToMono_chkBx, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_detectEdges_chkBx = new QCheckBox(dockWidgetContents);
        m_detectEdges_chkBx->setObjectName(QString::fromUtf8("m_detectEdges_chkBx"));

        horizontalLayout_2->addWidget(m_detectEdges_chkBx);

        label_2 = new QLabel(dockWidgetContents);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        m_detectEdges_comBx = new QComboBox(dockWidgetContents);
        m_detectEdges_comBx->setObjectName(QString::fromUtf8("m_detectEdges_comBx"));

        horizontalLayout_2->addWidget(m_detectEdges_comBx);


        gridLayout->addLayout(horizontalLayout_2, 5, 0, 1, 1);

        m_genHistogram_btn = new QPushButton(dockWidgetContents);
        m_genHistogram_btn->setObjectName(QString::fromUtf8("m_genHistogram_btn"));

        gridLayout->addWidget(m_genHistogram_btn, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_reverseImageVer_chkBx = new QCheckBox(dockWidgetContents);
        m_reverseImageVer_chkBx->setObjectName(QString::fromUtf8("m_reverseImageVer_chkBx"));

        horizontalLayout_3->addWidget(m_reverseImageVer_chkBx);

        m_reverseImageHor_chkBx = new QCheckBox(dockWidgetContents);
        m_reverseImageHor_chkBx->setObjectName(QString::fromUtf8("m_reverseImageHor_chkBx"));

        horizontalLayout_3->addWidget(m_reverseImageHor_chkBx);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        CImageProcessingToolsView->setWidget(dockWidgetContents);

        retranslateUi(CImageProcessingToolsView);

        QMetaObject::connectSlotsByName(CImageProcessingToolsView);
    } // setupUi

    void retranslateUi(QDockWidget *CImageProcessingToolsView)
    {
        CImageProcessingToolsView->setWindowTitle(QApplication::translate("CImageProcessingToolsView", "Image Processing Tools", 0, QApplication::UnicodeUTF8));
        m_convertToGrayScale_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Convert to Gray Scale", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CImageProcessingToolsView", "Method:", 0, QApplication::UnicodeUTF8));
        m_convertToMono_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Convert to MonoChrome", 0, QApplication::UnicodeUTF8));
        m_detectEdges_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Detect Edges", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CImageProcessingToolsView", "Method:", 0, QApplication::UnicodeUTF8));
        m_genHistogram_btn->setText(QApplication::translate("CImageProcessingToolsView", "Generate Histogram", 0, QApplication::UnicodeUTF8));
        m_reverseImageVer_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Mirror Image Vertically", 0, QApplication::UnicodeUTF8));
        m_reverseImageHor_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Mirror Image Horizontally", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CImageProcessingToolsView: public Ui_CImageProcessingToolsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESSINGTOOLS_DCKWGT_H
