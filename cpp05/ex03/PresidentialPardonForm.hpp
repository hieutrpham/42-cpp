#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

class PresidentialPardonForm : public AForm {
private:
	std::string m_target = "default";
public:
	PresidentialPardonForm();
	PresidentialPardonForm(const std::string& target);
	~PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm&);
	PresidentialPardonForm& operator=(const PresidentialPardonForm&);
	void formAction() const;
};
