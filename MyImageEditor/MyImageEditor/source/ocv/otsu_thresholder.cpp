

//http://www.labbookpages.co.uk/software/imgProc/otsuThreshold.html

#include "ocv\otsu_thresholder.hpp"
#include "ocv\histogram_calculate.hpp"

int COtsuThresholder::calculateThreshold(const CHistogramCalc::SHistMap& f_histogram)
{
    int l_th = 0;
    double l_varianceMax = 0.0;

    QVector<double>::const_iterator grayValIt = f_histogram.m_xvalues.begin() + 1;
    for(; grayValIt != f_histogram.m_xvalues.end(); grayValIt++)
    {
        double l_fgWeight = 0.0;
        double l_bgWeight = 0.0;
        double l_fgGrayMean = 0.0;
        double l_bgGrayMean = 0.0;

        QVector<double>::const_iterator it = f_histogram.m_xvalues.begin();
        for(; it != (f_histogram.m_xvalues.end() - 1); it++)
        {
            if(*it < *grayValIt)
            {
                int index = it - f_histogram.m_xvalues.begin();
                l_fgWeight += f_histogram.m_yvalues[index];

                l_fgGrayMean += (f_histogram.m_yvalues[index] * (*it));
            }
            else
            {
                int index = it - f_histogram.m_xvalues.begin();
                l_bgWeight += f_histogram.m_yvalues[index];

                l_bgGrayMean += (f_histogram.m_yvalues[index] * (*it));
            }
        }

        l_fgGrayMean = l_fgGrayMean/l_fgWeight;
        l_bgGrayMean = l_bgGrayMean/l_bgWeight;

        double l_varianceBet = l_fgWeight * l_bgWeight * (l_fgGrayMean - l_bgGrayMean) * (l_fgGrayMean - l_bgGrayMean);

        if(l_varianceBet > l_varianceMax)
        {
            l_th = *grayValIt;
            l_varianceMax = l_varianceBet;
        }
    }

    return l_th;
}

QImage COtsuThresholder::convertGrayToBinary(const QImage& f_image)
{
    CHistogramCalc histCalc;
    histCalc.calculateHistogram(f_image);
    int l_threshold = COtsuThresholder::calculateThreshold(histCalc.getChannel2());
    QImage l_monochrome(f_image);
    for(int l_count = 0; l_count < 256; l_count++)
    {
        l_monochrome.setColor(l_count, QColor(l_count, l_count, l_count).rgb());
    }

    for(int l_x = 0; l_x < f_image.width(); l_x++)
    {
        for(int l_y = 0; l_y < f_image.height(); l_y++)
        {
            if(l_threshold < f_image.constBits()[l_y * f_image.width() + l_x])
            {
                l_monochrome.setPixel(l_x, l_y, 255);
            }
            else
            {
                l_monochrome.setPixel(l_x, l_y, 0);
            }
        }
    }

    return l_monochrome;
}