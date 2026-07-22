#include "BitcoinExchange.hpp"

void str_trim(std::string &str);

time_t get_time(int year, int mon, int day)
{
	std::tm date = {};

	date.tm_year = year - 1900;
	date.tm_mon = mon - 1;
	date.tm_mday = day;
	date.tm_isdst = -1;

	return mktime(&date);
}

int main(int ac, char** av)
{
	if (ac != 2) {
		std::cerr << "Usage: ./btc <input file>\n";
		return EXIT_FAILURE;
	}

	const std::string input = av[1];

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

		std::stringstream date_stream(date);
		
		std::tm tm = {};
		date_stream >> std::get_time(&tm, "%Y-%m-%d");
		auto original_mday = tm.tm_mday;
		auto original_mon = tm.tm_mon;

		if (date_stream.fail())
		{
			std::cerr << "Error: bad input => " << date << "\n";
			continue;
		}

		time_t t = mktime(&tm);

		if (t < 0 || tm.tm_mday != original_mday || tm.tm_mon != original_mon)
		{
			std::cerr << "Error: bad input invalid calendar logic => " << date << "\n";
			continue;
		}

		auto min_date = get_time(2009, 1, 2);

		if (difftime(t, min_date) < 0) {
			// std::cout << t << ":" << min_date << '\n';
			std::cerr << "Error: bad input too early => " << date << "\n";
			continue;
		}

		auto data = coinbase.get_data();
		auto item = data.lower_bound(date);

		iss >> value;

		if (difftime(t, get_time(2022, 3, 29)) > 0)
		{
			item = data.lower_bound("2022-03-29");
			std::cout << date << " => " << value << " = " << value * item->second << "\n";
			continue;
		}

		if (value < 0)
		{
			std::cerr << "Error: not a positive number.\n";
			continue;
		}

		if (value > 1000)
		{
			std::cerr << "Error: too large a number.\n";
			continue;
		}

		if (iss.eof())
		{
			if ((*item).first != date)
				item--;
			std::cout << date << " => " << value << " = " << value * item->second << "\n";
		}
		else
			std::cerr << "Error: bad format\n";
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
