#pragma once
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
	Brain* brain;
public:
	Cat();
	~Cat();
	Cat& operator=(const Cat& other);
	Cat(const Cat& other);
	void makeSound() const override;
};
