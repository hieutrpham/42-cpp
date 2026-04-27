#include "Bureaucrat.hpp"

const std::string& Bureaucrat::getName() const {
	return m_name;
}

int Bureaucrat::getGrade() const {
	return m_grade;
}

void Bureaucrat::decrementGrade() {
	m_grade--;
}

void Bureaucrat::incrementGrade() {
	m_grade++;
}
