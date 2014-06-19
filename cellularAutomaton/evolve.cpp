#include "evolve.h"

#if modelName == forestFire

	static const long
		burnup=20,
		ground2tree=10,
		tree2fire=1;

	void evolveCell(Cell &c,Neighborhood & n){
		long i;
		if(c.stat==fire){
			if(n.stat[tree]==0) c.stat=ground; // Nothing to be burned and die out
			return;
		}
		if(c.stat==ground){
			REP(i,n.stat[tree])
				if(rand()%100<ground2tree) c.stat=tree; // seeds grow up
			return;
		}
		if(c.stat==tree){
			if(rand()%100<tree2fire){   
				c.stat=fire;            // the trees light up
				return;
			}
			REP(i,n.stat[fire])
				if(rand()%100<burnup) c.stat=fire; // the trees burn up
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
