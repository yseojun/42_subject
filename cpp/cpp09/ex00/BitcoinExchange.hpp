#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <iostream>
#include <map>
#include <sstream>

class BitcoinExchange {
private:
  std::map<std::string, double> _map;
  BitcoinExchange();
  void makeMap(const std::string &filename);

public:
  explicit BitcoinExchange(const std::string &filename);
  BitcoinExchange(const BitcoinExchange &copy);
  ~BitcoinExchange();
  BitcoinExchange &operator=(const BitcoinExchange &copy);

  /* getter */
  std::map<std::string, double> getMap() const;

  /* function */
  void inputFile(std::fstream &file);
  void printLine(std::string &line);
};

#endif