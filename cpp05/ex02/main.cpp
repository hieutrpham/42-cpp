#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b1("heiru", 1);
		ShrubberyCreationForm a("a");
		RobotomyRequestForm b("b");
		LOG(a);
		LOG(b);
		b1.signForm(b);
		b1.executeForm(b);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
