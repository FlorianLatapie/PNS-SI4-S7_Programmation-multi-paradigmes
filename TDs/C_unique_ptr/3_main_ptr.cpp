#include <iostream>
#include "movable.hpp"

Movable *f(Movable *p) {
  std::cout << "Inside f" << std::endl;
  return new Movable(*p);
}

int main() {
  Movable *pa = new Movable();
  Movable *pb = new Movable(*pa);

  pb = pa;  // address copy: the memory previously pointed to by pb is definitively lost

  f(pb);

  std::cout << "End of main()" << std::endl;

  return 0;
}
