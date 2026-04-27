#pragma once
#include <iostream>
#include <ostream>

class Bureaucrat {
private:
	const std::string m_name;
	int m_grade;

public:
	const std::string& getName() const;
	int getGrade() const;
	void incrementGrade();
	void decrementGrade();
};

std::ostream& operator<<(std::ostream& out, Bureaucrat& b) {
	out << b.getName() + ", bureaucrate grade " << b.getGrade() << std::endl;
	return out;
}
