#include "rand_uint.h"

Rand_uint::Rand_uint(unsigned lo, unsigned hi)
  :distribution(lo, hi) {}

unsigned Rand_uint::operator()() {
  return distribution(generator);
}
