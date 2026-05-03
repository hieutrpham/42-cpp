#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), m_target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : m_target(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
		m_target = other.m_target;
	}
	return *this;
}

void ShrubberyCreationForm::formAction() const {
	std::string file_name = m_target + "_shrubberry";
	std::ofstream outfile(file_name);
	if (!outfile.is_open()) {
		throw std::system_error();
	}
	// TODO: write ascii trees to outfile
}
