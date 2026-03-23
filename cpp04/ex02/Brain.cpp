#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout<< "Brain constructed\n";
	for (int i = 0; i < IDEAS_CAP; ++i) {
		this->ideas[i] = "bad idea";
	}
}
Brain::~Brain() {
	std::cout<< "Brain destructed\n";
}

Brain& Brain::operator=(Brain& other) {
	if (this != &other) {
		for (int i = 0; i < IDEAS_CAP; ++i) {
			this->ideas[i] = other.ideas[i];
		}
	}
	return *this;
}

Brain::Brain(Brain& other) {
	std::cout << "brain copy constructor\n";
	for (int i = 0; i < IDEAS_CAP; ++i) {
		this->ideas[i] = other.ideas[i];
	}
}

std::string* Brain::getIdeas() {
	return this->ideas;
}
