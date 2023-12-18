#include "AForm.hpp"

std::ostream &operator<<(std::ostream &os, const AForm &f) {
  os << "Name: " << f.getName() << ", ";
  os << "Sign grade: " << f.getSignGrade() << ", ";
  os << "Execute grade: " << f.getExecuteGrade() << ", ";
  os << std::boolalpha << "Signed: " << f.getSigned();
  return (os);
}

AForm::AForm(void)
    : mName(), mSigned(false), mSignGrade(150), mExecuteGrade(150) {}

AForm::AForm(const AForm &f)
    : mName(f.mName), mSigned(f.mSigned), mSignGrade(f.mSignGrade),
      mExecuteGrade(f.mExecuteGrade) {}

AForm::AForm(const std::string &name, const int signGrade,
             const int executeGrade)
    : mName(name), mSigned(false), mSignGrade(signGrade),
      mExecuteGrade(executeGrade) {
  if (signGrade < 1 || executeGrade < 1)
    throw AForm::GradeTooHighException();
  if (signGrade > 150 || executeGrade > 150)
    throw AForm::GradeTooLowException();
}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &f) {
  if (this == &f)
    return (*this);
  return (*this);
}

std::string AForm::getName(void) const { return (mName); }

bool AForm::getSigned(void) const { return (mSigned); }

int AForm::getSignGrade(void) const { return (mSignGrade); }

int AForm::getExecuteGrade(void) const { return (mExecuteGrade); }

void AForm::beSigned(const Bureaucrat &b) {
  if (mSigned)
    throw AForm::AlreadySignedException();
  else if (b.getGrade() > mSignGrade)
    throw AForm::GradeTooLowException();
  else
    mSigned = true;
}

const char *AForm::GradeTooHighException::what(void) const throw() {
  return ("grade is too high.");
}

const char *AForm::GradeTooLowException::what(void) const throw() {
  return ("grade is too low.");
}

const char *AForm::AlreadySignedException::what(void) const throw() {
  return ("already signed.");
}

const char *AForm::NotSignedException::what(void) const throw() {
  return ("form does not signed.");
}
