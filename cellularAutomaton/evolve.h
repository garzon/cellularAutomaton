#ifndef EVOLVE_H
#define EVOLVE_H

#include "neighborhood.h"

#ifdef advancedInterface
	void evolveCell(QImage *image,long x,long y,long w,long h,long t,Cell &c);
#else
	void evolveCell(Cell &c,Neighborhood & n);
#endif

#endif