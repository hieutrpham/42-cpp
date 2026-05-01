#include "Form.hpp"

Form::Form() : m_name("default"), m_is_signed(false), m_required_grade_to_sign(150), m_required_grade_to_execute(150) {}

Form::~Form() {}
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

std::ostream& operator<<(std::ostream& out, Form& form) {
	out << form.getName();
	return out;
}
