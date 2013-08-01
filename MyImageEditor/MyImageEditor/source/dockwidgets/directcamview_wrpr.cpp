
#include "dockwidgets\directcamview_wrpr.hpp"

CDirectCamViewWrpr::CDirectCamViewWrpr(QWidget* f_parent, Qt::WFlags f_flag):
QDockWidget(f_parent, f_flag),
	m_webCamSettingsMgr(),
    m_sliderDragged_b(false)
{
	
}

CDirectCamViewWrpr::~CDirectCamViewWrpr()
{
}

void CDirectCamViewWrpr::setWidget(QWidget* f_widget)
{
    m_directCamView_ui.setupUi(this);
    
    m_directCamView_ui.m_playPause_btn->setIcon(style()->standardIcon( QStyle::SP_MediaPlay ));
    m_directCamView_ui.m_prevFrame_btn->setIcon(style()->standardIcon( QStyle::SP_MediaSeekBackward ));
    m_directCamView_ui.m_nextFrame_btn->setIcon(style()->standardIcon( QStyle::SP_MediaSeekForward ));
    m_directCamView_ui.m_firstFrame_btn->setIcon(style()->standardIcon( QStyle::SP_MediaSkipBackward ));
    m_directCamView_ui.m_lastFrame_btn->setIcon(style()->standardIcon( QStyle::SP_MediaSkipForward ));

	connect(m_directCamView_ui.m_startStop_btn, SIGNAL(clicked()), this, SLOT(startStopBtnClicked()));
	connect(m_directCamView_ui.m_clr_btn, SIGNAL(clicked()), this, SLOT(clrBtnClicked()));
	connect(m_directCamView_ui.m_saveImage_btn, SIGNAL(clicked()), this, SLOT(saveImgBtnClicked()));
	connect(m_directCamView_ui.m_startStopRec_btn, SIGNAL(clicked()), this, SLOT(startStopRecBtnClicked()));
	connect(m_directCamView_ui.m_openFile_btn, SIGNAL(clicked()), this, SLOT(openFileBtnClicked()));
	connect(m_directCamView_ui.m_camRes_comBx, SIGNAL(currentIndexChanged(const QString&)), this, SLOT(camResChanged(const QString&)));

    connect(m_directCamView_ui.m_playPause_btn, SIGNAL(clicked()), this, SLOT(playPauseBtnClicked()));
    connect(m_directCamView_ui.m_prevFrame_btn, SIGNAL(clicked()), m_directCamView_ui.m_graphicsView, SLOT(getPrevFrame()));
    connect(m_directCamView_ui.m_nextFrame_btn, SIGNAL(clicked()), m_directCamView_ui.m_graphicsView, SLOT(getNextFrame()));
    connect(m_directCamView_ui.m_firstFrame_btn, SIGNAL(clicked()), m_directCamView_ui.m_graphicsView, SLOT(getFirstFrame()));
    connect(m_directCamView_ui.m_lastFrame_btn, SIGNAL(clicked()), m_directCamView_ui.m_graphicsView, SLOT(getLastFrame()));
    connect(m_directCamView_ui.m_frameSlider, SIGNAL(sliderPressed()), this, SLOT(sliderDragStart()),  Qt::AutoConnection);
    connect(m_directCamView_ui.m_frameSlider, SIGNAL(sliderReleased()), this, SLOT(sliderDragEnd()),  Qt::AutoConnection);
    connect(m_directCamView_ui.m_frameSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderValueChanged(int)),  Qt::AutoConnection);

    connect(m_directCamView_ui.m_graphicsView, SIGNAL(updateSeqCtrl()), this, SLOT(updateSeqCtrl()));
}

