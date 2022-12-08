#include <iostream>
#include <utility>
#include "movable.hpp"
#include "uniqueptr.hpp"

UniquePtr<Movable> f(UniquePtr<Movable> p) {
  std::cout << "Inside f" << std::endl;
  return UniquePtr<Movable>(*p);
}

int main() {
  UniquePtr<Movable> pa = UniquePtr<Movable>();
  UniquePtr<Movable> pb = UniquePtr<Movable>(*pa);

  // pb = pa;  // forbidden: copy deleted

  // f(pb);  // forbidden: copy deleted

  UniquePtr<Movable> pc = f(std::move(pb));  // pb can no longer be used

  std::cout << "End of main()" << std::endl;

  return 0;
}
