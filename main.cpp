#include "PSAExpress.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	PSAExpress w;
	w.show();
	return a.exec();
}
