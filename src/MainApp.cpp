#include "MainApp.h"
#include <iostream>
#include <QFileDialog>

using namespace std;

MainApp::MainApp()
{
	ui = new Ui::ARViewer();
	ui->setupUi(this);
}

MainApp::~MainApp()
{
	delete ui;
	ui = NULL;
}

void MainApp::update_status_bar(int x, int y)
{
	char buff[300];
	sprintf(buff, "(x: %04d, y: %04d)", x, y);
	ui->status_bar->showMessage(QString(buff));
}

void MainApp::open()
{
	QStringList filelist = QFileDialog::getOpenFileNames(this, tr("Open Files"), 
		QDir::currentPath(), tr("JPG (*.jpg);; PNG (*.png);; ALL (*.*)"));
	if (!filelist.isEmpty())
	{
		ui->gfx_view_canvas->set_filelist(filelist);
		ui->gfx_view_canvas->show_image_at(0);

	}
}
