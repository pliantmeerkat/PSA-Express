#include "PSAExpress.h"

//this is the main file for operations within the ui.

PSAExpress::PSAExpress(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
}


//class objects
Core C;


//run the applications
void PSAExpress::Run_application()
{

	



}

//when run button is clicked
void PSAExpress::Run_Clicked()
{
	
	C.Write_file("Mode00W.txt", 0.01, 4);	

	
	//Output(Text);
	

	

}


//to process output text
QString PSAExpress::Format_Text() const
{


	return ui.Output_Test_box->toHtml();

}
//clear and append textbox
void PSAExpress::Output(const QString &Text)
{

	//to clear text from last run
	//ui.Output_Test_box->clear();

	//to set the text
	ui.Output_Test_box->append(Text);

}