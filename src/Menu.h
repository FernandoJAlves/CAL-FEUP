#ifndef MENU_H_
#define MENU_H_

#include "Map.h"
#include <vector>


#if __linux__
#define clearScreen() system("clear")
#else
#define clearScreen() system("cls")
#endif


#define CARS_TEST     	 50

#define MAX_STR_COMP	 5



/**
 * @brief      Class for menu.
 */
class Menu{
	private:
	Map m;

public:
	bool terminate = false;

	/**
	 * @brief      Menu Constructor.
	 */
	Menu();

	/**
	 * @brief      Initial Options Menu
	 */
	void initialOptions();

	/**
	 * @brief      Calculates the paths with multiple cars, using exact and aproximate string comparation
	 */
	void calculatePaths_cars();


	/**
	 * @brief      Calculates the paths for a single car.
	 */
	void calculatePaths();









};

#endif
