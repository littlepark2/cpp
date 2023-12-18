#include "Serializer.hpp"

#include <iostream>

int main() {
  Data *ptr = new (Data);
  uintptr_t serial = Serializer::serialize(ptr);
  std::cout << std::hex << serial << std::endl;

  Data *deserial = Serializer::deserialize(serial);
  std::cout << deserial << std::endl;
  delete (ptr);
  return (0);
}
