#include <cctype>
#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	std::locale loc;
	for (int i = 1; i < ac; i++) {
		std::string str = av[i];
		for (int i = 0; i < str.length(); i++) {
			std::cout << std::toupper(str[i], loc);
		}
	}
	std:: cout << std::endl;
	return 0;
}
