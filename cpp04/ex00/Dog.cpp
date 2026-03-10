#include "Animal.hpp"
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
		this->type = other.type;
	}
	return *this;
}
Dog::Dog(Dog& other): Animal(other){
	this->type = other.type;
}

void Dog::makeSound() const {
	std::cout << "Dog sound\n";
}
