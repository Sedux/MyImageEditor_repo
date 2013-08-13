

//http://www.labbookpages.co.uk/software/imgProc/otsuThreshold.html

#ifndef OTSU_THRESHOLDER
#define OTSU_THRESHOLDER

#include "image\histogram_calculate.hpp"

class COtsuThresholder
{
public:

    static int calculateThreshold(const CHistogramCalc::SHistMap& f_histogram );

    static QImage convertGrayToBinary(const QImage& f_image);
};

#endif //OTSU_THRESHOLDER