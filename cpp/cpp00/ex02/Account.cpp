#include "Account.hpp"

Account::Account( int initial_deposit ) {
}

int	Account::getNbAccounts( void ) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void ) {
	return (Account::_totalAmount);
}

int Account::getNbDeposits( void ) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void ) {
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ) {
}

void	Account::makeDeposit( int deposit ) {
}

bool	Account::makeWithdrawal( int withdrawal ) {
}

int		Account::checkAmount( void ) const {
	return (0);
}

void	Account::displayStatus( void ) const {
}

void	Account::_displayTimestamp( void ) {
}
