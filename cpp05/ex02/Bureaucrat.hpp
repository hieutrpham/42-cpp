#pragma once
#include "AForm.hpp"
#include <exception>
#include <iostream>
#include <ostream>

#define LOG(msg) (std::cout << "LOG: " << (msg) << std::endl)
#define ERR(msg) (std::cerr << __FILE__ << ":" << __LINE__ << ": error: " << (msg) << std::endl)

class AForm;

class Bureaucrat {
private:
	const std::string m_name;
	int m_grade;

public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
	void executeForm(const AForm& form) const;
	void signForm(AForm &form) const;

private:
	class GradeTooLowException : public std::exception {
	public:
		virtual const char *what() const noexcept override;
	};

	class GradeTooHighException : public std::exception {
	public:
		virtual const char *what() const noexcept override;
	};

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
