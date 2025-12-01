
#include "Account.hpp"
#include <iostream>
#include <ctime> // i m use to time

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit )
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts++;
	_totalAmount += _amount;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";created" << std::endl;

}

Account::~Account(void) 
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";closed" << std::endl;
};

int Account::getNbAccounts(void) { return (_nbAccounts); }

int	Account::getTotalAmount( void ) { return (_totalAmount); }

int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }

int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

int		Account::checkAmount( void ) const { return (_amount); }

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();

	_totalNbDeposits++;

	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";deposit:" << deposit;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_deposits:" << _nbDeposits << std::endl;
}
//[19920104_091532] index:6;p_amount:763;withdrawal:657;amount:106;nb_withdrawals:1
bool	Account::makeWithdrawal( int withdrawal )
{
		_displayTimestamp();

	
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << checkAmount();
	std::cout << ";withdrawal:";
	if (withdrawal > checkAmount())
	{
		std::cout << "refused"<< std::endl;
		return (false);
	}
	std::cout << withdrawal;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	_totalNbWithdrawals++;

	return true;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << checkAmount();
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now;
	std::time(&now);
	std::tm *localtime = std::localtime(&now);
	std::cout << "[" << (localtime->tm_year + 1900);
	if ((localtime->tm_mon + 1) < 10)
		std::cout << "0";
	std::cout << (localtime->tm_mon + 1);
	if (localtime->tm_mday < 10)
		std::cout << "0";
	std::cout << localtime->tm_mday << "_";
	if (localtime->tm_hour < 10)
		std::cout << "0";
	std::cout << localtime->tm_hour;
	if (localtime->tm_min < 10)
		std::cout << "0";
	std::cout << localtime->tm_min;
	if (localtime->tm_sec < 10)
		std::cout << "0";
	std::cout << localtime->tm_sec << "]";
}

// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << " accounts:" << getNbAccounts();
	std::cout << ";total:" << getTotalAmount();
	std::cout << ";deposits:" << getNbDeposits();
	std::cout << ";withdrawals:" << getNbWithdrawals() << std::endl;
}