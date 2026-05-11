#include <iostream>
#include <cstdlib>
#include <ctime>
#include <exception>

#include "Base.hpp"

Base* generate(void)
{
	int random_val = std::rand() % 3;

	switch (random_val) {
		case 0: return new A(); break;
		case 1: return new B(); break;
		default: return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "C\n";
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	} catch (...) {}

	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	} catch(...) {}
}
