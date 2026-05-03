#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <ostream>

int main() {
	try {
		Bureaucrat b;
		Bureaucrat a("hieu", 1);
		Bureaucrat c;
		Bureaucrat d(b);
		LOG(b);
		LOG(a);
		LOG(c);
		c = a;
		LOG(c);
		b.incrementGrade();
		LOG(b);
		a.decrementGrade();
		LOG(a);
	} catch (std::exception& e) {
		ERR(e.what());
	}

	try {
		ShrubberyCreationForm a, b, c;
		LOG(a);
		LOG(b);
		LOG(c);
		ShrubberyCreationForm d(b);
		LOG(d);
		c = a;
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
