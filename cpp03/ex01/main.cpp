#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	ClapTrap c;
	ClapTrap f;
	f = c;
	ClapTrap a(c);
	ClapTrap b("test");
	b.attack("hie");
	b.takeDamage(9);
	b.beRepaired(9);
	ScavTrap s("test");
	ScavTrap s1;
	s1 = s;
	s.guardGate();
	s.attack("hieu");
}
