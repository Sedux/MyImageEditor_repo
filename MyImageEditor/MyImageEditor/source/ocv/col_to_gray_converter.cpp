
#include "ocv\col_to_gray_converter.hpp"
#include "ocv\ocv_utils.hpp"

QImage CColToGrayConv::convertToGray(const QImage& f_image, const CColToGrayConv::EMethod& f_method_e)
{
    if(QImage::Format_Indexed8 == f_image.format())
    {
        return f_image;
    }

    QImage l_outImage(f_image.width(), f_image.height(), QImage::Format_Indexed8);
    for(int l_count = 0; l_count < 256; l_count++)
    {
        l_outImage.setColor(l_count, QColor(l_count, l_count, l_count).rgb());
    }

    switch(f_method_e)
    {
    case OCV:
        convertByOCV(f_image, l_outImage);
        break;
    case LIGHTNESS:
        convertByLightness(f_image, l_outImage);
        break;
    case AVERAGE:
        convertByAverage(f_image, l_outImage);
        break;
    case LUMINOSITY:
        convertByLuminosity(f_image, l_outImage);
        break;
    }

    return l_outImage;
}

QStringList CColToGrayConv::getConMethods()
{
    QStringList strList;
    strList.append(TOSTR(OCV));
    strList.append(TOSTR(LIGHTNESS));
    strList.append(TOSTR(AVERAGE));
    strList.append(TOSTR(LUMINOSITY));
    return strList;
}


void CColToGrayConv::convertByOCV(const QImage& f_inImage, QImage& f_outImage)
{
    cv::Mat l_image = utils::QImageToMat(f_inImage);
    cv::cvtColor(l_image, l_image, CV_BGR2GRAY);
    f_outImage = utils::MatToQImage(l_image);
}

//http://www.johndcook.com/blog/2009/08/24/algorithms-convert-color-grayscale/

void CColToGrayConv::convertByLightness(const QImage& f_inImage, QImage& f_outImage)
{
     for(int l_x = 0; l_x < f_inImage.width(); l_x++)
    {
        for(int l_y = 0; l_y < f_inImage.height(); l_y++)
        {
            QRgb rgb = f_inImage.pixel(l_x, l_y);
            QColor color = QColor(rgb);
            int min = utils::min(utils::min(color.red(), color.green()), color.blue());
            int max = utils::max(utils::max(color.red(), color.green()), color.blue());
            int avg = (min + max) / 2;
            f_outImage.setPixel(l_x, l_y, avg);
        }
    }
}

void CColToGrayConv::convertByAverage(const QImage& f_inImage, QImage& f_outImage)
{
    for(int l_x = 0; l_x < f_inImage.width(); l_x++)
    {
        for(int l_y = 0; l_y < f_inImage.height(); l_y++)
        {
            QRgb rgb = f_inImage.pixel(l_x, l_y);
            QColor color = QColor(rgb);
            int avg = (color.red() + color.green() + color.blue())/3;
            f_outImage.setPixel(l_x, l_y, avg);
        }
    }
}

void CColToGrayConv::convertByLuminosity(const QImage& f_inImage, QImage& f_outImage)
{
    for(int l_x = 0; l_x < f_inImage.width(); l_x++)
    {
        for(int l_y = 0; l_y < f_inImage.height(); l_y++)
        {
            QRgb rgb = f_inImage.pixel(l_x, l_y);
            QColor color = QColor(rgb);
            int value = color.red() * 0.21f + color.green() * 0.71f + color.blue() * 0.07f;
            f_outImage.setPixel(l_x, l_y, value);
        }
    }
}
