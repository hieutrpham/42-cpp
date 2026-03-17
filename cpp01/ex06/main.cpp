#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERR: number of arguments wrong\n";
		return 0;
	}
	std::string str = av[1];
	std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int level = -1;
	for (int i = 0; i < 4; ++i) {
		if (names[i] == str) {
			level = i;
			break;
		}
	}
	if (level < 0) {
		std::cout << "Nah\n";
		return 0;
	}
	Harl h;
	switch (level) {
		case 0: h.complain("DEBUG"); [[fallthrough]];
		case 1: h.complain("INFO"); [[fallthrough]];
		case 2: h.complain("WARNING"); [[fallthrough]];
		case 3: h.complain("ERROR"); break;
		default: std::cout << "Unknown\n";
	}
}
