#include <iostream>
#include <vector>

int main() {
  std::cout << "====================================" << std::endl;
  std::cout << "https://projecteuler.net/problem=7"
            << "\n\n10001st prime" << std::endl;
  std::cout << "====================================" << std::endl;
  const int target_rank = 10001;
  const int N = target_rank * 20;
  std::vector<int> is_prime(N, true);
  int rank = 0;
  int target_prime = -1;
  for (int i = 2; i < N; ++i) {
    if (is_prime[i]) {
      rank += 1;
      if (rank == target_rank) {
        target_prime = i;
        break;
      }

      int j = i + i;
      while (j < N) {
        is_prime[j] = false;
        j += i;
      }
    }
  }
  if (target_prime == -1) {
    std::cerr << "Failed to find the " << target_rank << "st prime number"
              << std::endl;
  } else {
    std::cout << "the " << target_rank << "st prime number: " << target_prime
              << std::endl;
  }
  return 0;
}