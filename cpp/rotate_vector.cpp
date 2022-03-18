#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <utility>

using namespace std;

void rotate(vector<char>& v, int shift) {
  shift %= v.size();

  vector<pair<char, int>> negatives;

  for (int i = 0; i < v.size(); ++i) {
    int j = i - shift;

    if (j < 0) {
      negatives.push_back(make_pair(v[i], abs(j)));
    }
    else {
      v[j] = v[i];
    }
  }

  for (int i = 0; i < negatives.size(); ++i) {
    auto val = negatives[i].first;
    auto idx = negatives[i].second;

    v[v.size() - idx] = val;
  }
}

int main(int argc, char* argv[]) {
  int shift = 0;
  vector<char> v { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
  auto print_vector = [](vector<char> v) {
    for_each(v.begin(), v.end(), [](auto x) {
      cout << x;
    });
    cout << endl;
  };

  if (argc > 1) {
    shift = atoi(argv[1]);
  }
  
  print_vector(v);
  rotate(v, shift);
  print_vector(v);
}
