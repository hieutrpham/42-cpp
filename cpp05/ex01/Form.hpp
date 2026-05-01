#pragma once

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
	Form& operator=(const Form&);
	std::string getName() const;
	bool getIsSigned() const;
	int getRequiredGradeToSign() const;
	int getRequiredGradeToExec() const;
};

std::ostream& operator<<(std::ostream& out, Form& form);
