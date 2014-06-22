cellularAutomaton
=================

A framework of cellular automaton<br />
- With Model of "Forest Fire"<br />
- With Model of "Conway's Game of Life"<br />
- With Model of one demension cellular automaton (Rule #124)
- and more...

# Environment
- Visual Studio 2012
- Qt 5
- QtPluginForVS2012

# If you wanna add your models...
You JUST need to modify two files, cell.h & evolve.cpp.

### cell.h:
#### In "SPECIAL PART": 
- add "#define YOURMODELNAME ANOTHERNUMBER"

#### And Then...
- (option) If you wanna run the model you added, modify the "modelName" macro, like "#define modelName YOURMODELNAME"
- add "#if modelName == YOURMODELNAME", copy the settings and paste and modify, add "#endif"

#### The Settings
- "mapColor[]" decides the color of the cell in different status
- "enum status" decides all possible status a cell may has
- "numOfStatus" decides the number of all possible status
- "isNeighborSurrounded" decide the shape of neighborhood (Moore for true and von Neumann for false)
- "initStatusPossibility" decides the initial density (%) of the cell in different status

### evolve.cpp:
- add "#if modelName == YOURMODELNAME", copy the function evolveCell(Cell,Neighborhood) and paste and modify, add "#endif"

#### Function evolveCell(Cell &c,const Neighborhood &n)
- All you need to do in this function is to set the next status of the Cell &c, according to the Neighborhood &n.
- "(enum status)c.stat": the status of the cell
- "n.stat[X]": the number of neighbors in the status X



