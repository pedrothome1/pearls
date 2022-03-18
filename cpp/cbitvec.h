#ifndef CBITVEC_H
#define CBITVEC_H

#include <cstdlib>

struct bitvec;

class Bitvec {
public:
  explicit Bitvec(size_t capacity);
  ~Bitvec();

  void on(int i);
  void off(int i);
  int get(int i) const;
  size_t allocated_bytes() const;
private:
  bitvec* bit;
};

#endif // CBITVEC_H
