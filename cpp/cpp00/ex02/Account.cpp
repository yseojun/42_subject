#include "Account.hpp"
#include <iostream>

int	Account::_nbAccounts;
int	Account::_totalAmount;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account( void ){
	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "created" << std::endl;
}

Account::Account( int initial_deposit ) {
	_displayTimestamp();
	this->_accountIndex = _nbAccounts++;
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << initial_deposit << ";"
		<< "created" << std::endl;
	this->_amount = initial_deposit;
	_totalAmount += this->_amount;
}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		"amount:" << getTotalAmount() << ";"
		"closed" << std::endl;
}

void	Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		"p_amount:" << this->_amount << ";"
		"deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";"
		<< "nb_deposits:" << ++this->_nbDeposits << std::endl;
	_totalNbDeposits++;
	_totalAmount += deposit;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";
	if (this->_amount > withdrawal)
	{
		this->_amount -= withdrawal;
		std::cout << "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
		_totalNbWithdrawals++;
		_totalAmount -= withdrawal;
		return (1);
	}
	else
		std::cout << "widthdrawal:refused" << std::endl ;
	return (0);
}

int		Account::checkAmount( void ) const {
	return 0;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ) {
	std::time_t	now;
	char		buffer[80];

	std::strftime(buffer, 80, "[%Y%m%d_%H%M%S]", std::localtime(&now));
	std::cout << buffer;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawls:" << getNbWithdrawals() << ";" << std::endl;
}