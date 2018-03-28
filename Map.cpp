#include "Map.h"

#include <fstream>
#include <iostream>
#include <sstream>


using namespace std;

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
	string line;
	if(file.is_open()){
		while(getline(file,line)){

		}
	}
	else{
		cout << "Error opening the subroads file" << endl;
	}
}

void Map::read_roads(){
	ifstream file(ROADS_PATH);
	string line;
	if(file.is_open()){
		while(getline(file,line)){
			
		}
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