

#include "ui\directcam_graphicsview.hpp"
#include "ocv\ocv_utils.hpp"

CDirectCamGraphicsView::CDirectCamGraphicsView(QWidget* f_parent): QGraphicsView(f_parent),
	m_camReader(),
	m_videoWriter(),
	m_camWidth(640),
	m_camHeight(480),
    m_videoFile(),
    m_isPlaying(false)
{
	m_videoTimer = new QTimer(this);
	connect(m_videoTimer, SIGNAL(timeout()), this, SLOT(tmrTimeOut()));
	
	m_scene = new QGraphicsScene();
	m_imageItem = new QGraphicsPixmapItem();
}

//dest
CDirectCamGraphicsView::~CDirectCamGraphicsView()
{
	delete m_videoTimer;
	delete m_scene;
}

void CDirectCamGraphicsView::init()
{
	this->setScene(m_scene);
	m_scene->addItem(m_imageItem);
}

void CDirectCamGraphicsView::tmrTimeOut()
{
	cv::Mat l_camImage;

	if(false != m_camReader.read(l_camImage))
	{
		if(true ==isRecordEnabled())
		{
			m_videoWriter.write(l_camImage);
		}

		this->updateImage(l_camImage);
	}
}

void CDirectCamGraphicsView::updateImage(const cv::Mat& f_image)
{
    QImage sampleImage = utils::MatToQImage(f_image);
	m_imageItem->setPixmap(QPixmap::fromImage(sampleImage));
    emit updateImageEditorView(sampleImage);
}

void CDirectCamGraphicsView::clearView()
{
	m_imageItem->setPixmap(QPixmap());
}

void CDirectCamGraphicsView::enableStream(bool f_enable_b)
{
	if(true == f_enable_b)
	{
		m_camReader.open(0);
		bool value = m_camReader.set(CV_CAP_PROP_FRAME_WIDTH, m_camWidth);
		bool value1 = m_camReader.set(CV_CAP_PROP_FRAME_HEIGHT, m_camHeight);
		if(true == m_camReader.isOpened())
		{
			m_videoTimer->start(50);
		}
	}
	else
	{
		m_videoTimer->stop();
		m_camReader.release();
	}
}

bool CDirectCamGraphicsView::isStreamEnabled()
{
	return m_videoTimer->isActive();
}

QPixmap CDirectCamGraphicsView::getCurrentPixmap()
{
    return m_imageItem->pixmap();
}

QImage CDirectCamGraphicsView::getCurrentImage()
{
    return m_imageItem->pixmap().toImage();
}

void CDirectCamGraphicsView::enableRecord(bool f_enable_b)
{
	if(true == f_enable_b)
	{
		cv::Size size(640, 480);
		m_videoWriter.open("temp.avi", CV_FOURCC('D','I','V','X'), 20, size, true);
		if(false == m_videoWriter.isOpened())
		{
		}
	}
	else
	{
		m_videoWriter.release();
	}
}

bool CDirectCamGraphicsView::isRecordEnabled()
{
	return m_videoWriter.isOpened();
}

void CDirectCamGraphicsView::openImage(const QString& f_fileName)
{
	QImage l_image(f_fileName);
	m_imageItem->setPixmap(QPixmap::fromImage(l_image));
    emit updateImageEditorView(l_image);
}

void CDirectCamGraphicsView::openVideo(const QString& f_fileName)
{
    m_videoFile = f_fileName;
    getFirstFrame();		
}

void CDirectCamGraphicsView::closeVideo()
{
    m_videoFile.clear();
    m_videoReader.release();
}

void CDirectCamGraphicsView::getFrame(const int& f_frameNum)
{
    m_videoReader.release();
    if(false == m_videoReader.open(m_videoFile.toLocal8Bit().data()))
    {
        return;
    }

    if(0 <= f_frameNum && true == m_videoReader.isOpened())
	{
        for(int l_count = 0; l_count < f_frameNum ; l_count++)
        {
            m_videoReader.grab();
        }

        cv::Mat l_image;
        if(false != m_videoReader.read(l_image))
	    {
            this->updateImage(l_image);
            emit updateSeqCtrl();
        }
    }
}

void CDirectCamGraphicsView::getNextFrame()
{
    if(true == m_videoReader.isOpened())
    {
        cv::Mat l_image;
        if(false != m_videoReader.read(l_image))
	    {
            this->updateImage(l_image);
            emit updateSeqCtrl();
        }
    }
}

void CDirectCamGraphicsView::getPrevFrame()
{
    if(true == m_videoReader.isOpened())
    {
        int l_nextFrame = static_cast<int>(m_videoReader.get(CV_CAP_PROP_POS_FRAMES));
        int l_preFrame = l_nextFrame - 2;
        this->getFrame(l_preFrame);
    }
}

void CDirectCamGraphicsView::getFirstFrame()
{
    this->getFrame(0);
}
 
void CDirectCamGraphicsView::getLastFrame()
{
    if(true == m_videoReader.isOpened())
    {
        int l_frmCnt = static_cast<int>(m_videoReader.get(CV_CAP_PROP_FRAME_COUNT));
        this->getFrame(l_frmCnt - 1);
    }
}

void CDirectCamGraphicsView::play()
{
    if(false == this->isVideoPlaying())
    {
        m_isPlaying = true;
        while((true == m_isPlaying) && (m_videoReader.get(CV_CAP_PROP_POS_FRAMES) < m_videoReader.get(CV_CAP_PROP_FRAME_COUNT)))
        {
            this->getNextFrame();
            QApplication::processEvents();
        }
    }
}

bool CDirectCamGraphicsView::isVideoPlaying()
{
    return m_isPlaying;
}

void CDirectCamGraphicsView::pause()
{
    if(true == m_isPlaying)
    {
        m_isPlaying = false;
    }
}

void CDirectCamGraphicsView::changeCamRes(const int& f_width, const int& f_height)
{
	m_camWidth = f_width;
	m_camHeight = f_height;

	if(true == this->isStreamEnabled())
	{
		this->enableStream(false);
		this->enableStream(true);
	}
}

int CDirectCamGraphicsView::getFrameCnt()
{
    return static_cast<int>(m_videoReader.get(CV_CAP_PROP_FRAME_COUNT));
}

int CDirectCamGraphicsView::getCurrentFrameNum()
{
    return static_cast<int>(m_videoReader.get(CV_CAP_PROP_POS_FRAMES))  - 1;
}