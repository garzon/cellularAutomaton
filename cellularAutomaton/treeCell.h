#ifndef TREENEIGHBOR_H
#define TREENEIGHBOR_H

#include <qimage.h>
#include <cstdlib>
#include <ctime>

#ifndef REP
	#define REP(i,n) for(i=0;i<n;i++)
#endif

// ------------- SPECIAL PART START -------------------
static const QRgb mapColor[]={qRgb(150,50,0),qRgb(0,255,0),qRgb(255,0,0)};
static const long numOfStatus=3;
enum status{ ground,tree,fire };
static const long   fire2ground=30,
					ground2tree=10,
					tree2fire=3,
					firetree=25;
// -------------- SPECIAL PART END -------------------

class Cell{
public:
	status s;
	Cell(){};
	explicit Cell(QRgb p){
		long i;
		REP(i,numOfStatus){
			if(mapColor[i]==p){
				s=(status)i;
				return;
			}
		}
	}
};

#endif