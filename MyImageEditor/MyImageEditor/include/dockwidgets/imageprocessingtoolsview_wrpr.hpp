


#ifndef IMAGEPROCESSINGTOOLSVIEW_WRPR_HPP
#define IMAGEPROCESSINGTOOLSVIEW_WRPR_HPP

#include <QtGui\QtGui>

#include "ui_imageprocessingtools_dckwgt.h"

#include "dockwidgets\dockwidget_base.hpp"
#include "image\image_edit_params.hpp"

class CImageProcessingToolsViewWrpr : public QDockWidget, public IDckWidget
{
    Q_OBJECT

public:
    CImageProcessingToolsViewWrpr(QWidget* f_parent = 0, Qt::WFlags f_flag = 0);
    ~CImageProcessingToolsViewWrpr();

	void setWidget(QWidget* f_widget);

	void init(IMyImageEditor* f_int);
   
private:
	Ui::CImageProcessingToolsView m_imageProcessingToolsView_ui;

signals:
    void reloadImage(const CImageEditParams& f_imageEditParams);

private slots:
    void genHistogramBtnClicked();
    void doReloadImage();
  
};

#endif //IMAGEPROCESSINGTOOLSVIEW_WRPR_HPP