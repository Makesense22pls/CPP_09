#include "BitcoinExchange.hpp"



//FORME CANONIQUE
Data::Data(){

};

Data::Data(const Data &other){
	*this = other;
};

Data &Data::operator=(const Data &other){

}


Data::~Data(){
	
};



void Data::extract_input_file(std::string *file)
{
	std::ifstream file_read(*file);
	
}
int checking(char *arg){
	
	std::string file(arg);
	
	std::ifstream file_name(arg);
	if (!file_name.is_open())
	return(std::cout << "CAN'T OPEN THE FILE SORRY NOT SORRY" << std::endl,1);
	int len = file.length();
	std::string sub;
	if (len >= 4)
	sub = file.substr(len - 4, 4);
	if (sub == ".txt")
		return(0);
	return(std::cout << "WRONG FILE EXTENSION" << std::endl,1);
}
