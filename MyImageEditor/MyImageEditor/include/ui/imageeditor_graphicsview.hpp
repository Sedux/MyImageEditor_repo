

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

private:
    QGraphicsScene* m_scene;
    QGraphicsPixmapItem*    m_imageItem;

signals:

public slots:
	
};

#endif //IMAGEEDITOR_GRAPHICSVIEW_HPP