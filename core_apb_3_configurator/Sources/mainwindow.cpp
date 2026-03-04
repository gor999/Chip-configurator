#include "Headers/mainwindow.h"
#include "Headers/def.h"
#include <QLayout>
#include <QLabel>
#include <QTabWidget>
#include <QSpacerItem>
#include <QRadioButton>
#include <QComboBox>
#include <QCheckBox>
#include <QDialogButtonBox>
#include <QPushButton>
#include <iostream>
#include <QGroupBox> 
#include <QTextStream>
#include <QFile>
#include <QJsonDocument>
#include <QDesktopServices>
#include <QUrl>



MainWindow::MainWindow(QWidget *parent)
	:QDialog(parent,Qt::WindowCloseButtonHint)
{
	setWindowTitle("Configurator(on isc-libero)");
	setGeometry(200,10,800,900);
	setMinimumWidth(MIN_WIDTH);
	setMaximumHeight(1000);
	setMaximumWidth(1700);
	setStyleSheet(BG_WIDGET_COLOR);
	m_headersFont.setPointSize(11);
    	m_contentFont = QFont(FONT_FAMILY,9);
	QBoxLayout* pMainLayout = new QBoxLayout(QBoxLayout::TopToBottom);
	pMainLayout->addWidget( createHeaderWidget() );
	pMainLayout->addWidget( createTabWidget() );
	pMainLayout->addWidget( createFooterWidget() );		
	setLayout(pMainLayout);
	
	QStringList allData = getAllJsonValues("save.json");

	for (const QString &line : allData)
	{
	    qDebug() << line;
	}	

	setStates();
}

MainWindow::~MainWindow()
{}

QWidget* MainWindow::createHeaderWidget()
{
	QLabel* containerForMainerText= new QLabel(CORE_APB_3);
    	QLabel* containerForFouterText= new QLabel(SUB_TXT_ACTEL);
	QWidget* containerHeader      = new QWidget();	
    	QVBoxLayout *vbox 	      = new QVBoxLayout();
	containerHeader->setStyleSheet(BG_HEAD_COLOR);
	containerHeader->setMinimumHeight(70);
   	containerForMainerText->setFont(QFont(FONT_FAMILY, 16, 100));
	containerForFouterText->setFont(QFont(FONT_FAMILY, 9, 200));	
    vbox->addWidget(containerForMainerText);
    vbox->addWidget(containerForFouterText);
    containerHeader->setLayout(vbox);
	return containerHeader;
};

QTabWidget* MainWindow::createTabWidget()
{
		QTabWidget* mainTabWidget = new QTabWidget();
		QWidget* tabItem          = new QWidget();
		QVBoxLayout *tabItem1Lyt  = new QVBoxLayout();
		
		mainTabWidget->setMinimumHeight(700);
		mainTabWidget->addTab(tabItem,"Configuration");
		tabItem->setLayout(tabItem1Lyt);
		tabItem->setMinimumHeight(600);
		loadSource(); 
		tabItem1Lyt->addWidget( createDataConfigGb() );	
		tabItem1Lyt->addWidget( createAddressConfigGb() );	
		tabItem1Lyt->addWidget( createCheckesGb(ENABLED_APB_SLAVE_SLOTS) );
		tabItem1Lyt->addWidget( createCheckesGb(ALLOCATE_MEMORY_SPACE_TO_COMBINED_REGION_SLAVE) );
		tabItem1Lyt->addWidget( createTestbenchConfig() );	
		return mainTabWidget;
}


QGroupBox* MainWindow::createDataConfigGb()
{
	 QGroupBox* groupBox 						  = new QGroupBox("Data Width Configuration"); 
	 groupBox->setFont(m_headersFont);
	 
	 QGridLayout* ContainerForRadioButtonAndTexts = new QGridLayout();  // change to QHLayout
	  
	 QLabel* containerForGroupBoxText 			  = new QLabel("APB Master Bus Width");
	 QSpacerItem *SpacerForRadioButtons 		  = new QSpacerItem(0,60, QSizePolicy::Expanding, QSizePolicy::Expanding);
		
	 	 

	 QRadioButton *button32 					  = new QRadioButton("32-bit");
	 QRadioButton *button16 					  = new QRadioButton("16-bit");
	 QRadioButton *button8  					  = new QRadioButton("8-bit");
	
	m_busWidthData.push_back(button32);	
	m_busWidthData.push_back(button16);
	m_busWidthData.push_back(button8);



	 button32->setFont(m_contentFont);
	 button16->setFont(m_contentFont);
	 button8->setFont(m_contentFont);

	 QSizePolicy grBoxSzPolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
	 groupBox->setStyleSheet(GROUP_BOX_STYLE_SHEET);                    
	 groupBox->setSizePolicy(grBoxSzPolicy); 		
	 groupBox->setFixedHeight(50);
	 groupBox->setMinimumHeight(50);
	 containerForGroupBoxText->setFont(m_contentFont);		
     	 
	 //button32->setChecked(true);
   	 
	ContainerForRadioButtonAndTexts->addWidget(containerForGroupBoxText, 0, 0);
   	 ContainerForRadioButtonAndTexts->addWidget(button32, 0, 1);
   	 ContainerForRadioButtonAndTexts->addWidget(button16, 0, 2);
   	 ContainerForRadioButtonAndTexts->addWidget(button8,  0, 3);
	 ContainerForRadioButtonAndTexts->addItem(SpacerForRadioButtons, 4, 4);
     groupBox->setLayout(ContainerForRadioButtonAndTexts);
	 return groupBox;
}


