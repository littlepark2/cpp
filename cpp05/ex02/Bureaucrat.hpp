#pragma once

#include <iostream>
#include <ostream>

class AForm;

class Bureaucrat {

private:
  const std::string mName;
  int mGrade;
  Bureaucrat &operator=(const Bureaucrat &b);

public:
  Bureaucrat(void);
  Bureaucrat(const Bureaucrat &b);
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat(void);
  std::string getName(void) const;
  int getGrade(void) const;
  void gradeIncrement(void);
  void gradeDecrement(void);
  void signForm(AForm &f);
  void executeForm(AForm const &form);
  class GradeTooHighException : public std::exception {
  public:
    const char *what(void) const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what(void) const throw();
  };
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b);
