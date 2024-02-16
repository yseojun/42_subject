#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &filename) {
  makeMap(filename);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) { *this = copy; }

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &copy) {
  (void)copy;
  return (*this);
}

/* function */
void BitcoinExchange::makeMap(const std::string &filename) {
  std::ifstream file(filename);
  std::string line;
  std::string key;
  double value;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      std::stringstream ss(line);
      ss >> key >> value;
      _map[key] = value;
    }
    file.close();
  }
}

void BitcoinExchange::inputFile(std::fstream &file) {
  std::string line;

  if (file.is_open()) {
    while (std::getline(file, line)) {
      try {
        printLine(line);
      } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
      }
      file.close();
    }
  }
}

void BitcoinExchange::printLine(std::string &line) {
  std::stringstream ss(line);
  std::string date;
  double value;

  ss >> date >> value;
  // bad input 예를들면 value가 없는 경우
  if (ss.fail()) {
    throw std::invalid_argument("Error: Bad input. => " + line);
  }
  if (!isValidDate(date))
    throw std::invalid_argument("Error: invalid date.");
  if (!isValidValue(std::to_string(value)))
    throw std::invalid_argument("Error: invalid value.");

  // map에 날짜보다 이전 날짜 데이터가 있는 경우 그 데이터를 이용
  if (_map.lower_bound(date) != _map.begin()) {
    std::map<std::string, double>::iterator it = _map.lower_bound(date);
    std::cout << it->first << " " << it->second << std::endl;
  } else {
    std::cout << "No data" << std::endl;
  }
}

bool isValidDate(const std::string &date) {
  if (date.size() != 10)
    return false;
  if (date[4] != '-' || date[7] != '-')
    return false;
  for (size_t i = 0; i < date.size(); i++) {
    if (i == 4 || i == 7)
      continue;
    if (date[i] < '0' || date[i] > '9')
      return false;
  }
  return true;
}

/* 양수, 0~1000 */
/* 음수x*/
bool isValidValue(const std::string &value) {
  if (value[0] == '-')
    return false;
  if (value.size() > 5)
    return false;
  for (size_t i = 0; i < value.size(); i++) {
    if (value[i] < '0' || value[i] > '9')
      return false;
  }
  int num = std::stoi(value);
  if (num < 0 || num > 1000)
    return false;
  return true;
}