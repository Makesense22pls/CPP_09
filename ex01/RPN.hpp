#pragma once

#include <stack>
#include <iostream>
#include <string>
#include <stdexcept>

class RPN{

	private:
		std::stack<int> stack;
	public :
		RPN(const std::string &arg);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void calcul (const std::string &arg);
};