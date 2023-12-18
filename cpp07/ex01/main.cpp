#include "iter.hpp"

int main() {
  int arr1[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::string arr2[10] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j"};

  iter(arr1, sizeof(arr1) / sizeof(*arr1), print);
  iter(arr2, sizeof(arr2) / sizeof(*arr2), print);
  iter(arr1, sizeof(arr1) / sizeof(*arr1), square);
  iter(arr1, sizeof(arr1) / sizeof(*arr1), print);
}
