#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void) {
  try {
    Form error("error", 0, 0);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Form error("error", 200, 200);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Bureaucrat high("high", 1);
    Form form("form", 100, 100);
    std::cout << high << std::endl;
    std::cout << form << std::endl;
    high.signForm(form);
    high.signForm(form);
    std::cout << form << std::endl;
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  try {
    Bureaucrat low("low", 150);
    Form form("form", 100, 100);
    std::cout << low << std::endl;
    std::cout << form << std::endl;
    form.beSigned(low);
  } catch (std::exception &e) {
    std::cerr << "Error: " << e.what() << std::endl;
  }
  return (0);
}
