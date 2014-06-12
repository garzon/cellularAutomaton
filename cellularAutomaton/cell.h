#ifndef TREENEIGHBOR_H
#define TREENEIGHBOR_H

#include <qimage.h>
#include <cstdlib>
#include <ctime>

#ifndef REP
	#define REP(i,n) for(i=0;i<n;i++)
#endif

// ------------- SPECIAL PART START -------------------

#define forestFire 1
#define conwaysGameOfLife 2
#define modelName 1

// The macro modelName decides what model is going to run 

// -------------- SPECIAL PART END -------------------

#if modelName == forestFire

static const QRgb mapColor[]={qRgb(150,50,0),qRgb(0,255,0),qRgb(255,0,0)};
static const long numOfStatus=3;
enum status{ ground,tree,fire };
static const bool isNeighborSurrounded=true;

#endif
// forestFire

#if modelName == conwaysGameOfLife

static const QRgb mapColor[]={qRgb(0,0,0),qRgb(255,255,255)};
static const long numOfStatus=2;
enum status{ dead,live };
static const bool isNeighborSurrounded=true;

#endif
// conwaysGameOfLife

class Cell{
public:
	status stat;
	Cell(){};
	explicit Cell(QRgb p){
		long i;
		REP(i,numOfStatus){
			if(mapColor[i]==p){
				stat=(status)i;
				return;
			}
		}
	}
};

#endif