#include "RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN& other) {
	m_stack = other.m_stack;
}

RPN& RPN::operator=(const RPN& other) {
	if (this != &other)
		m_stack = other.m_stack;
	return *this;
}

int RPN::remove_top()
{
	int top = m_stack.top();
	if (!m_stack.empty())
		m_stack.pop();
	else
		throw std::runtime_error("m_stack empty");
	return top;
}

int RPN::handle_op(char op)
{
	if (m_stack.size() < 2)
		throw std::runtime_error("Invalid stack");

	switch (op) {
		case '+':
			return remove_top() + remove_top();
		case '-':
		{
			auto num1 = remove_top();
			auto num2 = remove_top();
			return num2 - num1;
		}
		case '/':
		{
			auto num1 = remove_top();
			auto num2 = remove_top();
			if (num1 != 0)
				return num2 / num1;
			else
				return 0;
		}
		case '*':
			return remove_top() * remove_top();
		default: throw std::runtime_error("Invalid operator");
	}
}

int RPN::top()
{
	return m_stack.top();
}

bool RPN::empty()
{
	return m_stack.empty();
}

void RPN::push(int num)
{
	m_stack.push(num);
}
