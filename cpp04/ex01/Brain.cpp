#include "Brain.hpp"
#include <iostream>

Brain::Brain() {
	std::cout<< "Brain constructed\n";
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
	for (int i = 0; i < IDEAS_CAP; ++i) {
		this->ideas[i] = other.ideas[i];
	}
}
