#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
  std::string mTarget;
  PresidentialPardonForm(void);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &form);

public:
  PresidentialPardonForm(const std::string &target);
  PresidentialPardonForm(const PresidentialPardonForm &form);
  ~PresidentialPardonForm(void);
  void execute(Bureaucrat const &executer) const;
};
