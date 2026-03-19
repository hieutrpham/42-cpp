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
	FragTrap F("Bocal");
	F.attack("Joensu");
	F.takeDamage(5);
	F.beRepaired(9);
	F.highFivesGuys();
	FragTrap G(F);
	G.takeDamage(200);
	G.beRepaired(9);
	G.highFivesGuys();
}
