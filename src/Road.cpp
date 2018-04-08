#include "Road.h"
#include <iostream>
#include <cmath>

double Road::x_meter = 1;
double Road::y_meter = 1;

Road::Road(Node * src, Node * dest):bidirectional(false),maxspeed(20),src(src),dest(dest)
{
	this->defineDist();
	//this->defineLimit();
}

void Road::setInfo(std::string name, bool bidirectional, int maxspeed){
	this->name = name;
	this->bidirectional = bidirectional;
	this->maxspeed = maxspeed;
	this->defineLimit();
}

int Road::getDist(){
  return this->dist_weight;
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
	this->limit = dist_weight * maxspeed; //TODO maybe this is too much, we need to test
}

void Road::defineDist(){
	this->dist_weight = sqrt(pow(this->x_meter * (this->src->getX() - this->dest->getX()),2)+pow(this->y_meter * (this->src->getY() - this->dest->getY()),2));
}

void Road::set_XY(double x, double y){
    x_meter = x;
    y_meter = y;
  }
