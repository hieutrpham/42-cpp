#include "Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat() : m_name("cookie"), m_grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : m_name(name), m_grade(grade){}

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
	m_grade--;
	// TODO: throw exception
}

void Bureaucrat::incrementGrade() {
	m_grade++;
	// TODO: throw exception
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b) {
	out << b.getName() + ", bureaucrat grade " << b.getGrade() << std::endl;
	return out;

