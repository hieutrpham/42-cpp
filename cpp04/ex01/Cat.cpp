#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>
#include "Cat.hpp"

Cat::Cat(): Animal() {
	this->brain = new Brain();
	this->type = "cat type";
	std::cout << "cat constructed\n";
}
Cat::~Cat(){
	delete this->brain;
	std::cout << "cat destructed\n";
}
Cat& Cat::operator=(Cat& other){
	if (this != &other) {
		Animal::operator=(other);
		this->brain = new Brain(*other.brain);
		delete this->brain;
	}
	return *this;
}
Cat::Cat(const Cat& other): Animal(other){
	std::cout << "cat copy constructor\n";
	this->brain = new Brain(*other.brain);
}

void Cat::makeSound() const {
	std::cout << "Cat sound\n";
}

Brain *Cat::getBrain() {
	return this->brain;
}
