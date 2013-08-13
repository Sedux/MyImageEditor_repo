

#ifndef EDGE_DETECTOR_HPP
#define EDGE_DETECTOR_HPP

#define TOSTR(X) #X

#include <QtGui\QtGui>

class CEdgeDetector
{

public:

    enum EMethod
    {
        ROBERTS = 0,
        SOBEL,
        PREWITTS,
        CANNY
    };

    QImage detectEdges(const QImage& f_image, const EMethod& f_method_e = ROBERTS);

    static QStringList getConMethods();

private:
    void detectByRoberts(const QImage& f_inImage, QImage& f_outImage);
    void detectBySobel(const QImage& f_inImage, QImage& f_outImage);
    void detectByPrewitts(const QImage& f_inImage, QImage& f_outImage);
    void detectByCanny(const QImage& f_inImage, QImage& f_outImage);
};

#endif //EDGE_DETECTOR_HPP