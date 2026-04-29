#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>

int main() {
	Bureaucrat b;
	Bureaucrat a("heiu", 1);
	Bureaucrat c;
	Bureaucrat d(b);
	std::cout << b << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	c = a;
	std::cout << c << std::endl;
	try {
	b.incrementGrade();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}
