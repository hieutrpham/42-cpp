#include "Animal.hpp"
#include "Brain.hpp"
#include "Dog.hpp"

Dog::Dog() : Animal(){
	this->brain = new Brain();
	this->type = "dog type";
	std::cout << "dog constructed\n";
}
Dog::~Dog(){
	delete this->brain;
	std::cout << "dog destructed\n";
}
Dog& Dog::operator=(Dog& other){
	if (this != &other) {
		this->type = other.type;
		for (int i = 0; i < IDEAS_CAP; ++i){
			this->brain[i] = other.brain[i];
		}
	}
	return *this;
}
Dog::Dog(Dog& other): Animal(other){
	this->type = other.type;
	for (int i = 0; i < IDEAS_CAP; ++i){
		this->brain[i] = other.brain[i];
	}
}

void Dog::makeSound() const {
	std::cout << "Dog sound\n";
}
