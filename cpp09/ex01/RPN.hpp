#pragma once
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

class RPN {
private:
	std::stack<int, std::list<int>> m_stack;

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
};
