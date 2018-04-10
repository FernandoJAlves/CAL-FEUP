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
	 * @brief      Node Constructor.
	 *
	 * @param[in]  x      x coordinate
	 * @param[in]  y      y coordinate
	 * @param[in]  index  The node index
	 */
	Node(int x, int y, int index);

	/**
	 * @brief      Gets the x coordinate.
	 *
	 * @return     The x.
	 */
	int getX();

	/**
	 * @brief      Gets the y coordinate.
	 *
	 * @return     The y.
	 */
	int getY();

	/**
	 * @brief      Gets the vector of adjacent roads.
	 *
	 * @return     The vector of roads.
	 */
	std::vector<Road*> & getRoads();
	
	/**
	 * @brief      Adds a road do the roads vector.
	 *
	 * @param      r     The road being added
	 */
	void addRoad(Road *r);

	/**
	 * @brief      Overload of the < operator.
	 *
	 * @param      n     The node being compared
	 */
	bool operator<(Node & n) const;      // required by MutablePriorityQueue

	friend class Map;
	friend class Menu;
	friend class MutablePriorityQueue;

};


#endif
