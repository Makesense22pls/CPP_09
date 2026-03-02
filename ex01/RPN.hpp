#pragma once

#include <stack>
#include <iostream>
#include <string>

class RPN{

	class NotDigit : public std::exception{
		const char* what() const throw()
		{
			return ("Not a single digit less than 10");
		}
		};
	private:
		std::stack<int> stack;
	public :
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();
		void polish (const std::string &arg);
};