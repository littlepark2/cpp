#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void)
    : AForm("presidential pardon", 25, 5), mTarget() {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("presidential pardon", 25, 5), mTarget(target) {}

PresidentialPardonForm::PresidentialPardonForm(
    const PresidentialPardonForm &form)
    : AForm(form), mTarget(form.mTarget) {}

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &form) {
  if (this == &form)
    return (*this);
  return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executer) const {
  if (executer.getGrade() > getExecuteGrade()) {
    throw AForm::GradeTooLowException();
  } else if (!getSigned()) {
    throw AForm::NotSignedException();
  } else
    std::cout << mTarget << " has been pardoned by Zaphod Beeblebrox."
              << std::endl;
}

AForm *PresidentialPardonForm::clone(const std::string &target) {
  return (new PresidentialPardonForm(target));
}
