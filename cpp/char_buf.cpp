#include <algorithm>
#include "char_buf.h"

Char_buf::Char_buf()
  :buf{new char[defaultcapacity]},
  size{0},
  capacity{defaultcapacity},
  ignored{} {}

Char_buf::~Char_buf() {
  delete[] buf;
}

bool Char_buf::is_ignored(int c) const {
  return std::find(ignored.begin(), ignored.end(), c) != ignored.end();
}

void Char_buf::ignore(int c) { ignored.push_back(c); }
void Char_buf::reset() { size = 0; }
void Char_buf::terminate() { buf[size] = '\0'; }

int Char_buf::append(int c) {
  if (size == capacity-1)
    throw std::length_error("The buffer is full.");

  if (is_ignored(c))
    return c;

  buf[size++] = c;

  if (size == capacity-1)
    terminate();

  return c;
}

std::string Char_buf::to_string() const {
  return std::string {buf};
}
