#include <qapplication.h>
#include "MainApp.h"
#include <windows.h>

using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置连接器选项

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainApp app_ui;
	app_ui.setWindowTitle("MainWindow");
	int screen_width = GetSystemMetrics(SM_CXSCREEN);
	int screen_height = GetSystemMetrics(SM_CYSCREEN);
	app_ui.setMinimumSize(screen_width / 2, screen_height / 2);

	app_ui.show();
	QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));
	return app.exec();
}