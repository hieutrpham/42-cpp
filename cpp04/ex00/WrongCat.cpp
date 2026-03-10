#include "WrongAnimal.hpp"
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
		this->type = other.type;
	}
	return *this;
}
WrongCat::WrongCat(WrongCat& other): WrongAnimal(other){
	this->type = other.type;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat sound\n";
}
