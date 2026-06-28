#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(std::ifstream &file)
{
	for (std::string line; std::getline(file, line);)
	{
		if (line == "date,exchange_rate")
		{
			continue;
		}

		std::istringstream iss(line);
		std::string date;

		std::getline(iss, date, ',');
		double rate;
		iss >> rate;
		m_coinbase[date] = rate;
	}
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : m_coinbase(other.m_coinbase) { }

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	if (this != &other)
		m_coinbase = other.m_coinbase;
	return *this;
}

std::map<std::string, double> BitcoinExchange::get_data()
{
	return m_coinbase;
}
