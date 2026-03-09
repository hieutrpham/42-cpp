#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap c;
	ClapTrap a(c);
	ClapTrap b("test");
	b.attack("hie");
	b.takeDamage(9);
}
