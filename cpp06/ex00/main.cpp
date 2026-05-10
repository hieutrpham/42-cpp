#include "ScalarConverter.hpp"
#include <iostream>

int main(int ac, char** av) {
	if (ac != 2)
	{
		std::cerr << "Usage: ./main 42.0f\n";
		return 1;
	}
	ScalarConverter::convert(av[1]);
}
