
#ifndef MYIMAGEEDITOR_BASE_HPP
#define MYIMAGEEDITOR_BASE_HPP


class IMyImageEditor
{
public:
    virtual QDockWidget* getHistogramView() = 0;
};

#endif