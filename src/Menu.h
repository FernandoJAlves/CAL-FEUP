#ifndef MENU_H_
#define MENU_H_

#include "Map.h"
#include <vector>

#define ARRAY_CAR	5000

#if __linux__
#define clearScreen() system("clear")
#else
#define clearScreen() system("cls")
#endif

/**
 * @brief      Class for menu.
 */
class Menu{
	private:
	Map m;

public:
	bool terminate = false;
	Menu();

	void initialOptions();
	void calculatePaths_cars();
	void calculatePaths();








	
};

#endif