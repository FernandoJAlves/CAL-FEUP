#include "Node.h"

Node::Node(int x, int y, int index): x(x),y(y), index(index)
{}

int Node::getX(){
	return this->x;
}

int Node::getY(){
	return this->y;
}

std::vector<Road*> & Node::getRoads(){
	return this->roads;
}

void Node::addRoad(Road *r){
	this->roads.push_back(r);
}

bool Node::operator<(Node & n) const {
	return this->dist < n.dist;
}