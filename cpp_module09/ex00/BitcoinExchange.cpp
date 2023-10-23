#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &bitcoinExchange)
{
	(void)bitcoinExchange;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &bitcoinExchange)
{
	if (this != &bitcoinExchange)
	{
	}
    return *this;
}

void BitcoinExchange::makeMapData(std::string line)
{

}

void BitcoinExchange::storeDataFile()
{
	std::ifstream ifs;
	std::string line;

	ifs.open("data.csv");
	if (!ifs.is_open())
		throw ;
	std::getline(ifs, line);
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		makeMapData(line);
		std::cout << line << std::endl;
	}
}

void BitcoinExchange::btcExecute()
{
	storeDataFile();
}