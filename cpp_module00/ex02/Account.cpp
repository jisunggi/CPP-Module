#include "Account.hpp"

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_accountIndex = _nbAccounts;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += _amount;
	_nbAccounts++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
				<< " amount:" << _amount << ";created"
				<< std::endl;
}

static void	Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* tm = localtime(&timer);
	
	char buffer[42];
	strftime(buffer, 42, "%Y%m%D_%H%M%S", tm);
}

void	Account::displayAccountsInfos(void)
{
	std::cout << 
}