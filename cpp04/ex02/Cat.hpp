#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* brain;
public:
	Cat();
	~Cat();
	Cat& operator=(Cat& other);
	Cat(Cat& other);
	void makeSound() const override;
};
