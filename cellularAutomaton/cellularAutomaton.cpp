#include "cellularAutomaton.h"

#define REP(i,n) for(i=0;i<n;i++)

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

template <typename T>
inline T imin(const T &a,const T &b){
	if(a<b) return a; else return b;
}

// -------------- MEMBER FUNCTIONS ------------------

void cellularAutomaton::_clean(){
	if(_isLoaded){
		delete image;
		delete displayImage;
		delete echo;
		_isLoaded=false;
		ui.btnAuto->setEnabled(false);
		ui.btnStep->setEnabled(false);
		ui.btnAuto->setEnabled(false);
		ui.btnSave->setEnabled(false);
	}
}

void cellularAutomaton::_init(){
	_clean();
	ui.btnAuto->setEnabled(true);
	ui.btnStep->setEnabled(true);
	ui.btnSave->setEnabled(true);
	image=new QImage(w,h,QImage::Format::Format_RGB32);
}

void cellularAutomaton::_initEnd(){
	displayImage=new QImage(*image);
	echo=new QImage(1,1,QImage::Format::Format_RGB32);
	_generation=0;
	ui.labelStat->setText("Stat:");
	updateImage();
	_isLoaded=true;
}

void cellularAutomaton::updateImage(){
	ui.label_2->setText(QString("Generation %1").arg(_generation));
	delete echo;
	echo=transform(displayImage,0.2);
	ui.label->setPixmap(QPixmap::fromImage(*echo));
}

void cellularAutomaton::updateStatus(Neighborhood &n){
	QString res("Stat:\n");
	long sum=0,i,tmp;
	REP(i,numOfStatus)
		sum+=n.stat[(status)i];
	REP(i,numOfStatus){
		tmp=(long)(n.stat[(status)i]*100.0/sum);
		res.append(QString("status%1: %2%\n").arg(i).arg(tmp));
	}
	ui.labelStat->setText(res);
}

// -------------- SLOTS -------------------

void cellularAutomaton::generate(){
	_init();
	long x,y;
	REP(x,w){
		REP(y,h){
			long p=rand()%100,z,sum=0;
			REP(z,numOfStatus){
				sum+=initStatusPossibility[z];
				if(p<sum){
					image->setPixel(x,y,mapColor[z]);
					break;
				}
			}
		}
	}
	_initEnd();
}

void cellularAutomaton::loadImage(){
	_clean();
	QImage *tttmp=new QImage(QFileDialog::getOpenFileName()),
		   *ttttmp=transform(tttmp,imin(tttmp->width()/(w+1.0),tttmp->height()/(h+1.0)));
	QImage tmp=*ttttmp; delete ttttmp;
	if((tmp.width()<w)||(tmp.width()<h)){
		//QMessageBox::warning(this,"Error","The image must bigger than the sandbox.",QMessageBox::StandardButton::Cancel);
		return;
	}
	_init();
	long x,y,z,t; double delta=255.0/numOfStatus,now; int gray,p; const long n=numOfStatus;
	myRGB *centerPoint=new myRGB[n];
	long **arr=new long*[h];
	for(x=0;x<h;x++){
		arr[x]=new long[w];
	}
	for(x=0;x<n;x++)
		centerPoint[x].randomize();
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			long mindist=999999999,tmpp;
			for(z=0;z<n;z++){
				tmpp=centerPoint[z].distance(tmp.pixel(x,y));
				if(tmpp<mindist){
					mindist=tmpp;
					arr[y][x]=z;
				}
			}
		}
	}
	long *counter=new long[n];
	for(t=0;t<50;t++){
		for(z=0;z<n;z++){ centerPoint[z].clear(); counter[z]=0; }
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				counter[arr[y][x]]++;
				centerPoint[arr[y][x]]+=tmp.pixel(x,y);
			}
		}
		for(z=0;z<n;z++) if(counter[z]) centerPoint[z]/=counter[z]; else centerPoint[z].randomize();
		for(y=0;y<h;y++){
			for(x=0;x<w;x++){
				long mindist=999999999,tmpp;
				for(z=0;z<n;z++){
					tmpp=centerPoint[z].distance(tmp.pixel(x,y));
					if(tmpp<mindist){
						mindist=tmpp;
						arr[y][x]=z;
					}
				}
			}
		}
	}
	for(y=0;y<h;y++){
		for(x=0;x<w;x++){
			image->setPixel(x,y,mapColor[arr[y][x]]);
		}
	}
	delete [] centerPoint;
	delete [] counter;
	for(x=0;x<w;x++){
		delete [] arr[x];
	}
	delete [] arr;
	_initEnd();
}

void cellularAutomaton::saveImage(){
	QImage tmp(*image);
	long x,y,z; double delta=255.0/numOfStatus,now; int gray;
	REP(x,w){
		REP(y,h){
			now=delta*(0.5+int(Cell(image->pixel(x,y)).stat));
			int ttmp=(int)now;
			tmp.setPixel(x,y,qRgb(now,now,now));
		}
	}
	tmp.save(QFileDialog::getSaveFileName());
}

void cellularAutomaton::step(){
	_generation++;
	Neighborhood sum;
	long x,y;
	REP(x,w){
		REP(y,h){
			Cell c(displayImage->pixel(x,y));
			sum+=c;
			#ifdef advancedInterface
				evolveCell(displayImage,x,y,w,h,_generation,c);
			#else
				Neighborhood n(*displayImage,x,y);
				evolveCell(c,n);
			#endif
			image->setPixel(x,y,mapColor[c.stat]);
		}
	}
	updateStatus(sum);
	delete displayImage;
	displayImage=new QImage(*image);
	updateImage();
	if(_isAutoMode){
		QTimer::singleShot(ui.speedSlider->value(),this,SLOT(step()));
	}
}

void cellularAutomaton::autoMode(){
	// TODO
	_isAutoMode=!_isAutoMode;
	if(_isAutoMode){
		ui.btnAuto->setText("Pause");
		ui.speedSlider->setEnabled(true);
		ui.btnGenerate->setEnabled(false);
		ui.pushButton->setEnabled(false);
		step();
	}else{
		ui.speedSlider->setEnabled(false);
		ui.btnGenerate->setEnabled(true);
		ui.pushButton->setEnabled(true);
		ui.btnAuto->setText("Auto");
	}
}

// --------------- CONSTRUCTORS -------------------

cellularAutomaton::cellularAutomaton(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	srand(time(0));
	_isLoaded=false;
	_isAutoMode=false;
	long i;
	REP(i,numOfStatus){
		mapStatusId[mapColor[(status)i]]=i;
	}
}

cellularAutomaton::~cellularAutomaton()
{
	_clean();
}