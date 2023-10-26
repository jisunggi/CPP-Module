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

void BitcoinExchange::checkStringDate(std::string string)
{
	struct tm tmStruct;
	if (strptime(string.c_str(), "%Y-%m-%d", &tmStruct) == NULL)
		throw std::exception();
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
		throw std::exception();
	std::getline(ifs, line);
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (line.size())
			makeMapData(line);
	}

	std::map<std::string, float>::iterator iter = data.begin();
	while (iter != data.end()) {
		std::cout << iter->first << " " << iter->second << std::endl;
		iter++;
	}
}

float BitcoinExchange::checkStringValue(std::string valueString)
{
	float floatValue;

	std::string::size_type dotIdx = valueString.find(".");
	for (std::string::size_type i = 0; i < valueString.size(); i++)
	{
		if (!(valueString[i] >= '0' && valueString[i] <= '9') && i != dotIdx)
			throw std::exception();
	}
	if (valueString[0] == '.' || valueString[valueString.size() - 1] == '.')
		throw std::exception();
	floatValue = stringToFloat(valueString);
	if (!(floatValue >= 0 && floatValue <= 1000))
		throw std::exception();
	return floatValue;
}

void BitcoinExchange::checkInputFile(std::string line)
{
	if (line.size() < 14)
		throw std::exception();
	std::string dateString = line.substr(0, 10);
	std::string middleString = line.substr(10, 3);
	std::string valueString = line.substr(13);
	if (middleString != " | ")
		throw std::exception();
	checkStringDate(dateString);
	inputDate = dateString;
	inputValue = checkStringValue(valueString);
}

// float BitcoinExchange::findClosestValue()
// {
// 	float value = 0;
// 	std::map<std::string, float>::iterator iter;

// 	iter = std::lower_bound(data.begin(), data.end(), inputDate);
// 	if (iter == data.begin())
// 	{
// 		std::cout << "Error : invalid date" << std::endl;
// 		return ;
// 	}
// 	return (*--iter).second * inputValue;
// }

void BitcoinExchange::printBitcoinValue()
{
	float value = 0;
	std::map<std::string, float>::iterator iter;

	for (iter = data.begin(); iter != data.end(); iter++)
	{
		if ((*iter).first == inputDate)
		{
			std::cout << iter->second << std::endl;
			value = (iter->second) * inputValue;
			std::cout << inputDate << " => " << inputValue << " = " << value << std::endl;
			return ;
		}
	}
	//iter = std::lower_bound(data.begin(), data.end(), inputDate);
	if (iter == data.begin())
	{
		std::cout << "Error : invalid date" << std::endl;
		return ;
	}
	//value = (*--iter).second * inputValue;
	std::cout << inputDate << " => " << inputValue << " = " << value << std::endl;
}

void BitcoinExchange::storeInputFile(char *inputFile)
{
	std::ifstream ifs;
	std::string line;

	ifs.open(inputFile);
	if (!ifs.is_open())
		throw std::exception();
	std::getline(ifs, line);
	if (line != "date | value")
		throw std::exception();
	while (!ifs.eof())
	{
		std::getline(ifs, line);
		if (line.size())
			checkInputFile(line);
		printBitcoinValue();
	}
}

void BitcoinExchange::btcExecute(char *inputFile)
{
	storeDataFile();
	storeInputFile(inputFile);
}