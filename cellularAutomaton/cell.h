#ifndef TREENEIGHBOR_H
#define TREENEIGHBOR_H

#include <qimage.h>
#include <cstdlib>
#include <ctime>
#include <map>

#ifndef REP
	#define REP(i,n) for(i=0;i<n;i++)
#endif

// ------------- SPECIAL PART START -------------------

#define forestFire 1
#define conwaysGameOfLife 2
#define oddOrEven 3
#define edgeSmoothing 4
#define cellularAutomaton1D 5

#define modelName 5

// The macro modelName decides what model is going to run 

// -------------- SPECIAL PART END -------------------

#if modelName == forestFire

static const long numOfStatus=3;
enum status{ ground,tree,fire };
static const long initStatusPossibility[]={80,20,0};
static const bool isNeighborSurrounded=true;
static const QRgb mapColor[]={qRgb(120,20,0),qRgb(0,255,0),qRgb(255,0,0)};

#endif
// forestFire

#if modelName == conwaysGameOfLife

static const long numOfStatus=2;
enum status{ dead,alive };
static const long initStatusPossibility[]={90,10};
static const bool isNeighborSurrounded=true;
static const QRgb mapColor[]={qRgb(255,255,255),qRgb(0,0,0)};

#endif
// conwaysGameOfLife

#if modelName == oddOrEven

static const long numOfStatus=2;
enum status{ even,odd };
static const long initStatusPossibility[]={50,50};
static const bool isNeighborSurrounded=false; // von.Neumann's neighbor
static const QRgb mapColor[]={qRgb(0,0,0),qRgb(255,255,255)};

#endif 
// oddOrEven

#if modelName == edgeSmoothing

static const long numOfStatus=2;
enum status{ border,non_border };
static const long initStatusPossibility[]={50,50}; 
static const bool isNeighborSurrounded=false; // von.Neumann's neighbor
static const QRgb mapColor[]={qRgb(0,0,0),qRgb(255,255,255)};

#endif 
// edgeSmoothing

#if modelName == cellularAutomaton1D

static const long numOfStatus=2;
enum status{ dead=0,alive=1 };
static const long initStatusPossibility[]={50,50}; 
static const bool isNeighborSurrounded=true;  // neighborhood radius=1
static const QRgb mapColor[]={qRgb(255,255,255),qRgb(0,0,0)};
#define advancedInterface  // use advanced interface of function evolveCell()

#endif 
// cellularAutomaton1D

static std::map<QRgb,long> mapStatusId; 

class Cell{
public:
	status stat;
	Cell(){};
	explicit Cell(QRgb p):stat((status)mapStatusId[p]){}
};

#endif