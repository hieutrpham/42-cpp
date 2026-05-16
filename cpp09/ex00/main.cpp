#include <iostream>

int main(int ac, char** av) {
	if (ac != 2) {
		std::cerr << "Usage: ./btc <input file>\n";
		return 1;
	}
	const std::string file_name = av[1];
	std::cout << file_name << std::endl;
}
