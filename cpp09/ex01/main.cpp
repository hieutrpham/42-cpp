#include <cctype>
#include <cstdio>
#include <list>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

int remove_top(std::stack<int, std::list<int>> &Stack)
{
	int top = Stack.top();
	Stack.pop();
	return top;
}

int handle_op(std::stack<int, std::list<int>> &Stack, char op)
{
	switch (op) {
		case '+':
			return remove_top(Stack) + remove_top(Stack);
		case '-':
			return remove_top(Stack) - remove_top(Stack);
		case '/':
			return remove_top(Stack) / remove_top(Stack);
		case '*':
			return remove_top(Stack) * remove_top(Stack);
		default: return 0;
	}
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Wrong arguments\n";
		return EXIT_FAILURE;
	}

	std::istringstream input(av[1]);
	std::string token;
	std::stack<int, std::list<int>> Stack;

	while(input >> token)
	{
		int num;
		try {
			num = std::stoi(token.c_str());
			Stack.push(num);
		} catch (std::exception &e) {
			if (token == "+")
			{
				Stack.push(handle_op(Stack, '+'));
			}
			else if (token == "-")
			{
				Stack.push(handle_op(Stack, '-'));
			}
			else if (token == "/")
			{
				Stack.push(handle_op(Stack, '/'));
			}
			else if (token == "*")
			{
				Stack.push(handle_op(Stack, '*'));
			}
			else
				std::cerr << "Error\n";
		}
	}
}
