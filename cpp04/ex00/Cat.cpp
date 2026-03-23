#include "Animal.hpp"
#include <iostream>
#include "Cat.hpp"

Cat::Cat() : Animal() {
	this->type = "cat type";
	std::cout << "cat constructed\n";
}
Cat::~Cat(){
	std::cout << "cat destructed\n";
}
Cat& Cat::operator=(Cat& other){
	if (this != &other) {
		Animal::operator=(other);
	}
	return *this;
}
Cat::Cat(Cat& other): Animal(other){
	std::cout << "cat copy constructor\n";
}

void Cat::makeSound() const {
	std::cout << "Cat sound\n";
}
