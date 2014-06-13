#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

#include <QtWidgets/QMainWindow>
#include "ui_cellularAutomaton.h"
#include "myRGB.h"
#include "evolve.h"
#include <qtimer.h>

class cellularAutomaton : public QMainWindow
{
	Q_OBJECT

public:
	cellularAutomaton(QWidget *parent = 0);
	~cellularAutomaton();
	QImage *image,*displayImage,*echo;
	void updateImage();
	void updateStatus(Neighborhood &n);
	static const long w=50,h=50;
public slots:
	void generate();
	void step();
	void autoMode();
private:
	Ui::cellularAutomatonClass ui;
	bool _isLoaded,_isAutoMode;
	long _generation;
};

#endif // CELLULARAUTOMATON_H
