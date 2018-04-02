#ifndef MENU_H_
#define MENU_H_

#include "Map.h"
#include <vector>

#define ARRAY_CAR	5000

class Menu{
	private:
	Map m;

public:
	bool terminate = false;
	Menu();

	void initialOptions();
	void calculatePaths();








	
};

#endif