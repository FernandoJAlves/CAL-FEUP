#include "Menu.h"
#include <iostream>
#include <cmath>

void Menu::calculatePaths(){

//Pseudo Codigo do algoritmo

	//Pedir ao user o node atual e o node de destino

	//Calcular o melhor trajeto para lá chegar

	//Modificar o graphViewer para mostrar esse path

	//Pedir ao user uma edge nesse path para "simular" um acidente que impede a passagem nessa edge

	//Gerar um vetor/array de Cars, e percorre-lo, e definir o path de cada carro como o path percorrido
		//No final de cada iteração, testar os edges do path, se algum deles estiver a 90% de capacidade, por o seu valor de acessable a false e recalcular um path

	//Quando terminarem os Cars, mostrar o output de alguma forma




	Map m;

	unsigned int origin, dest;

	cout << "Indique o nó atual: ";
	cin >> origin;


	cout << "Indique o nó destino: ";
	cin >> dest;

	
	m.dijkstraShortestPath_modified(origin);
	vector<unsigned int> v1 = m.getPath(origin, dest);

	if(v1.size() > 1){
		for(unsigned int i = 0; i < v1.size()-1; i++){
			cout << v1.at(i) << " -> ";
		}
		cout << v1.at(v1.size()-1);
	}



	this->terminate = true;

	
}

