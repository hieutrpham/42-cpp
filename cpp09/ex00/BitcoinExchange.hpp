#pragma once

#include <time.h>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <ctime>
#include <iostream>

class BitcoinExchange {
private:
	std::map<std::string, double> m_coinbase;

public:
	BitcoinExchange();
	BitcoinExchange(std::ifstream &file);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
	std::map<std::string, double> get_data();
};
