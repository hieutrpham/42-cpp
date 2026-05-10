#pragma once
#include "AForm.hpp"

static const std::string names[] = {
	"shrubbery",
	"robotomy",
	"president",
};

enum {
	SHRUBBERY,
	ROBOTOMY,
	PRESIDENT,
};

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	AForm* makeForm(std::string name, std::string target);
};
