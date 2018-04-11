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
	 * @brief      Map Constructor.
	 */
	Map();

	/**
	 * @brief      Calls all the read functions for files.
	 */
	void read();

	/**
	 * @brief      Reads the mperp values from a file.
	 */
	void read_mperp();

	/**
	 * @brief      Reads the nodes from a file.
	 */
	void read_nodes();

	/**
	 * @brief      Reads the subroads from a file.
	 */
	void read_subroads();

	/**
	 * @brief      Reads the roads' info from a file.
	 */
	void read_roads();

	/**
	 * @brief      Draws the map using the nodes and roads stored in vectors.
	 */
	void draw_map();

	/**
	 * @brief      Creates a graphical window and calls the read() function
	 */
	void createWindow();

	/**
	 * @brief      Closes the graphical window, and removes all nodes and roads.
	 */
	void closeWindow();


// Novos metodos

	/**
	 * @brief      Find a node with the given index.
	 *
	 * @param[in]  index  The node index
	 *
	 * @return     A node*, or NULL if non-existent.
	 */
	Node* findNode(unsigned int index) const;

	/**
	 * @brief      Shortest Path Algorithm, modified for our needs.
	 *
	 * @param[in]  origin  The origin node index
	 * @param[in]  dest    The destination index
	 */
	void dijkstraShortestPath_modified(unsigned int origin, unsigned int dest);

	/**
	 * @brief      Gets the path between the nodes origin and dest.
	 *
	 * @param[in]  origin  The origin index
	 * @param[in]  dest    The destination index
	 *
	 * @return     The path of indexes in a vector.
	 */
	vector<unsigned int> getPath(unsigned int origin, unsigned int dest) const;

	/**
	 * @brief      Gets the path between the nodes origin and dest, but assumes the origin and dest exist
	 *
	 * @param[in]  origin  The origin index
	 * @param[in]  dest    The destination index
	 *
	 * @return     The path of indexes in a vector.
	 */
	vector<unsigned int> getPath_secure(unsigned int origin, unsigned int dest) const;

	/**
	 * @brief      Sets the access road accessable to given value.
	 *
	 * @param[in]  index  The road index
	 * @param[in]  value  The bool value intended
	 */
	void setAccessRoad(unsigned int index, bool value);

	/**
	 * @brief      Increments the car_count of all the roads in a path
	 *
	 * @param[in]  v1    The vector of node indexes
	 *
	 * @return     The value of recalc, that determines if a path recalculation is needed
	 */
	bool incrementCounter(vector<unsigned int> v1);

	/**
	 * @brief      Paints the nodes in a path with the given color
	 *
	 * @param[in]  path   The path of nodes
	 * @param[in]  color  The color
	 */
	void paint_path(vector<unsigned int> path, string color);

	/**
	 * @brief      Gets the road between 2 given nodes.
	 *
	 * @param[in]  origin  The origin index
	 * @param[in]  dest    The destination index
	 *
	 * @return     A Road* to the road between 2 given nodes.
	 */
	Road * getRoadBetweenNodes(unsigned int origin, unsigned int dest);

	/**
	 * @brief      Calculates the time a path takes to be travelled.
	 *
	 * @param[in]  v1    The path of nodes
	 *
	 * @return     The time of travel.
	 */
	double timeOfTravel(vector<unsigned int> v1);

	/**
	 * @brief      Resets the vars used for calculating the shortest path
	 */
	void resetMapVars();

//Metodos para teste

	/**
	 * @brief      Prints the roads in the roads' vector
	 */
	void printRoads();

	/**
	 * @brief      Lists the limits of the roads in a given path
	 *
	 * @param[in]  v1    The path of indexes
	 */
	void listLimitofPath(vector<unsigned int> v1);


	friend class Menu;

};

#endif
