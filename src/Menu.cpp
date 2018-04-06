#include "Menu.h"
#include "Car.h"
#include <iostream>
#include <cmath>

Menu::Menu(){}

void Menu::initialOptions(){
	clearScreen();
	cout << endl;
	cout << "+--------------------------------+" << endl;
	cout << "|      Initial Options Menu      |" << endl;
	cout << "|                                |" << endl;
	cout << "|     1 - Start Simulation       |" << endl;
	cout << "|     2 - Exit                   |" << endl;
	cout << "|                                |" << endl;
	cout << "+--------------------------------+" << endl;
	
	int opcao;

	cout << "Your option: ";
	cin >> opcao;

	switch(opcao){
		case 1:
			this->calculatePaths();
			break;
		case 2:
			this->terminate = true;
			cout << "The program will terminate. Thank you for choosing our service" << endl;
			cin.get();
			break;
		default:
			cout << "Invalid input!\n";
			cin.get();
	}



}


void Menu::calculatePaths(){

//Pseudo Codigo do algoritmo

	//Pedir ao user o node atual e o node de destino

	//Calcular o melhor trajeto para lá chegar

	//Modificar o graphViewer para mostrar esse path

	//Pedir ao user uma edge nesse path para "simular" um acidente que impede a passagem nessa edge

	//Gerar um vetor/array de Cars, e percorre-lo, e definir o path de cada carro como o path percorrido
		//No final de cada iteração, testar os edges do path, se algum deles estiver a 90% de capacidade, por o seu valor de acessable a false e recalcular um path

	//Quando terminarem os Cars, mostrar o output de alguma forma


	m.createWindow();

/* //TESTING
	for(auto it : m.roads){
		cout << it->limit << endl;
	}
*/

	unsigned int origin, dest;

	cout << "Index of the current node: ";
	cin >> origin;


	cout << "Index of the destination node: ";
	cin >> dest;

	
	m.dijkstraShortestPath_modified(origin);
	vector<unsigned int> v1 = m.getPath(origin, dest);

	if(v1.size() > 1){
		for(unsigned int i = 0; i < v1.size()-1; i++){
			cout << v1.at(i) << " -> ";
		}
		cout << v1.at(v1.size()-1);
	}
	else{
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}


	//TODO Gonçalo -> Chama aqui a função de pintar o percurso. Os indices dos nodes
	//				  são os elementos do vetor v1 (acho que basta os nodes, no mapa
	//				  quase nem se vê as arestas por estarem muito perto os nodes)


	unsigned int acidente;
	cout << "\nIndique a aresta onde se localiza o acidente: ";
	cin >> acidente;

	if(acidente < m.roads.size()){
		m.setAccessRoad(acidente, false);
	}
	else{
		cout << "Invalid input!\n";
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}

	// Temporary - Shows 1st recalculation only

	cout << "\n\nRecalculating...\n\nNew path: ";

	m.dijkstraShortestPath_modified(origin);
	vector<unsigned int> v2 = m.getPath(origin, dest);

	if(v2.size() > 1){
		for(unsigned int i = 0; i < v2.size()-1; i++){
			cout << v2.at(i) << " -> ";
		}
		cout << v2.at(v2.size()-1);

	}
	cout << endl << "Press Enter to return" << endl;


/*

	//Acho que isto está bem, mas tenho de corrigir os inputs para testar

	vector<Car*> cars_vector(ARRAY_CAR); //array de 5000 cars para demostrar o redirecionamento


	bool recalc = true;
	int option = 0;

	vector<unsigned int> path_v;

	for(unsigned int i = 0; i < ARRAY_CAR; i++){

		if(recalc){
			m.dijkstraShortestPath_modified(origin);
			path_v = m.getPath_secure(origin, dest);
			option++;
		}

		cars_vector[i] = new Car(path_v,option);
		recalc = m.incrementCounter(path_v);

	}


	//Output

	cout << "\n\nResults testing with " << ARRAY_CAR << " cars: \n";

	int lastIndex = cars_vector[0]->option;
	int car_int_lower = 0;

	for(int i = 0; i < ARRAY_CAR; i++){

		cout << cars_vector[i]->option << endl;

		///if(lastIndex != cars_vector[i]->option){
			cout << "\n- Option " << cars_vector[i]->option << ": Cars " << car_int_lower << "-" << i-1 << endl;
			car_int_lower = i;
			lastIndex = cars_vector[i]->option;
		}

	}

*/
	cin.get();
	m.closeWindow();
	
}

