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

  int dist; // será usado como valor de weight
  int limit;
  int maxspeed;

  int car_count = 0; //usado para saber quantos carros irão passar numa dada Road e determinar se devemos redirecionar

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
