#include "evolve.h"

#if modelName == forestFire

	static const long   fire2ground=30,
						ground2tree=10,
						tree2fire=3,
						firetree=25;

	void evolveCell(Cell &c,const Neighborhood & n){
		if(c.stat==fire){
			if(rand()%100<fire2ground){
				c.stat=ground;
				return;
			}
		}
		if(c.stat==ground){
			if((n.stat.find(tree)->second)==0) return;
			if(rand()%100<ground2tree){
				c.stat=tree;
				return;
			}
		}
		if(c.stat==tree){
			if(rand()%100<tree2fire){
				c.stat=fire;
				return;
			}
			if((n.stat.find(fire)->second)==0) return;
			if(rand()%100<firetree){
				c.stat=fire;
				return;
			}
		}
	}

#endif
 // forestFire

#if modelName == conwaysGameOfLife

	void evolveCell(Cell &c,const Neighborhood & n){
		long neighbor=n.stat.find(live)->second;
		if(c.stat==live){
			if(neighbor==2) return;
			if(neighbor==3) return;
			c.stat=dead;
			return;
		}
		if(c.stat==dead){
			if(neighbor==3) c.stat=live;
			return;
		}
	}

#endif
// conwaysGameOfLife
