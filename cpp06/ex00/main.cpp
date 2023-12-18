#include "ScalarConvert.hpp"
#include <cctype>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Error: one argument required" << std::endl;
    return (1);
  }

  std::string str(argv[1]);
  if (str.size() == 0) {
    std::cerr << "Error: empty string argument" << std::endl;
    return (1);
  }
  std::string::iterator iter = str.begin();
  std::string::reverse_iterator riter = str.rbegin();

  while (iter != str.end() && isspace(*iter))
    iter++;
  if (iter == str.end()) {
    std::cerr << "Error: string contains space only" << std::endl;
    return (1);
  }
  while (riter != str.rend() && isspace(*riter))
    riter++;
  std::string::iterator end = riter.base();
  std::string trim(iter, end);
  ScalarConvert::convert(trim);
}
