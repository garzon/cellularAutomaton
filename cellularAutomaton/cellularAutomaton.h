#ifndef CELLULARAUTOMATON_H
#define CELLULARAUTOMATON_H

#include <QtWidgets/QMainWindow>
#include <qtimer.h>
#include <qfiledialog.h>
#include <qmessagebox.h>
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
	void updateStatus(Neighborhood &n);
	static const long w=100,h=100;
public slots:
	void generate();
	void step();
	void autoMode();
	void loadImage();
	void saveImage();
private:
	Ui::cellularAutomatonClass ui;
	bool _isLoaded,_isAutoMode;
	long _generation;
	void _clean();
	void _init();
	void _initEnd();
};

#endif // CELLULARAUTOMATON_H
