#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b1("heiru", 1);
		ShrubberyCreationForm a("a"), b("home"), c;
		LOG(a);
		LOG(b);
		LOG(c);
		ShrubberyCreationForm d(b);
		LOG(d);
		c = a;
		b.execute(b1);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
