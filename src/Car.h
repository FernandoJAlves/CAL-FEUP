#ifndef CAR_H_
#define CAR_H_

#include <vector>


/**
 * @brief      Class for car.
 */
class Car{
private:
	unsigned int start;
	unsigned int dest;

	std::vector<unsigned int> init_path;
	//std::vector<unsigned int> new_path;

public:

	/**
	 * @brief      Car Constructor.
	 */
	Car();

	/**
	 * @brief      Car Constructor with parameters.
	 */
	Car(unsigned int index1, unsigned int index2){
		this->start = index1;
		this->dest = index2;
	}
	
	friend class Menu;
};

#endif
