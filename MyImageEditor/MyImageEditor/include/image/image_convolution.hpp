
#include <QtCore\QtCore>

#include "image\ocv_utils.hpp"

template<class ImageKernalType>
class TImageConvolution
{

public:

    void operator()(QImage& f_image, const ImageKernalType& f_imageKernal)
    {
        Q_ASSERT(ImageKernalType::ROW_COUNT <= f_image.height());
        Q_ASSERT(ImageKernalType::COL_COUNT <= f_image.width());

        ImageKernalType::valueType divisor = 0;
        for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
        {
            for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
            {
                divisor += utils::abs(0, f_imageKernal(l_kernely, l_kernelx));
            }
        }

        Q_ASSERT(0 < divisor);

        for(int l_x = 0; l_x < f_image.width(); l_x++)
        {
            for(int l_y = 0; l_y < f_image.height(); l_y++)
            {
                ImageKernalType::valueType sum = 0;
                for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
                {
                    for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
                    {
                        sum += getPixelVal(f_image, l_x + l_kernelx, l_y + l_kernely) * f_imageKernal(l_kernely, l_kernelx);
                    }
                }

                int gradCol = static_cast<int>(sum/divisor);
                f_image.setPixel(l_x, l_y, gradCol);
            }
        }
    }

    void operator()(const QImage& f_inImage, QImage& f_outImage, const ImageKernalType& f_imageKernalX, const ImageKernalType& f_imageKernalY)
    {
        Q_ASSERT(ImageKernalType::ROW_COUNT <= f_inImage.height());
        Q_ASSERT(ImageKernalType::COL_COUNT <= f_inImage.width());

        ImageKernalType::valueType divisorX = 0;
        for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
        {
            for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
            {
                divisorX += utils::abs(0, f_imageKernalX(l_kernely, l_kernelx));
            }
        }

        ImageKernalType::valueType divisorY = 0;
        for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
        {
            for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
            {
                divisorY += utils::abs(0, f_imageKernalY(l_kernely, l_kernelx));
            }
        }

        Q_ASSERT(0 < divisorX);
        Q_ASSERT(0 < divisorY);

        for(int l_x = 0; l_x < f_inImage.width(); l_x++)
        {
            for(int l_y = 0; l_y < f_inImage.height(); l_y++)
            {
                ImageKernalType::valueType sumX = 0;
                for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
                {
                    for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
                    {
                        sumX += getPixelVal(f_inImage, l_x + l_kernelx, l_y + l_kernely) * f_imageKernalX(l_kernely, l_kernelx);
                    }
                }

                ImageKernalType::valueType sumY = 0;
                for(int l_kernelx = 0; l_kernelx < ImageKernalType::COL_COUNT; l_kernelx++)
                {
                    for(int l_kernely = 0; l_kernely < ImageKernalType::ROW_COUNT; l_kernely++)
                    {
                        sumY += getPixelVal(f_inImage, l_x + l_kernelx, l_y + l_kernely) * f_imageKernalY(l_kernely, l_kernelx);
                    }
                }

                double gradCol = sqrt(static_cast<double>((sumX * sumX)/(divisorX * divisorX) + (sumY * sumY)/(divisorY * divisorY)));
                int gradCol_i = static_cast<int>(gradCol); 
                f_outImage.setPixel(l_x, l_y, gradCol_i);
            }
        }
    }

private:

    int getPixelVal(const QImage& f_image, const int& f_x, const int& f_y)
    {
        if((0 > f_y) || (f_image.height() <= f_y) || (0 > f_x) || (f_image.width() <= f_x))
        {
            return 0;
        }

        return f_image.pixel(f_x, f_y);
    }
};