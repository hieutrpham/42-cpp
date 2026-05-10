#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdexcept>

Intern::Intern(){}
Intern::~Intern(){}
Intern::Intern(const Intern&){}
Intern& Intern::operator=(const Intern&){ return *this; }

AForm* Intern::makeForm(std::string name, std::string target) {
	struct FormMap {
		std::string name;
		AForm* (*create)(const std::string& target);
	};

	FormMap forms[] = {
		{.name = "shrubbery", .create = [](const std::string& t) -> AForm* { return new ShrubberyCreationForm(t); }},
		{.name = "robotomy", .create = [](const std::string& t) -> AForm* { return new RobotomyRequestForm(t); }},
		{.name = "president", .create = [](const std::string& t) -> AForm* { return new PresidentialPardonForm(t); }},
	};

	for (long unsigned int i = 0; i < sizeof(forms)/sizeof(*forms); i++) {
		if (name == forms[i].name) {
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}

	throw std::runtime_error("Invalid form");
}
