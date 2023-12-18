#pragma once

#include <cctype>
#include <iomanip>
#include <iostream>
#include <limits>
#include <string>

enum Type { NOTANUMBER, CASECHAR, CASEVALID, CASEEXCEPT };

class ScalarConvert {

private:
  static const std::string mExcept[7];
  ScalarConvert();
  ScalarConvert(const ScalarConvert &);
  ~ScalarConvert();
  ScalarConvert &operator=(const ScalarConvert &);

public:
  static void convert(const std::string &input);
  static int type(const std::string &input);
  static int typeException(const std::string &input);
  static void caseInvalid();
  static void caseChar(const std::string &input);
  static void caseValid(const std::string &input);
  static void caseExcept(const std::string &input);
};
