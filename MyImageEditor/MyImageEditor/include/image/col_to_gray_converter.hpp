
#ifndef COL_TO_GRAY_CONVERTER_HPP
#define COL_TO_GRAY_CONVERTER_HPP

#define TOSTR(X) #X

#include <QtGui\QtGui>

class CColToGrayConv
{

public:

    enum EMethod
    {
        OCV = 0,
        LIGHTNESS,
        AVERAGE,
        LUMINOSITY
    };

    QImage convertToGray(const QImage& f_image, const EMethod& f_method_e = OCV);

    static QStringList getConMethods();

private:
    void convertByOCV(const QImage& f_inImage, QImage& f_outImage);
    void convertByLightness(const QImage& f_inImage, QImage& f_outImage);
    void convertByAverage(const QImage& f_inImage, QImage& f_outImage);
    void convertByLuminosity(const QImage& f_inImage, QImage& f_outImage);
};

#endif //COL_TO_GRAY_CONVERTER_HPP