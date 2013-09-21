
#include "image/image_blur.hpp"
#include "image/gaussian_kernel_gen.hpp"

QImage CImageBlur::blurImage(const QImage& f_image, const EMethod& f_method_e)
{
    QImage l_outImage(f_image.width(), f_image.height(), QImage::Format_Indexed8);
    for(int l_count = 0; l_count < 256; l_count++)
    {
        l_outImage.setColor(l_count, QColor(l_count, l_count, l_count).rgb());
    }

    switch(f_method_e)
    {
    case GAUSSIAN:
        blurByGaussian(f_image, l_outImage);
        break;
    case LINEAR:
        blurByLinear(f_image, l_outImage);
        break;
    case RADIAL:
        blurByRadial(f_image, l_outImage);
        break;
    case ZOOM:
        blurByZoom(f_image, l_outImage);
        break;
    }

    return l_outImage;
}

QStringList CImageBlur::getBlurMethods()
{
    QStringList strList;
    strList.append(TOSTR(GAUSSIAN));
    strList.append(TOSTR(LINEAR));
    strList.append(TOSTR(RADIAL));
    strList.append(TOSTR(ZOOM));
    return strList;
}

void CImageBlur::blurByGaussian(const QImage& f_inImage, QImage& f_outImage)
{
    CGaussianKernalGen<3> l_kernal;
    CGaussianKernalGen<3>::ImageKernalType l_image;
    l_kernal(l_image, 1);

    for(int l_x = 5; l_x < f_inImage.width() - 5; l_x++)
    {
        for(int l_y = 5; l_y < f_inImage.height() - 5; l_y++)
        {
            int val1 = (l_image(0, 0) * f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x - 1)] 
                        + l_image(0, 1) * f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x)]
                        + l_image(0, 2) * f_inImage.constBits()[(l_y - 1) * f_inImage.bytesPerLine() + (l_x + 1)]
                        + l_image(1, 0) * f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x - 1)]
                        + l_image(1, 1) * f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x)]
                        + l_image(1, 2) * f_inImage.constBits()[(l_y) * f_inImage.bytesPerLine() + (l_x + 1)]
                        + l_image(2, 0) * f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x - 1)]
                        + l_image(2, 1) * f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x)]
                        + l_image(2, 2) * f_inImage.constBits()[(l_y + 1) * f_inImage.bytesPerLine() + (l_x + 1)]);
           
            int grad_i32 = static_cast<int>(val1/l_image.sum());
            f_outImage.setPixel(l_x, l_y, grad_i32);
        }
    }
}

void CImageBlur::blurByLinear(const QImage& f_inImage, QImage& f_outImage)
{
}

void CImageBlur::blurByRadial(const QImage& f_inImage, QImage& f_outImage)
{
}

void CImageBlur::blurByZoom(const QImage& f_inImage, QImage& f_outImage)
{
}