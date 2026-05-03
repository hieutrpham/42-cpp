#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string m_name;
	bool m_is_signed;
	const int m_required_grade_to_sign;
	const int m_required_grade_to_execute;
public:
	AForm();
	virtual ~AForm() = 0;
	AForm(const AForm&);
	AForm(const std::string, bool, const int, const int);
	AForm& operator=(const AForm&);
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

	void beSigned(const Bureaucrat& b);
};

std::ostream& operator<<(std::ostream& out, AForm& form);
