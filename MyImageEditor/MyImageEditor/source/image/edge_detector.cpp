

#include "image\edge_detector.hpp"
#include "image\ocv_utils.hpp"

QImage CEdgeDetector::detectEdges(const QImage& f_image, const CEdgeDetector::EMethod& f_method_e)
{
    QImage l_outImage(f_image.width(), f_image.height(), QImage::Format_Indexed8);
    for(int l_count = 0; l_count < 256; l_count++)
    {
        l_outImage.setColor(l_count, QColor(l_count, l_count, l_count).rgb());
    }

    switch(f_method_e)
    {
    case ROBERTS:
        detectByRoberts(f_image, l_outImage);
        break;
    case SOBEL:
        detectBySobel(f_image, l_outImage);
        break;
    case PREWITTS:
        detectByPrewitts(f_image, l_outImage);
        break;
    case CANNY:
        detectByCanny(f_image, l_outImage);
        break;
    }

    return l_outImage;
}

QStringList CEdgeDetector::getConMethods()
{
    QStringList strList;
    strList.append(TOSTR(ROBERTS));
    strList.append(TOSTR(SOBEL));
    strList.append(TOSTR(PREWITTS));
    strList.append(TOSTR(CANNY));
    return strList;
}


void CEdgeDetector::detectByRoberts(const QImage& f_inImage, QImage& f_outImage)
{
   for(int l_x = 0; l_x < f_inImage.width() - 1; l_x++)
    {
        for(int l_y = 0; l_y < f_inImage.height() - 1; l_y++)
        {
            int val1 = (f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)] - f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x)])/4;
            int val2 = (f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x)] - f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x + 1)])/4;
            double grad = sqrt(static_cast<double>(val1 * val1 + val2 * val2 ));
            int grad_i32 = static_cast<int>(grad);
            QColor color = QColor(grad_i32, grad_i32, grad_i32);
            f_outImage.setPixel(l_x, l_y, grad_i32);
        }
    }
}

void CEdgeDetector::detectBySobel(const QImage& f_inImage, QImage& f_outImage)
{
    for(int l_x = 1; l_x < f_inImage.width() - 1; l_x++)
    {
        for(int l_y = 1; l_y < f_inImage.height() - 1; l_y++)
        {
            int val1 = ((f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                    2 * f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x - 1)]) -
                        (f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x + 1)] + 
                    2 * f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x + 1)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)]))/8;

            int val2 = ((f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                    2 * f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x)] + 
                        f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x + 1)]) -
                        (f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                    2 * f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)]))/8;

            double grad = sqrt(static_cast<double>(val1 * val1 + val2 * val2 ));
            int grad_i32 = static_cast<int>(grad);
            QColor color = QColor(grad_i32, grad_i32, grad_i32);
            f_outImage.setPixel(l_x, l_y, grad_i32);
        }
    }
}

void CEdgeDetector::detectByPrewitts(const QImage& f_inImage, QImage& f_outImage)
{
    for(int l_x = 1; l_x < f_inImage.width() - 1; l_x++)
    {
        for(int l_y = 1; l_y < f_inImage.height() - 1; l_y++)
        {
            int val1 = ((f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                        f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x - 1)]) -
                        (f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x + 1)] + 
                        f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x + 1)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)]))/6;

            int val2 = ((f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                        f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x)] + 
                        f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x + 1)]) -
                        (f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x - 1)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x)] + 
                        f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)]))/6;

            double grad = sqrt(static_cast<double>(val1 * val1 + val2 * val2 ));
            int grad_i32 = static_cast<int>(grad);
            QColor color = QColor(grad_i32, grad_i32, grad_i32);
            f_outImage.setPixel(l_x, l_y, grad_i32);
        }
    }
}

void CEdgeDetector::detectByCanny(const QImage& f_inImage, QImage& f_outImage)
{
    /*for(int l_x = 0; l_x < f_inImage.width(); l_x++)
    {
        for(int l_y = 0; l_y < f_inImage.height(); l_y++)
        {
            QRgb rgb = f_inImage.pixel(l_x, l_y);
            QColor color = QColor(rgb);
            int value = color.red() * 0.21f + color.green() * 0.71f + color.blue() * 0.07f;
            f_outImage.setPixel(l_x, l_y, value);
        }
    }*/
}
