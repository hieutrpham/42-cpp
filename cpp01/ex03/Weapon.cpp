#include "Weapon.hpp"
#include <iostream>

const std::string& Weapon::getType() const {
	return this->type;
}

void Weapon::setType(std::string type) {
	this->type = type;
}

Weapon::Weapon(std::string w) {
	this->setType(w);
}

Weapon::Weapon() {}
Weapon::~Weapon() {}
