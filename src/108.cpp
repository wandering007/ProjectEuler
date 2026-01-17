#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include<iomanip>
#define eps 1e-8

const std::vector<int> primes = {2, 3, 5, 7, 11, 13, 17};
int best_n = 2 * 3 * 5 * 7 * 11 * 13 * 17; // -1 acts as "not set" or infinity here

void solve(int target_divs, int p_idx, int current_n, int current_divs, int limit) {
    // failed to find a better solution
    if (current_n >= best_n) {
        return;
    }
    // Check if we've met or exceeded the divisor requirement
    if (current_divs >= target_divs) {
        best_n = current_n;
        return;
    }

    // Stop if we run out of primes
    if (p_idx >= int(primes.size())) {
        return;
    }

    // Try adding the current prime with exponent 'a'
    int next_n = current_n;
    for (int a = 1; a <= limit; ++a) {        
        next_n *= primes[p_idx];
        // Only recurse if this branch has potential to be better than best_n
        solve(target_divs, p_idx + 1, next_n, current_divs * (2 * a + 1), a);
    }
}


int main()
{
    clock_t start = clock();
    /*
    1/x + 1/y = 1/n
    => xy - nx - ny = 0
    => (x - n)(y - n) = n^2 -- simon's favorite factoring trick
    => vu = n^2, where v=x-n, u=y-n
    => n=p1^a1*p2^a2*...*pk^ak, where p1, p2, ..., pk are prime factors of n
    => n^2=p1^(2a1)*p2^(2a2)*...*pk^(2ak)
    => combinations: ((2a1 + 1)*(2a2 + 1)*...*(2ak + 1) + 1[x=y=n]) / 2 > 1k
    => 3 ^ 7 = 2187 > 1k, 2,3,5,7,11,13,17
    */
    solve(2001, 0, 1, 1, 9); // 2 ^ 19 > 2 * 3 * 5 * 7 * 11 * 13 * 17
    std::cout << "Minimum n: " << best_n << std::endl;
    std::cout << "Time cost: " << std::setprecision(6) << std::scientific << (double)(clock() - start) / CLOCKS_PER_SEC << " s." << std::endl;
    return 0;
}