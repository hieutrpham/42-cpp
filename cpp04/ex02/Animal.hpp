#pragma once
#include <string>
#include <iostream>

class Animal {
protected:
	std::string type;
	Animal();
public:
	virtual ~Animal();
	Animal& operator=(Animal& other);
	Animal(const Animal& other);
	virtual void makeSound() const = 0;
	std::string getType() const;
};
