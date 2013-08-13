

#ifndef RULER_WIDGET_HPP
#define RULER_WIDGET_HPP

#include <QtGui\QtGui>

class CRulerWidget : public QWidget
{
Q_OBJECT

public:

    enum EOrientation
    {
        HORIZONTAL = 0,
        VERTICAL
    };

    //const
    CRulerWidget(QWidget* f_parent = 0);
    //dest
    ~CRulerWidget();

    void setOrientation(const EOrientation& f_orientation)
    {
        m_orientation = f_orientation;
    }

    EOrientation geOrientation()
    {
        return m_orientation;
    }

    void setOriginGlobalPos(const QPoint& f_pos)
    {
        m_originGlobalPos = f_pos;
    }

    void set100GlobalPos(const QPoint& f_pos)
    {
        m_100GlobalPos = f_pos;
    }

    

protected:
    void paintEvent(QPaintEvent* f_event);

private:
    EOrientation m_orientation;

    QPoint m_originGlobalPos;
    QPoint m_100GlobalPos;
    QPoint m_curPos;

signals:

public slots:
    void graphicsViewRedrawn(const QPoint& f_orgGlobal, const QPoint& f_100Global)
    {
        this->setOriginGlobalPos(f_orgGlobal);
        this->set100GlobalPos(f_100Global);
        this->update();
    }

    void setCurrentPos(const QPoint& f_pos)
    {
        m_curPos = f_pos;
        this->update();
    }
	
};

#endif //RULER_WIDGET_HPP