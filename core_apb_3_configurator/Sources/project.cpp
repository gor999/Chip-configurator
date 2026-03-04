#include<QApplication>
#include"Headers/appWindow.h"


int main(int argc, char* argv[])
{
	
	QApplication app(argc, argv);
	AppMainWindow  p;
	p.show();
	return app.exec();
}
