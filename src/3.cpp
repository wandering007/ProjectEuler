#include <iostream>

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=3"
            << "\n\nLargest prime factor" << std::endl;
  std::cout << "====================================" << std::endl;
  const long long N = 600851475143;
  long long largest_prime_factor = N;
  while (not(largest_prime_factor & 1)) {  // even
    largest_prime_factor >>= 1;            // divide by 2
  }
  int i = 3;  // odd factors
  while (i * i < largest_prime_factor) {
    while (largest_prime_factor % i == 0) {
      largest_prime_factor /= i;
    }
    i += 2;
  }
  std::cout << "The largest prime factor of the number " << N << ": "
            << largest_prime_factor << std::endl;
  return 0;
}