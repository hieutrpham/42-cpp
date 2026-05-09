#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), m_target("default") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), m_target(target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

void PresidentialPardonForm::formAction() const {
	std::cout << m_target << " has been pardoned by Zaphod Beeblebrox\n";
}
