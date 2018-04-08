#ifndef ROAD_H_
#define ROAD_H_

#include "Node.h"
#include <string>

class Node;

class Road{
private:
  std::string name;
  
  bool accessable = true;
  bool bidirectional;

  int dist_weight; // será usado como valor de weight
  int limit;
  int maxspeed;

  int car_count = 0; //usado para saber quantos carros irão passar numa dada Road e determinar se devemos redirecionar

  Node * src;
  Node * dest;
public:

  Road(){};
  Road(Node * src, Node * dest);

  static double x_meter;
  static double y_meter;

  void setInfo(std::string name, bool bidirectional, int maxspeed);
  int getDist();
  std::string getName();
  bool isAccessable();
  bool isBidirectional();
  int getLimit();
  void setAccess(bool acess);
  int getMaxspeed();
  Node * getSrc();
  Node * getDest();
  void defineLimit();
  void defineDist();
  static void set_XY(double x, double y);




  friend class Map;
  friend class Menu;
  
};

#endif
