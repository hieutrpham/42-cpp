#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac == 1) {
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}
	for (int i = 1; i < ac; i++) {
		std::string str = av[i];
		for (std::string::size_type i = 0; i < str.length(); i++) {
			std::cout << (char)std::toupper(str[i]);
		}
	}
	std:: cout << std::endl;
	return 0;
}
