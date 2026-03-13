#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : name(name), weapon(nullptr) { }
HumanB::HumanB() {}
HumanB::~HumanB() {}
void HumanB::attack() {
	if (weapon != nullptr)
		std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w) {
	this->weapon = &w;
}
