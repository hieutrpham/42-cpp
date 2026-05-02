#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Form {
private:
	const std::string m_name;
	bool m_is_signed;
	const int m_required_grade_to_sign;
	const int m_required_grade_to_execute;
public:
	Form();
	~Form();
	Form(const Form&);
	Form(const std::string, bool, const int, const int);
	Form& operator=(const Form&);
	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExec() const;
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};

	void beSigned(Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, Form& form);
