#include "neighborhood.h"

Neighborhood::Neighborhood(const QImage &map,long x,long y){
	long w=map.width(),h=map.height();
	neighborList.push_back(Cell(map.pixel(prev(x,w),y)));
	neighborList.push_back(Cell(map.pixel(next(x,w),y)));
	neighborList.push_back(Cell(map.pixel(x,prev(y,h))));
	neighborList.push_back(Cell(map.pixel(x,next(y,h))));
	if(isNeighborSurrounded){
		neighborList.push_back(Cell(map.pixel(prev(x,w),prev(y,h))));
		neighborList.push_back(Cell(map.pixel(prev(x,w),next(y,h))));
		neighborList.push_back(Cell(map.pixel(next(x,w),prev(y,h))));
		neighborList.push_back(Cell(map.pixel(next(x,w),prev(y,h))));
	}
	long p;
	for(p=0;p<numOfStatus;p++)
		stat[(status)p]=0;
	for(p=0;p<neighborList.size();p++)
		stat[neighborList[p].stat]++;
}

inline long Neighborhood::prev(long x,long xmax,long xmin){
	long res=x-1;
	if(res<xmin) res=xmax-1;
	return res;
}
inline long Neighborhood::next(long x,long xmax,long xmin){
	long res=x+1;
	if(res==xmax) res=xmin;
	return res;
}