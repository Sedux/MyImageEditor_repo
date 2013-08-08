

#include "dockwidgets\imageeditorview_wrpr.hpp"
#include "dockwidgets\histogramview_wrpr.hpp"
#include "ocv\col_to_gray_converter.hpp"
#include "ocv\otsu_thresholder.hpp"

CImageEditorViewWrpr::CImageEditorViewWrpr(QWidget* f_parent, Qt::WFlags f_flag):
    QDockWidget(f_parent, f_flag)
{
	
}

CImageEditorViewWrpr::~CImageEditorViewWrpr()
{
}

void CImageEditorViewWrpr::setWidget(QWidget* f_widget)
{
    m_imageEditorView_ui.setupUi(this);
    connect(m_imageEditorView_ui.m_genHistogram_btn, SIGNAL(clicked()), this, SLOT(genHistogramBtnClicked()));
    connect(m_imageEditorView_ui.m_convertToGrayScale_chkBx, SIGNAL(stateChanged(int)), this, SLOT(reloadImage()));
    connect(m_imageEditorView_ui.m_convertToMonochkBx, SIGNAL(stateChanged(int)), this, SLOT(reloadImage()));
    connect(m_imageEditorView_ui.m_grayScaleMethod_comBx, SIGNAL(currentIndexChanged(int)), this, SLOT(reloadImage()));
}

void CImageEditorViewWrpr::init(IMyImageEditor* f_int)
{
    this->setMyImageEditorInt(f_int);
    m_imageEditorView_ui.m_graphicsView->init();

    QStringList l_grayScaleConvList = CColToGrayConv::getConMethods();
    m_imageEditorView_ui.m_grayScaleMethod_comBx->addItems(l_grayScaleConvList);
}

QGraphicsView* CImageEditorViewWrpr::getGraphicsView()
{
    return  m_imageEditorView_ui.m_graphicsView;
}

void CImageEditorViewWrpr::genHistogramBtnClicked()
{
    CHistogramViewWrpr* histView = dynamic_cast<CHistogramViewWrpr*>(this->m_myImageEditorInt->getHistogramView());
    histView->calculateHistogram(m_imageEditorView_ui.m_graphicsView->getCurrentImage());
}

void CImageEditorViewWrpr::updateImage(const QImage& f_image)
{
    m_image = f_image;
    QImage l_convertedImage = f_image;
    if(true == m_imageEditorView_ui.m_convertToGrayScale_chkBx->isChecked())
    {
        CColToGrayConv l_grayScaleConv;
        l_convertedImage = l_grayScaleConv.convertToGray(f_image, static_cast<CColToGrayConv::EMethod>(m_imageEditorView_ui.m_grayScaleMethod_comBx->currentIndex()));   
    }

    if((QImage::Format_Indexed8 == l_convertedImage.format()) && (true ==  m_imageEditorView_ui.m_convertToMonochkBx->isChecked()))
    {
        l_convertedImage = COtsuThresholder::convertGrayToBinary(l_convertedImage);
    }

    m_imageEditorView_ui.m_graphicsView->updateImage(l_convertedImage);
}

void CImageEditorViewWrpr::reloadImage()
{
    if(false == m_image.isNull())
    {
        this->updateImage(m_image);
    }
}



