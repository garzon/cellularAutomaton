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
