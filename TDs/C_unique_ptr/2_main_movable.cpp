#include <iostream>
#include <utility>
#include "movable.hpp"

Movable f(Movable m) {
  std::cout << "Inside f" << std::endl;
  return m;
}

int main() {
  Movable ma;
  Movable mb = ma;

  mb = std::move(ma);  // ma can no longer be used

  f(mb);

  std::cout << "Between calls" << std::endl;

  Movable mc = f(std::move(mb));  // m2 can no longer be used

  std::cout << "End of main()" << std::endl;

  return 0;
}
