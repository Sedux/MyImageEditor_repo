

#ifndef MYIMAGEEDITOR_HPP
#define MYIMAGEEDITOR_HPP

#include <QtGui\QMainWindow>

#include "ui_myimageeditor.h"

#include "myimageeditor\myimageeditor_base.hpp"

Q_DECLARE_METATYPE(QtMsgType)

class CMyImageEditor : public QMainWindow, public IMyImageEditor
{
	Q_OBJECT

public:
    //const
    CMyImageEditor(QWidget* f_parent = 0, Qt::WFlags f_flags = 0);
    ~CMyImageEditor(); //dest

	void init();

    CHistogramViewWrpr* getHistogramView();
    QImage              getImageEditorImage();

private:
	//main GUI
	Ui::CMyImageEditorUI  m_myImageEditor_ui;

	void prepareGui();
};

#endif