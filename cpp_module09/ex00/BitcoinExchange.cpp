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

int	BitcoinExchange::stringToInt(std::string string)
{
	std::stringstream stream;
	int integer;

	stream << string;
	stream >> integer;
	return integer;
}

struct tm BitcoinExchange::stringToDate(std::string string)
{
	struct tm tmStruct;
	if (strptime(string.c_str(), "%Y-%m-%d", &tmStruct) == NULL)
		throw std::exception();
	tmStruct.tm_hour = 0;
	tmStruct.tm_min = 0;
	tmStruct.tm_sec = 0;
	return tmStruct;
}

void BitcoinExchange::makeMapData(std::string line)
{
	std::string dateString = line.substr(0, 10);
	std::string valueString = line.substr(11);
	stringToDate(dateString);
	//data.insert(std::pair<struct tm, int>(stringToDate(dateString), stringToInt(valueString)));
	// for (auto iter : data) {
	// std::cout << iter.first << " " << iter.second << std::endl;
//}
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
		if (line.size())
			makeMapData(line);
	}
}

// void checkInputFile()
// {

// }

void BitcoinExchange::btcExecute()
{
	storeDataFile();
	//checkInputFile();
}