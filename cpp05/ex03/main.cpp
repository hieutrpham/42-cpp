#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
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
		Intern i;
		AForm *f = i.makeForm("president", "home");
		AForm *f1 = i.makeForm("shrubbery", "home");
		AForm *f2 = i.makeForm("robotomy", "home");
		f->beSigned(b1);
		b1.signForm(*f);
		b1.executeForm(*f);
		LOG(f->getName());
		LOG(f1->getName());
		LOG(f2->getName());
		delete f;
		delete f1;
		delete f2;
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
