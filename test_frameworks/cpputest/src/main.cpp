#include <stdint.h>

#include <iostream>

#include "arithmetic/arithmetic.h"

int main(int argc, char** argv) {
  const uint32_t result = add(10, 20);
  std::cout << result << std::endl;
  return 0;
}