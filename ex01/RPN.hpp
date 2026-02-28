#pragma once

#include <iostream>
#include <string>
#include <stack>

int checking(int argc, char *argv);

class RPN {
	private:
		std::stack<double> stack;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void calcul(const std::string &expression);
};
