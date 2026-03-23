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
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
		delete this->brain;
	}
	return *this;
}
Dog::Dog(Dog& other): Animal(other){
	std::cout << "dog copy constructor\n";
	this->type = other.type;
	this->brain = new Brain(*other.brain);
}

void Dog::makeSound() const {
	std::cout << "Dog sound\n";
}

Brain *Dog::getBrain() {
	return this->brain;
}
