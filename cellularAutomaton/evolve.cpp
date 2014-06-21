#include "evolve.h"

#if modelName == forestFire

	static const long
		ground2tree=1000,
		tree2fire=2;

	void evolveCell(Cell &c,Neighborhood & n){
		long i;
		if(c.stat==fire){
			c.stat=ground; // Nothing to be burned and die out
			return;
		}
		if(c.stat==ground){
			if(rand()%10000<ground2tree) c.stat=tree; // seeds grow up
			return;
		}
		if(c.stat==tree){
			if(n.stat[fire]) c.stat=fire;
			if(rand()%10000<tree2fire) c.stat=fire;
			return;
		}
	}

#endif
 // forestFire

#if modelName == conwaysGameOfLife

	void evolveCell(Cell &c,Neighborhood & n){
		long neighbor=n.stat[alive];
		if(neighbor==3){ c.stat=alive; return; }
		if(neighbor==2) return;
		c.stat=dead;
	}

#endif
// conwaysGameOfLife

#if modelName == oddOrEven

	void evolveCell(Cell &c,Neighborhood & n){
		c.stat=(status)(n.stat[odd]&1);
	}

#endif
// oddOrEven

#if modelName == edgeSmoothing

	void evolveCell(Cell &c,Neighborhood & n){
		if(n.stat[(status)(1-int(c.stat))]>2) c.stat=(status)(1-int(c.stat));
		//else c.stat=non_border;
	}

#endif
// edgeSmoothing

#if modelName == cellularAutomaton1D

	static const int elementaryCARules=124;

	void evolveCell(QImage *image,long x,long y,long w,long h,long t,Cell &c){
		static const int _rules=elementaryCARules;
		long i,j,k;
		t%=h;
		if(t!=y) return;
		Neighborhood n(*image,x,y);
		auto p=n.neighborList.begin();
		k=0;
		REP(i,3){
			k=k*2+int(p->stat);
			p++;
		}
		if(k==2){
			k=2;
		};
		k=(_rules>>k)&1;
		c.stat=(status)k;
	}

#endif
// cellularAutomaton1D

#if modelName == spread

	void evolveCell(Cell &c,Neighborhood & n){
		n.stat[c.stat]++;
		long neighbor=n.stat[y];
		if(neighbor>4){ c.stat=y; return; }
		c.stat=x;
	}

#endif
// spread