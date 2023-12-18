#include "Bureaucrat.hpp"
#include "AForm.hpp"

std::ostream &operator<<(std::ostream &os, const Bureaucrat &b) {
  os << b.getName() << ", bureaucrat grade " << b.getGrade();
  return (os);
}

Bureaucrat::Bureaucrat(void) : mName(), mGrade(1) {}

Bureaucrat::Bureaucrat(const Bureaucrat &b)
    : mName(b.mName), mGrade(b.mGrade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : mName(name) {
  if (grade < 1)
    throw Bureaucrat::GradeTooHighException();
  else if (grade > 150)
    throw Bureaucrat::GradeTooLowException();
  mGrade = grade;
}

Bureaucrat::~Bureaucrat(void) {
  std::cout << "Bureaucrat destructor called." << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &b) {
  if (this == &b)
    return (*this);
  return (*this);
}

std::string Bureaucrat::getName(void) const { return (mName); }

int Bureaucrat::getGrade(void) const { return (mGrade); }

void Bureaucrat::gradeIncrement(void) {
  if (mGrade == 1)
    throw Bureaucrat::GradeTooHighException();
  --mGrade;
}

void Bureaucrat::gradeDecrement(void) {
  if (mGrade == 150)
    throw Bureaucrat::GradeTooLowException();
  ++mGrade;
}

void Bureaucrat::signForm(AForm &f) {
  try {
    f.beSigned(*this);
    std::cout << mName << " signed " << f.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << mName << " couldn't sign " << f.getName() << " because "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) {
  try {
    std::cout << mName << " execute " << form.getName() << std::endl;
    form.execute(*this);
  } catch (std::exception &e) {
    std::cout << mName << " couldn't execute " << form.getName() << " because "
              << e.what() << std::endl;
  }
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw() {
  return ("Grade is too high.");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw() {
  return ("Grade is too low.");
}
