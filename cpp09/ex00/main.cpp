#include <cstdlib>
#include <time.h>
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>

void str_trim(std::string &str);

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btc <input file>\n";
		return 1;
	}

	const std::string input = av[1];

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Please provide data.csv file\n";
		return EXIT_FAILURE;
	}

	// NOTE: parsing data.csv
	std::map<std::string, float> coinbase;
	for (std::string line; std::getline(file, line);)
	{
		if (line == "date,exchange_rate")
		{
			continue;
		}

		std::istringstream iss(line);
		std::string date;

		std::getline(iss, date, ',');
		float rate;
		iss >> rate;
		coinbase[date] = rate;
	}

	// NOTE: parsing input
	std::ifstream input_stream(input);
	if (!input_stream.is_open())
	{
		std::cerr << "Invalid input file\n";
		return EXIT_FAILURE;
	}

	for (std::string line; std::getline(input_stream, line);)
	{
		if (line.empty() || line.length() == 0 || line == "date | value")
			continue;
		std::istringstream iss(line);
		std::string date;
		double value;

		std::getline(iss, date, '|');
		str_trim(date);

		struct tm tm;
		if (!strptime(date.c_str(), "%Y-%m-%d", &tm))
		{
			std::cout << "Error: bad input => " << date << "\n";
			continue;
		}

		iss >> value;
		if (value < 0)
		{
			std::cout << "Error: not a positive number.\n";
			continue;
		}

		if (value > 1000)
		{
			std::cout << "Error: too large a number.\n";
			continue;
		}
		auto price = coinbase.lower_bound(date)->second;
		std::cout << date << " => " << value << " = " << value * price << "\n";
	}
}

// Source - https://stackoverflow.com/a/217605
void str_trim(std::string &str)
{
	// trim left
	str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) {
		return !std::isspace(ch);
	}));

	// trim right
	str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {
		return !std::isspace(ch);
	}).base(), str.end());
}
