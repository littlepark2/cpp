#pragma once

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm {

private:
  const std::string mTarget;
  RobotomyRequestForm(void);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &form);

public:
  RobotomyRequestForm(const std::string &target);
  RobotomyRequestForm(const RobotomyRequestForm &form);
  ~RobotomyRequestForm(void);
  void execute(Bureaucrat const &executer) const;

  static AForm *clone(const std::string &target);
};
