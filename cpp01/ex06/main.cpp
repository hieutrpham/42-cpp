#include "Harl.hpp"
#include <iostream>
#include <string>

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "ERR: number of arguments wrong\n";
		return 0;
	}
	std::string str = av[1];
	std::cout << str;
	std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	int level;
	Harl h;
	switch (level) {
		case 0: h.complain(names[level]);
	}
}
