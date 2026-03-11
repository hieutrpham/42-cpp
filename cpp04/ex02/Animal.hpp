#pragma once
#include <string>
#include <iostream>

class Animal {
protected:
	std::string type;
public:
	Animal();
	virtual ~Animal();
	Animal& operator=(Animal& other);
	Animal(Animal& other);
	virtual void makeSound() const = 0;
	std::string getType() const;
};
