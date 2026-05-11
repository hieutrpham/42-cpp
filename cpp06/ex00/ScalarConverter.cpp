#include "ScalarConverter.hpp"

std::ostream& operator<<(std::ostream& o, Type& t) {
	switch (t) {
		case Type::CHAR: o << "char"; break;
		case Type::INT: o << "int"; break;
		case Type::FLOAT: o << "float"; break;
		case Type::DOUBLE: o << "double"; break;
		default: o << "unknown";
	}
	return o;
}

void ScalarConverter::convert(const std::string& str)
{
	Type actual_type = Type::UNKNOWN;

	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
		actual_type = Type::CHAR;
	else if (str == "-inff" || str == "+inff" || str == "nanf" ||
		(str.find('.') != std::string::npos && str.back() == 'f'))
		actual_type = Type::FLOAT;
	else if (str == "-inf" || str == "+inf" || str == "nan" ||
		(str.find('.') != std::string::npos))
		actual_type = Type::DOUBLE;
	else if (str.find('.') == std::string::npos)
		actual_type = Type::INT;
	else
		actual_type = Type::UNKNOWN;

	double base_value = 0.0;

	#ifdef DEBUG
	std::cout << "LOG: actual type: " << actual_type << std::endl;
	#endif

	try {
		switch (actual_type) {
			case Type::CHAR: base_value = static_cast<double>(str[0]); break;
			case Type::INT: base_value = static_cast<double>(std::stoi(str)); break;
			case Type::FLOAT: base_value = static_cast<double>(std::stof(str)); break;
			case Type::DOUBLE: base_value = std::stod(str); break;
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