QGroupBox* MainWindow::createAddressConfigGb()
{
//change to GridLayout	

	QGroupBox *boxForAdress     	       = new QGroupBox("Address Configuration");
	QGridLayout*  boxForAdressLyt          = new QGridLayout();
	
	
	
	m_drivenConfigs               		= new QComboBox();
	m_positionConfigs            	 	= new QComboBox();
	m_indirectConfigs 	      		= new QComboBox(); 
	QLabel* drivenTextLable	                = new QLabel(NUMBERSADDRBTS);	
	QLabel* positionTextContent             = new QLabel(POSITION_SLAVE);
	QLabel* indirectTextLable  	        = new QLabel(INDIRECTADDR);
//////////////
	
	m_drivenConfigs->addItems(QStringList({"32","28", "24", "20", "12"}));
	boxForAdressLyt->addWidget(drivenTextLable, 0, 0);
   	boxForAdressLyt->addWidget(m_drivenConfigs, 0, 1);
	m_drivenConfigs->setFont(m_contentFont);
    	drivenTextLable->setFont(m_contentFont);

	m_positionConfigs->addItems(positionConfigStatus);
	boxForAdressLyt->addWidget(positionTextContent, 1, 0);
    	boxForAdressLyt->addWidget(m_positionConfigs, 1, 1);
	m_positionConfigs->setFont(m_contentFont);
	positionTextContent->setFont(m_contentFont);
	
	m_indirectConfigs->addItems(indirectConfigStatus);
	boxForAdressLyt->addWidget(indirectTextLable, 2, 0);
    	boxForAdressLyt->addWidget(m_indirectConfigs, 2, 1);
	indirectTextLable->setFont(m_contentFont);
	m_indirectConfigs->setFont(m_contentFont);
	boxForAdress->setLayout(boxForAdressLyt);	
    	boxForAdress->setStyleSheet(GROUP_BOX_STYLE_SHEET); 	
	boxForAdress->setFixedHeight(130);
	boxForAdress->setMinimumHeight(130);		
	return boxForAdress;

}






QGroupBox* MainWindow::createCheckesGb(const QString& strType)
{
	if (!( (strType == ENABLED_APB_SLAVE_SLOTS) || (strType == ALLOCATE_MEMORY_SPACE_TO_COMBINED_REGION_SLAVE) ) ) return NULL;

//impliment third construction	
    QGroupBox *BoxForAllocateMemory = new QGroupBox(strType);   
	BoxForAllocateMemory->setStyleSheet(GROUP_BOX_STYLE_SHEET);
										 
	QGridLayout *ContainerforCheckboxes = new QGridLayout;
	ContainerforCheckboxes->setContentsMargins(10, 20, 10, 15);
	
	QSpacerItem *horizontalSpacerAlocateMem = new QSpacerItem(0,20, QSizePolicy::Expanding, QSizePolicy::Expanding);
	ContainerforCheckboxes->addItem(horizontalSpacerAlocateMem, 4, 4);
	
	BoxForAllocateMemory->setFont(m_headersFont);

	BoxForAllocateMemory->setLayout(ContainerforCheckboxes);
	BoxForAllocateMemory->setFixedHeight(150);
	BoxForAllocateMemory->setMinimumHeight(150);		
	
	int txl = 0;
	for(size_t i = 0; i < m_vecChbSrc.size() / 4; ++i){
		for(size_t j = 0; j < m_vecChbSrc.size() / 4; ++j){
			if (strType == ENABLED_APB_SLAVE_SLOTS)
			{
				ContainerforCheckboxes->addWidget(this->m_vecChbSrc[txl].first, i, j);
			}
			else
			{
				ContainerforCheckboxes->addWidget(this->m_vecChbSrc[txl].second, i, j) ;	
			}
			txl += 1;
		} 	
	}
	return BoxForAllocateMemory;
}

