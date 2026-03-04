#include "Headers/appWindow.h"
#include "Headers/mainwindow.h"
#include "Headers/def.h"
#include <QLayout>
#include <QPushButton>
#include <QLabel>
#include <QMenuBar>

AppMainWindow::AppMainWindow(QWidget* parent)
	:QMainWindow(parent)
{
	setWindowTitle("App Window");
	setMinimumWidth(MIN_WIDTH_);
	setMinimumHeight(MIN_HEIGHT_);
	setStyleSheet(BG_WIDGET_COLOR_);
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

QWidget* AppMainWindow::createButtons()
{
   	 QWidget* widgForBtn                 = new QWidget();
   	 QGridLayout* widgForBtnLyt          = new QGridLayout();
   	 QPushButton* coreApb3Config         = new QPushButton("Open CoreAPB3Config");
   	 QPushButton* closeApp               = new QPushButton("close App");
   	 QLabel* textLabel = new QLabel(QString("By Gor Iskandaryan"));
   	 textLabel->setFont(QFont("Cursive", 10, 100));
   	 coreApb3Config->setStyleSheet(BUTTON_OPEN_STYLE);
   	 closeApp->setStyleSheet(BUTTON_CLOSE_STYLE);
   	 closeApp->setToolTip("Click for close program");
   	 coreApb3Config->setToolTip("Click to run program");
   	 coreApb3Config->setFixedSize(150, 30);
   	 closeApp->setFixedSize(150,30);
   	 widgForBtnLyt->addWidget(coreApb3Config, 0, 0);
   	 widgForBtnLyt->addWidget(closeApp, 1, 0);
   	 widgForBtnLyt->addWidget(createImage(), 2,0);
   	 widgForBtnLyt->addWidget(textLabel, 4, 0);
   	 widgForBtn->setLayout(widgForBtnLyt);
   	 connect(coreApb3Config,  &QPushButton::clicked, this, &AppMainWindow::openCoreApb3Config);
   	 connect(closeApp, &QPushButton::clicked, this, &AppMainWindow::close);
   	 return widgForBtn;	
}
void AppMainWindow::openCoreApb3Config()
{
	MainWindow p(this);
	p.exec();
}


AppMainWindow::~AppMainWindow()
{}
