#pragma once
#include <string>
#define IDEAS_CAP 100

class Brain {
private:
	std::string ideas[IDEAS_CAP];
public:
	Brain();
	~Brain();
	Brain& operator=(Brain& other);
	Brain(Brain& other);
	std::string *getIdeas();
};
