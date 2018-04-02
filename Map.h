#ifndef MAP_H_
#define MAP_H_

#include "graphviewer.h"
#include "Node.h"
#include <limits>

#define INF std::numeric_limits<double>::max()

class Map{
private:
	GraphViewer *gv;
	std::vector<Node*> nodes;
	std::vector<Road*> roads;
public:
	Map();
	void read();
	void read_nodes();
	void read_subroads();
	void read_roads();
	void draw_map();
	void createWindow();
	void closeWindow();


//Novos metodos a implementar
	Node* findNode(const unsigned int index) const;
	void dijkstraShortestPath_modified(const unsigned int origin);
	vector<unsigned int> getPath(const unsigned int origin, const unsigned int dest) const;
	vector<unsigned int> getPath_secure(const unsigned int origin, const unsigned int dest) const;
	void setAccessRoad(unsigned int index, bool value);
	bool incrementCounter(vector<unsigned int> v1);

//Metodos para teste
	void printRoads();


	friend class Menu;

};

#endif