void CDirectCamViewWrpr::init(IMyImageEditor* f_int)
{
    this->setMyImageEditorInt(f_int);
	m_directCamView_ui.m_graphicsView->init();
	m_directCamView_ui.m_clr_btn->setEnabled(false);
	m_directCamView_ui.m_saveImage_btn->setEnabled(false);
	m_directCamView_ui.m_startStopRec_btn->setEnabled(false);
	m_directCamView_ui.m_openFile_btn->setEnabled(true);

	//http://openmeetings.apache.org/WebcamResolutions.html
	m_webCamSettingsMgr.registerSetting("160X120", 160, 120);
	m_webCamSettingsMgr.registerSetting("240X180", 240, 180);
	m_webCamSettingsMgr.registerSetting("480X360", 480, 360);
	m_webCamSettingsMgr.registerSetting("640X480", 640, 480);
	m_webCamSettingsMgr.registerSetting("1024X600", 1024, 600);
	m_webCamSettingsMgr.registerSetting("1024X768", 1024, 768);

	m_directCamView_ui.m_camRes_comBx->addItems(m_webCamSettingsMgr.getAllSettings());
	m_directCamView_ui.m_camRes_comBx->setCurrentIndex(m_directCamView_ui.m_camRes_comBx->findText("640X480"));

    this->enableSeqCtrl(false);
}

QGraphicsView* CDirectCamViewWrpr::getGraphicsView()
{
    return  m_directCamView_ui.m_graphicsView;
}

void CDirectCamViewWrpr::startStopBtnClicked()
{
    if(true == m_directCamView_ui.m_graphicsView->isVideoPlaying())
    {
        this->playPauseBtnClicked();
    }

    m_directCamView_ui.m_graphicsView->closeVideo();
    this->enableSeqCtrl(false);
	if(true == m_directCamView_ui.m_graphicsView->isStreamEnabled())
	{
		if(true == m_directCamView_ui.m_graphicsView->isRecordEnabled())
		{
			this->startStopRecBtnClicked();
		}

		m_directCamView_ui.m_graphicsView->enableStream(false);
		m_directCamView_ui.m_startStop_btn->setText("Start Streaming");

		m_directCamView_ui.m_clr_btn->setEnabled(true);
		m_directCamView_ui.m_saveImage_btn->setEnabled(true);
		m_directCamView_ui.m_startStopRec_btn->setEnabled(false);
		m_directCamView_ui.m_openFile_btn->setEnabled(true);
	}
	else
	{
		m_directCamView_ui.m_graphicsView->enableStream(true);
		m_directCamView_ui.m_startStop_btn->setText("Stop Streaming");

		m_directCamView_ui.m_clr_btn->setEnabled(false);
		m_directCamView_ui.m_saveImage_btn->setEnabled(false);
		m_directCamView_ui.m_startStopRec_btn->setEnabled(true);
		m_directCamView_ui.m_openFile_btn->setEnabled(false);
	}
}

void CDirectCamViewWrpr::clrBtnClicked()
{
	m_directCamView_ui.m_graphicsView->clearView();
	m_directCamView_ui.m_clr_btn->setEnabled(false);
	m_directCamView_ui.m_saveImage_btn->setEnabled(false);
}

void CDirectCamViewWrpr::saveImgBtnClicked()
{
	QString fileName = QFileDialog::getSaveFileName(this, "Save File Name:", QString(), "*.jpg");
	if(false == fileName.isEmpty())
	{
		m_directCamView_ui.m_graphicsView->getCurrentPixmap().save(fileName);
	}
}

void CDirectCamViewWrpr::startStopRecBtnClicked()
{
	if(true == m_directCamView_ui.m_graphicsView->isRecordEnabled())
	{
		m_directCamView_ui.m_graphicsView->enableRecord(false);
		m_directCamView_ui.m_startStopRec_btn->setText("Start Recording");
		m_directCamView_ui.m_camRes_comBx->setEnabled(true);

		QString l_fileName = QFileDialog::getSaveFileName(this, "Save Recorded File", QString(), "*.avi");
		if(false == l_fileName.isEmpty())
		{
			QFile::copy("temp.avi", l_fileName);
		}
	}
	else
	{
		m_directCamView_ui.m_graphicsView->enableRecord(true);
		m_directCamView_ui.m_startStopRec_btn->setText("Stop Recording");
		m_directCamView_ui.m_camRes_comBx->setEnabled(false);
	}
}

