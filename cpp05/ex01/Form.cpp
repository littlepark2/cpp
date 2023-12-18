#include "Form.hpp"

std::ostream &operator<<(std::ostream &os, const Form &f) {
  os << "Name: " << f.getName() << ", ";
  os << "Sign grade: " << f.getSignGrade() << ", ";
  os << "Execute grade: " << f.getExecuteGrade() << ", ";
  os << std::boolalpha << "Signed: " << f.getSigned();
  return (os);
}

Form::Form(void)
    : mName(), mSigned(false), mSignGrade(150), mExecuteGrade(150) {}

Form::Form(const Form &f)
    : mName(f.mName), mSigned(f.mSigned), mSignGrade(f.mSignGrade),
      mExecuteGrade(f.mExecuteGrade) {}

Form::Form(const std::string &name, const int signGrade, const int executeGrade)
    : mName(name), mSigned(false), mSignGrade(signGrade),
      mExecuteGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw Form::GradeTooHighException();
  if (signGrade > 150 || executeGrade > 150)
    throw Form::GradeTooLowException();
}

Form::~Form(void) {}

Form &Form::operator=(const Form &f) {
  if (this == &f)
    return (*this);
  return (*this);
}

std::string Form::getName(void) const { return (mName); }

bool Form::getSigned(void) const { return (mSigned); }

int Form::getSignGrade(void) const { return (mSignGrade); }

int Form::getExecuteGrade(void) const { return (mExecuteGrade); }

void Form::beSigned(const Bureaucrat &b) {
  if (mSigned)
    throw Form::AlreadySignedException();
  else if (b.getGrade() > mSignGrade)
    throw Form::GradeTooLowException();
  else
    mSigned = true;
}

const char *Form::GradeTooHighException::what(void) const throw() {
  return ("grade is too high.");
}

const char *Form::GradeTooLowException::what(void) const throw() {
  return ("grade is too low.");
}

const char *Form::AlreadySignedException::what(void) const throw() {
  return ("already signed.");
}
