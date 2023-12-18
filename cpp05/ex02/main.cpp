#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  ShrubberyCreationForm tree("home");
  RobotomyRequestForm robo("human");
  PresidentialPardonForm pre("sungjpar");
  PresidentialPardonForm pre2(pre);
  Bureaucrat b("low", 145);
  Bureaucrat c("high", 1);

  std::cout << tree << std::endl;
  b.executeForm(tree);
  c.executeForm(tree);
  c.signForm(tree);
  c.executeForm(tree);
  b.signForm(robo);
  b.executeForm(robo);
  c.executeForm(robo);
  c.signForm(robo);
  c.executeForm(robo);
  c.signForm(pre);
  c.executeForm(pre);
  std::cout << pre2 << std::endl;
  return (0);
}
