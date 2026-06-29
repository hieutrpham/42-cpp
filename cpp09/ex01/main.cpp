#include <cctype>
#include <cstdio>
#include <list>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

int remove_top(std::stack<int, std::list<int>> &Stack)
{
	int top = Stack.top();
	if (!Stack.empty())
		Stack.pop();
	else
		throw std::runtime_error("Stack empty");
	return top;
}

int handle_op(std::stack<int, std::list<int>> &Stack, char op)
{
	if (Stack.size() < 2)
		throw std::runtime_error("Invalid stack");

	switch (op) {
		case '+':
			return remove_top(Stack) + remove_top(Stack);
		case '-':
		{
			auto num1 = remove_top(Stack);
			auto num2 = remove_top(Stack);
			return num2 - num1;
		}
		case '/':
		{
			auto num1 = remove_top(Stack);
			auto num2 = remove_top(Stack);
			if (num1 != 0)
				return num2 / num1;
			else
				return 0;
		}
		case '*':
			return remove_top(Stack) * remove_top(Stack);
		default: throw std::runtime_error("Invalid operator");
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
				try {
					Stack.push(handle_op(Stack, '+'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "-")
			{
				try {
					Stack.push(handle_op(Stack, '-'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "/")
			{
				try {
					Stack.push(handle_op(Stack, '/'));
				} catch (...) {
					goto EXIT;
				}
			}
			else if (token == "*")
			{
				try {
					Stack.push(handle_op(Stack, '*'));
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
