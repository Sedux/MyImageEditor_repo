
#ifndef DOCKWIDGET_BASE_HPP
#define DOCKWIDGET_BASE_HPP

#include "myimageeditor\myimageeditor_base.hpp"

class IDckWidget
{

protected:
    IMyImageEditor* m_myImageEditorInt;

    void setMyImageEditorInt(IMyImageEditor* f_int)
    {
        m_myImageEditorInt = f_int;
    }
};

#endif