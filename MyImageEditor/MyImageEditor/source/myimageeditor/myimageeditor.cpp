

#include "myimageeditor\myimageeditor.hpp"
#include "myimageeditor\logger_defines.hpp"
#include "myimageeditor\logger.hpp"
#include "myimageeditor\settings.hpp"
#include "ui\imageeditor_graphicsview.hpp"

//#include "image\gaussian_kernel_gen.hpp"

CMyImageEditor::CMyImageEditor(QWidget* f_parent, Qt::WFlags f_flags) : 
QMainWindow(f_parent, f_flags)
{
    qRegisterMetaType<QtMsgType>("QtMsgType");

	this->prepareGui();
	this->init();

    connect(m_myImageEditor_ui.m_directCamView->getGraphicsView(), SIGNAL(updateImageEditorView(const QImage&)), 
            m_myImageEditor_ui.m_imageEditorView, SLOT(updateImage(const QImage&)));
    connect(m_myImageEditor_ui.m_imageProcessingToolsView, SIGNAL(reloadImage(const CImageEditParams&)), 
            m_myImageEditor_ui.m_imageEditorView, SLOT(reloadImage(const CImageEditParams&)));

    CSettings::getInstance(this)->restoreSettings();

    /*QDEBUG_MSG("Debug");
    QWARNING_MSG("Warning");
    QERROR_MSG("Error");
    qDebug()<<"Error1";
    qWarning()<<"Warning1";
    qCritical()<<"Critical";*/
}

CMyImageEditor::~CMyImageEditor()
{
    CSettings::getInstance()->storeSettings();
}

void CMyImageEditor::init()
{
    //logger
    qInstallMsgHandler(CLogger::logMessageOutput);
    //logger connection has to be make first before starting with other UI initialisation, in order to catch errors while doing UI initialisation
    connect(CLogger::getInstance(), SIGNAL(logMessage(QtMsgType, QString)), m_myImageEditor_ui.m_loggingView, SLOT(addMessage(QtMsgType, QString)));


	m_myImageEditor_ui.m_directCamView->init(this);
    m_myImageEditor_ui.m_histogramView->init(this);
    m_myImageEditor_ui.m_loggingView->init(this);
    m_myImageEditor_ui.m_imageEditorView->init(this);
    m_myImageEditor_ui.m_imageProcessingToolsView->init(this);

    /*CGaussianKernalGen<5> l_kernal;
    CGaussianKernalGen<5>::ImageKernalType l_image;
    l_kernal(l_image, 1);*/
}

void CMyImageEditor::prepareGui()
{
	m_myImageEditor_ui.setupUi(this); 
	m_myImageEditor_ui.centralwidget->hide();
}

CHistogramViewWrpr* CMyImageEditor::getHistogramView()
{
    return m_myImageEditor_ui.m_histogramView;
}

QImage CMyImageEditor::getImageEditorImage()
{
    return m_myImageEditor_ui.m_imageEditorView->getGraphicsView()->getCurrentImage();
}