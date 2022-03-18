#ifndef CHAR_BUF_H
#define CHAR_BUF_H

#include <vector>

class Char_buf {
public:
  Char_buf();
  ~Char_buf();

  bool is_ignored(int c) const;
  void ignore(int c);
  void reset();
  void terminate();
  int append(int c);
  std::string to_string() const;
private:
  const std::size_t defaultcapacity = 255;
  char* buf;
  std::size_t size;
  std::size_t capacity;
  std::vector<int> ignored;
};

#endif // CHAR_BUF_H
