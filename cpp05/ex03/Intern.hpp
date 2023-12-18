#pragma once

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

private:
public:
  Intern();
  Intern(const Intern &intern);
  ~Intern();
  Intern &operator=(const Intern &intern);
  AForm *selectForm(const std::string &name, const std::string &target) const;
  AForm *makeForm(const std::string &name, const std::string &target) const;
  class NoExistFormException : public std::exception {
    const char *what() const throw();
  };
};
