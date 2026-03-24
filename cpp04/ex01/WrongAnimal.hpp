#pragma once
#include <string>
#include <iostream>

class WrongAnimal {
protected:
	std::string type;
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal& operator=(WrongAnimal& other);
	WrongAnimal(WrongAnimal& other);
	void makeSound() const;
	std::string getType() const;
};
