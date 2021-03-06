#include <iostream>

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=2"
            << "\n\nEven Fibonacci numbers" << std::endl;
  std::cout << "====================================" << std::endl;
  long long sum = 0;
  int f0 = 1, f1 = 2;
  const int N = 4000000;
  while (f1 <= N) {
    if (not(f1 & 1)) {  // even
      sum += f1;
    }
    f0 += f1;
    std::swap(f0, f1);
  }
  std::cout << "the sum of the even-valued terms: " << sum << std::endl;
  return 0;
}