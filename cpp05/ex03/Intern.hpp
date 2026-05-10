#pragma once
#include "AForm.hpp"

class Intern {
public:
	Intern();
	~Intern();
	Intern(const Intern&);
	Intern& operator=(const Intern&);
	AForm* makeForm(std::string name, std::string target);
};
