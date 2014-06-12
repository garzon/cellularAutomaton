#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

#include <QtWidgets/QMainWindow>
#include "ui_cellularAutomaton.h"
#include "myRGB.h"
#include "evolve.h"

class cellularAutomaton : public QMainWindow
{
	Q_OBJECT

public:
	cellularAutomaton(QWidget *parent = 0);
	~cellularAutomaton();
	QImage *image,*displayImage,*echo;
	void updateImage();
	static const long w=50,h=50;

public slots:
	void generate();
	void step();
	void autoMode();
private:
	Ui::cellularAutomatonClass ui;
	bool _isLoaded,_isAutoMode;
	
};

#endif // CELLULARAUTOMATON_H