void CDirectCamViewWrpr::openFileBtnClicked()
{
    QString l_fileName = QFileDialog::getOpenFileName(this, "Select an image or video file", QString(), "*.jpg *.bmp *.tif *.avi");
	if(false == l_fileName.isEmpty())
	{
		QString l_suffix = QFileInfo(l_fileName).suffix();
		if(QString("jpg") == l_suffix || QString("bmp") == l_suffix || QString("tif") == l_suffix)
		{
			m_directCamView_ui.m_graphicsView->openImage(l_fileName);
            this->enableSeqCtrl(false);
		}
		else if(QString("avi") == l_suffix)
		{
			m_directCamView_ui.m_graphicsView->openVideo(l_fileName);
            this->enableSeqCtrl(true);
            m_directCamView_ui.m_frameSlider->setRange(0, m_directCamView_ui.m_graphicsView->getFrameCnt() - 1);
		}
	}
}

void CDirectCamViewWrpr::camResChanged(const QString& f_res)
{
	m_directCamView_ui.m_graphicsView->changeCamRes(m_webCamSettingsMgr.getWidth(f_res), m_webCamSettingsMgr.getHeight(f_res));
}

void CDirectCamViewWrpr::playPauseBtnClicked()
{
    if(true == m_directCamView_ui.m_graphicsView->isVideoPlaying())
    {
        m_directCamView_ui.m_playPause_btn->setIcon(style()->standardIcon( QStyle::SP_MediaPlay ));
        m_directCamView_ui.m_graphicsView->pause();
        
    }
    else
    {
        m_directCamView_ui.m_playPause_btn->setIcon(style()->standardIcon( QStyle::SP_MediaPause ));
        m_directCamView_ui.m_graphicsView->play();
    }
}

void CDirectCamViewWrpr::sliderDragStart()
{
    m_sliderDragged_b = true;
}

void CDirectCamViewWrpr::sliderDragEnd()
{
    m_sliderDragged_b = false;
    m_directCamView_ui.m_graphicsView->getFrame(m_directCamView_ui.m_frameSlider->value());
}

void CDirectCamViewWrpr::sliderValueChanged(int f_value)
{
    if(true == m_sliderDragged_b)
    {
        
    }
}

void CDirectCamViewWrpr::updateSeqCtrl()
{
    int frmCnt = m_directCamView_ui.m_graphicsView->getFrameCnt();
    int crtFrm = m_directCamView_ui.m_graphicsView->getCurrentFrameNum();

    m_directCamView_ui.m_frameSlider->setValue(crtFrm);
    if(0 == crtFrm)
    {
        this->enableSeqCtrl(true);
        m_directCamView_ui.m_firstFrame_btn->setEnabled(false);
        m_directCamView_ui.m_prevFrame_btn->setEnabled(false);
    }
    else if(crtFrm == frmCnt - 1)
    {
        this->enableSeqCtrl(true);
        m_directCamView_ui.m_nextFrame_btn->setEnabled(false);
        m_directCamView_ui.m_lastFrame_btn->setEnabled(false);
        m_directCamView_ui.m_playPause_btn->setEnabled(false);
    }
    else
    {
        this->enableSeqCtrl(true);
    }
}

void CDirectCamViewWrpr::enableSeqCtrl(bool f_enable_b)
{
    m_directCamView_ui.m_firstFrame_btn->setEnabled(f_enable_b);
    m_directCamView_ui.m_prevFrame_btn->setEnabled(f_enable_b);
    m_directCamView_ui.m_nextFrame_btn->setEnabled(f_enable_b);
    m_directCamView_ui.m_lastFrame_btn->setEnabled(f_enable_b);
    m_directCamView_ui.m_playPause_btn->setEnabled(f_enable_b);
    m_directCamView_ui.m_frameSlider->setEnabled(f_enable_b);
}