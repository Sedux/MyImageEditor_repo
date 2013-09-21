
#include "image\image_kernel.hpp"
#include "myimageeditor\logger_defines.hpp"

template<int Length>
class CGaussianKernalGen
{
public:
    
    enum
    {
        KERNEL_LENGTH = Length,
        KERNEL_INDEX = Length - 1
    };

    typedef TImageKernel<double, KERNEL_LENGTH, KERNEL_LENGTH> ImageKernalType;

    void operator()(ImageKernalType& f_imageKernal, const double& f_sigma)
    {
        for(int l_row = 0; l_row < KERNEL_LENGTH; l_row++)
        {
            int y = l_row - KERNEL_INDEX/2;
            for(int l_column = 0; l_column < KERNEL_LENGTH; l_column++)
            {
                int x = l_column - KERNEL_INDEX/2;
                f_imageKernal(l_row, l_column) = exp(-(x * x + y * y) / (2.0 * f_sigma * f_sigma)) / (2.0 * M_PI * f_sigma * f_sigma);
                QDEBUG_MSG(QString::number(f_imageKernal(l_row, l_column)));
            }
        }
    }
};