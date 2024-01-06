#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy)
{
	(void)copy;
	return (*this);
}
