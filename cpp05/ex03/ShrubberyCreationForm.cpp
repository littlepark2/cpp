#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void)
    : AForm("shrubbery creation", 145, 137), mTarget("") {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
    : AForm(form), mTarget(form.mTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("shrubbery creation", 145, 137), mTarget(target) {}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form) {
  if (this == &form)
    return (*this);
  return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executer) const {
  std::ofstream outFile;
  std::string asciiTree = "          &&& &&  & &&\n"
                          "      && &\\/&\\|& ()|/ @, &&\n"
                          "      &\\/(/&/&||/& /_/)_&/_&\n"
                          "   &() &\\/&|()|/&\\/ '%\" & ()\n"
                          "  &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
                          "&&   && & &| &| /& & % ()& /&&\n"
                          " ()&_---()&\\&\\|&&-&&--%---()~\n"
                          "     &&     \\|||\n"
                          "             |||\n"
                          "             |||\n"
                          "             |||\n"
                          "       , -=-~  .-^- _\n";

  if (executer.getGrade() > getExecuteGrade()) {
    throw AForm::GradeTooLowException();
  } else if (!getSigned()) {
    throw AForm::NotSignedException();
  } else {
    outFile.open(mTarget + "_shrubbery", std::ios_base::trunc);
    if (!outFile.is_open())
      throw ShrubberyCreationForm::FileOpenFailureException();
    outFile << asciiTree;
    outFile.close();
  }
}

const char *ShrubberyCreationForm::FileOpenFailureException::what(void) const
    throw() {
  return ("file creation failure.");
}

AForm *ShrubberyCreationForm::clone(const std::string &target) {
  return (new ShrubberyCreationForm(target));
}
