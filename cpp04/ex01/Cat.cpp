#include "Animal.hpp"
#include "Cat.hpp"

Cat::Cat(){
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
		this->type = other.type;
		for (int i = 0; i < IDEAS_CAP; ++i){
			this->brain[i] = other.brain[i];
		}
	}
	return *this;
}
Cat::Cat(Cat& other): Animal(other){
	this->type = other.type;
	for (int i = 0; i < IDEAS_CAP; ++i){
		this->brain[i] = other.brain[i];
	}
}

void Cat::makeSound() const {
	std::cout << "Cat sound\n";
}
