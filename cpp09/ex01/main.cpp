#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong arguments\n";
		return EXIT_FAILURE;
	}

	std::istringstream input(av[1]);
	std::string token;
	// std::stack<int, std::list<int>> Stack;
	RPN Stack;

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
	if (!Stack.empty())
		std::cout << Stack.top() << "\n";
}
