#pragma once

#include <deque>
#include <exception>
#include <iostream>
#include <list>
#include <stdexcept>
#include <vector>

template <typename T> typename T::iterator easyfind(T &c, const int value) {
  typename T::iterator iter = std::find(c.begin(), c.end(), value);
  if (iter == c.end())
    throw std::runtime_error("cannot find value");
  return (iter);
}

template <typename T>
typename T::const_iterator easyfind(const T &c, const int value) {
  typename T::const_iterator iter = std::find(c.begin(), c.end(), value);
  if (iter == c.end())
    throw std::runtime_error("cannot find value");
  return (iter);
}
