#include <map>
#include "str_utils.h"

std::string escape(std::string& s) {
  std::string ret;
  std::string::iterator it;
  std::map<char, std::string> escapees { {'\0', "\\0"}, {'\n', "\\n"} };

  for (it = s.begin(); it != s.end(); ++it) {
    if (escapees.contains(*it)) {
      ret.append(escapees[*it]);
    }
    else {
      ret.push_back(*it);
    }
  }

  return ret;
}

std::string& string_to_upper(std::string& s) {
  std::for_each(s.begin(), s.end(), [](char& c) { c = std::toupper(c); });
  return s;
}
