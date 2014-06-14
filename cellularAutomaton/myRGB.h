#ifndef MYRGB_H
#define MYRGB_h

class myRGB{
public:
	long long r,g,b;
	myRGB(){
		r=0;g=0;b=0;
	}
	myRGB(int rr,int gg,int bb):r(rr),g(gg),b(bb){}
	myRGB(const QRgb & tmp){
		r=qRed(tmp); 
		g=qGreen(tmp);
		b=qBlue(tmp);
	}
	static int toGray(const QRgb &c){
		myRGB sum(c);
		sum.vmul(0.3,0.59,0.11);
		int res=sum.r+sum.g+sum.b;
		return res;
	}
	void randomize(){
		r=rand()%256;
		g=rand()%256;
		b=rand()%256;
	}
	void clear(){
		r=g=b=0;
	}
	long distance(const QRgb &c){
		long res=0;
		res+=(r-qRed(c))*(r-qRed(c));
		res+=(g-qGreen(c))*(g-qGreen(c));
		res+=(b-qBlue(c))*(b-qBlue(c));
		return res;
	}
	myRGB& operator +=(const QRgb & tmp){
		r+=qRed(tmp); 
		g+=qGreen(tmp);
		b+=qBlue(tmp);
		return *this;
	}
	myRGB& operator +=(const myRGB & tmp){
		r+=tmp.r;
		g+=tmp.g;
		b+=tmp.b;
		return *this;
	}
	myRGB& operator /=(long area){
		r/=area; g/=area; b/=area;
		return *this;
	}
	void trim(){
		_trim(r); _trim(g); _trim(b);
	}
	void vmul(double rr,double gg,double bb){
		r=(long)(rr*r);
		g=(long)(gg*g);
		b=(long)(bb*b);
	}
	QRgb toQRGB() const{
		return qRgb(r,g,b);
	}

private:
	void _trim(long long &v){
		if(v>255) v=255;
		if(v<0)   v=0;
	}
};

#endif