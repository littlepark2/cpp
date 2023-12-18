#include "easyfind.hpp"

int main() {
  std::vector<int> vec(10, 5);
  const std::deque<int> deq(10, 3);
  std::vector<int>::iterator iter_vec;
  std::deque<int>::const_iterator iter_deq;

  try {
    iter_vec = easyfind(vec, 5);
    iter_deq = easyfind(deq, 3);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << *iter_vec << std::endl;
  std::cout << *iter_deq << std::endl;
  return (0);
}
