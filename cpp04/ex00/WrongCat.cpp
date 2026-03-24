#include "WrongAnimal.hpp"
#include <iostream>
#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat type";
	std::cout << "WrongCat constructed\n";
}
WrongCat::~WrongCat(){
	std::cout << "WrongCat destructed\n";
}
WrongCat& WrongCat::operator=(WrongCat& other){
	if (this != &other) {
		WrongCat::operator=(other);
	}
	return *this;
}
WrongCat::WrongCat(WrongCat& other): WrongAnimal(other){
	std::cout << "wrong cat copy constructor\n";
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound\n";
}
