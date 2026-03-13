#include "HumanA.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanA::~HumanA() {}
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) { }

void HumanA::attack() {
	std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}
