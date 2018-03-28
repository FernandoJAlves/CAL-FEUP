#ifndef ROAD_H_
#define ROAD_H_

#include "Node.h"
#include <string>

class Node;

class Road{
private:
  std::string name;

  
  bool acessable = true;
  bool bidirectional;

  int dist;
  int limit;
  int maxspeed;

  Node * src;
  Node * dest;
public:
  Road(Node * src, Node * dest);
  void setInfo(std::string name, bool bidirectional, int maxspeed);
  int getDist();
  std::string getName();
  bool isAcessable();
  bool isBidirectional();
  int getLimit();
  void setAcess(bool acess);
  int getMaxspeed();
  Node * getSrc();
  Node * getDest();
  void defineLimit();
  void defineDist();
};


#endif
