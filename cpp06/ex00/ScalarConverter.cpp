#include "ScalarConverter.hpp"

std::ostream& operator<<(std::ostream& o, Type& t) {
	switch (t) {
		case  Type::CHAR:    o <<  "char";    break;
		case  Type::INT:     o <<  "int";     break;
		case  Type::FLOAT:   o <<  "float";   break;
		case  Type::DOUBLE:  o <<  "double";  break;
		default:			 o <<  "unknown";
	}
	return o;
}

void impossible() {
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}

bool is_type_double(const std::string& str) {
	bool count_alpha = false;

	for (auto c : str)
		if (std::isalpha(c)) count_alpha = true;

	return str == "-inf" || str == "+inf" || str == "nan" ||
		(!count_alpha && (str.find('.') != std::string::npos) && !std::isalpha(str.back()));
}

bool is_type_float(const std::string& str) {
	bool is_float = true;
	int count = 0;

	for (auto c : str) {
		if (std::isalpha(c))
			count++;
		if (std::isalpha(c) && c != 'f')
			is_float = false;
	}

	return str == "-inff" || str == "+inff" || str == "nanf" ||
		(count == 1 && is_float && str.find('.') != std::string::npos && str.back() == 'f');
}

void ScalarConverter::convert(const std::string& str)
{
	if (str.empty()) {
		impossible();
		return;
	}

	Type actual_type;

	if (str.length() == 1 && !std::isdigit(str[0]) && std::isprint(str[0]))
		actual_type = Type::CHAR;
	else if (is_type_float(str))
		actual_type = Type::FLOAT;
	else if (is_type_double(str))
		actual_type = Type::DOUBLE;
	else if (str.find('.') == std::string::npos && !std::isalpha(str.back()))
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
				impossible();
				return;
		}
	} catch (std::exception &e) {
		impossible();
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
