#include "Bureaucrat.hpp"

int main(void) {
  try {
    Bureaucrat error("error", 0);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Bureaucrat high("high", 1);
    std::cout << high << std::endl;
    high.gradeDecrement();
    std::cout << high << std::endl;
    high.gradeIncrement();
    std::cout << high << std::endl;
    high.gradeIncrement();
    std::cout << high << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Bureaucrat low("low", 150);
    std::cout << low << std::endl;
    low.gradeIncrement();
    std::cout << low << std::endl;
    low.gradeDecrement();
    std::cout << low << std::endl;
    low.gradeDecrement();
    std::cout << low << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return (0);
}
