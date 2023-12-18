#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate() {
  srand(time(NULL));
  switch (rand() % 3) {
  case 0:
    return (new A());
  case 1:
    return (new B());
  case 2:
    return (new C());
  }
  return (NULL);
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p)) {
    std::cout << "Actual type of the object pointed to by p : A" << std::endl;
  } else if (dynamic_cast<B *>(p)) {
    std::cout << "Actual type of the object pointed to by p : B" << std::endl;
  } else if (dynamic_cast<C *>(p)) {
    std::cout << "Actual type of the object pointed to by p : C" << std::endl;
  }
}

void identify(Base &p) {
  try {
    A &ref = dynamic_cast<A &>(p);
    std::cout << "Actual type of the object pointed to by p : A" << std::endl;
    static_cast<void>(ref);
  } catch (std::bad_cast &bc) {
  }
  try {
    B &ref = dynamic_cast<B &>(p);
    std::cout << "Actual type of the object pointed to by p : B" << std::endl;
    static_cast<void>(ref);
  } catch (std::bad_cast &bc) {
  }
  try {
    C &ref = dynamic_cast<C &>(p);
    std::cout << "Actual type of the object pointed to by p : C" << std::endl;
    static_cast<void>(ref);
  } catch (std::bad_cast &bc) {
  }
}
