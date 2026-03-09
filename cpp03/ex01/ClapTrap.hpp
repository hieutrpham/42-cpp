#pragma once
#include <string>

class ClapTrap {
protected:
	std::string name;
	int hp = 10;
	int ep = 10;
	int dmg = 0;

public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();
	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};
