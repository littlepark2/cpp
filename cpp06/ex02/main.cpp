#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <iostream>

int main() {
  Base *a = new A();
  Base *b = new B();
  Base *c = new C();
  Base *ptr = generate();
  Base &ref = *ptr;

  std::cout << "identify test" << std::endl;
  identify(a);
  identify(b);
  identify(c);

  std::cout << "random test" << std::endl;
  identify(ptr);
  identify(ref);

  delete a;
  delete b;
  delete c;
  delete ptr;
  return (0);
}
