#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() {
	std::cout << "ScavTrap constructed\n";
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	this->dmg = 100;
	this->ep = 50;
	this->dmg = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << this->name <<  " destroyed\n";
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

void ScavTrap::guardGate() {
	std::cout << this->name << " is in gatekeeper mode\n";
}
