#pragma once
#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog& operator=(Dog& other);
	Dog(Dog& other);
	void makeSound() const override;
	std::string getType();
};
