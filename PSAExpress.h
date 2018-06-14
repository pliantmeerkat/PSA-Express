#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PSAExpress.h"
#include "stadfx.h"

class PSAExpress : public QMainWindow
{
	Q_OBJECT

public:
	PSAExpress(QWidget *parent = Q_NULLPTR);


	void Run_application();
	void Output(const QString &Text);


	QString Format_Text() const;
	


private:
	Ui::PSAExpressClass ui;



protected slots:
	void Run_Clicked();

};
