#include <math.h>

#include <iostream>
#include <vector>

int main() {
  const int N = 1000;
  std::vector<bool> is_multipler_3or5(N, false);
  int v = 0;
  for (int i = 1; v < N; ++i) {
    v = 3 * i;
    is_multipler_3or5[v] = true;
  }
  v = 0;
  for (int i = 1; v < N; ++i) {
    v = 5 * i;
    is_multipler_3or5[v] = true;
  }
  int sum = 0;
  for (int i = 0; i < N; ++i) {
    if (is_multipler_3or5[i]) {
      sum += i;
    }
  }
  std::cout << "The sum of all the multiples of 3 or 5 below 1000: " << sum
            << std::endl;
  return 0;
}