#include <iostream>
#include <vector>

int main() {
    const int N = 2000000;
    std::vector<int> is_prime(N, 1);
    for (int k = 2; k + k < N; ++k) {
        for (int j = k + k; j < N; j += k) {
            is_prime[j] = 0;
        }
    }
    long long sum_of_primes = 0;  // 不能用int
    for (int i = 2; i < N; ++i) {
        if (1 == is_prime[i]) {
            sum_of_primes += i;
        }
    }
    std::cout << "The sum of all the primes below two million is " << sum_of_primes << std::endl;
    return 0;
}