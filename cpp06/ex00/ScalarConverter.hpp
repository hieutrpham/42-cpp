#pragma once

#include <cctype>
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>
#include <string>
#include <iostream>

enum class Type {
	UNKNOWN,
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
};

class ScalarConverter {
private:
		ScalarConverter() = delete;
		ScalarConverter(const ScalarConverter&) = delete;
		ScalarConverter& operator=(const ScalarConverter&) = delete;
		~ScalarConverter() = delete;
public:
	static void convert(const std::string&);
};
