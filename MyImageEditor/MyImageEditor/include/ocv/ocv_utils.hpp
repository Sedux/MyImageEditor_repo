
#ifndef OCV_UTILS_HPP
#define OCV_UTILS_HPP

#include "opencv\cv.h"
#include "opencv\highgui.h"

#include <QtGui\QtGui>

namespace utils
{
    inline QImage MatToQImage(const cv::Mat& f_matImage)
    {
        cv::Mat l_image;
        cv::cvtColor(f_matImage, l_image, CV_BGR2RGB); //to convert from BGR to RGB
	    QImage l_qImage(l_image.data, l_image.cols, l_image.rows, l_image.step, QImage::Format_RGB888); 
        return l_qImage.copy();
    }

    inline QImage MatToQImageG(const cv::Mat& f_matImage)
    {
        QImage l_qImage(f_matImage.data, f_matImage.cols, f_matImage.rows, f_matImage.step, QImage::Format_Indexed8); 
        return l_qImage.copy();
    }

    inline cv::Mat QImageToMat(const QImage& f_qImage)
    {
        QImage l_image = f_qImage.convertToFormat(QImage::Format_RGB888);
        cv::Mat l_matImage = cv::Mat(l_image.height(), l_image.width(), CV_8UC3, l_image.bits(), l_image.bytesPerLine());
        cv::Mat l_matImageClone = l_matImage.clone();
        cv::cvtColor(l_matImageClone, l_matImageClone, CV_RGB2BGR);
        return l_matImageClone;
    }

    template<class type>
    inline type min(const type& f_first, const type& f_second)
    {
        return (f_first > f_second) ? f_second : f_first;
    }

    template<class type>
    inline type max(const type& f_first, const type& f_second)
    {
        return (f_first < f_second) ? f_second : f_first;
    }

}

#endif