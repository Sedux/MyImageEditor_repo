

#ifndef IMAGE_BLUR_HPP
#define IMAGE_BLUR_HPP

#define TOSTR(X) #X

#include <QtGui\QtGui>

class CImageBlur
{

public:

    enum EMethod
    {
        GAUSSIAN = 0,
        LINEAR,
        RADIAL,
        ZOOM
    };

    QImage blurImage(const QImage& f_image, const EMethod& f_method_e = GAUSSIAN);

    static QStringList getBlurMethods();

private:
    void blurByGaussian(const QImage& f_inImage, QImage& f_outImage);
    void blurByLinear(const QImage& f_inImage, QImage& f_outImage);
    void blurByRadial(const QImage& f_inImage, QImage& f_outImage);
    void blurByZoom(const QImage& f_inImage, QImage& f_outImage);
};


#endif //IMAGE_BLUR_HPP