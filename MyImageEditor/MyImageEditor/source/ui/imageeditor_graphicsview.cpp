

#include "ui\imageeditor_graphicsview.hpp"
#include "ocv\col_to_gray_converter.hpp"
#include "ocv\ocv_utils.hpp"

CImageEditorGraphicsView::CImageEditorGraphicsView(QWidget* f_parent): QGraphicsView(f_parent)
{
    m_scene = new QGraphicsScene();
	m_imageItem = new QGraphicsPixmapItem();
}

//dest
CImageEditorGraphicsView::~CImageEditorGraphicsView()
{
}

void CImageEditorGraphicsView::init()
{
	this->setScene(m_scene);
	m_scene->addItem(m_imageItem);
}

void CImageEditorGraphicsView::updateImage(const QImage& f_image)
{
    m_imageItem->setPixmap(QPixmap::fromImage(f_image));
}

QImage CImageEditorGraphicsView::getCurrentImage()
{
    return m_imageItem->pixmap().toImage();
}


