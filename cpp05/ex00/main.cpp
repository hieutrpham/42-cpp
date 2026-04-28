#include "Bureaucrat.hpp"
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
	// std::cout << c << std::endl;
}
