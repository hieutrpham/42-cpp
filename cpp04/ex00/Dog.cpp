#include "Animal.hpp"
#include <iostream>
#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->type = "dog type";
	std::cout << "dog constructed\n";
}
Dog::~Dog(){
	std::cout << "dog destructed\n";
}
Dog& Dog::operator=(Dog& other){
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}
Dog::Dog(Dog& other): Animal(other){
	std::cout << "dog copy constructor\n";
}

void Dog::makeSound() const {
	std::cout << "Dog sound\n";
}
