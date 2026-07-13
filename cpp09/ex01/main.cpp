#include "RPN.hpp"

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

	// BUG:
	// * overflow 9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9*9
	// * stoi parsing things like 12.34asdfkj. take a look at from_chars
	// * also shouldn't allow numbers > 10
	while(input >> token)
	{
		int num;
		try {
			num = std::stoi(token.c_str());
			Stack.push(num);
		} catch (std::exception &e) {
			if (token == "+")
			{
				try {
					Stack.push(Stack.handle_op('+'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "-")
			{
				try {
					Stack.push(Stack.handle_op('-'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "/")
			{
				try {
					Stack.push(Stack.handle_op('/'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "*")
			{
				try {
					Stack.push(Stack.handle_op('*'));
				} catch (...) {
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
