#include <iostream>
#include <vector>
#include<iomanip>
#include <numeric>
#include <functional>


const std::vector<int> primes = {2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47};
long long best_n = std::accumulate(primes.begin(), primes.end(), 1LL, std::multiplies<long long>());
const int target_divs = 8000000;

void solve(int p_idx, long long current_n, int current_divs, int limit)
{
    // Check if we've met or exceeded the divisor requirement
    if (current_divs >= target_divs)
    {
        best_n = current_n;
        return;
    }

    // Stop if we run out of primes
    if (p_idx >= int(primes.size()))
    {
        return;
    }

    // Try adding the current prime with exponent 'a'
    long long next_n = current_n;
    for (int a = 1; a <= limit; ++a)
    {
        // failed to find a better solution
        if (next_n >= best_n * 1.0 / primes[p_idx])
        {
            break;
        }
        next_n *= primes[p_idx];
        // Only recurse if this branch has potential to be better than best_n
        solve(p_idx + 1, next_n, current_divs * (2 * a + 1), a);
    }
    return;
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
    => combinations: ((2a1 + 1)*(2a2 + 1)*...*(2ak + 1) + 1[x=y=2n]) / 2 > 4M
    => (3 ^ 15+1)/2 = 1.59M > 4M, 2,3,5,7,11, 13,17,19,23,29, 31,37,41,43,47 multiplication < 2^60
    */
    solve(0, 1, 1, 60);
    std::cout << "the least value of n for which the number of distinct solutions exceeds four million: " << best_n << std::endl;
    std::cout << "Time cost: " << std::setprecision(6) << std::scientific << (double)(clock() - start) / CLOCKS_PER_SEC << " s." << std::endl;
    return 0;
}
