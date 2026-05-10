#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

class ShrubberyCreationForm : public AForm {
private:
	std::string m_target = "default";
public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const std::string& target);
	~ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm&);
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&);
	void formAction() const;
};
