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
   * @brief      { function_description }
   */
  Road(){};

  /**
   * @brief      { function_description }
   *
   * @param      src   The source
   * @param      dest  The destination
   */
  Road(Node * src, Node * dest);

  static double x_meter;
  static double y_meter;

  /**
   * @brief      Sets the information.
   *
   * @param[in]  name           The name
   * @param[in]  bidirectional  The bidirectional
   * @param[in]  maxspeed       The maxspeed
   */
  void setInfo(std::string name, bool bidirectional, int maxspeed);
  
  /**
   * @brief      Gets the distance.
   *
   * @return     The distance.
   */
  int getDist();
  
  /**
   * @brief      Gets the name.
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
   * @brief      Sets the access.
   *
   * @param[in]  acess  The acess
   */
  void setAccess(bool acess);
  
  /**
   * @brief      Gets the maxspeed.
   *
   * @return     The maxspeed.
   */
  int getMaxspeed();
  
  /**
   * @brief      Gets the source.
   *
   * @return     The source.
   */
  Node * getSrc();
  
  /**
   * @brief      Gets the destination.
   *
   * @return     The destination.
   */
  Node * getDest();
  
  /**
   * @brief      { function_description }
   */
  void defineLimit();
  
  /**
   * @brief      { function_description }
   */
  void defineDist();
  
  /**
   * @brief      Sets the xy.
   *
   * @param[in]  x     { parameter_description }
   * @param[in]  y     { parameter_description }
   */
  static void set_XY(double x, double y);




  friend class Map;
  friend class Menu;
  
};

#endif
