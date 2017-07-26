#include <qapplication.h>
#include "MainApp.h"

using namespace std;

int main(int argc, char** argv)
{
	QApplication app(argc, argv);
	MainApp app_ui;
	app_ui.setWindowTitle("MainWindow");
	int screen_width = 1600;//GetSystemMetrics(SM_CXSCREEN);
	int screen_height = 1000;//GetSystemMetrics(SM_CYSCREEN);
	app_ui.setMinimumSize(screen_width / 2, screen_height / 2);

	app_ui.show();
	QObject::connect(qApp, SIGNAL(lastWindowClosed()), qApp, SLOT(quit()));
	return app.exec();
}