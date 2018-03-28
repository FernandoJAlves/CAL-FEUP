#ifndef MAP_H_
#define MAP_H_

#include "Node.h"

#define NODES_PATH "Porto_nodes.txt"
#define ROADS_PATH "Porto_roads.txt"
#define SUBROADS_PATH "Porto_subroads.txt"

class Map{
private:
	std::vector<Node*> nodes;
public:
	void read();
	void read_nodes();
	void read_subroads();
	void read_roads();
};

#endif