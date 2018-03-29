#ifndef CAR_H_
#define CAR_H_

#include <vector>


class Car{
private:
	std::vector<int> path_Index;
public:
	Car();
	void add_Index(int i){
		this.path_Index.push_back(i);
	}


	
};

#endif