#include "Node.h"

/**
 * @brief      Constructs the object.
 *
 * @param[in]  x      { parameter_description }
 * @param[in]  y      { parameter_description }
 * @param[in]  index  The index
 */
Node::Node(int x, int y, int index): x(x),y(y), index(index)
{}

/**
 * @brief      Gets the x.
 *
 * @return     The x.
 */
int Node::getX(){
	return this->x;
}

/**
 * @brief      Gets the y.
 *
 * @return     The y.
 */
int Node::getY(){
	return this->y;
}

/**
 * @brief      Gets the roads.
 *
 * @return     The roads.
 */
std::vector<Road*> & Node::getRoads(){
	return this->roads;
}

/**
 * @brief      Adds a road.
 *
 * @param      r     { parameter_description }
 */
void Node::addRoad(Road *r){
	this->roads.push_back(r);
}

/**
 * @brief      { operator_description }
 *
 * @param      n     { parameter_description }
 *
 * @return     { description_of_the_return_value }
 */
bool Node::operator<(Node & n) const {
	return this->dist < n.dist;
}