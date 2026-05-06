#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b1("heiru", 150);
		ShrubberyCreationForm a("a"), b("home"), c;
		LOG(a);
		LOG(b);
		LOG(c);
		ShrubberyCreationForm d(b);
		LOG(d);
		c = a;
		b1.signForm(a);
		b1.executeForm(a);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
