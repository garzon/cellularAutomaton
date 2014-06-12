#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

#include <qvector.h>
#include <map>
#include <algorithm>
using namespace std;

// ------------- SPECIAL PART START -------------------
#include "treeCell.h"
static const bool isNeighborSurrounded=true;
// -------------- SPECIAL PART END -------------------

class CellNeighborhood{
public:
	QVector<Cell> neighborList; map<status,long> stat;
	explicit CellNeighborhood(const QImage &map,long x,long y);
private:
	inline long prev(long x,long xmax,long xmin=0);
	inline long next(long x,long xmax,long xmin=0);
};

#endif