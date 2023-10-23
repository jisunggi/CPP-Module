#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <map>
#include <ctime>

class BitcoinExchange
{
	private :
		std::map<struct tm, int> data;
		std::map<struct tm, int> input;

    public :
        BitcoinExchange();
        ~BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &bitcoinExchange);
		BitcoinExchange &operator=(const BitcoinExchange &bitcoinExchange);

		void btcExecute();
		void storeDataFile();
		void makeMapData(std::string line);
};

#endif