#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() {
	std::cout << "default constructed\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "default destructed\n";
}

ClapTrap::ClapTrap(std::string name) : name(name) {
	std::cout << name << " constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "copy constructor\n";
	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->dmg = other.dmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "assignment constructor\n";
	if (this != &other) {
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->dmg = other.dmg;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hp <= 0 || this->ep <= 0) {
		std::cout << "nah\n";
		return;
	}
	std::cout << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->ep--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp <= 0) {
		std::cout << "dead\n";
		return;
	}
	std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp <= 0 || this->ep <= 0) {
		std::cout << "nah\n";
		return;
	}
	std::cout << this->name << " repairs " << amount << " points of hp!" << std::endl;
	this->ep--;
	this->hp += amount;
}
