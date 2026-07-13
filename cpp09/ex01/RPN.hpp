#pragma once
#include <iostream>
#include <sstream>
#include <stack>

class RPN {
private:
	std::stack<int> m_stack;

public:
	RPN();
	~RPN();
	RPN(const RPN&);
	RPN& operator=(const RPN&);
	int  handle_op(char op);
	int  remove_top();
	void push(int num);
	bool empty();
	int  top();
	int  size();
};
