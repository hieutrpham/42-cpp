#pragma once

#include "Bureaucrat.hpp"
#include <ostream>
#include <string>

class Bureaucrat;

class AForm {
private:
	const std::string m_name;
	const int m_required_grade_to_sign;
	const int m_required_grade_to_execute;
	bool m_is_signed = false;
public:
	AForm();
	virtual ~AForm() = 0;
	AForm(const AForm&);
	AForm(const std::string, const int, const int);
	AForm& operator=(const AForm&);
	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExec() const;
	void beSigned(const Bureaucrat& b);
	void execute(const Bureaucrat&) const;
	virtual void formAction() const = 0;

private:
	class GradeTooHighException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception {
		public:
			virtual const char* what() const noexcept override;
	};

	class FormNotSigned : public std::exception {
	public:
		virtual const char* what() const noexcept override;
	};

	class ExecException : public std::exception {
	public:
		virtual const char* what() const noexcept override;
	};
};

std::ostream& operator<<(std::ostream& out, AForm& form);
