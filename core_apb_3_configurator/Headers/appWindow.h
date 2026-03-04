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
	QMenu* fileMenu;// = new QMenu;
    	QMenu* helpMenu;

private:

private slots:
	void openCoreApb3Config();
};

#endif
