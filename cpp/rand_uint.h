#ifndef RAND_UINT_H
#define RAND_UINT_H

#include <random>

class Rand_uint {
public:
  Rand_uint(unsigned lo, unsigned hi);
  unsigned operator()();
private:
  std::default_random_engine generator;
  std::uniform_int_distribution<unsigned> distribution;
};

#endif