QWidget* MainWindow::createTestbenchConfig() //funcPartOfTest()
{       
	QWidget* partOfTests   			       = new QWidget();
	QGridLayout* partOfTestsLyt 	       = new QGridLayout();
	QComboBox *testBenchConfigs 	       = new QComboBox();
	QRadioButton *buttonofObfuscated       = new QRadioButton("Obfuscated");
	QRadioButton *buttonofRtl 		 	   = new QRadioButton("RTL");
	buttonofRtl->setChecked(true);
			
	QLabel* textLableForTestBench 	 	   = new QLabel("Testbench:");
	QLabel* textLableForLicense 	 	   = new QLabel("License:  ");
	buttonofObfuscated->setFont(m_contentFont);
    buttonofRtl->setFont(m_contentFont); 
	textLableForTestBench->setFont(m_contentFont); 	 	
    textLableForLicense->setFont(m_contentFont); 
	
	
	QSpacerItem *SpacerForTestBrenchConfig = new QSpacerItem(0,60, QSizePolicy::Expanding, QSizePolicy::Expanding);

		
	
	testBenchConfigs->addItems(QStringList({"User", "None"}));
	testBenchConfigs->setFont(m_contentFont);
	testBenchConfigs->setMaximumSize(70, 30);
	
	partOfTestsLyt->addWidget(textLableForTestBench, 0,0);		
	partOfTestsLyt->addWidget(testBenchConfigs, 0, 1);	
	partOfTestsLyt->addWidget(textLableForLicense, 1, 0);
   	partOfTestsLyt->addWidget(buttonofObfuscated, 1, 1);
	partOfTestsLyt->addWidget(buttonofRtl, 1, 2);
	partOfTestsLyt->addItem(SpacerForTestBrenchConfig, 4, 4);
	partOfTests->setLayout(partOfTestsLyt);	
	return partOfTests;
}

void MainWindow::tempCloseForJson()
{
	
	QJsonObject jsObj;
	

	getCheckedRadioButton();
	getJsonState();
		
	jsObj.insert("Tiltle", CORE_APB_3);
	jsObj.insert("Subbtitle",SUB_TXT_ACTEL );	
	
	QString posConfig        = m_positionConfigs->currentText();
	QString drivenConfig     = m_drivenConfigs->currentText();
	QString indConfigs 	 = m_indirectConfigs->currentText(); 
	
	
	jsObj.insert(INDIRECTADDR,   indConfigs);
	jsObj.insert(NUMBERSADDRBTS, drivenConfig);
	jsObj.insert(POSITION_SLAVE, posConfig);
	

	m_arr.append(jsObj);
	m_arr.append(m_checkBoxNameJson);



	QFile File("save.json");
	
	QString strFromObj = QJsonDocument(m_arr).toJson(QJsonDocument::Indented);
	if(File.open(QIODevice::Truncate | QIODevice::ReadWrite)){
		QTextStream stream(&File);
		stream.setCodec("utf-8");
		stream<<strFromObj;
	}
	File.close();	
	


}




QWidget* MainWindow::createFooterWidget()
{
 	QWidget* widgetForFooterButtons 	   = new QWidget();
	QGridLayout* containerForFooterButtons 	   = new QGridLayout();
	

	
	QSpacerItem *SpacerForFooterButtons        = new QSpacerItem(20,60, QSizePolicy::Expanding, QSizePolicy::Expanding);
	QDialogButtonBox* bb 		           = new QDialogButtonBox(
			QDialogButtonBox::Ok | QDialogButtonBox::Cancel | QDialogButtonBox::Help );

	QSizePolicy grBoxSzPolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
	widgetForFooterButtons->setSizePolicy(grBoxSzPolicy); 		
	
	QPushButton* okBtn = bb->button(QDialogButtonBox::Ok);
	okBtn->setAutoDefault(true);
	okBtn->setDefault(true);	
	okBtn->setFont(m_contentFont);
	connect(bb, &QDialogButtonBox::clicked, this, &MainWindow::tempCloseForJson);
	
	
	
	connect(bb, &QDialogButtonBox::clicked, this, &QDialog::reject);	
	QPushButton* caBtn = bb->button(QDialogButtonBox::Cancel);	
	caBtn->setFont(m_contentFont);
	caBtn->setAutoDefault(false);
	caBtn->setDefault(false);
	
	
	QPushButton* helpBtn = bb->button(QDialogButtonBox::Help); 

connect(helpBtn, &QPushButton::clicked, this, [=]()
{
    QUrl url("https://www.google.com");

    if (!QDesktopServices::openUrl(url))
    {
        qDebug() << "Failed to open URL";
    }
});










	
	helpBtn->setFont(m_contentFont);
	okBtn->setMaximumSize(70, 30);
	caBtn->setMaximumSize(70, 30);
	helpBtn->setMaximumSize(85, 30);
	containerForFooterButtons->addWidget(okBtn, 0, 3);
	containerForFooterButtons->addWidget(caBtn, 0, 4);	
	containerForFooterButtons->addWidget(helpBtn, 0, 0);
	containerForFooterButtons->addItem(SpacerForFooterButtons, 0, 0);
	widgetForFooterButtons->setFixedHeight(50);
	widgetForFooterButtons->setLayout(containerForFooterButtons);
	return widgetForFooterButtons;
}

