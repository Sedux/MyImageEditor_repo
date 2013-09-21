

#include "dockwidgets\imageprocessingtoolsview_wrpr.hpp"
#include "dockwidgets\histogramview_wrpr.hpp"
#include "image\col_to_gray_converter.hpp"
#include "image\edge_detector.hpp"

CImageProcessingToolsViewWrpr::CImageProcessingToolsViewWrpr(QWidget* f_parent, Qt::WFlags f_flag):
    QDockWidget(f_parent, f_flag)
{
}

CImageProcessingToolsViewWrpr::~CImageProcessingToolsViewWrpr()
{
}

void CImageProcessingToolsViewWrpr::setWidget(QWidget* f_widget)
{
    m_imageProcessingToolsView_ui.setupUi(this);
    m_imageProcessingToolsView_ui.m_none_rdBtn->setChecked(true);
    connect(m_imageProcessingToolsView_ui.m_genHistogram_btn, SIGNAL(clicked()), this, SLOT(genHistogramBtnClicked()));
    connect(m_imageProcessingToolsView_ui.m_convertToGrayScale_chkBx, SIGNAL(stateChanged(int)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_none_rdBtn, SIGNAL(clicked(bool)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_convertToMono_rdBtn, SIGNAL(clicked(bool)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_detectEdges_rdBtn, SIGNAL(clicked(bool)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_blurImage_rdBtn, SIGNAL(clicked(bool)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_grayScaleMethod_comBx, SIGNAL(currentIndexChanged(int)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_detectEdges_comBx, SIGNAL(currentIndexChanged(int)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_blurImageMethod_comBx, SIGNAL(currentIndexChanged(int)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_reverseImageHor_chkBx, SIGNAL(stateChanged(int)), this, SLOT(doReloadImage()));
    connect(m_imageProcessingToolsView_ui.m_reverseImageVer_chkBx, SIGNAL(stateChanged(int)), this, SLOT(doReloadImage()));
}

void CImageProcessingToolsViewWrpr::init(IMyImageEditor* f_int)
{
    this->setMyImageEditorInt(f_int);
    
    QStringList l_grayScaleConvList = CColToGrayConv::getConMethods();
    m_imageProcessingToolsView_ui.m_grayScaleMethod_comBx->addItems(l_grayScaleConvList);

    QStringList l_edgeDetectorList = CEdgeDetector::getConMethods();
    m_imageProcessingToolsView_ui.m_detectEdges_comBx->addItems(l_edgeDetectorList);

    QStringList l_imageBlurMethods = CImageBlur::getBlurMethods();
    m_imageProcessingToolsView_ui.m_blurImageMethod_comBx->addItems(l_imageBlurMethods);
}

void CImageProcessingToolsViewWrpr::genHistogramBtnClicked()
{
    CHistogramViewWrpr* histView = dynamic_cast<CHistogramViewWrpr*>(this->m_myImageEditorInt->getHistogramView());
    histView->calculateHistogram(this->m_myImageEditorInt->getImageEditorImage());
}

void CImageProcessingToolsViewWrpr::doReloadImage()
{
    CImageEditParams l_imageEditParams;
    l_imageEditParams.m_reverseImageHor_b = m_imageProcessingToolsView_ui.m_reverseImageHor_chkBx->isChecked();
    l_imageEditParams.m_reverseImageVer_b = m_imageProcessingToolsView_ui.m_reverseImageVer_chkBx->isChecked();
    l_imageEditParams.m_convertToGray_b = m_imageProcessingToolsView_ui.m_convertToGrayScale_chkBx->isChecked();
    l_imageEditParams.m_colToGrayMethod = static_cast<CColToGrayConv::EMethod>(m_imageProcessingToolsView_ui.m_grayScaleMethod_comBx->currentIndex());   
    l_imageEditParams.m_convertToMonochrome_b = m_imageProcessingToolsView_ui.m_convertToMono_rdBtn->isChecked();
    l_imageEditParams.m_detectEdges_b = m_imageProcessingToolsView_ui.m_detectEdges_rdBtn->isChecked();
    l_imageEditParams.m_edgeDetectionMethod = static_cast<CEdgeDetector::EMethod>(m_imageProcessingToolsView_ui.m_detectEdges_comBx->currentIndex());
    l_imageEditParams.m_blurImage_b = m_imageProcessingToolsView_ui.m_blurImage_rdBtn->isChecked();
    l_imageEditParams.m_imageBlurMethod = static_cast<CImageBlur::EMethod>(m_imageProcessingToolsView_ui.m_blurImageMethod_comBx->currentIndex());

    emit reloadImage(l_imageEditParams);
}




