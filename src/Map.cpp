#include "Map.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "MutablePriorityQueueNode.h"

#define MPERP_PATH "graph/porto_mperp.txt"
#define NODES_PATH "graph/porto_nodes.txt"
#define ROADS_PATH "graph/porto_roads.txt"
#define SUBROADS_PATH "graph/porto_subroads.txt"
#define MAP_PATH "maps/map.png"
#define WIDTH 1216
#define HEIGHT 989
#define SCALE 2.4f
#define WIDTHSCREEN 1560
#define HEIGHTSCREEN 210

double x_pix, y_pix;

using namespace std;

/**
 * @brief      Constructs the object.
 */
Map::Map(){
	gv = new GraphViewer(WIDTH, HEIGHT, false);
	gv->setBackground(MAP_PATH);
	this->read();

}

/**
 * @brief      Creates a window.
 */
void Map::createWindow(){
	gv->createWindow(WIDTH, HEIGHT);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	this->draw_map();
}

/**
 * @brief      Closes a window.
 */
void Map::closeWindow(){
	gv->closeWindow();
}

/**
 * @brief      Reads a mperp.
 */
void Map::read_mperp(){
	ifstream file(MPERP_PATH);
	if(file.is_open()){
		file >> x_pix;
		file >> y_pix;
	}
	else{
		cout << "Error opening the meters per pixel file" << endl;
	}

	Road::set_XY(x_pix, y_pix);

	x_pix = x_pix/SCALE;
	y_pix = y_pix/SCALE;

}

/**
 * @brief      Reads nodes.
 */
void Map::read_nodes(){
	ifstream file(NODES_PATH);
	string line;
	stringstream ss;
	int index,x,y;
	char comma;
	if(file.is_open()){
		while(getline(file,line)){
			ss << line;
			ss >> index >> comma >> x >> comma >> y;
			ss.clear();
			nodes.push_back(new Node(x,y,(index-1)));
		}
		file.close();
	}
	else{
		cout << "Error opening the nodes file" << endl;
	}
}


/**
 * @brief      Reads subroads.
 */
void Map::read_subroads(){
	ifstream file(SUBROADS_PATH);
	Road * r;
	string line;
	stringstream ss;
	int index,src,dest;
	char comma;
	if(file.is_open()){
		while(getline(file,line)){
			ss << line;
			ss >> index >> comma >> src >> comma >> dest >> comma;
			//cout << "First: " << index << " " << src << " " << dest << endl;
			ss.clear();
			r = new Road(nodes[src-1],nodes[dest-1]);
			this->nodes[src-1]->addRoad(r);
			this->roads.push_back(r);
			//cout << "Second: " << index << " " << src << " " << dest << endl;
		}
		file.close();
	}
	else{
		cout << "Error opening the subroads file" << endl;
	}
}

/**
 * @brief      Reads roads.
 */
void Map::read_roads(){
	ifstream file(ROADS_PATH);
	stringstream ss;
	string line;
	string index,name,bidirectional,maxspeed;
	int i,ms;
	Road * r;
	bool bd;
	if(file.is_open()){
		while(getline(file,line)){
			ss << line;
			getline(ss,index,';');
			getline(ss,name,';');
			getline(ss,bidirectional,';');
			getline(ss,maxspeed,';');
			ss.clear();
			i = stoi(index);
			if(bidirectional == "True"){
				bd = true;
			}
			else{
				bd = false;
			}
			if(maxspeed == "PT:urban\r"  || maxspeed == "PT:urban" ){
				ms = 50;
			}
			else if(maxspeed == "" || maxspeed == "\r"){
				ms = 20;
			}
			else{
				ms = stoi(maxspeed);
			}
			this->roads[i-1]->setInfo(name,bd,ms);
			if(bd){
				r = new Road(this->roads[i-1]->dest,this->roads[i-1]->src);
				r->setInfo(name,bd,ms);
				this->nodes[this->roads[i-1]->dest->index]->addRoad(r);
				this->roads.push_back(r);
			}

		}
		file.close();
	}
	else{
		cout << "Error opening the roads file" << endl;
	}
}

/**
 * @brief      { function_description }
 */
void Map::read(){
	read_mperp();
	read_nodes();
	read_subroads();
	read_roads();
}


/**
 * @brief      Draws a map.
 */
void Map::draw_map(){
	for(auto it : this->nodes){
		gv->addNode(it->index, (it->x*x_pix)-WIDTHSCREEN, (it->y*y_pix)-HEIGHTSCREEN);
		//gv->setVertexIcon(it->index,"res/icon.gif");
		gv->setVertexSize(it->index,10);

	}
	gv->rearrange();


	for(unsigned int i = 0; i < this->roads.size();i++){
		gv->addEdge(i,this->roads.at(i)->src->index,this->roads.at(i)->dest->index,EdgeType::DIRECTED);
		stringstream temp;
		temp << i;
		gv->setEdgeLabel(i, temp.str());
		gv->setEdgeThickness(i,1);
	}
	gv->rearrange();
}


//Novos metodos a implementar

/**
 * @brief      { function_description }
 *
 * @param[in]  index  The index
 *
 * @return     { description_of_the_return_value }
 */
Node* Map::findNode(const unsigned int index) const {
	if(index >= this->nodes.size()){
		return NULL;
	}
	return this->nodes.at(index);
}

/**
 * @brief      { function_description }
 *
 * @param[in]  origin  The origin
 */
