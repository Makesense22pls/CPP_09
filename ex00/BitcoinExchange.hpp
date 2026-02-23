#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>
#include <sstream>

int checking(char *argv);



class Data{
	private:
		std::multimap<std::string, double> data_csv_all;

	public:
		Data();
		Data(const Data &other);
		Data &operator=(const Data &other);
		~Data();
		void extract_input_file(std::string *file);
		void extract_data_csv();
		bool parse(std::string date, double value);
		double rate(std::string date);
};
