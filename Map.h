#ifndef MAP_H_
#define MAP_H_

#include "graphviewer.h"
#include "Node.h"

class Map{
private:
	GraphViewer *gv;
	std::vector<Node*> nodes;
	std::vector<Road*> roads;
public:
	Map();
	void read();
	void read_nodes();
	void read_subroads();
	void read_roads();
};

#endif