#include <QString>
#include <QStringList>
const unsigned int MIN_WIDTH = 880;

const QString CORE_APB_3 							         =	  "CoreAPB3 Configurator";  
const QString SUB_TXT_ACTEL 								 = 	  "Actel:DirectCore:CoreAPB3:4.2.100";
const QString BG_HEAD_COLOR   		  						 = 	  "QWidget { background-color:#A9D5D0}";
const QString BG_WIDGET_COLOR_ 								 = 	  "QWidget {background-color:#edf6f3;}";
const QString ENABLED_APB_SLAVE_SLOTS 						 	 =	  "Enabled APB Slave Slots";
const QString ALLOCATE_MEMORY_SPACE_TO_COMBINED_REGION_SLAVE = 					  "Allocate memory space to combined region slave";
const QString FONT_FAMILY 							         = 	  "OldEnglish";
const QString GROUP_BOX_STYLE_SHEET 						 	 =	  "QGroupBox {               \
                           									  border: 1px solid gray;    \
                           									  border-radius: 1px;        \
                           									  margin-top: 0.5em;         \
                           									  }                          \
                           									  QGroupBox::title{          \
                           									  font-size:7;               \
                           									  subcontrol-origin: margin; \
                           									  left: 10px;\
                           									  padding: 0 3px 0 3px;\
                           									  }";    

const QString POSITION_SLAVE 
  = "Position in slave address of upper 4 bit of master address:";
const QString INDIRECTADDR 
  = "Indirect Addressing:";
const QString NUMBERSADDRBTS 
  = "Number of Address bits driven by master:";


const QString BG_WIDGET_COLOR = "QWidget { background-color:white}";
const unsigned int MIN_WIDTH_  = 500;
const unsigned int MIN_HEIGHT_ = 500;
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



const	QStringList positionConfigStatus = 					{"Uppeer 4 master address bits do not appear in slave address",
										"[31:28]", 
										"([27:24]Ignored if master address width >= 32 bits)",
										"[23:20](Ignored if master address width >= 28 bits)",
										"[19:16](Ignored if master address width >= 24 bits)",
										"[15:12](Ignored if master address width >= 20 bits)",
										"[11:8](Ignored if master address width >= 16 bits)"};

const   QStringList indirectConfigStatus  = 					{"Indirect address sourced from IADDR input port",
										 "Indirect address sourced from register(s) in slot 0 space", 	 
										 "Indirect address sourced from register(s) in slot 1 space",
										 "Indirect address sourced from register(s) in slot 2 space",
										 "Indirect address sourced from register(s) in slot 3 space",
										 "Indirect address sourced from register(s) in slot 4 space",
										 "Indirect address sourced from register(s) in slot 5 space",
										 "Indirect address sourced from register(s) in slot 6 space",
										 "Indirect address sourced from register(s) in slot 7 space",
										 "Indirect address sourced from register(s) in slot 8 space",
										 "Indirect address sourced from register(s) in slot 9 space",
										 "Indirect address sourced from register(s) in slot 10 space",
										 "Indirect address sourced from register(s) in slot 11 space",
										 "Indirect address sourced from register(s) in slot 12 space",
										 "Indirect address sourced from register(s) in slot 13 space",
										 "Indirect address sourced from register(s) in slot 14 space",
										 "Indirect address sourced from register(s) in slot 15 space"};


