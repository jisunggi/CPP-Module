#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	try
	{
			
		BitcoinExchange bitcoinExchange;
		(void)argc;;
		bitcoinExchange.btcExecute(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}