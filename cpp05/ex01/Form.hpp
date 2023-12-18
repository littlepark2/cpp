#pragma once

#include "Bureaucrat.hpp"
#include <iostream>
#include <ostream>

class Form {

private:
  const std::string mName;
  bool mSigned;
  const int mSignGrade;
  const int mExecuteGrade;
  Form &operator=(const Form &f);

public:
  Form(void);
  Form(const Form &f);
  Form(const std::string &name, const int signGrade, const int executeGrade);
  ~Form(void);
  std::string getName(void) const;
  bool getSigned(void) const;
  int getSignGrade(void) const;
  int getExecuteGrade(void) const;
  void beSigned(const Bureaucrat &b);
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
};

std::ostream &operator<<(std::ostream &os, const Form &f);
