/********************************************************************************
** Form generated from reading UI file 'imageprocessingtools_dckwgt.ui'
**
** Created: Sun 8. Sep 23:23:35 2013
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
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CImageProcessingToolsView
{
public:
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QRadioButton *m_none_rdBtn;
    QRadioButton *m_convertToMono_rdBtn;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *m_detectEdges_rdBtn;
    QLabel *label_2;
    QComboBox *m_detectEdges_comBx;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *m_blurImage_rdBtn;
    QLabel *label_3;
    QComboBox *m_blurImageMethod_comBx;
    QHBoxLayout *horizontalLayout;
    QCheckBox *m_convertToGrayScale_chkBx;
    QLabel *label;
    QComboBox *m_grayScaleMethod_comBx;
    QPushButton *m_genHistogram_btn;
    QCheckBox *m_reverseImageHor_chkBx;
    QCheckBox *m_reverseImageVer_chkBx;

    void setupUi(QDockWidget *CImageProcessingToolsView)
    {
        if (CImageProcessingToolsView->objectName().isEmpty())
            CImageProcessingToolsView->setObjectName(QString::fromUtf8("CImageProcessingToolsView"));
        CImageProcessingToolsView->resize(548, 301);
        CImageProcessingToolsView->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: rgb(45, 45, 45);\n"
"     border: 2px solid #8f8f91;\n"
"	 border-color: rgb(90, 93, 125);\n"
"     border-radius: 6px;\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #f6f7fa, stop: 1 #dadbde);\n"
"     min-width: 80px;\n"
" }\n"
"\n"
" QPushButton:pressed {\n"
"     background-color: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 #dadbde, stop: 1 #f6f7fa);\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     border-color: rgb(90, 93, 255);\n"
" }\n"
"\n"
" QPushButton:default {\n"
"     border-color: navy; /* make the default button prominent */\n"
" }\n"
"\n"
"QPushButton:disabled {  \n"
"	color: rgb(171, 171, 171);\n"
"     border-color: none; /* make the default button prominent */\n"
" }\n"
"\n"
"QDockWidget::title {\n"
"	background-color: rgb(174, 174, 220);\n"
"	color: rgb(45, 45, 45);\n"
"	 border: 1px solid black;\n"
"     border-top: 3px solid qlineargradient(x"
                        "1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                       stop: 0 black, stop: 1  rgb(174, 174, 220));\n"
"     border-radius: 2px;\n"
" }\n"
"\n"
"QComboBox {\n"
"     border: 1px solid gray;\n"
"     border-radius: 3px;\n"
"     padding: 1px 18px 1px 3px;\n"
"     min-width: 6em;\n"
" }\n"
"\n"
"QComboBox:editable {\n"
"     background: white;\n"
" }\n"
"\n"
" QComboBox:!editable, QComboBox::drop-down:editable {\n"
"      background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                  stop: 0 #E1E1E1, stop: 0.4 #DDDDDD,\n"
"                                  stop: 0.5 #D8D8D8, stop: 1.0 #D3D3D3);\n"
" }\n"
"\n"
" /* QComboBox gets the \"on\" state when the popup is open */\n"
" QComboBox:!editable:on, QComboBox::drop-down:editable:on {\n"
"     background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                 stop: 0 #D3D3D3, stop: 0.4 #D8D8D8,\n"
"                                 stop: 0.5 #DDDDDD, stop: 1.0 #E1E1E1);\n"
" }\n"
"\n"
" QComb"
                        "oBox:on { /* shift the text when the popup opens */\n"
"     padding-top: 3px;\n"
"     padding-left: 4px;\n"
" }\n"
"\n"
" QComboBox::drop-down {\n"
"     subcontrol-origin: padding;\n"
"     subcontrol-position: top right;\n"
"     width: 15px;\n"
"\n"
"     border-left-width: 1px;\n"
"     border-left-color: darkgray;\n"
"     border-left-style: solid; /* just a single line */\n"
"     border-top-right-radius: 3px; /* same radius as the QComboBox */\n"
"     border-bottom-right-radius: 3px;\n"
" }\n"
"\n"
"\n"
" QComboBox::down-arrow {\n"
"    image: url(:/images/Action-arrow-down-icon.png);\n"
" }\n"
"\n"
" QComboBox::down-arrow:on { /* shift the arrow when popup is open */\n"
"     top: 1px;\n"
"     left: 1px;\n"
" }\n"
"\n"
"QCheckBox:indicator {\n"
"	color: rgb(45, 45, 45);\n"
"     border: 0px solid #8f8f91;\n"
"	 border-color: rgb(90, 93, 125);\n"
"     border-radius: 4px;\n"
"    \n"
"	background-color: qlineargradient(spread:pad, x1:0.015, y1:0.051, x2:1, y2:0, stop:0 rgba(255, 255, 255, 255), stop"
                        ":1 rgba(255, 255, 255, 255));\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked {\n"
