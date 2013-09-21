

#include "ui\imageeditor_graphicsview.hpp"
#include "image\col_to_gray_converter.hpp"
#include "image\ocv_utils.hpp"

CImageEditorGraphicsView::CImageEditorGraphicsView(QWidget* f_parent): QGraphicsView(f_parent)
{
    m_scene = new QGraphicsScene();
	m_imageItem = new QGraphicsPixmapItem();

    m_scaleVal = 100;

    this->setMouseTracking(true);
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
    m_displayedImage = f_image;
    m_imageItem->setPixmap(QPixmap::fromImage(m_displayedImage));
}

QImage CImageEditorGraphicsView::getCurrentImage()
{
    return m_displayedImage;
}

void CImageEditorGraphicsView::paintEvent(QPaintEvent* f_event)
{
    QGraphicsView::paintEvent(f_event);

    QPoint l_orgGlobal = this->mapToGlobal(this->mapFromScene(QPoint(0, 0)));
    QPoint l_100Global = this->mapToGlobal(this->mapFromScene(QPoint(100, 100)));
    emit graphicsViewRedrawn(l_orgGlobal, l_100Global);
}

//use mouse wheel event for scaling
void CImageEditorGraphicsView::wheelEvent(QWheelEvent* f_event)
{
    int l_delta = f_event->delta() / 8;
    int l_deltaScale = l_delta / 15;
    
    int l_newScale = m_scaleVal + 10 * l_deltaScale;
    doScaling(l_newScale);
}

void CImageEditorGraphicsView::doScaling(int f_scaleValue)
{
    m_scaleVal = f_scaleValue;

    qreal scaleFraction = f_scaleValue * 0.01;
    setTransform(QTransform().scale(scaleFraction, scaleFraction));
}

void CImageEditorGraphicsView::mouseMoveEvent(QMouseEvent* f_event)
{
    QPoint l_org = this->mapFromScene(QPoint(0, 0));
    QPoint l_curGlobal = f_event->pos();
    emit curMousePos(l_curGlobal - l_org);

    QGraphicsView::mouseMoveEvent(f_event);
}