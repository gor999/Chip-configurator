#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QString>
#include <QMainWindow>
#include <QDialog>
#include <QJsonArray>
#include <QJsonObject>



class QCheckBox;
class QGroupBox;
class QComboBox;
class QRadioButton;




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
	void 		loadSource();
	void 		getJsonState();
	void 		getCheckedRadioButton();	
	void 		setStates();
	void            setStatesForCombobox(QComboBox* cmb);
	QWidget*	createHeaderWidget();
 	QTabWidget*     createTabWidget();	
	QWidget* 	createFooterWidget(); 
	QGroupBox*	createDataConfigGb(); 
	QGroupBox*	createAddressConfigGb();
	QGroupBox*	createCheckesGb(const QString& strType);
	QWidget*	createTestbenchConfig();
	QStringList 	getAllJsonValues(const QString& filePath);	
	QString 	getCheckedRadioButtonText();	
private:
	std::vector<std::pair<QCheckBox*, QCheckBox*>>  m_vecChbSrc;	
	std::vector<std::pair<QString, QString> >       m_states;	
	QFont 						m_contentFont;	
	QFont 						m_headersFont;
	QComboBox* 					m_drivenConfigs;
	QComboBox* 					m_positionConfigs;
	QComboBox* 					m_indirectConfigs; 
	std::vector<QRadioButton*> 			m_busWidthData;
	QJsonArray  		   			m_arr;
	QJsonObject 		   			m_checkBoxNameJson;
};



#endif
