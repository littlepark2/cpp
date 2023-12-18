#include "ScalarConvert.hpp"

const std::string ScalarConvert::mExcept[7] = {
    "-inf", "-infinity", "nan", "+inf", "+infinity", "inf", "infinity"};

ScalarConvert::ScalarConvert() {}

ScalarConvert::ScalarConvert(const ScalarConvert &ref) {
  if (this == &ref)
    return;
  return;
}

ScalarConvert::~ScalarConvert() {}

ScalarConvert &ScalarConvert::operator=(const ScalarConvert &ref) {
  if (this == &ref)
    return (*this);
  return (*this);
}

void ScalarConvert::convert(const std::string &input) {
  switch (type(input)) {
  case 0:
    caseInvalid();
    break;
  case 1:
    caseChar(input);
    break;
  case 2:
    caseValid(input);
    break;
  case 3:
    std::string copy = input;
    for (int idx = 0; idx < static_cast<int>(copy.size()); idx++)
      copy[idx] = tolower(copy[idx]);
    caseExcept(copy);
    break;
  }
}

int ScalarConvert::typeException(const std::string &input) {
  std::string copy = input;

  for (int idx = 0; idx < static_cast<int>(copy.size()); idx++)
    copy[idx] = tolower(copy[idx]);
  for (int idx = 0; idx < 7; idx++)
    if (copy == mExcept[idx])
      return (1);
  return (0);
}

int ScalarConvert::type(const std::string &input) {
  int dotCount = 0;
  int floatCount = 0;

  if (typeException(input))
    return (CASEEXCEPT);
  if (input.size() == 1 && !isdigit(*input.begin()) &&
      *input.begin() >= std::numeric_limits<char>::min() &&
      *input.begin() <= std::numeric_limits<char>::max())
    return (CASECHAR);
  std::string::const_iterator iter = input.begin();
  if (iter != input.end() && (*iter == '+' || *iter == '-'))
    ++iter;
  while (iter != input.end()) {
    if (*iter == 'f')
      floatCount++;
    if (*iter == '.')
      dotCount++;
    if (!isdigit(*iter) && *iter != '.' && *iter != 'f')
      return (NOTANUMBER);
    ++iter;
  }
  if (dotCount > 1 || floatCount > 1)
    return (NOTANUMBER);
  if (floatCount == 1 && *(input.end() - 1) != 'f')
    return (NOTANUMBER);
  return (CASEVALID);
}

void ScalarConvert::caseInvalid() {
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: impossible" << std::endl;
  std::cout << "double: impossible" << std::endl;
}

void ScalarConvert::caseChar(const std::string &input) {
  char c = *input.begin();

  if (isprint(c))
    std::cout << "char: " << c << std::endl;
  else
    std::cout << "char: Non displayable" << std::endl;
  std::cout << "int: " << static_cast<int>(c) << std::endl;
  std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
  std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void ScalarConvert::caseValid(const std::string &input) {
  double convert = atof(&input[0]);

  if (convert >= static_cast<double>(std::numeric_limits<char>::min()) &&
      convert <= static_cast<double>(std::numeric_limits<char>::max())) {
    char convertChar = static_cast<char>(convert);
    if (isprint(convertChar))
      std::cout << "char: " << convertChar << std::endl;
    else
      std::cout << "char: Non displayable" << std::endl;
  } else
    std::cout << "char: overflow" << std::endl;

  if (convert >= static_cast<double>(std::numeric_limits<int>::min()) &&
      convert <= static_cast<double>(std::numeric_limits<int>::max()))
    std::cout << "int: " << static_cast<int>(convert) << std::endl;
  else
    std::cout << "int: overflow" << std::endl;

  if (convert >= -std::numeric_limits<float>::max() &&
      convert <= std::numeric_limits<float>::max()) {
    if (floor(convert) == convert)
      std::cout << std::fixed << std::setprecision(0)
                << "float: " << static_cast<float>(convert) << ".0f"
                << std::endl;
    else
      std::cout << "float: " << static_cast<float>(convert) << "f" << std::endl;
  } else
    std::cout << "float: overflow" << std::endl;

  if (convert >= -std::numeric_limits<double>::max() &&
      convert <= std::numeric_limits<double>::max()) {
    if (floor(convert) == convert)
      std::cout << std::fixed << std::setprecision(0) << "double: " << convert
                << ".0" << std::endl;
    else
      std::cout << "double: " << convert << std::endl;
  } else
    std::cout << "double: overflow" << std::endl;
}

void ScalarConvert::caseExcept(const std::string &input) {
  std::string out;
  if (*input.begin() == '+' || *input.begin() == '-')
    out = input.substr(0, 4);
  else
    out = input.substr(0, 3);
  std::cout << "char: impossible" << std::endl;
  std::cout << "int: impossible" << std::endl;
  std::cout << "float: " << out << "f" << std::endl;
  std::cout << "double: " << out << std::endl;
}
