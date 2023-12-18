#include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &ref) { static_cast<void>(ref); }

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &ref) {
  if (this == &ref)
    return (*this);
  return (*this);
}

uintptr_t Serializer::serialize(Data *ptr) {
  uintptr_t serial = reinterpret_cast<uintptr_t>(ptr);
  return (serial);
}

Data *Serializer::deserialize(uintptr_t raw) {
  Data *ptr = reinterpret_cast<Data *>(raw);
  return (ptr);
}
