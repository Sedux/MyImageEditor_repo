

#ifndef HISTOGRAMCALCULATE_WRPR_HPP
#define HISTOGRAMCALCULATE_WRPR_HPP

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "image\ocv_utils.hpp"

class CHistogramCalc
{

public:
    struct SHistMap
    {
        QVector<double> m_xvalues;
        QVector<double> m_yvalues;
    };

    CHistogramCalc(){}
    ~CHistogramCalc(){}

    void calculateHistogram(const QImage& f_image)
    {
        m_channel0.m_xvalues.clear();
        m_channel0.m_yvalues.clear();

        m_channel1.m_xvalues.clear();
        m_channel1.m_yvalues.clear();

        m_channel2.m_xvalues.clear();
        m_channel2.m_yvalues.clear();

        cv::Mat l_image = utils::QImageToMat(f_image);

        cv::vector<cv::Mat> bgr_planes;
        cv::split(l_image, bgr_planes);

        /// Establish the number of bins
        int histSize = 256;

        /// Set the ranges ( for B,G,R) )
        float range[] = { 0, 256 } ;
        const float* histRange = { range };

        bool uniform = true; bool accumulate = false;

        cv::Mat b_hist, g_hist, r_hist;

        /// Compute the histograms:
        cv::calcHist( &bgr_planes[0], 1, 0, cv::Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate );

        if(CV_8UC1 != l_image.type())
        {
            cv::calcHist( &bgr_planes[1], 1, 0, cv::Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate );
            cv::calcHist( &bgr_planes[2], 1, 0, cv::Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate );
        }

        for(int l_count = 0; l_count < histSize; l_count++)
        {
            m_channel0.m_xvalues.push_back(l_count);
            m_channel0.m_yvalues.push_back(b_hist.at<int>(l_count));

            if(CV_8UC1 != l_image.type())
            {
                m_channel1.m_xvalues.push_back(l_count);
                m_channel1.m_yvalues.push_back(g_hist.at<int>(l_count));

                m_channel2.m_xvalues.push_back(l_count);
                m_channel2.m_yvalues.push_back(r_hist.at<int>(l_count));
            }
        }
    }

    const SHistMap& getChannel0()
    {
        return m_channel0;
    }

    const SHistMap& getChannel1()
    {
        return m_channel1;
    }

    const SHistMap& getChannel2()
    {
        return m_channel2;
    }

private:

    SHistMap m_channel0;
    SHistMap m_channel1;
    SHistMap m_channel2;

};

#endif
