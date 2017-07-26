#include "MainApp.h"

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

