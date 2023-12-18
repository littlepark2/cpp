#pragma once

#include <iostream>

template <typename T> void iter(T *addr, int len, void (*func)(T &)) {
  for (int idx = 0; idx < len; idx++)
    func(addr[idx]);
}

template <typename T> void print(const T arg) { std::cout << arg << std::endl; }

template <typename T> void square(T &num) { num = num * num; }

template <typename T> void square(const T &num) {
  *(const_cast<T *>(&num)) = num * num;
}
