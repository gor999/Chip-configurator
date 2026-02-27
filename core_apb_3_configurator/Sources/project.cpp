#include<QApplication>
#include"Headers/appWindow.h"



int main(int argc, char* argv[]){

	QApplication app(argc, argv);
	//MainWindow w;
	AppMainWindow  p;
	p.show();
	return app.exec();
}