"     image: url(:/images/checkbox_unchecked.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:hover {\n"
"     border: 1px solid;\n"
"     border-color: rgb(90, 93, 255);\n"
"     image: url(:/images/checkbox_unchecked_hover.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:unchecked:pressed {\n"
"     image: url(:/images/checkbox_unchecked_pressed.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked {\n"
"     image: url(:/images/checkbox_checked.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:hover {\n"
"     border: 1px solid;\n"
"     border-color: rgb(90, 93, 255);\n"
"     image: url(:/images/checkbox_checked_hover.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:checked:pressed {\n"
"     image: url(:/images/checkbox_checked_pressed.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:indeterminate:hover {\n"
"     image: url(:/images/checkbox_indeterminate_hover.png);\n"
" }\n"
"\n"
" QCheckBox::indicator:indeterminate:pressed {\n"
""
                        "     image: url(:/images/checkbox_indeterminate_pressed.png);\n"
" }\n"
""));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        groupBox = new QGroupBox(dockWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_none_rdBtn = new QRadioButton(groupBox);
        m_none_rdBtn->setObjectName(QString::fromUtf8("m_none_rdBtn"));

        verticalLayout->addWidget(m_none_rdBtn);

        m_convertToMono_rdBtn = new QRadioButton(groupBox);
        m_convertToMono_rdBtn->setObjectName(QString::fromUtf8("m_convertToMono_rdBtn"));

        verticalLayout->addWidget(m_convertToMono_rdBtn);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        m_detectEdges_rdBtn = new QRadioButton(groupBox);
        m_detectEdges_rdBtn->setObjectName(QString::fromUtf8("m_detectEdges_rdBtn"));

        horizontalLayout_2->addWidget(m_detectEdges_rdBtn);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setLayoutDirection(Qt::LeftToRight);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        m_detectEdges_comBx = new QComboBox(groupBox);
        m_detectEdges_comBx->setObjectName(QString::fromUtf8("m_detectEdges_comBx"));

        horizontalLayout_2->addWidget(m_detectEdges_comBx);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        m_blurImage_rdBtn = new QRadioButton(groupBox);
        m_blurImage_rdBtn->setObjectName(QString::fromUtf8("m_blurImage_rdBtn"));

        horizontalLayout_4->addWidget(m_blurImage_rdBtn);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        m_blurImageMethod_comBx = new QComboBox(groupBox);
        m_blurImageMethod_comBx->setObjectName(QString::fromUtf8("m_blurImageMethod_comBx"));

        horizontalLayout_4->addWidget(m_blurImageMethod_comBx);


        verticalLayout->addLayout(horizontalLayout_4);


        gridLayout->addWidget(groupBox, 4, 0, 1, 1);

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

        m_genHistogram_btn = new QPushButton(dockWidgetContents);
        m_genHistogram_btn->setObjectName(QString::fromUtf8("m_genHistogram_btn"));

        gridLayout->addWidget(m_genHistogram_btn, 0, 0, 1, 1);

        m_reverseImageHor_chkBx = new QCheckBox(dockWidgetContents);
        m_reverseImageHor_chkBx->setObjectName(QString::fromUtf8("m_reverseImageHor_chkBx"));

        gridLayout->addWidget(m_reverseImageHor_chkBx, 2, 0, 1, 1);

        m_reverseImageVer_chkBx = new QCheckBox(dockWidgetContents);
        m_reverseImageVer_chkBx->setObjectName(QString::fromUtf8("m_reverseImageVer_chkBx"));

        gridLayout->addWidget(m_reverseImageVer_chkBx, 1, 0, 1, 1);

        CImageProcessingToolsView->setWidget(dockWidgetContents);

        retranslateUi(CImageProcessingToolsView);

        QMetaObject::connectSlotsByName(CImageProcessingToolsView);
    } // setupUi

    void retranslateUi(QDockWidget *CImageProcessingToolsView)
    {
        CImageProcessingToolsView->setWindowTitle(QApplication::translate("CImageProcessingToolsView", "Image Processing Tools", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("CImageProcessingToolsView", "Mutually Exclusive Operations", 0, QApplication::UnicodeUTF8));
        m_none_rdBtn->setText(QApplication::translate("CImageProcessingToolsView", "None", 0, QApplication::UnicodeUTF8));
        m_convertToMono_rdBtn->setText(QApplication::translate("CImageProcessingToolsView", "Convert to Monochrome", 0, QApplication::UnicodeUTF8));
        m_detectEdges_rdBtn->setText(QApplication::translate("CImageProcessingToolsView", "Detect Edges", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("CImageProcessingToolsView", "Method:", 0, QApplication::UnicodeUTF8));
        m_blurImage_rdBtn->setText(QApplication::translate("CImageProcessingToolsView", "Blur Image", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("CImageProcessingToolsView", "Method:", 0, QApplication::UnicodeUTF8));
        m_convertToGrayScale_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Convert to Gray Scale", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("CImageProcessingToolsView", "Method:", 0, QApplication::UnicodeUTF8));
        m_genHistogram_btn->setText(QApplication::translate("CImageProcessingToolsView", "Generate Histogram", 0, QApplication::UnicodeUTF8));
        m_reverseImageHor_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Mirror Image Horizontally", 0, QApplication::UnicodeUTF8));
        m_reverseImageVer_chkBx->setText(QApplication::translate("CImageProcessingToolsView", "Mirror Image Vertically", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CImageProcessingToolsView: public Ui_CImageProcessingToolsView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESSINGTOOLS_DCKWGT_H
