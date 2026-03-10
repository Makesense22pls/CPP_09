#include "RPN.hpp"
#include <cstring>

RPN::RPN(const std::string &) : stack(){};


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

int checking(int argc, char *argv){
	if (argc != 2)
		return (std::cerr << "Error: invalid number of arguments" << std::endl,1);
	if (!argv || strlen(argv) == 0)
		return (std::cerr << "Error: invalid argument" << std::endl,1);
	return (0);	
}

void RPN::calcul(const std::string &arg)
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
				throw std::runtime_error("Error: add operands");
			
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
					throw std::runtime_error("Error: div by 0");
				stack.push(a / b);
			}
		}
		else
		{
			throw std::runtime_error("Not a single digit less than 10");
		}
	}
	
	if (stack.size() != 1)
		throw std::runtime_error("Error: invalid expression");
	
	std::cout << stack.top() << std::endl;
}