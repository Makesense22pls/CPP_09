#include "RPN.hpp"

int main(int argc, char **argv){

	if (checking(argc, argv[1]) == 1)
		return (1);
	else
	{
		RPN rpn;
		rpn.calcul(argv[1]);
	}
	return (0);
}
