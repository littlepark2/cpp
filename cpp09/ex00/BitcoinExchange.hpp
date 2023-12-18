#pragma once

#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <string>

class BitcoinExchange {

private:
  static std::map<std::string, float> mChart;
  std::ifstream mDatabase;
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &ref);
  BitcoinExchange &operator=(const BitcoinExchange &ref);
  static int dateValidation(std::string &date);
  static int valueValidation(std::string &value);

public:
  BitcoinExchange(const std::string &input);
  ~BitcoinExchange();
  void calculateExchangeRate(const std::string &date) const;
  class WrongDateException : public std::exception {
    const char *what() const throw();
  };
  class InvalidValueException : public std::exception {
    const char *what() const throw();
  };

  static std::map<std::string, float> setChart();
};
