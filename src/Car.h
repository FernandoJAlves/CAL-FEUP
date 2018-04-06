#ifndef CAR_H_
#define CAR_H_

#include <vector>


class Car{
private:
	int option = 0;
	std::vector<unsigned int> path_Index;
public:
	Car();
	Car(std::vector<unsigned int> v, int option){
		this->path_Index = v;
		this->option = option;
	}

	/*
	void add_Index(int i){
		this->path_Index.push_back(i);
	}
	void set_Path(std::vector<unsigned int> v){
		this->path_Index = v;
	}
	*/

	friend class Menu;
};

#endif