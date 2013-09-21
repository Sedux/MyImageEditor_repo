
#ifndef IMAGE_EDIT_PARAMS_HPP
#define IMAGE_EDIT_PARAMS_HPP

#include "image\col_to_gray_converter.hpp"
#include "image\edge_detector.hpp"
#include "image\image_blur.hpp"

struct CImageEditParams
{
    CImageEditParams() : 
        m_reverseImageHor_b(false),
        m_reverseImageVer_b(false),
        m_convertToGray_b(false),
        m_convertToMonochrome_b(false),
        m_detectEdges_b(false),
        m_blurImage_b(false),
        m_colToGrayMethod(CColToGrayConv::OCV),
        m_edgeDetectionMethod(CEdgeDetector::ROBERTS),
        m_imageBlurMethod(CImageBlur::GAUSSIAN)
        {
        }

    bool m_reverseImageHor_b;
    bool m_reverseImageVer_b;
    bool m_convertToGray_b;
    bool m_convertToMonochrome_b;
    bool m_detectEdges_b;
    bool m_blurImage_b;
    CColToGrayConv::EMethod m_colToGrayMethod;
    CEdgeDetector::EMethod  m_edgeDetectionMethod;
    CImageBlur::EMethod     m_imageBlurMethod;
};

#endif //IMAGE_EDIT_PARAMS_HPP