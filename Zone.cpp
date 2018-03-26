#include "Zone.h"
#include <iostream>

Zone::Zone() {}

Zone::Zone(std::string name, double x, double y, int limit):name(name),x(x),y(y),limit(limit)
{}

Zone::Zone(std::string name, double x, double y, int limit, bool acessable):name(name),x(x),y(y),acessable(acessable),limit(limit)
{}

double Zone::getX(){
  return this->x;
}

double Zone::getY(){
  return this->y;
}
std::string Zone::getName(){
  return this->name;
}

bool Zone::isAcessable(){
  return this->acessable;
}
int Zone::getLimit(){
  return this->limit;
}

void Zone::setAcess(bool acess){
  this->acessable = acess;
}
