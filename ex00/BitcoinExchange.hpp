#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

int checking(char *argv);



class Data{
	private:
		std::map<std::string, double> input_all;
		std::string date_input;
		std::string date_csv;
		std::string btc_rate;


	public:
		Data();
		Data(const Data &other);
		Data &operator=(const Data &other);\
		void extract_input_file(std::string *file);
};
