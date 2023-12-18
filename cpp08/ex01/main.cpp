#include "Span.hpp"

int main() {
  Span sp = Span(100000);
  sp.addNumber(2147483647);
  sp.addRandomNumbers(9999);
  sp.addNumberInRange(50000, -1000000000);
  try {
    sp.addNumber(-10);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
