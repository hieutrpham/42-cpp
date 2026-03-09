#include "ClapTrap.hpp"
#include <iostream>
#include <ostream>

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructed\n";
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap default destructed\n";
}

ClapTrap::ClapTrap(std::string name) : name(name) {
	std::cout << "Claptrap name constructed\n";
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	std::cout << "Claptrap copy constructor\n";
	this->name = other.name;
	this->hp = other.hp;
	this->ep = other.ep;
	this->dmg = other.dmg;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Claptrap assignment constructor\n";
	if (this != &other) {
		this->name = other.name;
		this->hp = other.hp;
		this->ep = other.ep;
		this->dmg = other.dmg;
	}
	return *this;
}

void ClapTrap::attack(const std::string& target) {
	if (this->hp <= 0 || this->ep <= 0)
		return;
	std::cout << this->name << " attacks " << target << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->ep--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (this->hp <= 0)
		return;
	std::cout << this->name << " takes " << amount << " points of damage!" << std::endl;
	this->hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (this->hp <= 0 || this->ep <= 0)
		return;
	std::cout << this->name << " repairs " << amount << " points of hp!" << std::endl;
	this->ep--;
	this->hp += amount;
}
