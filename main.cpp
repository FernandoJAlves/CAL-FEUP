#include <iostream>
#include "Map.h"
#include "Menu.h"

using namespace std;

int main(){
	//Map map;

	Menu m1;
	
	while(!m1.terminate){
		m1.initialOptions();
	}

	cout << "\n-----/////-----\n";
	cout << "\nClose the GraphViewer window to terminate";

	cin.get();
	cin.get();
	cin.get();

	return 0;
}
