#ifndef APPWINDOW_H
#define APPWINDOW_H
#include<QMainWindow>

class AppMainWindow : public QMainWindow
{
	Q_OBJECT
public:
	AppMainWindow(QWidget *parent = nullptr);
	~AppMainWindow();
private:
 	QWidget* createImage();
  	QWidget* createButtons();

private:
//	QMenuBar* menuBarMain; 
	QMenu* fileMenu;// = new QMenu;
    QMenu* helpMenu;
//    QAction* quitAction;
//    QAction* aboutAction;
//    QAction* saveAction;
//    QAction* newAction;
//    QAction* openAction;

private:

private slots:
	void openCoreApb3Config();
	void closeCoreApb3Config();
//	void tempCloseUseForJson();
};

#endif
