#include "RPN.hpp"

int checking(int argc, char *argv);

int main(int argc, char **argv)
{
	try {
		if (checking(argc, argv[1]) == 1)
			return (1);
		RPN rpn(argv[1]);
		rpn.calcul(argv[1]);
	}
	catch (const std::exception &e)
	{
		return (std::cerr<< "Error :" << e.what()<< std::endl, 1);
	}
	return (0);
}