#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class AForm {

private:
  const std::string mName;
  bool mSigned;
  const int mSignGrade;
  const int mExecuteGrade;
  AForm &operator=(const AForm &f);

public:
  AForm(void);
  AForm(const AForm &f);
  AForm(const std::string &name, const int signGrade, const int executeGrade);
  virtual ~AForm(void);
  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecuteGrade(void) const;
  void beSigned(const Bureaucrat &b);
  virtual void execute(Bureaucrat const &executer) const = 0;
  class GradeTooHighException : public std::exception {
    const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
    const char *what(void) const throw();
  };
  class AlreadySignedException : public std::exception {
  public:
    const char *what(void) const throw();
  };
  class NotSignedException : public std::exception {
    const char *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const AForm &f);
