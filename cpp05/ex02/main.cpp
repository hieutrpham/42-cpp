#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b1("heiru", 1);
		ShrubberyCreationForm a("a");
		RobotomyRequestForm b("b");
		PresidentialPardonForm c;
		LOG(a);
		LOG(b);
		LOG(c);
		b1.signForm(b);
		b1.signForm(a);
		b1.signForm(c);
		b1.executeForm(a);
		b1.executeForm(b);
		b1.executeForm(c);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
