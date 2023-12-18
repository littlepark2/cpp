#include "Array.hpp"

template <typename T> Array<T>::Array() : mArray(new T[0]), mSize(0) {}

template <typename T>
Array<T>::Array(unsigned int size) : mArray(new T[size]), mSize(size) {}

template <typename T>
Array<T>::Array(const Array &array)
    : mArray(new T[array.size()]), mSize(array.size()) {
  for (unsigned int idx = 0; idx < array.size(); idx++)
    mArray[idx] = array[idx];
}

template <typename T> Array<T>::~Array() {
  std::cout << "Array desturctor called" << std::endl;
  delete[] mArray;
}

template <typename T> Array<T> &Array<T>::operator=(const Array<T> &array) {
  if (this == &array)
    return (*this);
  delete[] mArray;
  mArray = new T[array.size()];
  mSize = array.size();
  for (unsigned int idx = 0; idx < array.size(); idx++)
    mArray[idx] = array[idx];
}

template <typename T> T &Array<T>::operator[](const unsigned int idx) const {
  if (idx >= mSize)
    throw(Array::IndexOutOfBoundException());
  return (mArray[idx]);
}

template <typename T> unsigned int Array<T>::size() const { return (mSize); }

template <typename T>
const char *Array<T>::IndexOutOfBoundException::what() const throw() {
  return ("Error: index out of bound");
}
