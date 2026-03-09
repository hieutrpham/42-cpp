#include "FragTrap.hpp"
#include <iostream>

int main() {
	FragTrap c;
	FragTrap f;
	f = c;
	FragTrap a(c);
	FragTrap b("test");
	b.attack("hie");
	b.takeDamage(9);
	b.beRepaired(9);
	FragTrap s("test");
	FragTrap s1;
	s1 = s;
	s.attack("hieu");
	s.highFivesGuys();
}
