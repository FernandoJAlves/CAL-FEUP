#include <iostream>
#include "Map.h"
#include "Menu.h"

using namespace std;

/**
 * @brief      { function_description }
 *
 * @return     { description_of_the_return_value }
 */
int main(){
	//Map map;

	Menu m1;
	
	while(!m1.terminate){
		m1.initialOptions();
	}

	return 0;
}
