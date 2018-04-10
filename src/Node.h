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

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  x      { parameter_description }
	 * @param[in]  y      { parameter_description }
	 * @param[in]  index  The index
	 */
	Node(int x, int y, int index);

	/**
	 * @brief      Gets the x.
	 *
	 * @return     The x.
	 */
	int getX();

	/**
	 * @brief      Gets the y.
	 *
	 * @return     The y.
	 */
	int getY();

	/**
	 * @brief      Gets the roads.
	 *
	 * @return     The roads.
	 */
	std::vector<Road*>  & getRoads();
	
	/**
	 * @brief      Adds a road.
	 *
	 * @param      r     { parameter_description }
	 */
	void addRoad(Road *r);

	bool operator<(Node & n) const; // // required by MutablePriorityQueue

	friend class Map;
	friend class Menu;
	friend class MutablePriorityQueue;

};


#endif
