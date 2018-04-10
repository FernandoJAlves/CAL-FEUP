#include "Road.h"
#include <iostream>
#include <cmath>

double Road::x_meter = 1;
double Road::y_meter = 1;

/**
 * @brief      Constructs the object.
 *
 * @param      src   The source
 * @param      dest  The destination
 */
Road::Road(Node * src, Node * dest):bidirectional(false),maxspeed(20),src(src),dest(dest)
{
	this->defineDist();
	this->defineLimit();
	this->weight = ((double)(this->dist))/(this->maxspeed) + 0.5;
}

/**
 * @brief      Sets the information.
 *
 * @param[in]  name           The name
 * @param[in]  bidirectional  The bidirectional
 * @param[in]  maxspeed       The maxspeed
 */
void Road::setInfo(std::string name, bool bidirectional, int maxspeed){
	this->name = name;
	this->bidirectional = bidirectional;
	this->maxspeed = maxspeed;
	this->defineLimit();
	this->weight = ((double)(this->dist))/(this->maxspeed) + 0.5;
}

/**
 * @brief      Gets the distance.
 *
 * @return     The distance.
 */
int Road::getDist(){
  return this->dist;
}

/**
 * @brief      Gets the weight.
 *
 * @return     The weight.
 */
double Road::getWeight(){
  return this->weight;
}

/**
 * @brief      Gets the name.
 *
 * @return     The name.
 */
std::string Road::getName(){
  return this->name;
}

/**
 * @brief      Determines if accessable.
 *
 * @return     True if accessable, False otherwise.
 */
bool Road::isAccessable(){
  return this->accessable;
}
/**
 * @brief      Gets the limit.
 *
 * @return     The limit.
 */
int Road::getLimit(){
  return this->limit;
}

/**
 * @brief      Sets the access.
 *
 * @param[in]  acess  The acess
 */
void Road::setAccess(bool acess){
  this->accessable = acess;
}

/**
 * @brief      Gets the source.
 *
 * @return     The source.
 */
Node * Road::getSrc(){
	return this->src;
}

/**
 * @brief      Gets the destination.
 *
 * @return     The destination.
 */
Node * Road::getDest(){
	return this->dest;
}

/**
 * @brief      { function_description }
 */
void Road::defineLimit(){
	this->limit = dist * maxspeed; //TODO maybe this is too much, we need to test
}

/**
 * @brief      { function_description }
 */
void Road::defineDist(){
	this->dist = (double)sqrt((double)pow(this->x_meter * (this->src->getX() - this->dest->getX()),2)+(double)pow(this->y_meter * (this->src->getY() - this->dest->getY()),2)) + 1;
}

/**
 * @brief      Sets the xy.
 *
 * @param[in]  x     { parameter_description }
 * @param[in]  y     { parameter_description }
 */
void Road::set_XY(double x, double y){
    x_meter = x;
    y_meter = y;
  }
