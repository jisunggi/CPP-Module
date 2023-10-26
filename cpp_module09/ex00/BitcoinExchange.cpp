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

float BitcoinExchange::stringToFloat(std::string string)
{
	std::stringstream stream;
	float floatValue;

	stream << string;
	stream >> floatValue;
	return floatValue;
}

int BitcoinExchange::checkStringDate(std::string string)
{
	struct tm tmStruct;
	if (strptime(string.c_str(), "%Y-%m-%d", &tmStruct) == NULL)
		return 1;
	return 0;
}

void BitcoinExchange::makeMapData(std::string line)
{
	std::string dateString = line.substr(0, 10);
	std::string valueString = line.substr(11);
	checkStringDate(dateString);
	data.insert(std::pair<std::string, float>(dateString, stringToFloat(valueString)));
}

void BitcoinExchange::storeDataFile()
{
	std::ifstream ifs;
	std::string line;

	ifs.open("data.csv");
	if (!ifs.is_open())
		throw BitcoinExchange::notOpenFile();
	std::getline(ifs, line);
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (line.size())
			makeMapData(line);
	}

	// std::map<std::string, float>::iterator iter = data.begin();
	// while (iter != data.end()) {
	// 	std::cout << iter->first << " " << iter->second << std::endl;
	// 	iter++;
	// }
}

int BitcoinExchange::checkStringValue(std::string valueString)
{
	std::string::size_type dotIdx = valueString.find(".");
	for (std::string::size_type i = 0; i < valueString.size(); i++)
	{
		if (valueString[0] == '-')
			continue;
		if (!(valueString[i] >= '0' && valueString[i] <= '9') && i != dotIdx
				)
			return 1;
	}
	if (valueString[0] == '.' || valueString[valueString.size() - 1] == '.')
		return 1;
	return 0;
}

int BitcoinExchange::checkInputFile(std::string line)
{
	float floatValue;

	std::string dateString = line.substr(0, 10);	
	if (checkStringDate(dateString))
	{
		std::cout << "Error: bad input => " << dateString << std::endl;
		return 1;
	}
	if (line.size() < 11)
		throw BitcoinExchange::wrongInputException();
	std::string middleString = line.substr(10, 3);
	if (middleString != " | ")
		throw BitcoinExchange::wrongInputException();
	std::string valueString = line.substr(13);
	if (checkStringValue(valueString))
	{
		std::cout << "Error: bad input => " << valueString << std::endl;
		return 1;
	}
	
	floatValue = stringToFloat(valueString);
	if (floatValue < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return 1;
	}
	if (floatValue > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return 1;
	}
	inputDate = dateString;
	inputValue = floatValue;
	return 0;
}

void BitcoinExchange::printBitcoinValue()
{
	float value = 0;
	std::map<std::string, float>::iterator iter;

	for (iter = data.begin(); iter != data.end(); iter++)
	{
		if ((*iter).first == inputDate)
		{
			value = (*iter).second * inputValue;
			std::cout << inputDate << " => " << inputValue << " = " << value << std::endl;
			return ;
		}
	}
	iter = data.lower_bound(inputDate);
	if (iter == data.begin())
	{
		std::cout << "Error : invalid date" << std::endl;
		return ;
	}
	value = (*--iter).second * inputValue;
	std::cout << inputDate << " => " << inputValue << " = " << value << std::endl;
}

void BitcoinExchange::storeInputFile(char *inputFile)
{
	std::ifstream ifs;
	std::string line;

	ifs.open(inputFile);
	if (!ifs.is_open())
		throw BitcoinExchange::notOpenFile();
	std::getline(ifs, line);
	if (line != "date | value")
		throw BitcoinExchange::wrongInputException();
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (line.size())
		{
			if(!checkInputFile(line))
				printBitcoinValue();
		}
	}
}

void BitcoinExchange::btcExecute(char *inputFile)
{
	storeDataFile();
	storeInputFile(inputFile);
}

const char *BitcoinExchange::wrongInputException::what() const throw()
{
	return "Error: wrong input file form";
}

const char *BitcoinExchange::notOpenFile::what() const throw()
{
	return "Error: could not open file.";
}