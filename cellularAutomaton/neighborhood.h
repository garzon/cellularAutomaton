#ifndef NEIGHBORHOOD_H
#define NEIGHBORHOOD_H

#include <qvector.h>
#include <map>
#include <algorithm>
#include "cell.h"
using namespace std;
using namespace modelName;

class Neighborhood{
public:
	QVector<Cell> neighborList; map<status,long> stat;
	explicit Neighborhood(const QImage &map,long x,long y);
private:
	inline long prev(long x,long xmax,long xmin=0);
	inline long next(long x,long xmax,long xmin=0);
};

#endif