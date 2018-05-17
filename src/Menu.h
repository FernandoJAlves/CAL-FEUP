#ifndef MENU_H_
#define MENU_H_

#include "Map.h"
#include <vector>


#if __linux__
#define clearScreen() system("clear")
#else
#define clearScreen() system("cls")
#endif


#define START_TEST1    1537
#define END_TEST1      225
#define CARS_TEST1     50

#define START_TEST2    24
#define END_TEST2      3159
#define CARS_TEST2     50

#define START_TEST3    103
#define END_TEST3      1132
#define CARS_TEST3     1000

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
