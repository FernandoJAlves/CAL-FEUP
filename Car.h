#ifndef CAR_H_
#define CAR_H_

#include <vector>


class Car{
private:
	std::vector<unsigned int> path_Index;
public:
	Car();
	Car(std::vector<unsigned int> v){
		this.path_Index = v;
	}
	void add_Index(int i){
		this.path_Index.push_back(i);
	}
	void set_Path(std::vector<unsigned int> v){
		this.path_Index = v;
	}

	
};

#endif