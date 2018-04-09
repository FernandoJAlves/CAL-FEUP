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
#define SCALE 3

double x_pix, y_pix;

using namespace std;

Map::Map(){
	gv = new GraphViewer(WIDTH, HEIGHT, false);
	gv->setBackground(MAP_PATH);
	this->read();

}

void Map::createWindow(){
	gv->createWindow(WIDTH, HEIGHT);
	gv->defineVertexColor("blue");
	gv->defineEdgeColor("black");
	//TODO this->draw_map();
}

void Map::closeWindow(){
	gv->closeWindow();
}

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

void Map::read(){
	read_mperp();
	read_nodes();
	read_subroads();
	read_roads();
}


void Map::draw_map(){
	for(auto it : this->nodes){
		gv->addNode(it->index, (it->x*x_pix)-WIDTH, (it->y*y_pix));
		//gv->setVertexIcon(it->index,"res/icon.gif");
		gv->setVertexSize(it->index,10);

	}
	gv->rearrange();


	for(unsigned int i = 0; i < this->roads.size();i++){
		gv->addEdge(i,this->roads.at(i)->src->index,this->roads.at(i)->dest->index,EdgeType::DIRECTED);
		stringstream temp;
		temp << i;
		gv->setEdgeLabel(i, temp.str());
	}
	gv->rearrange();
}


//Novos metodos a implementar

Node* Map::findNode(const unsigned int index) const {
	if(index >= this->nodes.size()){
		return NULL;
	}
	return this->nodes.at(index);
}

void Map::dijkstraShortestPath_modified(const unsigned int origin){

	Node * v1 = this->findNode(origin);
	double oldDist;

	for(auto it: this->nodes){
		it->dist = INF;
		it->path = NULL;
		it->queueIndex = 0;
	}

	v1->dist = 0;

	MutablePriorityQueue q;

	q.insert(v1);

	while(!q.empty()){
		v1 = q.extractMin();

		for(auto it: v1->roads){

			if(it->accessable){

				oldDist = it->dest->dist;
				if(it->dest->dist > v1->dist + it->dist_weight){

					it->dest->dist = v1->dist + it->dist_weight;
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


void Map::setAccessRoad(unsigned int index, bool value){
	this->roads.at(index)->setAccess(value);
}


void Map::printRoads(){
	for(auto it : this->roads){
		cout << it->src->index << " " << it->dest->index << endl;
	}
}


bool Map::incrementCounter(vector<unsigned int> v1){
	bool recalculate = false;
	unsigned int index;
	for(unsigned int i = 0; i < v1.size(); i++){
		index = v1.at(i);
		this->roads.at(index)->car_count++;

		//se +90% de capacidade nesta road
		if((this->roads.at(index)->car_count) > (this->roads.at(index)->limit) * 0.9){
			recalculate = true;
			this->setAccessRoad(index, false);
		}
	}

	return recalculate;
}

void Map::paint_path(vector<unsigned int> path) {
	for(unsigned int i = 0; i < path.size() - 1; i++) {
		gv->setEdgeThickness(path.at(i), 2);
		gv->setEdgeColor(path.at(i), "YELLOW");
	}
// Se sempre quiserm um icone para diferencer o inicio do fim, fica só a faltar um parametrozito
//	gv->setVertexIcon(path.at(0),)
	gv->rearrange();
}
