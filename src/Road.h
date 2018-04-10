#ifndef ROAD_H_
#define ROAD_H_

#include "Node.h"
#include <string>

class Node;

/**
 * @brief      Class for road.
 */
class Road{
private:
  std::string name;
  
  bool accessable = true;
  bool bidirectional;

  double weight = 0; // será usado como valor de weight
  int dist;
  int limit;
  int maxspeed;

  int car_count = 0; //usado para saber quantos carros irão passar numa dada Road e determinar se devemos redirecionar

  Node * src;
  Node * dest;
public:

  /**
   * @brief      Road Constructor.
   */
  Road(){};

  /**
   * @brief      Road Constructor.
   *
   * @param      src   The source node
   * @param      dest  The destination node
   */
  Road(Node * src, Node * dest);

  static double x_meter;
  static double y_meter;

  /**
   * @brief      Sets aditional information.
   *
   * @param[in]  name           The name of the road
   * @param[in]  bidirectional  If the road is bidirectional
   * @param[in]  maxspeed       The maxspeed of the road
   */
  void setInfo(std::string name, bool bidirectional, int maxspeed);
  
  /**
   * @brief      Gets the distance of a road.
   *
   * @return     The distance.
   */
  int getDist();
  
  /**
   * @brief      Gets the name of a road.
   *
   * @return     The name.
   */
  std::string getName();
  
  /**
   * @brief      Determines if accessable.
   *
   * @return     True if accessable, False otherwise.
   */
  bool isAccessable();
  
  /**
   * @brief      Determines if bidirectional.
   *
   * @return     True if bidirectional, False otherwise.
   */
  bool isBidirectional();
  
  /**
   * @brief      Gets the limit.
   *
   * @return     The limit.
   */
  int getLimit();
  
  /**
   * @brief      Gets the weight.
   *
   * @return     The weight.
   */
  double getWeight();
  
  /**
   * @brief      Sets the accessable value.
   *
   * @param[in]  access  The access
   */
  void setAccess(bool access);
  
  /**
   * @brief      Gets the maxspeed.
   *
   * @return     The maxspeed.
   */
  int getMaxspeed();
  
  /**
   * @brief      Gets the source node.
   *
   * @return     The source node.
   */
  Node * getSrc();
  
  /**
   * @brief      Gets the destination node.
   *
   * @return     The destination node.
   */
  Node * getDest();
  
  /**
   * @brief      Defines the limit of a road.
   */
  void defineLimit();
  
  /**
   * @brief      Defines the dist of a road.
   */
  void defineDist();
  
  /**
   * @brief      Sets the xy values for map scaling.
   *
   * @param[in]  x     x ratio
   * @param[in]  y     y ratio
   */
  static void set_XY(double x, double y);

  friend class Map;
  friend class Menu;
  
};

#endif
