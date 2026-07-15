#include "RPN.hpp"

bool is_allow(char c)
{
	return c == '*' || c == '-' || c == '+' || c == '/';
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Usage: " << av[0] << " [sequence of numbers to sort]\n";
		return EXIT_FAILURE;
	}

	std::istringstream input(av[1]);
	std::string token;
	RPN Stack;

	while(input >> token)
	{
		int num;

		// handle negative number
		if (token[0] == '-')
		{
			for (size_t i = 1; i < token.size(); ++i)
			{
				if (!std::isdigit(token[i]))
				{
					std::cerr << "Invalid input (contained forbidden char)\n";
					return EXIT_FAILURE;
				}
			}
		}
		else
		{
			for (size_t i = 0; i < token.size(); ++i)
			{
				if (!is_allow(token[i]) && !std::isdigit(token[i]))
				{
					std::cerr << "Invalid input (contained forbidden char)\n";
					return EXIT_FAILURE;
				}
			}
		}

		try {
			num = std::stoi(token.c_str());
			if (num > 9)
			{
				std::cerr << "Invalid input (too big)\n";
				return EXIT_FAILURE;
			}
			Stack.push(num);
		} catch (std::exception &e) {
			if (token == "+")
			{
				try {
					Stack.push(Stack.handle_op('+'));
				} catch (...) {
					std::cerr << e.what() << ' ';
					goto EXIT;
				}
			}
			else if (token == "-")
			{
				try {
					Stack.push(Stack.handle_op('-'));
				} catch (...) {
					std::cerr << e.what() << ' ';
					goto EXIT;
				}
			}
			else if (token == "/")
			{
				try {
					Stack.push(Stack.handle_op('/'));
				} catch (std::exception &e) {
					std::cerr << e.what() << ' ';
					goto EXIT;
				}
			}
			else if (token == "*")
			{
				try {
					Stack.push(Stack.handle_op('*'));
				} catch (std::exception &e) {
					std::cerr << e.what() << ' ';
					goto EXIT;
				}
			}
			else
			{
			EXIT:
				std::cerr << "Error\n";
				return 1;
			}
		}
	}

	if (!Stack.empty() && Stack.size() == 1)
		std::cout << Stack.top() << "\n";
	else
		std::cerr << "Invalid input\n";
}
