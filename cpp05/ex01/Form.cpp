#include "Form.hpp"

Form::Form() : m_name("default"), m_is_signed(false), m_required_grade_to_sign(150), m_required_grade_to_execute(150) {}

Form::~Form() {}

Form::Form(
	const std::string name,
	bool is_signed,
	const int required_grade_to_sign,
	const int required_grade_to_execute) :
	m_name(name), m_is_signed(is_signed),
	m_required_grade_to_sign(required_grade_to_sign),
	m_required_grade_to_execute(required_grade_to_execute)
{
	if (required_grade_to_sign < 1 || required_grade_to_execute < 1)
		throw Form::GradeTooHighException();
	if (required_grade_to_sign > 150 || required_grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& other) :
	m_name(other.m_name),
	m_is_signed(other.m_is_signed),
	m_required_grade_to_sign(other.m_required_grade_to_sign),
	m_required_grade_to_execute(other.m_required_grade_to_execute) {}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		m_is_signed = other.m_is_signed;
	}
	return *this;
}

std::string Form::getName() const {
	return m_name;
}

bool Form::getIsSigned() const {
	return m_is_signed;
}

int Form::getRequiredGradeToSign() const {
	return m_required_grade_to_sign;
}

int Form::getRequiredGradeToExec() const {
	return m_required_grade_to_execute;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "FORM: grade too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "FORM: grade too low";
}

void Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= m_required_grade_to_sign)
		m_is_signed = true;
	else
		throw GradeTooLowException();
}

std::ostream& operator<<(std::ostream& out, Form& form) {
	out << "Form: " << form.getName()
		<< ", is signed? " << (form.getIsSigned() ? "true" : "false")
		<< ", required grade to sign: " << form.getRequiredGradeToSign()
		<< ", required grade to execute: " << form.getRequiredGradeToExec();
	return out;
}
