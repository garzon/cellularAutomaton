#include "evolve.h"

void evolveCell(Cell &c,const CellNeighborhood & n){
	if(c.s==fire){
		if(rand()%100<fire2ground){
			c.s=ground;
			return;
		}
	}
	if(c.s==ground){
		if((n.stat.find(tree)->second)==0) return;
		if(rand()%100<ground2tree){
			c.s=tree;
			return;
		}
	}
	if(c.s==tree){
		if(rand()%100<tree2fire){
			c.s=fire;
			return;
		}
		if((n.stat.find(fire)->second)==0) return;
		if(rand()%100<firetree){
			c.s=fire;
			return;
		}
	}
}
