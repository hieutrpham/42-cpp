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
	ScavTrap D("Bocal");
	D.attack("Joensu");
	D.takeDamage(5);
	D.beRepaired(9);
	D.guardGate();
	ScavTrap E(D);
	E.takeDamage(200);
	E.beRepaired(9);
	E.guardGate();
}
