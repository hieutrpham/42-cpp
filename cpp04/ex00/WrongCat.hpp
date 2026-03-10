#pragma once
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat& operator=(WrongCat& other);
	WrongCat(WrongCat& other);
	void makeSound() const override;
};
