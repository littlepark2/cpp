#pragma once

#include <exception>
#include <iostream>

template <typename T> class Array {

private:
  T *mArray;
  unsigned int mSize;

public:
  Array();
  Array(unsigned int size);
  Array(const Array &array);
  ~Array();
  Array &operator=(const Array &array);
  T &operator[](const unsigned int idx) const;
  unsigned int size() const;
  class IndexOutOfBoundException : public std::exception {
    const char *what() const throw();
  };
};

#include "Array.tpp"
