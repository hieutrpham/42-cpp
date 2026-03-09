#pragma once
#include "ClapTrap.hpp"

class ScavTrap : ClapTrap {
public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void guardGate();
	virtual void attack(const std::string &other);
};
