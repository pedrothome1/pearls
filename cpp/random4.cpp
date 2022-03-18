#include <iostream>
#include <cstdlib>

#include "rand_uint.h"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    std::cerr << "Usage: program <filename>" << std::endl;
    exit(0);
  }

  const unsigned max_records = 4000000000U;

  std::string filename {argv[1]};
  Rand_uint rand_uint {0x0U, 0xFFFFFFFFU};

  for (int i = 0; i < max_records; ++i) {
    
  }
}