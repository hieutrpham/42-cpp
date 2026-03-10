#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("animal type"){
	std::cout << "wrong animal constructed\n";
}
WrongAnimal::~WrongAnimal(){
	std::cout << "wrong animal destructed\n";
}
WrongAnimal& WrongAnimal::operator=(WrongAnimal& other){
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
WrongAnimal::WrongAnimal(WrongAnimal& other){
	this->type = other.type;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const {
	return this->type;
}
