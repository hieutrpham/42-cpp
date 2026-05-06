#include "AForm.hpp"

AForm::AForm() : m_name("default"), m_is_signed(false), m_required_grade_to_sign(150), m_required_grade_to_execute(150) {}

AForm::~AForm() {}

AForm::AForm(
	const std::string name,
	bool is_signed,
	const int required_grade_to_sign,
	const int required_grade_to_execute) :
	m_name(name), m_is_signed(is_signed),
	m_required_grade_to_sign(required_grade_to_sign),
	m_required_grade_to_execute(required_grade_to_execute)
{
	if (required_grade_to_sign < 1 || required_grade_to_execute < 1)
		throw AForm::GradeTooHighException();
	if (required_grade_to_sign > 150 || required_grade_to_execute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& other) :
	m_name(other.m_name),
	m_is_signed(other.m_is_signed),
	m_required_grade_to_sign(other.m_required_grade_to_sign),
	m_required_grade_to_execute(other.m_required_grade_to_execute) {}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		m_is_signed = other.m_is_signed;
	}
	return *this;
}

std::string AForm::getName() const {
	return m_name;
}

bool AForm::getIsSigned() const {
	return m_is_signed;
}

int AForm::getRequiredGradeToSign() const {
	return m_required_grade_to_sign;
}

int AForm::getRequiredGradeToExec() const {
	return m_required_grade_to_execute;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "grade too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "grade too low";
}

const char* AForm::FormNotSigned::what() const noexcept {
	return "Form not signed";
}

const char* AForm::ExecException::what() const noexcept {
	return "exec grade too low";
}

void AForm::beSigned(const Bureaucrat& b) {
	if (b.getGrade() <= m_required_grade_to_sign)
		m_is_signed = true;
	else
		throw GradeTooLowException();
}

void AForm::execute(const Bureaucrat& b) const {
	if (b.getGrade() > m_required_grade_to_execute)
		throw ExecException();
	if (!m_is_signed)
		throw FormNotSigned();
	this->formAction();
}

std::ostream& operator<<(std::ostream& out, AForm& form) {
	out << "AForm: " << form.getName()
		<< ", is signed? " << (form.getIsSigned() ? "true" : "false")
		<< ", required grade to sign: " << form.getRequiredGradeToSign()
		<< ", required grade to execute: " << form.getRequiredGradeToExec();
	return out;
}
