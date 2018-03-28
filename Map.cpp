#include "Map.h"

#include <fstream>
#include <iostream>
#include <sstream>

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
			nodes.push_back(new Node(x,y));
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
			this->nodes[src-1]->addRoad(*r);
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