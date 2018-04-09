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

	std::vector<unsigned int> index_path;
	std::vector<unsigned int> old_path;
	
public:


	Car();
	Car(unsigned int index1, unsigned int index2){
		this->start = index1;
		this->dest = index2;
	}


	friend class Menu;
};

#endif