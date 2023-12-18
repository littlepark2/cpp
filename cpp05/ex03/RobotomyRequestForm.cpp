#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void)
    : AForm("robotomy request", 72, 45), mTarget() {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("robotomy request", 72, 45), mTarget(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
    : AForm(form), mTarget(form.mTarget) {}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &form) {
  if (this == &form)
    return (*this);
  return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executer) const {
  if (executer.getGrade() > getExecuteGrade()) {
    throw AForm::GradeTooLowException();
  } else if (!getSigned()) {
    throw AForm::NotSignedException();
  } else {
    srand(time(NULL));
    if (rand() % 2)
      std::cout << mTarget << " successfully robotomized." << std::endl;
    else
      std::cout << mTarget << " robotomization fail..." << std::endl;
  }
}

AForm *RobotomyRequestForm::clone(const std::string &target) {
  return (new RobotomyRequestForm(target));
}
