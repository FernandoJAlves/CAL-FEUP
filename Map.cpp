#include "Map.h"

#include <fstream>
#include <iostream>
#include <sstream>

#include "MutablePriorityQueueNode.h"

#define NODES_PATH "porto_nodes.txt"
#define ROADS_PATH "porto_roads.txt"
#define SUBROADS_PATH "porto_subroads.txt"

using namespace std;

Map::Map(){
	gv = new GraphViewer(600, 600, true);
	gv->createWindow(600, 600);
	gv->defineEdgeColor("black");
	this->read();
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
			ss >> index >> comma >> src >> comma >> dest;
			ss.clear();
			r = new Road(nodes[src-1],nodes[dest-1]);
			this->nodes[src-1]->addRoad(r);
			this->roads.push_back(r);
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
			if(bidirectional == "TRUE"){
				bd = true;
			}
			else{
				bd = false;
			}
			if(maxspeed == "PT:urban\r"){
				ms = 50;
			}
			else if(maxspeed == "" || maxspeed == "\r"){
				ms = 20;
			}
			else{
				ms = stoi(maxspeed);
			}
			this->roads[i-1]->setInfo(name,bd,ms);
		}
		file.close();
	}
	else{
		cout << "Error opening the roads file" << endl;
	}
}

void Map::read(){
	read_nodes();
	read_subroads();
	read_roads();
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

