#include "RPN.hpp"



int main (int ac, char **av)
{
	if (ac != 2)
		return(std::cout << "Error: wrong number of arguments" << std::endl,1);
	try{
		RPN calcul;
		calcul.polish(av[1]);
	}catch(std::exception &e){
		std::cout <<  e.what() << std::endl;
	}
	return (0);
}
