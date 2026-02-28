#include"Headers/appWindow.h"
#include"Headers/mainwindow.h"
#include<QLayout>
#include<QPushButton>
#include<QLabel>
#include<QMenuBar>
#include<QMenu>
#include<QAction>
#include<QToolBar>
#include<iostream>
#include <QFile>
#include <QDir>






const QString BG_WIDGET_COLOR = "QWidget { background-color:white}";
const unsigned int MIN_WIDTH  = 500;
const unsigned int MIN_HEIGHT = 500;
const QString menuStyle = "QMenuBar { background-color:#737A6B}";
const QString BUTTON_OPEN_STYLE = "QPushButton {\
                                     background:#C9BDB3;\
                                     border: 2px solid gray; \
                                     border-radius: 10px;\
                                     font-size:12px;}\
                                     QPushButton::hover{\
                                     background:yellow;\
                                     }";

const QString BUTTON_CLOSE_STYLE = "QPushButton {\
                                     background:#C9BDB3;\
                                     border: 2px solid gray; \
                                     border-radius: 10px;\
                                     font-size:12px;}\
                                     QPushButton::hover{\
                                     background:yellow;\
                                    }";

AppMainWindow::AppMainWindow(QWidget* parent)
	:QMainWindow(parent)
{

	setWindowTitle("App Window");
	setMinimumWidth(MIN_WIDTH);
	setMinimumHeight(MIN_HEIGHT);
	setStyleSheet(BG_WIDGET_COLOR);
	QWidget* bgWidget 		 = new QWidget();
	QGridLayout* bgWidgetLyt = new QGridLayout();

	bgWidgetLyt->addWidget(createButtons());
	bgWidget->setLayout(bgWidgetLyt);
	
	menuBar()->setStyleSheet(menuStyle);

	fileMenu = menuBar()->addMenu("&File");
	fileMenu->addAction("New");
	fileMenu->addAction("Open");
	fileMenu->addAction("Save");

	setCentralWidget(bgWidget);

}


QWidget* AppMainWindow::createImage()
{
    QLabel* imgLabel = new QLabel();
    QPixmap img("Pictures/microcontroller.png");
    imgLabel->setPixmap(img);
    imgLabel->setScaledContents(true);
    imgLabel->setFixedSize(300,300);

    return imgLabel;
}



QWidget* AppMainWindow::createButtons(){
    QWidget* widgForBtn                 = new QWidget();
    QGridLayout* widgForBtnLyt          = new QGridLayout();
    QPushButton* coreApb3Config         = new QPushButton("Open CoreAPB3Config");
    QPushButton* closeApp               = new QPushButton("close App");
//  QSpacerItem *SpacerForFooterButtons = new QSpacerItem(0,200, QSizePolicy::Fixed, QSizePolicy::Expanding);

    QLabel* textLabel = new QLabel(QString("By Gor Iskandaryan"));

    textLabel->setFont(QFont("Cursive", 10, 100));
    coreApb3Config->setStyleSheet(BUTTON_OPEN_STYLE);
    closeApp->setStyleSheet(BUTTON_CLOSE_STYLE);

    closeApp->setToolTip("Click for close program");
    coreApb3Config->setToolTip("Click to run program");
    //coreApb3Config->setFont(QFont("OldEnglish", 10, 100));
    //closeApp->setFont(QFont("System", 10, 100));
    coreApb3Config->setFixedSize(150, 30);
    closeApp->setFixedSize(150,30);

    widgForBtnLyt->addWidget(coreApb3Config, 0, 0);
    widgForBtnLyt->addWidget(closeApp, 1, 0);


    widgForBtnLyt->addWidget(createImage(), 2,0);
//  widgForBtn->setMaximumWidth(400);
    widgForBtnLyt->addWidget(textLabel, 4, 0);
    widgForBtn->setLayout(widgForBtnLyt);
	connect(coreApb3Config,  &QPushButton::clicked, this, &AppMainWindow::openCoreApb3Config);

    
    connect(closeApp, &QPushButton::clicked, this, &AppMainWindow::closeCoreApb3Config);
	
    connect(closeApp, &QPushButton::clicked, this, &AppMainWindow::close);
	return widgForBtn;
	
}
void AppMainWindow::openCoreApb3Config()
{

	MainWindow p(this);
	//p.show();
	//p.exec();
	if(p.exec() == QDialog::Accepted )
	{
		std::cout<<"Okay thats work"<<std::endl;
	}
	else
	{
		std::cout<<"Cancel"<<std::endl;
	}

//std::cout<<"Okay its work"<<std::endl;
}

void AppMainWindow::closeCoreApb3Config()
{
	QString filePath = QDir().absolutePath() +"/save.json" ;
	QFile file(filePath);
	if (file.exists()) {
 	
		QFile::remove(filePath);
	        qDebug() << "File deleted";
	} 
	else {
	        qDebug() << "Failed to delete:" << file.errorString();
	    }
	
}


AppMainWindow::~AppMainWindow()
{}
