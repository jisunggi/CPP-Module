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

void	Account::_displayTimestamp(void)
{
	time_t timer = time(NULL);
	struct tm* tm = localtime(&timer);

	char buffer[42];
	strftime(buffer, 42, "%Y%m%D_%H%M%S", tm);
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts << ";"
			<< "total:" << _totalAmount << ";"
			<< "deposits:" << _totalNbDeposits << ";"
			<< "withdrawals:" << _totalNbWithdrawals << ";";
}

int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "amount:" << _amount << ";"
			<< "deposits:" << _nbDeposits << ";"
			<< "withdrawals:" << _nbWithdrawals << ";";
}

// int	Account::checkAmount(void) const
// {

// }

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";"
			<< "p_amount:" << _amount << ";"
			<< "deposit:" << deposit << ";"
			<< "amount:" << _amount + deposit << ";"
			<< "nb_deposits:" << _nbDeposits++ << ";";
}

// bool	Account::makeWithdrawal(int withdrawal)
// {
// 	_displayTimestamp();
// 	std::cout << " index:" << _accountIndex << ";"
// 			<< "p_amount:" << _amount << ";"
// 			<< "deposit:" << deposit << ";"
// 			<< "amount:" << _amount + deposit << ";"
// 			<< "nb_deposits:" << _nbDeposits++ << ";"
// }