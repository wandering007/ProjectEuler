#include <iostream>
#include <vector>

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=5"
            << "\n\nSmallest multiple" << std::endl;
  std::cout << "====================================" << std::endl;
  const int N = 20;
  std::vector<bool> is_prime(N + 1, true);
  long long smallest_multiple = 1;
  for (int i = 2; i <= N; ++i) { // not consider
    if (is_prime[i]) {
      // find maximum power for the prime
      int j = i;
      while (j * i <= N) {
        j *= i;
      }
      smallest_multiple *= j;

      // find composite number that are the multiple of this prime
      j = i + i;
      while (j <= N) {
        is_prime[j] = false; // composite number
        j += i;
      }
    }
  }
  std::cout << "The smallest positive number that is evenly divisible by all "
               "of the numbers from 1 to "
            << N << " is: " << smallest_multiple << std::endl;
  return 0;
}