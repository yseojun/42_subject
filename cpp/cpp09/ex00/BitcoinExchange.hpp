#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>

class BitcoinExchange
{
	private:
		std::map<std::string, double> _map;
		BitcoinExchange();

	public:
		explicit BitcoinExchange(const std::string& filename);
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange& copy);

		std::map<std::string, double> getMap() const;	
};

#endif