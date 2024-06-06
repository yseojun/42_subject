#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange(const std::string &filename);
  BitcoinExchange(const BitcoinExchange &other);
  ~BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &other);

  void processInput(const std::string &inputFile);

private:
  BitcoinExchange();

  std::map<std::string, double> exchangeRates;

  void loadDatabase(const std::string &filename);
  double getExchangeRate(const std::string &date);
  bool isValidDate(const std::string &date);
  bool isValidValue(const std::string &value);
};

#endif