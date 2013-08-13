

#include "ui\ruler_widget.hpp"

CRulerWidget::CRulerWidget(QWidget* f_parent) : QWidget(f_parent),
    m_orientation(HORIZONTAL),
    m_originGlobalPos(0, 0),
    m_100GlobalPos(100, 100),
    m_curPos(0, 0)
{ 
}

CRulerWidget::~CRulerWidget()
{
}

void CRulerWidget::paintEvent(QPaintEvent* f_event)
{
    QPainter painter(this);

    QPoint l_curPoint = (m_curPos);

    if(HORIZONTAL == m_orientation)
    {
        QRect l_rect(0, 0, this->width() - 3, 16);
        painter.fillRect(l_rect, Qt::white);
        painter.setPen(Qt::black);
        painter.drawRect(l_rect);

        QPoint l_orgPoint = this->mapFromGlobal(m_originGlobalPos);
        QPoint l_100Point = this->mapFromGlobal(m_100GlobalPos);

        int l_startX = l_orgPoint.x();
        float l_incX = (l_100Point.x() - l_orgPoint.x())/10.0f;

        int l_val = 0;
        while(l_startX < this->width())
        {
            painter.drawLine(QPoint(l_startX, 0), QPoint(l_startX, 12));
            painter.drawText(QPoint(l_startX + 2, 15), QString::number(l_val));
            for(int l_count = 0; l_count < 9; l_count++)
            {
                l_startX += l_incX;
                painter.drawLine(QPoint(l_startX, 0), QPoint(l_startX, 4));
            }

            l_startX += l_incX;
            l_val += 100;
        }

        l_startX = l_orgPoint.x();
        l_val = 0;
        while(l_startX > 0)
        {
            for(int l_count = 0; l_count < 9; l_count++)
            {
                l_startX -= l_incX;
                painter.drawLine(QPoint(l_startX, 0), QPoint(l_startX, 4));
            }

            l_startX -= l_incX;
            l_val -= 100;

            painter.drawLine(QPoint(l_startX, 0), QPoint(l_startX, 12));
            painter.drawText(QPoint(l_startX + 2, 15), QString::number(l_val));
        }

        painter.drawLine(QPoint(l_orgPoint.x() + l_curPoint.x(), 0), QPoint(l_orgPoint.x() + l_curPoint.x(), 16));
    }
    else
    {
        QRect l_rect(0, 0, 16, this->height() - 3);
        painter.fillRect(l_rect, Qt::white);
        painter.setPen(Qt::black);
        painter.drawRect(l_rect);

        QPoint l_orgPoint = this->mapFromGlobal(m_originGlobalPos);
        QPoint l_100Point = this->mapFromGlobal(m_100GlobalPos);

        int l_startY = l_orgPoint.y();
        float l_incY = (l_100Point.y() - l_orgPoint.y())/10.0f;

        int l_val = 0;
        while(l_startY < this->height())
        {
            painter.drawLine(QPoint(0, l_startY), QPoint(12, l_startY));
            painter.drawText(QPoint(5, l_startY + 10), QString::number(l_val));
            for(int l_count = 0; l_count < 9; l_count++)
            {
                l_startY += l_incY;
                painter.drawLine(QPoint(0, l_startY), QPoint(4, l_startY));
            }

            l_startY += l_incY;
            l_val += 100;
        }

        l_startY = l_orgPoint.y();
        l_val = 0;
        while(l_startY > 0)
        {
            for(int l_count = 0; l_count < 9; l_count++)
            {
                l_startY -= l_incY;
                painter.drawLine(QPoint(0, l_startY), QPoint(4, l_startY));
            }

            l_startY -= l_incY;
            l_val -= 100;

            painter.drawLine(QPoint(0, l_startY), QPoint(12, l_startY));
            painter.drawText(QPoint(5, l_startY + 10), QString::number(l_val));
        }

        painter.drawLine(QPoint(0, l_orgPoint.y() + l_curPoint.y()), QPoint(16, l_orgPoint.y() + l_curPoint.y()));
    }
}