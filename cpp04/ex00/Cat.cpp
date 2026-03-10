#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(){
	this->type = "cat type";
	std::cout << "cat constructed\n";
}
Cat::~Cat(){
	std::cout << "cat destructed\n";
}
Cat& Cat::operator=(Cat& other){
	if (this != &other) {
		this->type = other.type;
	}
	return *this;
}
Cat::Cat(Cat& other): Animal(other){
	this->type = other.type;
}

void Cat::makeSound() const {
	std::cout << "Cat sound\n";
}
