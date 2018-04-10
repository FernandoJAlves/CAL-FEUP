#ifndef MAP_H_
#define MAP_H_

#include "graphviewer.h"
#include "Node.h"
#include <limits>

#define INF std::numeric_limits<double>::max()

/**
 * @brief      Class for map.
 */
class Map{
private:
	GraphViewer *gv;
	std::vector<Node*> nodes;
	std::vector<Road*> roads;

public:

	/**
	 * @brief      { function_description }
	 */
	Map();

	/**
	 * @brief      { function_description }
	 */
	void read();

	/**
	 * @brief      Reads a mperp.
	 */
	void read_mperp();

	/**
	 * @brief      Reads nodes.
	 */
	void read_nodes();
	
	/**
	 * @brief      Reads subroads.
	 */
	void read_subroads();
	
	/**
	 * @brief      Reads roads.
	 */
	void read_roads();
	
	/**
	 * @brief      Draws a map.
	 */
	void draw_map();
	
	/**
	 * @brief      Creates a window.
	 */
	void createWindow();
	
	/**
	 * @brief      Closes a window.
	 */
	void closeWindow();


// Novos metodos a implementar

	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  index  The index
	 *
	 * @return     { description_of_the_return_value }
	 */
	Node* findNode(const unsigned int index) const;
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  origin  The origin
	 */
	void dijkstraShortestPath_modified(const unsigned int origin);
	
	/**
	 * @brief      Gets the path.
	 *
	 * @param[in]  origin  The origin
	 * @param[in]  dest    The destination
	 *
	 * @return     The path.
	 */
	vector<unsigned int> getPath(const unsigned int origin, const unsigned int dest) const;
	
	/**
	 * @brief      Gets the path secure.
	 *
	 * @param[in]  origin  The origin
	 * @param[in]  dest    The destination
	 *
	 * @return     The path secure.
	 */
	vector<unsigned int> getPath_secure(const unsigned int origin, const unsigned int dest) const;
	
	/**
	 * @brief      Sets the access road.
	 *
	 * @param[in]  index  The index
	 * @param[in]  value  The value
	 */
	void setAccessRoad(unsigned int index, bool value);
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  v1    The v 1
	 *
	 * @return     { description_of_the_return_value }
	 */
	bool incrementCounter(vector<unsigned int> v1);
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  path   The path
	 * @param[in]  color  The color
	 */
	void paint_path(vector<unsigned int> path, string color);
	
	/**
	 * @brief      Gets the road between nodes.
	 *
	 * @param[in]  origin  The origin
	 * @param[in]  dest    The destination
	 *
	 * @return     The road between nodes.
	 */
	Road * getRoadBetweenNodes(unsigned int origin, unsigned int dest);
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  v1    The v 1
	 *
	 * @return     { description_of_the_return_value }
	 */
	double timeOfTravel(vector<unsigned int> v1);
	
	/**
	 * @brief      { function_description }
	 */
	void resetMapVars();

//Metodos para teste
	
	/**
	 * @brief      { function_description }
	 */
	void printRoads();
	
	/**
	 * @brief      { function_description }
	 *
	 * @param[in]  v1    The v 1
	 */
	void listLimitofPath(vector<unsigned int> v1);


	friend class Menu;

};

#endif
