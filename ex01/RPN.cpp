#include "RPN.hpp"



//FORME CANONIQUE
RPN::RPN(){};

RPN::RPN(const RPN &other){
	*this = other;
};

RPN &RPN::operator=(const RPN &other){
	if (this != &other)
	{
		this->stack = other.stack;
	}
	return *this;
}

RPN::~RPN(){};



int checking(int argc, char *argv){
	if (argc != 2)
		return(std::cerr << "Error: wrong number of arguments" << std::endl, 1);
	std::string copy(argv);
	if (copy.empty())
		return(std::cerr << "Error: empty input" << std::endl, 1);
	return (0);
}

void RPN::calcul(const std::string &input)
{
	size_t i = 0;

	while (i < input.length())
	{
		if (input[i] == ' ')
		{
			i++;
			continue ;
		}
		char c = input[i];
		if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (stack.size() < 2)
			{
				std::cerr << "Error" << std::endl;
				return ;
			}
			double b = stack.top(); stack.pop();
			double a = stack.top(); stack.pop();
			if (c == '+')
				stack.push(a + b);
			else if (c == '-')
				stack.push(a - b);
			else if (c == '*')
				stack.push(a * b);
			else if (c == '/')
			{
				if (b == 0)
				{
					std::cerr << "Error: division by zero" << std::endl;
					return ;
				}
				stack.push(a / b);
			}
		}
		else if (c >= '0' && c <= '9')
			stack.push(c - '0');
		else
		{
			std::cerr << "Error" << std::endl;
			return ;
		}
		i++;
	}
	if (stack.size() != 1)
	{
		std::cerr << "Error" << std::endl;
		return ;
	}
	std::cout << stack.top() << std::endl;
}
