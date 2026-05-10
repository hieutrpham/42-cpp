#pragma once
#include "AForm.hpp"
#include <iostream>
#include <fstream>
#include <ostream>

class RobotomyRequestForm : public AForm {
private:
	std::string m_target = "default";
public:
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	~RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm&);
	RobotomyRequestForm& operator=(const RobotomyRequestForm&);
	void formAction() const;
};
