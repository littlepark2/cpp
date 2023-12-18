#pragma once

#include <cstdint>

struct Data {
  int data;
};

class Serializer {

private:
  Serializer();
  Serializer(const Serializer &ref);
  ~Serializer();
  Serializer &operator=(const Serializer &ref);

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);
};
