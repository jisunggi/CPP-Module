#include "BitcoinExchange.hpp"

int main()
{
	try
	{
			
		BitcoinExchange bitcoinExchange;

		bitcoinExchange.btcExecute();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}