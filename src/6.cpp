#include <iostream>

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=6"
            << "\n\nSum square difference" << std::endl;
  std::cout << "====================================" << std::endl;
  // WARNING: the definition of natural numbers is wrong.
  const int N = 100;
  long long diff = 0;
  for (int i = 1; i <= N; ++i) {
    for (int j = i + 1; j <= N; ++j) {
      diff += i * j;
    }
  }
  diff *= 2;
  std::cout << "The difference between the sum of the squares of the first "
            << N << " natural numbers and the square of the sum: " << diff
            << std::endl;
  return 0;
}