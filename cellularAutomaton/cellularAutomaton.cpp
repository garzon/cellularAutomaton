#include "cellularAutomaton.h"

#define REP(i,n) for(i=0;i<n;i++)

// --------------- CONSTRUCTORS -------------------

cellularAutomaton::cellularAutomaton(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	srand(time(0));
	_isLoaded=false;
	_isAutoMode=false;
}

cellularAutomaton::~cellularAutomaton()
{
	if(_isLoaded){
		delete image;
		delete displayImage;
		delete echo;
	}
}

// ------------------ HELPERS -----------------------

QImage * transform(QImage * const image,double zoom){
	long x,y,i,j,w=(long)(image->width()/zoom),h=(long)(image->height()/zoom);
	QImage *res=new QImage(w,h,QImage::Format::Format_RGB32);
	for(x=0;x<w;x++){
		for(y=0;y<h;y++){
			long b=(long)(x*zoom),c=(long)(y*zoom);
			myRGB sum; long area=0;
			for(i=b;i<b+zoom;i++){
				for(j=c;j<c+zoom;j++){
					sum+=image->pixel(i,j);
					area++;
				}
			}
			sum/=area;
			res->setPixel(x,y,sum.toQRGB());
		}
	}
	return res;
}

// -------------- MEMBER FUNCTIONS ------------------

void cellularAutomaton::updateImage(){
	delete echo;
	echo=transform(displayImage,0.4);
	ui.label->setPixmap(QPixmap::fromImage(*echo));
}

// -------------- SLOTS -------------------

void cellularAutomaton::generate(){
	ui.btnAuto->setEnabled(true);
	ui.btnStep->setEnabled(true);
	if(_isLoaded){
		delete image;
		delete displayImage;
		delete echo;
	}
	image=new QImage(w,h,QImage::Format::Format_RGB32);
	long x,y;
	REP(x,w){
		REP(y,h){
			image->setPixel(x,y,mapColor[rand()%numOfStatus]);
		}
	}
	displayImage=new QImage(*image);
	echo=new QImage(1,1,QImage::Format::Format_RGB32);
	updateImage();
	_isLoaded=true;
}

void cellularAutomaton::step(){
	long x,y;
	REP(x,w){
		REP(y,h){
			Cell c(displayImage->pixel(x,y));
			CellNeighborhood n(*displayImage,x,y);
			evolveCell(c,n);
			image->setPixel(x,y,mapColor[c.s]);
		}
	}
	delete displayImage;
	displayImage=new QImage(*image);
	updateImage();
}

void cellularAutomaton::autoMode(){

}

