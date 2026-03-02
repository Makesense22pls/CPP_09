#include "RPN.hpp"

RPN::RPN(){};


RPN::RPN(const RPN &other){
	*this = other;
};

RPN &RPN::operator=(const RPN &other){

	if ( this != &other )
	{
		this->stack = other.stack;
	}
	return(*this);
}

RPN::~RPN(){};



void RPN::polish(const std::string &arg)
{
	for (size_t i = 0; i < arg.length(); i++)
	{
		if (arg[i] == ' ' || arg[i] == '\t')
			continue;
		
		if (std::isdigit(arg[i]))
		{
			stack.push(arg[i] - '0');
		}
		else if (arg[i] == '+' || arg[i] == '-' || arg[i] == '*' || arg[i] == '/')
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: insufficient operands");
			
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			
			if (arg[i] == '+')
				stack.push(a + b);
			else if (arg[i] == '-')
				stack.push(a - b);
			else if (arg[i] == '*')
				stack.push(a * b);
			else if (arg[i] == '/')
			{
				if (b == 0)
					throw std::runtime_error("Error: division by zero");
				stack.push(a / b);
			}
		}
		else
		{
			throw NotDigit();
		}
	}
	
	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	
	std::cout << stack.top() << std::endl;
}