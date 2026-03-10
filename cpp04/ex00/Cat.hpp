#pragma once
#include "Animal.hpp"

class Cat : public Animal {
public:
	Cat();
	~Cat();
	Cat& operator=(Cat& other);
	Cat(Cat& other);
	void makeSound() const override;
};
