#include "Road.h"
#include <iostream>
#include <cmath>

Road::Road(Node * src, Node * dest):bidirectional(false),src(src),dest(dest)
{
	this->defineDist();
	this->defineLimit();
}

void Road::setInfo(std::string name, bool bidirectional, int maxspeed){
	this->name = name;
	this->bidirectional = bidirectional;
	this->maxspeed = maxspeed;
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
	this->dist_weight = sqrt(pow(this->src->getX() - this->dest->getX(),2)+pow(this->src->getY() - this->dest->getY(),2));
}
