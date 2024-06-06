#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  loadDatabase(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
  exchangeRates = other.exchangeRates;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
  if (this != &other) {
    exchangeRates = other.exchangeRates;
  }
  return *this;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream file(filename.c_str());
  std::string line, date;
  double rate;

  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    exit(EXIT_FAILURE);
  }

  if (!std::getline(file, line)) {
    std::cerr << "Error: file is empty." << std::endl;
    exit(EXIT_FAILURE);
  }

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    std::getline(ss, date, ',');
    date.erase(date.find_last_not_of(" \n\r\t") + 1);
    std::string rateStr;
    std::getline(ss, rateStr);
    rateStr.erase(0, rateStr.find_first_not_of(" \n\r\t"));
    try {
      rate = std::stod(rateStr);
      this->exchangeRates[date] = rate;
    } catch (const std::invalid_argument &e) {
      std::cerr << "Error: invalid rate value in line: " << line << std::endl;
    }
  }
}

void BitcoinExchange::processInput(const std::string &inputFile) {
  std::ifstream file(inputFile.c_str());
  std::string line, date, valueStr;

  if (!file.is_open()) {
    std::cerr << "Error: could not open file." << std::endl;
    return;
  }

  if (!std::getline(file, line)) {
    std::cerr << "Error: file is empty." << std::endl;
    exit(EXIT_FAILURE);
  }

  while (std::getline(file, line)) {
    std::istringstream ss(line);
    if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
      date.erase(date.find_last_not_of(" \n\r\t") + 1);
      valueStr.erase(0, valueStr.find_first_not_of(" \n\r\t"));
      if (isValidDate(date)) {
        char *end;
        double value = std::strtod(valueStr.c_str(), &end);
        if (*end != '\0') {
          std::cerr << "Error: bad input => " << line << std::endl;
        } else if (value < 0) {
          std::cerr << "Error: not a positive number." << std::endl;
        } else if (value > 1000) {
          std::cerr << "Error: too large a number." << std::endl;
        } else {
          double rate = getExchangeRate(date);
          std::cout << date << " => " << value << " = " << value * rate
                    << std::endl;
        }
      } else {
        std::cerr << "Error: bad input => " << line << std::endl;
      }
    } else {
      std::cerr << "Error: bad input => " << line << std::endl;
    }
  }
}

double BitcoinExchange::getExchangeRate(const std::string &date) {
  std::map<std::string, double>::iterator it =
      this->exchangeRates.lower_bound(date);
  if (it != this->exchangeRates.begin() &&
      (it == this->exchangeRates.end() || it->first != date)) {
    --it;
  }
  return it->second;
}

bool BitcoinExchange::isValidDate(const std::string &date) {
  return date.size() == 10 && date[4] == '-' && date[7] == '-';
}

bool BitcoinExchange::isValidValue(const std::string &value) {
  char *end;
  double val = std::strtod(value.c_str(), &end);
  return *end == '\0' && val >= 0 && val <= 1000;
}
