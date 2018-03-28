#include "Node.h"

Node::Node(int x, int y): x(x),y(y)
{}

int Node::getX(){
	return this->x;
}

int Node::getY(){
	return this->y;
}

std::vector<Road> & Node::getRoads(){
	return this->roads;
}

void Node::addRoad(Road &r){
	this->roads.push_back(r);
}