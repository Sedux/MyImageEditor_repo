
#include "dockwidgets\histogramview_wrpr.hpp"

#include <qwt_plot_curve.h>
#include <qwt_series_data.h>

CHistogramViewWrpr::CHistogramViewWrpr(QWidget* f_parent, Qt::WFlags f_flag):
QDockWidget(f_parent, f_flag)
{
	
}

CHistogramViewWrpr::~CHistogramViewWrpr()
{
}

void CHistogramViewWrpr::setWidget(QWidget* f_widget)
{
    m_histogramView_ui.setupUi(this);
    //m_histogramView_ui.m_qwtPlot->setAxisScale(QwtPlot::yLeft, 0.0, 100.0);
}

void CHistogramViewWrpr::init(IMyImageEditor* f_int)
{
    this->setMyImageEditorInt(f_int);
}

void CHistogramViewWrpr::calculateHistogram(const QImage& f_image)
{
    this->clearAllPlots();
    m_histogram.calculateHistogram(f_image);
    this->addPlot(m_histogram.getChannel0().m_xvalues, m_histogram.getChannel0().m_yvalues, QColor(0, 0, 255));
    if(QImage::Format_Indexed8 != f_image.format())
    {
        this->addPlot(m_histogram.getChannel1().m_xvalues, m_histogram.getChannel1().m_yvalues, QColor(0, 255, 0));
        this->addPlot(m_histogram.getChannel2().m_xvalues, m_histogram.getChannel2().m_yvalues, QColor(255, 0, 0));
    }
    m_histogramView_ui.m_qwtPlot->replot();
}

void CHistogramViewWrpr::addPlot(const QVector<double>& f_xValues, const QVector<double>& f_yValues, const QColor& f_color)
{
    QwtPlotCurve* plotCurve = new QwtPlotCurve(QString("Histogram Curve"));
    plotCurve->setPen(f_color);
    plotCurve->setSamples(f_xValues, f_yValues);
    plotCurve->attach( m_histogramView_ui.m_qwtPlot);
}

void CHistogramViewWrpr::clearAllPlots()
{
    m_histogramView_ui.m_qwtPlot->detachItems();
}

