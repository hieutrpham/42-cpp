#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
	Brain* brain;
public:
	Dog();
	~Dog();
	Dog& operator=(Dog& other);
	Dog(const Dog& other);
	void makeSound() const override;
	Brain *getBrain();
};
