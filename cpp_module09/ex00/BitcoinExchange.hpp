#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <ctime>
#include <sstream>

class BitcoinExchange
{
	private :
		std::map<std::string, float> data;
		std::string inputDate;
		float inputValue;

    public :
        BitcoinExchange();
        ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinExchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);

		void btcExecute(char *inputFile);

		void storeDataFile();
		void makeMapData(std::string line);
		float stringToFloat(std::string string);
		int checkStringDate(std::string string);

		void storeInputFile(char *inputFile);
		int checkInputFile(std::string line);
		int checkStringValue(std::string valueString);
		void printBitcoinValue();

		class wrongInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class notOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif