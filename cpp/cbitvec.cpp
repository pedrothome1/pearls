#include "cbitvec.h"

extern "C" {
#include <bitvec.h>
}

Bitvec::Bitvec(size_t capacity) :bit{bitvec_init(capacity)} {}

Bitvec::~Bitvec() {
  bitvec_free(bit);
}

void Bitvec::on(int i) {
  bitvec_on(bit, i);
}

void Bitvec::off(int i) {
  bitvec_off(bit, i);
}

int Bitvec::get(int i) const {
  return bitvec_get(bit, i);
}

size_t Bitvec::allocated_bytes() const {
  return bit->bytes_n;
}
