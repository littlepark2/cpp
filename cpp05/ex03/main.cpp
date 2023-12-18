#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  Intern someRandomIntern;
  AForm *rrf;
  AForm *scf;
  AForm *ppf;
  AForm *none;
  Bureaucrat high("boss", 1);

  rrf = someRandomIntern.makeForm("robotomy request", "Bender");
  scf = someRandomIntern.makeForm("shrubbery creation", "Forest");
  ppf = someRandomIntern.makeForm("presidential pardon", "Bob");
  none = someRandomIntern.makeForm("none", "aa");
  std::cout << *rrf << std::endl;
  std::cout << *scf << std::endl;
  std::cout << *ppf << std::endl;
  high.signForm(*rrf);
  high.signForm(*scf);
  high.signForm(*ppf);
  high.executeForm(*rrf);
  high.executeForm(*scf);
  high.executeForm(*ppf);
  delete rrf;
  delete scf;
  delete ppf;
  delete none;
  return (0);
}
