

#ifndef DIRECTCAMVIEW_WRPR_HPP
#define DIRECTCAMVIEW_WRPR_HPP

#include <QtGui\QtGui>

#include "ui_directcamview_dckwgt.h"

#include "dockwidgets\dockwidget_base.hpp"
#include "myimageeditor\webcamsettings.hpp"

class CDirectCamViewWrpr : public QDockWidget, public IDckWidget
{
    Q_OBJECT

public:
    CDirectCamViewWrpr(QWidget* f_parent = 0, Qt::WFlags f_flag = 0);
    ~CDirectCamViewWrpr();

	void setWidget(QWidget* f_widget);

	void init(IMyImageEditor* f_int);

    QGraphicsView* getGraphicsView();

private:
	Ui::CDirectCamView m_directCamView_ui;

	wcs::CWebCamSettingsMgr m_webCamSettingsMgr;

    bool m_sliderDragged_b;

    void enableSeqCtrl(bool f_enable_b);

private slots:
	void startStopBtnClicked();
	void clrBtnClicked();
	void saveImgBtnClicked();
	void startStopRecBtnClicked();
	void openFileBtnClicked();
    void playPauseBtnClicked();
    void sliderValueChanged(int f_value);
    void sliderDragStart();
    void sliderDragEnd();

	void camResChanged(const QString& f_res);
    void updateSeqCtrl();

};

#endif