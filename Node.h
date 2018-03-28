#ifndef NODE_H_
#define NODE_H_

#include "Road.h"
#include <vector>

class Road;

class Node{
private:
  int x,y;
  std::vector<Road> roads;
public:
  Node(int x, int y);
  int getX();
  int getY();
  std::vector<Road>  & getRoads();
  void addRoad(Road &r);
};


#endif