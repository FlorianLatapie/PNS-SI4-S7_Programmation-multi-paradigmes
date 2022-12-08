#include <iostream>
#include "copiable.hpp"

Copiable f(Copiable c) {
  std::cout << "Inside f" << std::endl;
  return c;
}

int main() {
  Copiable ca;
  Copiable cb = ca;

  cb = ca;

  f(cb);

  std::cout << "Between calls" << std::endl;

  Copiable cc = f(cb);

  std::cout << "End of main()" << std::endl;

  return 0;
}
