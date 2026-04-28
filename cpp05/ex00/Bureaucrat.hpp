#pragma once
#include <iostream>
#include <ostream>

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
};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);
