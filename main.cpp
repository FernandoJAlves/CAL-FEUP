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

	return 0;
}
