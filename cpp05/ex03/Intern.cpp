#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &intern) { (void)intern; }

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &intern) {
  if (this == &intern)
    return (*this);
  return (*this);
}

AForm *Intern::selectForm(const std::string &name,
                          const std::string &target) const {
  const std::string formList[3] = {"shrubbery creation", "robotomy request",
                                   "presidential pardon"};
  AForm *(*func[3])(const std::string &) = {&ShrubberyCreationForm::clone,
                                            &RobotomyRequestForm::clone,
                                            &PresidentialPardonForm::clone};
  for (int idx = 0; idx < 3; idx++)
    if (name == formList[idx])
      return (func[idx](target));
  throw Intern::NoExistFormException();
  return (NULL);
}

AForm *Intern::makeForm(const std::string &name,
                        const std::string &target) const {
  AForm *form;

  try {
    form = selectForm(name, target);
    std::cout << "Intern creates " << name << std::endl;
    return (form);
  } catch (std::exception &e) {
    std::cout << "Fail to create form. " << name << e.what() << std::endl;
    return (NULL);
  }
}

const char *Intern::NoExistFormException::what() const throw() {
  return (" does not exist.");
}
