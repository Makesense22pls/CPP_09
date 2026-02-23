#include "BitcoinExchange.hpp"
#include <climits>



//FORME CANONIQUE
Data::Data(){};

Data::Data(const Data &other){
	*this = other;
};

Data &Data::operator=(const Data &other){
	if(this != &other)
	{
		this->data_csv_all = other.data_csv_all;
	}
	return *this;
}

Data::~Data(){};



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

void Data::extract_data_csv()
{
	std::ifstream filename("data.csv");
	if(!filename)
		std::cerr << "Failed to open the file" << std::endl;
	std::string line;
	while(std::getline(filename, line))
		{
			size_t comma = line.find(","); // j ai la pos de mon ,
			if (comma == std::string::npos)
				continue;
			std::string date = line.substr(0,comma);
			std::string value_str = line.substr(comma+1);
			std::stringstream ss(value_str);
			double value;
			ss >> value;
			data_csv_all.insert(std::pair<std::string,double>(date,value));
		}
	
}
void Data::extract_input_file(std::string *file)
{
	std::ifstream filename(file->c_str());
	if(!filename)
		std::cerr << "Failed to open the file" << std::endl;
	std::string line;
	bool firstline = true;
	while(std::getline(filename, line))
	{
		if (firstline)
		{
			firstline = false;
			if (line == "date | value")
				continue;
		}
		
		size_t barre = line.find("|"); // j ai la pos de mon |
		if (barre == std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string date = line.substr(0, barre - 1);
		std::string value_str = line.substr(barre + 1);
		std::stringstream ss(value_str);
		double value;
		if (!(ss >> value))
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		
		if (this->parse(date, value) == 1)
		{
			double result;
			result = ((rate(date)) * value);
			std::cout << date << " => " << value << " = " << result << std::endl;
		}
	}
}

bool Data::parse(std::string date, double value)
{
	int year = atoi(date.substr(0,4).c_str());
	int month = atoi(date.substr(5,8).c_str());
	int day = atoi(date.substr(8,10).c_str());
	if(value < 0){
		std::cerr << "Error: not a positive number." << std::endl;
		return(false);
	}
	if (date.length()!= 10){
		std::cerr << "Error: bad input => " << date <<  std::endl;
		return(false);
	}
	if (year < 2011 || year > 2022){
		std::cerr << "Error: bad input => " << date <<  std::endl;
		return(false);
	}
	if (month < 0 || month > 12){
		std::cerr << "Error: bad input => " << date <<  std::endl;
		return(false);
	}
	if (day < 0 || day > 31){
		std::cerr << "Error: bad input => " << date <<  std::endl;
		return(false);
	}
	if (month == 2){
		if(day > 29){
			std::cerr << "Error: bad input => " << date <<  std::endl;
			return(false);
		}
		else if(year == 2012 || year == 2016 || year == 2020){
			if (month == 2 && day > 28){
				std::cerr << "Error: bad input => " << date <<  std::endl;
				return(false);
			}
		}
	}
	if ( month == 3 || month == 1 ||month == 5 || month == 7 || month == 9 || month == 11){
		if (day > 31){
			std::cerr << "Error: bad input => " << date <<  std::endl;
			return(false);
		}
	}
	if (month == 4 ||month == 6 || month == 8 || month == 10){
		if (day > 30){
			std::cerr << "Error: bad input => " << date <<  std::endl;
			return(false);
		}
	}
	if (value > INT_MAX){
		std::cerr << "Error: too large number." << std::endl;
		return(false);
	}
	return (true);
}
double Data::rate(std::string date)
{
	std::multimap<std::string, double>::iterator it = data_csv_all.lower_bound(date);
	if (it != data_csv_all.end() && it->first == date)
		return (it->second);
	if (it == data_csv_all.begin())
		return (it->second);
	--it;
	return (it->second);
}