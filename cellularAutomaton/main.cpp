#include "cellularAutomaton.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	cellularAutomaton w;
	w.show();
	return a.exec();
}
