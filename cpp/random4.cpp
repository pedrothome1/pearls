#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <stdexcept>
#include <string_view>
#include <vector>
#include <map>

#include <cstdlib>
#include <cctype>

#include "char_buf.h"
#include "rand_uint.h"
#include "str_utils.h"

int main(int argc, char* argv[]) {
  if (argc <= 1) {
    std::cerr << "Usage: program <filename>" << std::endl;
    exit(0);
  }

  Char_buf buf {};
  std::string answer;
  std::string filename {argv[1]};
  Rand_uint rand_int {0x0U, 0xFFFFFFFFU};

  buf.ignore('\n');

  while (true) {
    std::cout << rand_int() << std::endl;
    std::cout << "Do you want to continue? [Y/n] ";
    
    buf.reset();
    while (!std::cin.eof() && buf.append(std::cin.get()) != '\n')
      ;

    answer = buf.to_string();
    string_to_upper(answer);

    if (answer == "N")
      break;
  }
}