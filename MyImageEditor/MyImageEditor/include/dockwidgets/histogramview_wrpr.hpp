

#ifndef HISTOGRAMVIEW_WRPR_HPP
#define HISTOGRAMVIEW_WRPR_HPP

#include <QtGui\QtGui>

#include "ui_histogramview_dckwgt.h"

#include "dockwidgets\dockwidget_base.hpp"
#include "image\histogram_calculate.hpp"

class CHistogramViewWrpr : public QDockWidget, public IDckWidget
{
    Q_OBJECT

public:
    CHistogramViewWrpr(QWidget* f_parent = 0, Qt::WFlags f_flag = 0);
    ~CHistogramViewWrpr();

	void setWidget(QWidget* f_widget);

	void init(IMyImageEditor* f_int);

    void addPlot(const QVector<double>& f_xValues, const QVector<double>& f_yValues, const QColor& f_color);

    void calculateHistogram(const QImage& f_image);

    void clearAllPlots();

private:
    Ui::CHistogramView m_histogramView_ui;
    CHistogramCalc m_histogram;

private slots:

};

#endif //HISTOGRAMVIEW_WRPR_HPP