

#include "dockwidgets\imageeditorview_wrpr.hpp"
#include "image\col_to_gray_converter.hpp"
#include "image\otsu_thresholder.hpp"
#include "image\edge_detector.hpp"

CImageEditorViewWrpr::CImageEditorViewWrpr(QWidget* f_parent, Qt::WFlags f_flag):
    QDockWidget(f_parent, f_flag),
    m_imageEditParmas()
{
}

CImageEditorViewWrpr::~CImageEditorViewWrpr()
{
}

void CImageEditorViewWrpr::setWidget(QWidget* f_widget)
{
    m_imageEditorView_ui.setupUi(this);
    m_imageEditorView_ui.m_horRuler_wdgt->setOrientation(CRulerWidget::HORIZONTAL);
    m_imageEditorView_ui.m_verRuler_wdgt->setOrientation(CRulerWidget::VERTICAL);
    connect(m_imageEditorView_ui.m_graphicsView, SIGNAL(graphicsViewRedrawn(const QPoint&, const QPoint&)), 
            m_imageEditorView_ui.m_horRuler_wdgt, SLOT(graphicsViewRedrawn(const QPoint&, const QPoint&)));
    connect(m_imageEditorView_ui.m_graphicsView, SIGNAL(graphicsViewRedrawn(const QPoint&, const QPoint&)), 
            m_imageEditorView_ui.m_verRuler_wdgt, SLOT(graphicsViewRedrawn(const QPoint&, const QPoint&)));
    connect(m_imageEditorView_ui.m_graphicsView, SIGNAL(curMousePos(const QPoint&)), 
            m_imageEditorView_ui.m_horRuler_wdgt, SLOT(setCurrentPos(const QPoint&)));
    connect(m_imageEditorView_ui.m_graphicsView, SIGNAL(curMousePos(const QPoint&)), 
            m_imageEditorView_ui.m_verRuler_wdgt, SLOT(setCurrentPos(const QPoint&)));

}

void CImageEditorViewWrpr::init(IMyImageEditor* f_int)
{
    this->setMyImageEditorInt(f_int);
    m_imageEditorView_ui.m_graphicsView->init();
}

CImageEditorGraphicsView* CImageEditorViewWrpr::getGraphicsView()
{
    return  m_imageEditorView_ui.m_graphicsView;
}

void CImageEditorViewWrpr::updateImage(const QImage& f_image)
{
    m_image = f_image;
    QImage l_convertedImage = f_image;
     
    l_convertedImage = l_convertedImage.mirrored(m_imageEditParmas.m_reverseImageHor_b, m_imageEditParmas.m_reverseImageVer_b);
    
    if(true == m_imageEditParmas.m_convertToGray_b)
    {
        CColToGrayConv l_grayScaleConv;
        l_convertedImage = l_grayScaleConv.convertToGray(l_convertedImage, m_imageEditParmas.m_colToGrayMethod);   
    }

    if(QImage::Format_Indexed8 == l_convertedImage.format())
    {
        if(true ==  m_imageEditParmas.m_convertToMonochrome_b)
        {
            l_convertedImage = COtsuThresholder::convertGrayToBinary(l_convertedImage);
        }
        else if(true ==  m_imageEditParmas.m_detectEdges_b)
        {
            CEdgeDetector l_edgeDetector;
            l_convertedImage = l_edgeDetector.detectEdges(l_convertedImage, m_imageEditParmas.m_edgeDetectionMethod);
        }
    }

    m_imageEditorView_ui.m_graphicsView->updateImage(l_convertedImage);
}

void CImageEditorViewWrpr::reloadImage(const CImageEditParams& f_imageEditParams)
{
    m_imageEditParmas = f_imageEditParams;
    if(false == m_image.isNull())
    {
        this->updateImage(m_image);
    }
}



