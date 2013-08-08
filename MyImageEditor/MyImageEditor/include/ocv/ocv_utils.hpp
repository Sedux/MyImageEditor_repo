
#ifndef OCV_UTILS_HPP
#define OCV_UTILS_HPP

#include "opencv\cv.h"
#include "opencv\highgui.h"

#include <QtGui\QtGui>
#include "myimageeditor\logger_defines.hpp"

namespace utils
{
    inline QImage MatToQImage(const cv::Mat& f_matImage)
    {
        cv::Mat l_image;
        if(CV_8UC3 == f_matImage.type())
        {
            cv::cvtColor(f_matImage, l_image, CV_BGR2RGB); //to convert from BGR to RGB
	        QImage l_qImage(l_image.data, l_image.cols, l_image.rows, l_image.step, QImage::Format_RGB888); 
            return l_qImage.copy();
        }
        else if(CV_8UC1 == f_matImage.type())
        {
            QImage l_qImage(f_matImage.data, f_matImage.cols, f_matImage.rows, f_matImage.step, QImage::Format_Indexed8); 
            l_qImage = l_qImage.copy();
            for(int l_count = 0; l_count < 256; l_count++)
            {
                l_qImage.setColor(l_count, QColor(l_count, l_count, l_count).rgb());
            }
            return l_qImage;
        }

        QERROR_MSG("MatToQImage: Unsupported Image Format");
        return QImage();
    }

    inline cv::Mat QImageToMat(const QImage& f_qImage)
    {
        QImage l_temp(f_qImage);
        QImage::Format l_f = f_qImage.format();
       
        if(QImage::Format_Indexed8 == f_qImage.format())
        {
            cv::Mat l_matImage = cv::Mat(l_temp.height(), l_temp.width(), CV_8UC1, l_temp.bits(), l_temp.bytesPerLine());
            cv::Mat l_matImageClone = l_matImage.clone();
            return l_matImageClone;
        }
        else
        {
            l_temp = l_temp.convertToFormat(QImage::Format_RGB888);
            cv::Mat l_matImage = cv::Mat(l_temp.height(), l_temp.width(), CV_8UC3, l_temp.bits(), l_temp.bytesPerLine());
            cv::Mat l_matImageClone = l_matImage.clone();
            cv::cvtColor(l_matImageClone, l_matImageClone, CV_RGB2BGR); //to convert from RGB to BGR
            return l_matImageClone;
        }

        QERROR_MSG("QImageToMat: Unsupported Image Format");
        return cv::Mat();
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