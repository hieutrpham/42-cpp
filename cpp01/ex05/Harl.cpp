#include "Harl.hpp"

void Harl::DEBUG(void) {
	std::cout << "debug" << std::endl;
}
void Harl::INFO(void) {
	std::cout << "info" << std::endl;
}
void Harl::WARNING(void) {
	std::cout << "warning" << std::endl;
}
void Harl::ERROR(void) {
	std::cout << "error" << std::endl;
}

/* #define LEVEL_LIST \
     X("DEBUG", &Harl::DEBUG) \
     X("INFO",  &Harl::INFO)  \
     X("ERROR", &Harl::ERROR) \
     X("WARNING", &Harl::WARNING)
*/
void Harl::complain(std::string level) {
	// (this->*&Harl::DEBUG)();

	// MemberFunc f = &Harl::DEBUG;
	// (this->*f)();

	std::string names[] = { "DEBUG", "INFO", "WARNING", "ERROR" };
	MemberFunc functions[] = {
		&Harl::DEBUG,
		&Harl::INFO,
		&Harl::WARNING,
		&Harl::ERROR
	};

	for (int i = 0; i < 4; i++) {
		if (names[i] == level) {
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "Unknown\n";

	// #define X(name, func) if (level == name) { (this->*func)(); return; }
	// 	LEVEL_LIST
	// 	#undef X
}
