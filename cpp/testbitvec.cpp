#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
#include "cbitvec.h"

void print_bitvec(Bitvec& bv) {
  for (int i = 0; i < bv.allocated_bytes()*8; ++i) {
    if (i>0 && i % 8 == 0) std::cout << ' ';
    std::cout << bv.get(i);
  }
  std::cout << '\n';
}

int main() {
  Bitvec bit {10};
  std::vector<int> positions {1,4,7};
  std::vector<int>::iterator vec_it;

  std::for_each(positions.begin(), positions.end(), [&bit](auto pos){
    bit.on(pos);
  });

  print_bitvec(bit);

  for (int i = 0; i < bit.allocated_bytes() * 8; ++i) {
    vec_it = std::find(positions.begin(), positions.end(), i);

    if (vec_it != positions.end()) {
      if (bit.get(i) != 1) {
        throw std::runtime_error("The bit should have been set.");
      }
    }
  }
}
