#include "ScalarConverter.hpp"
#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

void ScalarConverter::convert(const std::string& literal)
{
	enum class Type {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNKNOWN
	};

	Type actual_type;

	if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0]))
		actual_type = Type::CHAR;
	else if (literal == "-inff" || literal == "+inff" || literal == "nanf" ||
		(literal.find('.') != std::string::npos && literal.back() == 'f'))
		actual_type = Type::FLOAT;
	else if (literal == "-inf" || literal == "+inf" || literal == "nan" ||
		(literal.find('.') != std::string::npos))
		actual_type = Type::DOUBLE;
	else if (literal.find('.') == std::string::npos)
		actual_type = Type::INT;
	else
		actual_type = Type::UNKNOWN;

	std::cout << "type: " << (int)actual_type << std::endl;

	double base_value = 0.0;

	try {
		switch (actual_type) {
			case Type::CHAR: base_value = static_cast<double>(literal[0]); break;
			case Type::INT: base_value = static_cast<double>(std::stoi(literal)); break;
			case Type::FLOAT: base_value = static_cast<double>(std::stof(literal)); break;
			case Type::DOUBLE: base_value = std::stod(literal); break;
			default:
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
				return;
		}
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
		return;
	}

	if (std::isnan(base_value) || std::isinf(base_value) || base_value < 0 || base_value > 127)
		std::cout << "char: impossible\n";
	else if (std::isprint(static_cast<char>(base_value)))
		std::cout << "char: '" << static_cast<char>(base_value) << "'\n";
	else
		std::cout << "char: Non displayable\n";

	if (std::isnan(base_value) || std::isinf(base_value) || base_value > std::numeric_limits<int>::max()
		|| base_value < std::numeric_limits<int>::min())
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(base_value) << "\n";

	float f = static_cast<float>(base_value);
	if (f == static_cast<int>(f) && !std::isnan(f) && !std::isinf(f))
		std::cout << "float: " << f << ".0f\n";
	else
		std::cout << "float: " << f << "f\n";

	if (base_value == static_cast<int>(base_value) &&!std::isnan(base_value) && !std::isinf(base_value))
		std::cout << "double: " << base_value << ".0\n";
	else
		std::cout << "double: " << base_value << "\n";
}
