#pragma once
#include <string>
#define IDEAS_CAP 100

class Brain {
private:
	std::string ideas[100];
public:
	Brain();
	~Brain();
	Brain& operator=(Brain& other);
	Brain(Brain& other);
};