void MainWindow::loadSource()
{
	int index = 0;	
	for(int i = 0; i < 4; ++i){
		for(int j = 0; j < 4; ++j){
			QString tmp = QString::number(index);
			QCheckBox* chUp   = new QCheckBox("Slot " + tmp);
			QCheckBox* chDown = new QCheckBox("Slot " + tmp);
			chUp->setFont(m_contentFont);
		    	chDown->setFont(m_contentFont);
			chDown->setChecked(true);
			chDown->setEnabled(false);
			MainWindow::m_vecChbSrc.push_back(std::make_pair(chUp, chDown));
			connect(chUp, SIGNAL(stateChanged(int)), this, SLOT(changeCheckBoxState()));
			index += 1;
		} 
	}
}
void MainWindow::changeCheckBoxState()
{
	QString tmp;
	QCheckBox* chb = dynamic_cast<QCheckBox*>(sender());
	for(size_t i = 0; i < m_vecChbSrc.size(); ++i){
		if(chb == m_vecChbSrc[i].first)
		{
			m_vecChbSrc[i].second->setChecked( !(m_vecChbSrc[i].first->checkState()) );
			QCheckBox* chb1( m_vecChbSrc[i].first );
			QCheckBox* chb2( m_vecChbSrc[i].second );
			bool b = chb1->checkState();
			chb2->setChecked(!b);
		}
	}	
}

void MainWindow::getJsonState()
{	
	QString tmp;
	for(size_t i = 0; i < m_vecChbSrc.size(); ++i){
	 	tmp = "loto" +  QString::number(i);	
		if(m_vecChbSrc[i].first->isChecked())
		{
		m_checkBoxNameJson.insert(tmp, m_vecChbSrc[i].first->text());
		}
	}	
}

void MainWindow::getCheckedRadioButton()
{
	QJsonObject obj; 	
	for(size_t i = 0; i < m_busWidthData.size(); ++i){
	 	if (m_busWidthData[i]->isChecked()){
		obj.insert("Data with configuration", m_busWidthData[i]->text());	
		m_arr.append(obj);	
		}
	}
}

QStringList MainWindow::getAllJsonValues(const QString &filePath)
{
QStringList result;

QFile file(filePath);
if (!file.open(QIODevice::ReadOnly)) {
    return result;
}

QByteArray data = file.readAll();
file.close();

QJsonParseError error;
QJsonDocument doc = QJsonDocument::fromJson(data, &error);

if (error.error != QJsonParseError::NoError) {
    return result;
}

if (!doc.isArray()) {
    return result;
}

QJsonArray rootArray = doc.array();

for (const QJsonValue &value : rootArray)
{
    if (value.isObject())
    {
        QJsonObject obj = value.toObject();

        for (auto it = obj.begin(); it != obj.end(); ++it)
        {
            QString key = it.key();
            QString val = it.value().toString();

            m_states.push_back(std::make_pair(key, val));
            result.append(val);

        }
    }

}

return result;
}

void MainWindow::setStatesForCombobox(QComboBox* cmb){
	
	for(size_t i = 0; i < m_states.size(); i++)
	{
		for( int j = 0; j < cmb->count(); j++)
		{
			if(cmb->itemText(j) == m_states[i].second)
			{
				cmb->setItemText(0, m_states[i].second);
			}	
			
		}

	}
}





void MainWindow::setStates()
{
	
for(size_t i = 0; i < m_states.size(); i++)
{
    for(size_t j = 0; j < m_busWidthData.size(); j++)
    {
        if(m_busWidthData[j]->text() == m_states[i].second)
        {
            m_busWidthData[j]->setChecked(true);
        }
    }

    for(size_t j = 0; j < m_vecChbSrc.size(); ++j)
    {
        if (m_vecChbSrc[j].first->text() == m_states[i].second)
        {
            m_vecChbSrc[j].first->setChecked(true);
        }
    }
}

	setStatesForCombobox(m_drivenConfigs);
	setStatesForCombobox(m_indirectConfigs);
	setStatesForCombobox(m_positionConfigs);


}













