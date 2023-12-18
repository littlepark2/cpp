#include "BitcoinExchange.hpp"

std::map<std::string, float> BitcoinExchange::mChart =
    BitcoinExchange::setChart();

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &ref) {
  static_cast<void>(ref);
}

BitcoinExchange::BitcoinExchange(const std::string &input) {
  mDatabase.open(input, std::ifstream::in);
  if (mDatabase.fail()) {
    std::cerr << "Error: open database failure" << std::endl;
    exit(EXIT_FAILURE);
  }
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &ref) {
  if (this == &ref)
    return (*this);
  return (*this);
}

std::map<std::string, float> BitcoinExchange::setChart() {
  std::ifstream chart;

  chart.open("data.csv", std::ifstream::in);
  if (chart.fail()) {
    std::cerr << "Error: data open failure" << std::endl;
    exit(EXIT_FAILURE);
  }
}
