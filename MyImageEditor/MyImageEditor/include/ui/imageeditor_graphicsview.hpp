

#ifndef IMAGEEDITOR_GRAPHICSVIEW_HPP
#define IMAGEEDITOR_GRAPHICSVIEW_HPP

#include <QtGui\QtGui>

class CImageEditorGraphicsView : public QGraphicsView
{
Q_OBJECT

public:
    //const
    CImageEditorGraphicsView(QWidget* f_parent);
    //dest
    ~CImageEditorGraphicsView();

	void init();

    QImage getCurrentImage();

    void updateImage(const QImage& f_image);

protected:
    void paintEvent(QPaintEvent* f_event);
    void wheelEvent(QWheelEvent* f_event);
    void mouseMoveEvent(QMouseEvent* f_event);

private:
    QGraphicsScene* m_scene;
    QGraphicsPixmapItem*    m_imageItem;
    QImage                  m_displayedImage;

    int m_scaleVal;

    void doScaling(int f_scaleValue);

signals:
    void graphicsViewRedrawn(const QPoint& f_originGlobal, const QPoint& f_100Global);
    void curMousePos(const QPoint& f_mousePosGlobal);

public slots:
	
};

#endif //IMAGEEDITOR_GRAPHICSVIEW_HPP