#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("cookie"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name) {
	if (grade <= 0)
		throw GradeTooHighException();
	if (grade >= 150)
		throw GradeTooLowException();
	m_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : m_name(other.m_name), m_grade(other.m_grade) { }

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other)
		m_grade = other.m_grade;
	return *this;
}

const std::string& Bureaucrat::getName() const {
	return m_name;
}

int Bureaucrat::getGrade() const {
	return m_grade;
}

void Bureaucrat::decrementGrade() {
	int temp = m_grade + 1;
	if (temp > 150)
		throw GradeTooLowException();
	m_grade = temp;
}

void Bureaucrat::incrementGrade() {
	int temp = m_grade - 1;
	if (temp < 1)
		throw GradeTooHighException();
	m_grade = temp;
}

const char *Bureaucrat::GradeTooHighException::what() const noexcept {
	return "grade too high";
}

const char *Bureaucrat::GradeTooLowException::what() const noexcept {
	return "grade too low";
}

void Bureaucrat::signForm(AForm& form) const {
	try {
		form.beSigned(*this);
		std::cout << m_name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cerr << m_name << " couldn't sign " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() + ", bureaucrat grade " << b.getGrade() << '.';
	return out;
}
