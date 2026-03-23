#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("animal type"){
	std::cout << "animal constructed\n";
}
Animal::~Animal(){
	std::cout << "animal destructed\n";
}
Animal& Animal::operator=(Animal& other){
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
Animal::Animal(const Animal& other) : type(other.type){
	std::cout << "animal copy constructor\n";
}

void Animal::makeSound() const {
	std::cout << "Animal sound\n";
}

std::string Animal::getType() const {
	return this->type;
}
