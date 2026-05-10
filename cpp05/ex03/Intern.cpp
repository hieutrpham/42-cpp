#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern&){}
Intern& Intern::operator=(const Intern&){ return *this; }

AForm* Intern::makeForm(std::string name, std::string target) {
	std::string names[] = {"shrubbery", "robotomy", "president"};
	int index = -1;
	for (long unsigned int i = 0; i < sizeof(names)/sizeof(*names); ++i) {
		if (name == names[i])
			index = i;
	}
	AForm *f = NULL;
	switch (index) {
		case SHRUBBERY: f = new ShrubberyCreationForm(target); break;
		case ROBOTOMY: f = new RobotomyRequestForm(target); break;
		case PRESIDENT: f = new PresidentialPardonForm(target); break;
	}
	return f;
}
