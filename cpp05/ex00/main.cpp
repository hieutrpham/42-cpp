#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main() {
	try {
		Bureaucrat b;
		Bureaucrat a("hieu", 1);
		Bureaucrat c;
		Bureaucrat d(b);
		LOG(b);
		LOG(b);
		LOG(b);
		c = a;
		LOG(c);
		b.decrementGrade();
		LOG(b);
		a.incrementGrade();
		LOG(a);
	} catch (std::exception& e) {
		ERR(e.what());
	}
}
