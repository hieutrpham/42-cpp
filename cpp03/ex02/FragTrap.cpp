#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() {
	std::cout << "FragTrap constructed\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap name constructed\n";
	this->dmg = 100;
	this->ep = 100;
	this->dmg = 30;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name <<  " destroyed\n";
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Fragtrap copy constructor\n";
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "Fragtrap assignment constructor\n";
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void FragTrap::highFivesGuys(void) {
	if (this->hp <= 0 || this->ep <= 0) {
		std::cout << "nah\n";
		return;
	}
	std::cout << this->name << " high five\n";
}
