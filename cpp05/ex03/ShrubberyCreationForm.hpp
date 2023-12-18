#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm {

private:
  std::string mTarget;
  ShrubberyCreationForm(void);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &form);

public:
  ShrubberyCreationForm(const ShrubberyCreationForm &form);
  ShrubberyCreationForm(const std::string &target);
  ~ShrubberyCreationForm(void);
  void execute(Bureaucrat const &executer) const;
  class FileOpenFailureException : public std::exception {
    const char *what(void) const throw();
  };

  static AForm *clone(const std::string &target);
};
