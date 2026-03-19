#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap c;
	ClapTrap a(c);
	ClapTrap b("test");
	b.attack("hie");
	b.takeDamage(9);
	b.beRepaired(9);

	ClapTrap A("Hive");
	ClapTrap B(A);
	ClapTrap C("Byyyy");
	C = A;
	
	A.attack("CPP");
	A.takeDamage(5);
	A.beRepaired(9);

	B.attack("Helsin");
	B.takeDamage(20);
	B.beRepaired(9);
	B.attack("Aarg");
	B.takeDamage(10);
}
