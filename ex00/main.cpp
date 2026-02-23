#include "BitcoinExchange.hpp"

int main(int argc, char **argv){

	std::string file(argv[1]);
	if (argc < 2)
		return(std::cout << "Not enough args" << std::endl,1);
	if(checking(argv[1]) == 1)
		return(1);
	else
	{
		Data data;
		data.extract_data_csv();
		data.extract_input_file(&file);
		std::cout << "All good !" << std::endl;
	}
}