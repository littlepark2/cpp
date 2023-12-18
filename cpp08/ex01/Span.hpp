#pragma once

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

class Span {

private:
  std::vector<int> mVec;
  unsigned int mMaxSize;

public:
  Span();
  Span(const Span &span);
  Span(unsigned int N);
  ~Span();
  Span &operator=(const Span &span);
  std::vector<int> getVector() const;
  unsigned int getSize() const;
  void addNumber(int element);
  unsigned int shortestSpan() const;
  unsigned int longestSpan() const;
  void addRandomNumbers(unsigned int amount);
  void addNumberInRange(const unsigned int amount, const int value);
  class FullContainerException : public std::exception {
    const char *what() const throw();
  };
  class TooFewElementException : public std::exception {
    const char *what() const throw();
  };
};
