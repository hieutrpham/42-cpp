#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap constructed\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap name constructed\n";
	this->hp = 100;
	this->ep = 50;
	this->dmg = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name <<  " destroyed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Scavtrap copy constructor\n";
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Scavtrap assignment constructor\n";
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {
	if (this->hp <= 0 || this->ep <= 0) {
		std::cout << "nah\n";
		return;
	}
	std::cout << this->name << " is in gatekeeper mode\n";
}

void ScavTrap::attack(const std::string& other) {
	if (this->hp <= 0 || this->ep <= 0) {
		std::cout << "nah\n";
		return;
	}
	std::cout << this->name << " attacks " << other << ", causing " << this->dmg << " points of damage!" << std::endl;
	this->ep--;
}
