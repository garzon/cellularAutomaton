#ifndef TREENEIGHBOR_H
#define TREENEIGHBOR_H

#include <qimage.h>
#include <cstdlib>
#include <ctime>

// ------------- SPECIAL PART START -------------------

#define modelName forestFire

// The macro modelName decides what model is going to run 

// -------------- SPECIAL PART END -------------------

namespace forestFire{

#ifndef REP
	#define REP(i,n) for(i=0;i<n;i++)
#endif

static const QRgb mapColor[]={qRgb(150,50,0),qRgb(0,255,0),qRgb(255,0,0)};
static const long numOfStatus=3;
enum status{ ground,tree,fire };
static const bool isNeighborSurrounded=true;

}; // namespace forestFire

using namespace modelName;

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