void Map::dijkstraShortestPath_modified(const unsigned int origin){
	Node * v1 = this->findNode(origin);
	double oldDist;
	//Initializing
	for(auto it: this->nodes){
		it->dist = INF;
		it->path = NULL;
		it->queueIndex = 0;
	}
	v1->dist = 0;
	MutablePriorityQueue q;
	q.insert(v1);
	//Loop until q is empty
	while(!q.empty()){
		v1 = q.extractMin();
		for(auto it: v1->roads){
			if(it->accessable){ //"accessable" determines if a road can be used. Will be false in case of acident or if it's full
				oldDist = it->dest->dist;
				if(it->dest->dist > v1->dist + it->weight){
					it->dest->dist = v1->dist + it->weight;
					it->dest->path = v1;
					if(oldDist == INF){
						q.insert(it->dest);
					}
					else{
						q.decreaseKey(it->dest);
					}
				}
			}
		}
	}
}


/**
 * @brief      Gets the path.
 *
 * @param[in]  origin  The origin
 * @param[in]  dest    The destination
 *
 * @return     The path.
 */
vector<unsigned int> Map::getPath(const unsigned int origin, const unsigned int dest) const{

	vector<unsigned int> temp;
	Node * v1 = this->findNode(dest);
	Node * last = v1->path;

	if(last == NULL){
		if(origin == dest){
			cout << "The origin and destination introduced are the same node.\n";
		}
		else{
			cout << "There is no paths available from node " << origin << " to node " << dest << endl;
		}
	}

	while(last != NULL){
		temp.push_back(last->index);
		last = last->path;
	}

	vector<unsigned int> res;

	for(int i = temp.size()-1; i >= 0; i--){
		res.push_back(temp.at(i));
	}
	res.push_back(dest);

	return res;

}

/**
 * @brief      Gets the path secure.
 *
 * @param[in]  origin  The origin
 * @param[in]  dest    The destination
 *
 * @return     The path secure.
 */
vector<unsigned int> Map::getPath_secure(const unsigned int origin, const unsigned int dest) const{

	vector<unsigned int> temp;
	Node * v1 = this->findNode(dest);
	Node * last = v1->path;

	while(last != NULL){
		temp.push_back(last->index);
		last = last->path;
	}

	vector<unsigned int> res;

	for(int i = temp.size()-1; i >= 0; i--){
		res.push_back(temp.at(i));
	}
	res.push_back(dest);

	return res;

}


/**
 * @brief      Sets the access road.
 *
 * @param[in]  index  The index
 * @param[in]  value  The value
 */
void Map::setAccessRoad(unsigned int index, bool value){
	this->roads.at(index)->setAccess(value);
}


/**
 * @brief      { function_description }
 */
void Map::printRoads(){
	for(auto it : this->roads){
		cout << it->src->index << " " << it->dest->index << endl;
	}
}

/**
 * @brief      Gets the road between nodes.
 *
 * @param[in]  origin  The origin
 * @param[in]  dest    The destination
 *
 * @return     The road between nodes.
 */
Road * Map::getRoadBetweenNodes(unsigned int origin, unsigned int dest){
	Node * n = findNode(origin);
	for(auto it: n->getRoads()){
		if(it->dest->index == dest){
			return it;
		}
	}
	return NULL;
}

// TODO Corrigir roads para nodes
//
// @param[in]  v1    The v 1
//
// @return     { description_of_the_return_value }
//
bool Map::incrementCounter(vector<unsigned int> v1){
	bool recalculate = false;
	unsigned int index_ori, index_dest;
	for(unsigned int i = 0; i < v1.size() - 1; i++){
		index_ori = v1.at(i);
		index_dest = v1.at(i+1);
		Road * r = this->getRoadBetweenNodes(index_ori, index_dest);
		if(r == NULL){
			cout << "\nError! Road non-existent!\n";
			return false;
		}
		r->car_count++;

		//se +90% de capacidade nesta road
		if((r->car_count) > (r->limit) * 0.9){
			recalculate = true;
			r->accessable = false;
		}

	}

	return recalculate;
}

/**
 * @brief      { function_description }
 *
 * @param[in]  v1    The v 1
 */
void Map::listLimitofPath(vector<unsigned int> v1){
	unsigned int index_ori, index_dest;
	Road * r = new Road();
	cout << "\nLimits: \n";
	for(unsigned int i = 0; i < v1.size() - 2; i++){
		index_ori = v1.at(i);
		index_dest = v1.at(i+1);
		r = this->getRoadBetweenNodes(index_ori, index_dest);
		cout << index_ori << ": " << r->limit << "  ->  ";
	}
	index_ori = v1.at(v1.size() - 2);
	index_dest = v1.at(v1.size() - 1);
	r = this->getRoadBetweenNodes(index_ori, index_dest);

	cout << v1.at(v1.size() - 1) << ": " << r->limit << endl;
}


/**
 * @brief      { function_description }
 *
 * @param[in]  path  The path
 */
void Map::paint_path(vector<unsigned int> path) {
	for(unsigned int i = 0; i < path.size(); i++) {
		//gv->setEdgeThickness(path.at(i), 2);
		gv->setVertexColor(path.at(i), "YELLOW");
	}
// Se sempre quiserm um icone para diferencer o inicio do fim, fica só a faltar um parametrozito
//	gv->setVertexIcon(path.at(0),)
	gv->rearrange();
}


/**
 * @brief      { function_description }
 *
 * @param[in]  v1    The v 1
 */
double Map::timeOfTravel(vector<unsigned int> v1){
	unsigned int index_ori, index_dest;
	double total = 0;
	Road * r = new Road();
	for(unsigned int i = 0; i < v1.size() - 1; i++){
		index_ori = v1.at(i);
		index_dest = v1.at(i+1);
		r = this->getRoadBetweenNodes(index_ori, index_dest);
		total += r->weight;
	}
	return total;
}