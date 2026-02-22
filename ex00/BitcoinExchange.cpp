#include "BitcoinExchange.hpp"



//FORME CANONIQUE
Data::Data(){

};

Data::Data(const Data &other){
	*this = other;
};

Data &Data::operator=(const Data &other){
	if(this != &other)
	{
		this->input_all = other.input_all;
	}
	return *this;
}


Data::~Data(){
	
};



void Data::extract_input_file(std::string *file)
{
	std::ifstream filename(file->c_str());
	if(!filename)
		std::cerr << "Failed to open the file" << std::endl;
	std::string line;
	while(std::getline(filename, line))
		{
			size_t barre = line.find("|"); // j ai la pos de mon |
			if (barre != std::string::npos)
			{
				std::string date = line.substr(0,barre);
				std::string value_str = line.substr(barre+1);

				std::stringstream ss(value_str);
				double value;
				ss >> value;
				
				input_all[date] = value;
				std::cout << barre << std::endl;
				std::cout << line << std::endl;
			}
		}

	
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
