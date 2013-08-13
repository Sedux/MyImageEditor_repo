

#ifndef IMAGEEDITORVIEW_WRPR_HPP
#define IMAGEEDITORVIEW_WRPR_HPP

#include <QtGui\QtGui>

#include "ui_imageeditorview_dckwgt.h"

#include "dockwidgets\dockwidget_base.hpp"
#include "ui\imageeditor_graphicsview.hpp"
#include "image\image_edit_params.hpp"

class CImageEditorViewWrpr : public QDockWidget, public IDckWidget
{
    Q_OBJECT

public:
    CImageEditorViewWrpr(QWidget* f_parent = 0, Qt::WFlags f_flag = 0);
    ~CImageEditorViewWrpr();

	void setWidget(QWidget* f_widget);

	void init(IMyImageEditor* f_int);

    CImageEditorGraphicsView* getGraphicsView();

private:
	Ui::CImageEditorView m_imageEditorView_ui;
    QImage m_image;
    CImageEditParams m_imageEditParmas;

private slots:

    void updateImage(const QImage& f_image);
    void reloadImage(const CImageEditParams& f_imageEditParams);
};

#endif //IMAGEEDITORVIEW_WRPR_HPP