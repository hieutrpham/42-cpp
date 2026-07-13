#include "BitcoinExchange.hpp"

void str_trim(std::string &str);

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btc <input file>\n";
		return EXIT_FAILURE;
	}

	const std::string input = av[1];
	if (input != "input.txt")
	{
		std::cerr << "Invalid input file\n";
		return EXIT_FAILURE;
	}

	std::ifstream file("data.csv");
	if (!file.is_open())
	{
		std::cerr << "Please provide data.csv file\n";
		return EXIT_FAILURE;
	}

	BitcoinExchange coinbase(file);

	// NOTE: parsing input
	std::ifstream input_stream(input);
	if (!input_stream.is_open())
	{
		std::cerr << "Unable to open input file\n";
		return EXIT_FAILURE;
	}

	uint line_num = 0;
	for (std::string line; std::getline(input_stream, line); line_num++)
	{
		if (line.empty() || line_num == 0)
		{
			line_num++;
			continue;
		}
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
		auto data = coinbase.get_data();
		auto price = data.lower_bound(date);
		if (price == data.end())
		{
			std::cout << "Error: bad input => " << date << "\n";
			continue;
		}

		if (iss.eof())
			std::cout << date << " => " << value << " = " << value * price->second << "\n";
		else
			std::cout << "Error: bad format\n";
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
