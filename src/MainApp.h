#ifndef _MAINAPP_H_
#define _MAINAPP_H_

#include "ui_mainwindow.h"

class MainApp : public QMainWindow
{
	Q_OBJECT

public:
	MainApp();
	~MainApp();

private:
	Ui::ARViewer*				ui;
	//AlgoObj*					obj;
};

#endif