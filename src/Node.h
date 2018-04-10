#ifndef NODE_H_
#define NODE_H_

#include "Road.h"
#include <vector>
#include <cstddef>

class Road;

/**
 * @brief      Class for node.
 */
class Node{
private:
	int x,y;
	unsigned int index;
	std::vector<Road*> roads;

	//bool visited;          // auxiliary field
	double dist = 0;
	Node *path = NULL;
	int queueIndex = 0; 		// required by MutablePriorityQueue

public:
	Node(int x, int y, int index);
	int getX();
	int getY();
	std::vector<Road*>  & getRoads();
	void addRoad(Road *r);

	bool operator<(Node & n) const; // // required by MutablePriorityQueue

	friend class Map;
	friend class Menu;
	friend class MutablePriorityQueue;

};


#endif
