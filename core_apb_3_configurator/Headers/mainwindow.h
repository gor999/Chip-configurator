#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QString>
#include<QMainWindow>
#include<QDialog>
#include <QRadioButton> 
#include<QJsonArray>
#include<QJsonObject>
#include<QComboBox>

class QCheckBox;
class QGroupBox;

class MainWindow : public QDialog
{
	Q_OBJECT
public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void 		changeCheckBoxState();
	void		tempCloseForJson();

private:
	QWidget*	createHeaderWidget();
 	QTabWidget* createTabWidget();	
	QWidget* 	createFooterWidget(); 
		
	QGroupBox*	createDataConfigGb(); 
	QGroupBox*	createAddressConfigGb();
	QGroupBox*	createCheckesGb(const QString& strType);
	QWidget*	createTestbenchConfig();
	
	QString getCheckedRadioButtonText();	
	
private:
	void 		loadSource();
	void 		getJsonState();
	QStringList 	getAllJsonValues(const QString& filePath);	
	void 		getCheckedRadioButton();	
private:
	QFont m_contentFont;	
	QFont m_headersFont;
	QComboBox* m_drivenConfigs;
	QComboBox* m_positionConfigs;
	QComboBox* m_indirectConfigs; 
	
	std::vector<std::pair<QCheckBox*, QCheckBox*> > m_vecChbSrc;	
	std::vector<QRadioButton*> m_busWidthData;
	QJsonArray m_arr;
	QJsonObject m_checkBoxNameJson;
	
};


#endif
