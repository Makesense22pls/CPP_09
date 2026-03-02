#include "RPN.hpp"

<<<<<<< HEAD


int main (int ac, char **av)
{
	if (ac != 2)
		return(std::cout << "Error: wrong number of arguments" << std::endl,1);
	try{
		RPN calcul;
		calcul.polish(av[1]);
	}catch(std::exception &e){
		std::cout <<  e.what() << std::endl;
=======
int main(int argc, char **argv){

	if (checking(argc, argv[1]) == 1)
		return (1);
	else
	{
		RPN rpn;
		rpn.calcul(argv[1]);
>>>>>>> refs/remotes/origin/main
	}
	return (0);
}
