#include "Road.h"
#include <iostream>
#include <cmath>

double Road::x_meter = 1;
double Road::y_meter = 1;

Road::Road(Node * src, Node * dest):bidirectional(false),maxspeed(20),src(src),dest(dest)
{
	this->defineDist();
	this->defineLimit();
	this->weight = ((double)(this->dist))/(this->maxspeed);
}

void Road::setInfo(std::string name, bool bidirectional, int maxspeed){
	this->name = name;
	this->bidirectional = bidirectional;
	this->maxspeed = maxspeed;
	this->defineLimit();
	this->weight = (this->dist)/(this->maxspeed);
}

int Road::getDist(){
  return this->dist;
}

double Road::getWeight(){
  return this->weight;
}

std::string Road::getName(){
  return this->name;
}

bool Road::isAccessable(){
  return this->accessable;
}
int Road::getLimit(){
  return this->limit;
}

void Road::setAccess(bool acess){
  this->accessable = acess;
}

Node * Road::getSrc(){
	return this->src;
}

Node * Road::getDest(){
	return this->dest;
}

void Road::defineLimit(){
	this->limit = dist * maxspeed; //TODO maybe this is too much, we need to test
}

void Road::defineDist(){
	this->dist = (double)sqrt((double)pow(this->x_meter * (this->src->getX() - this->dest->getX()),2)+(double)pow(this->y_meter * (this->src->getY() - this->dest->getY()),2)) + 1;
}

void Road::set_XY(double x, double y){
    x_meter = x;
    y_meter = y;
  }
