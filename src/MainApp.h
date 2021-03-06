#ifndef _MAINAPP_H_
#define _MAINAPP_H_

#include "ui_mainwindow.h"
#include <QWheelEvent>

class MainApp : public QMainWindow
{
	Q_OBJECT

public:
	MainApp();
	~MainApp();

public slots:
	void update_status_bar(int x, int y);
	void update_window_title(const QString& filename);
	void open();

private:
	Ui::ARViewer*				ui;
	//AlgoObj*					obj;
	int key = -1, key_modified = -1;
};

#endif