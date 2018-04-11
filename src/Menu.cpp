#include "Menu.h"
#include "Car.h"
#include <iostream>
#include <chrono>
#include <cmath>


Menu::Menu(){}

void Menu::initialOptions(){
	clearScreen();
	cout << endl;
	cout << "+---------------------------------------------+" << endl;
	cout << "|            Initial Options Menu             |" << endl;
	cout << "|                                             |" << endl;
	cout << "|     1 - Start Simulation (Single Car)       |" << endl;
	cout << "|     2 - Start Simulation (Multiple Cars)    |" << endl;
	cout << "|     3 - Exit                                |" << endl;
	cout << "|                                             |" << endl;
	cout << "+---------------------------------------------+" << endl;

	int opcao;

	cout << "Your option: ";
	cin >> opcao;

	switch(opcao){
		case 1:
			this->calculatePaths();
			break;
		case 2:
			this->calculatePaths_cars();
			break;
		case 3:
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

//Single car, single accident
//Pseudo Codigo do algoritmo

	//(Explicado na função seguinte)

	m.createWindow();


	unsigned int origin, dest;
	cout << "Index of the current node: ";
	cin >> origin;
	cout << "Index of the destination node: ";
	cin >> dest;

	m.dijkstraShortestPath_modified(origin, dest);
	vector<unsigned int> v1 = m.getPath(origin, dest);

	cout << "\n\nPath: \n";
	if(v1.size() > 1){
		for(unsigned int i = 0; i < v1.size()-1; i++){
			cout << v1.at(i) << " -> ";
		}
		cout << v1.at(v1.size()-1);
		m.paint_path(v1, "YELLOW");
		cout << "\nTime of travel: " << m.timeOfTravel(v1) << endl;
	}
	else{
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}


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

	cout << "\n\nRecalculating...\n\nNew path: \n";

	m.dijkstraShortestPath_modified(origin, dest);
	vector<unsigned int> v2 = m.getPath(origin, dest);

	if(v2.size() > 1){
		for(unsigned int i = 0; i < v2.size()-1; i++){
			cout << v2.at(i) << " -> ";
		}
		cout << v2.at(v2.size()-1);
		m.paint_path(v2, "RED");
		cout << "\nTime of travel: " << m.timeOfTravel(v2) << endl;
	}
	else{
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}

	cout << endl << "Press Enter to return" << endl;
	cin.get();
	cin.get();
	m.closeWindow();
}

void Menu::calculatePaths_cars(){
	//auto start = std::chrono::high_resolution_clock::now();

//Multiple cars, single accident

//Pseudo Codigo do algoritmo

	//Pedir ao user um trajeto (origem e destino)

	//Calcular o melhor trajeto para lá chegar

	//Modificar o graphViewer para mostrar esse path

	//Mostrar recalculamento com vários cars + redirecionamento

	//Pedir ao user uma edge nesse path para "simular" um acidente que impede a passagem nessa edge

	//Calcular o "novo" melhor trajeto para chegar ao destino

	//Modificar o graphViewer para mostrar também esse novo path

	//Gerar um vetor/array de Cars, e percorre-lo, e definir o path de cada carro como o path percorrido
		//No final de cada iteração, testar os edges do path, se algum deles estiver a 90% de capacidade, por o seu valor de acessable a false e recalcular os paths

	//Quando terminarem os Cars, mostrar o output


	m.createWindow();

	unsigned int start_test, end_test;
	int car_amount;

	cout << endl;
	cout << "+--------------------------------------------------------+" << endl;
	cout << "|                  Select an Example:                    |" << endl;
	cout << "|                                                        |" << endl;
	cout << "|   1 - Example 1 (Palacio Cristal -> Cedofeita)         |" << endl;
	cout << "|   2 - Example 2 (Praca da Rep. -> Rot. da Boavista)    |" << endl;
	cout << "|   3 - Example 3 (Alfandega -> Gaia)                    |" << endl;
	cout << "|   0 - Exit                                             |" << endl;
	cout << "|                                                        |" << endl;
	cout << "+--------------------------------------------------------+" << endl;

	int opcao;

	cout << "Your option: ";
	cin >> opcao;

	switch(opcao){
		case 1:
			start_test = START_TEST1;
			end_test = END_TEST1;
			car_amount = CARS_TEST1;
			break;
		case 2:
			start_test = START_TEST2;
			end_test = END_TEST2;
			car_amount = CARS_TEST2;
			break;
		case 3:
			start_test = START_TEST3;
			end_test = END_TEST3;
			car_amount = CARS_TEST3;
			break;
		case 0:
			m.closeWindow();
			return;
		default:
			cout << "Invalid input!\nReturning to the main menu\n";
			cin.get();
			cin.get();
			m.closeWindow();
			return;
	}


	m.dijkstraShortestPath_modified(start_test, end_test);
	vector<unsigned int> v1 = m.getPath(start_test, end_test);

	if(v1.size() > 1){
		cout << "\nIdeal Path: \n";
		for(unsigned int i = 0; i < v1.size()-1; i++){
			cout << v1.at(i) << " -> ";
		}
		cout << v1.at(v1.size()-1);

		//Já com o re-arrange
		m.paint_path(v1, "YELLOW");

		cout << "\nTime of travel: " << m.timeOfTravel(v1) << endl;
		cout << "\nPress Enter to calculate using multiple cars in circulation\n";
		cin.get();
		cin.get();
	}
	else{
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}



	//Loop com vários carros para testar o redirecionamento

	vector<Car*> cars_vector(car_amount);

	bool recalc = true;
	vector<unsigned int> path_v;

	for(int i = 0; i < car_amount; i++){
		Car * c = new Car(start_test, end_test);

		if(recalc){
			m.dijkstraShortestPath_modified(start_test, end_test);
			path_v = m.getPath_secure(start_test, end_test);
		}

		c->init_path = path_v;
		cars_vector[i] = c;
		recalc = m.incrementCounter(path_v);

	}


	//Output

	cout << "\n\nResults testing with " << car_amount << " cars: \n";

	vector<unsigned int> last_path = cars_vector[0]->init_path;
	int car_int_lower = 0;
	int option = 1;

	for(int i = 0; i < car_amount; i++){

		if(last_path != cars_vector[i]->init_path){
			cout << "\n- Option " << option << ": Cars " << car_int_lower << "-" << i-1 << endl;

			//Show the path
			if(last_path.size() > 1){
				for(unsigned int i = 0; i < last_path.size()-1; i++){
				cout << last_path.at(i) << " -> ";
				}
				cout << last_path.at(last_path.size()-1);

				cout << "\nTime of travel: " << m.timeOfTravel(last_path) << endl;
			}
			else{
				cout << "\nNo paths are available right now\n";
			}

			car_int_lower = i;
			last_path = cars_vector[i]->init_path;
			option++;
		}

		//Final iteration
		else if(i == car_amount-1){
			cout << "\n- Option " << option << ": Cars " << car_int_lower << "-" << i << endl;

			//Show the path
			if(last_path.size() > 1){
				for(unsigned int i = 0; i < last_path.size()-1; i++){
				cout << last_path.at(i) << " -> ";
				}
				cout << last_path.at(last_path.size()-1);

				cout << "\nTime of travel: " << m.timeOfTravel(last_path) << endl;
			}
			else{
				cout << "\nNo paths are available right now\n";
			}
		}
	}

	m.resetMapVars();

	unsigned int acidente;
	cout << "\nIndex of the edge where you want to simulate an accident: ";
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

	cout << "\n\nRecalculating...\n\n";

	m.dijkstraShortestPath_modified(start_test, end_test);
	vector<unsigned int> v2 = m.getPath(start_test, end_test);

	if(v2.size() > 1){
		if(v1 == v2){
			cout << "\nThe ideal path stayed the same\n";
			cin.get();
			cin.get();
		}
		else{
			cout << "\nNew path: \n";
			for(unsigned int i = 0; i < v2.size()-1; i++){
				cout << v2.at(i) << " -> ";
			}
			cout << v2.at(v2.size()-1);

			//Já com o re-arrange
			m.paint_path(v2, "RED");

			cout << "\nTime of travel: " << m.timeOfTravel(v2) << endl;
			cout << "\nPress Enter to calculate using multiple cars in circulation\n";
			cin.get();
			cin.get();
		}
	}
	else{
		cin.get();
		cin.get();
		m.closeWindow();
		return;
	}

	//Loop com vários carros para testar o redirecionamento

	vector<Car*> cars_vector2(car_amount);

	recalc = true;

	for(int i = 0; i < car_amount; i++){
		Car * c = new Car(start_test, end_test);

		if(recalc){
			m.dijkstraShortestPath_modified(start_test, end_test);
			path_v = m.getPath_secure(start_test, end_test);
		}

		c->init_path = path_v;
		cars_vector2[i] = c;
		recalc = m.incrementCounter(path_v);

	}


	//Output

	cout << "\n\nResults testing with " << car_amount << " cars: \n";

	last_path = cars_vector2[0]->init_path;
	car_int_lower = 0;
	option = 1;

	for(int i = 0; i < car_amount; i++){

		if(last_path != cars_vector2[i]->init_path){
			cout << "\n- Option " << option << ": Cars " << car_int_lower << "-" << i-1 << endl;

			//Show the path
			if(last_path.size() > 1){
				for(unsigned int i = 0; i < last_path.size()-1; i++){
				cout << last_path.at(i) << " -> ";
				}
				cout << last_path.at(last_path.size()-1);

				cout << "\nTime of travel: " << m.timeOfTravel(last_path) << endl;
			}
			else{
				cout << "\nNo paths are available right now\n";
			}

			car_int_lower = i;
			last_path = cars_vector2[i]->init_path;
			option++;
		}

		//Final iteration
		else if(i == car_amount-1){
			cout << "\n- Option " << option << ": Cars " << car_int_lower << "-" << i << endl;

			//Show the path
			if(last_path.size() > 1){
				for(unsigned int i = 0; i < last_path.size()-1; i++){
				cout << last_path.at(i) << " -> ";
				}
				cout << last_path.at(last_path.size()-1);

				cout << "\nTime of travel: " << m.timeOfTravel(last_path) << endl;
			}
			else{
				cout << "\nNo paths are available right now\n";
			}
		}
	}

	m.resetMapVars();
	//auto finish = std::chrono::high_resolution_clock::now();
	//auto mili = chrono::duration_cast<chrono::milliseconds>(finish - start).count();
	//cout << "\ngetPath_car took " << mili << " milliseconds\n";
	cout << endl << "\nPress Enter to return\n" << endl;
	cin.get();
	m.closeWindow();
}
