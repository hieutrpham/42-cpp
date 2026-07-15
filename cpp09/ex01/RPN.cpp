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
		{
			auto a = remove_top();
			auto b = remove_top();
			if (a + 1LL + b > INT_MAX)
				throw std::runtime_error("Overflow");
			return a + b;
		}
		case '-':
		{
			auto a = remove_top();
			auto b = remove_top();
			if (b - 1LL - a < INT_MIN)
				throw std::runtime_error("Overflow");
			return b - a;
		}
		case '/':
		{
			auto a = remove_top();
			auto b = remove_top();
			if (a != 0)
				return b / a;
			else
				throw std::runtime_error("Division by 0");
		}
		case '*':
		{
			auto a = remove_top();
			auto b = remove_top();
			if (a * 1LL * b > INT_MAX)
				throw std::runtime_error("Overflow");
			return a * b;
		}
		default: throw std::runtime_error("Invalid operator");
	}
}

int RPN::top()
{
	return m_stack.top();
}

int RPN::size()
{
	return m_stack.size();
}

bool RPN::empty()
{
	return m_stack.empty();
}

void RPN::push(int num)
{
	m_stack.push(num);
}
