#include <fstream>
#include <iostream>
#include <string>

int main(int ac, char** av) {
	if (ac != 4) {
		std::cerr << "Wrong argument number\n";
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	if (s1.empty()) {
		std::cerr << "S1 can't be empty\n";
		return 1;
	}

	std::string s2 = av[3];

	// open file
	std::fstream infile(filename);
	if (!infile.is_open()) {
		std::cerr << "Error open file\n";
		return 1;
	}

	std::ofstream outfile(filename + ".replace");
	if (!outfile.is_open()) {
		std::cerr << "ERR outfile\n";
		return 1;
	}

	std::string line;
	// reading each line from the infile
	while (std::getline(infile, line)) {
		// find the first occurence of s1
		std::string::size_type index = line.find(s1);
		while (index != std::string::npos) {
			std::string line1 = line.substr(0, index);
			std::string line2 = line.substr(index+1);
			line = line1 + s2 + line2;
			index = line.find(s1);
		}
		outfile << line << '\n';
	}

	return 0;
}
