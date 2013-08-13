

#ifndef DIRECTCAM_GRAPHICSVIEW_HPP
#define DIRECTCAM_GRAPHICSVIEW_HPP

#include "opencv\cv.h"
#include "opencv\highgui.h"

#include <QtGui\QtGui>


class CDirectCamGraphicsView : public QGraphicsView
{
Q_OBJECT

public:
    //const
    CDirectCamGraphicsView(QWidget* f_parent);
    //dest
    ~CDirectCamGraphicsView();

	void init();

	void enableStream(bool f_enable_b);
	bool isStreamEnabled();

	void clearView();
	QImage getCurrentImage();
    QPixmap getCurrentPixmap();

	void enableRecord(bool f_enable_b);
	bool isRecordEnabled();

	void openImage(const QString& f_fileName);
	void openVideo(const QString& f_fileName);
    void closeVideo();

	void changeCamRes(const int& f_width, const int& f_height);

    bool isVideoPlaying();

    int getFrameCnt();
    int getCurrentFrameNum();

protected:
    void paintEvent(QPaintEvent* f_event);
    void wheelEvent(QWheelEvent* f_event);
    void mouseMoveEvent(QMouseEvent* f_event);

private:

	QTimer* m_videoTimer;

	QGraphicsScene* m_scene;
	QGraphicsPixmapItem*    m_imageItem;

	cv::VideoCapture m_camReader;
    cv::VideoCapture m_videoReader;
	cv::VideoWriter  m_videoWriter;

    QString m_videoFile;

	int m_camHeight;
	int m_camWidth;

    bool m_isPlaying;
    
    int m_scaleVal;

    void updateImage(const cv::Mat& f_image);

    void doScaling(int f_scaleValue);

signals:
    void graphicsViewRedrawn(const QPoint& f_originGlobal, const QPoint& f_100Global);
    void curMousePos(const QPoint& f_mousePosGlobal);

    void updateSeqCtrl();
    void updateImageEditorView(const QImage& f_image);

public slots:
	void tmrTimeOut();

    void play();
    void pause();
    void getFrame(const int& f_frameNum);
    void getNextFrame();
    void getPrevFrame();
    void getFirstFrame();
    void getLastFrame();
};

#endif