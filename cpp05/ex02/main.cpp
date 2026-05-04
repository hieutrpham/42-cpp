#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b1("heiru", 146);
		ShrubberyCreationForm a("a"), b("home"), c;
		LOG(a);
		LOG(b);
		LOG(c);
		ShrubberyCreationForm d(b);
		LOG(d);
		c = a;
		b.formAction();
		a.beSigned(b1);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
