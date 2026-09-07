#include <iostream>
#include <vector>
#include <iomanip>
#include <numeric>
#include <functional>

using u64 = unsigned long long;

static const u64 POW10[10] = {
    1ULL, 10ULL, 100ULL, 1000ULL, 10000ULL,
    100000ULL, 1000000ULL, 10000000ULL, 100000000ULL, 1000000000ULL
};

// We can predict that $M(10, d)$ must be very high (either $9$ or at worst $8$) through a combination of Dirichlet's Theorem / the Prime Number Theorem (heuristic density) and simple modular arithmetic. So we can just brute force all $10$-digit numbers with $M(10, d)$ digits equal to $d$ and check for primality. The only tricky part is that we need a fast primality test, so we use Miller-Rabin with a fixed set of bases that is guaranteed to work for $n < 2^{64}$.


u64 mulmod(u64 a, u64 b, u64 mod) {
    __uint128_t res = (__uint128_t)a * b;
    return (u64)(res % mod);
}

u64 powmod(u64 a, u64 e, u64 mod) {
    u64 result = 1 % mod;
    a %= mod;
    while (e) {
        if (e & 1) result = mulmod(result, a, mod);
        a = mulmod(a, a, mod);
        e >>= 1;
    }
    return result;
}

bool isPrime(u64 n) {
    
    if (n < 2) return false;
    static const u64 smallPrimes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (u64 p : smallPrimes) {
        if (n == p) return true;
        if (n % p == 0) return false;
    }
    u64 d = n - 1;
    int s = 0;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }
    // if n < 1,122,004,669,633, it is enough to test a = 2, 13, 23, and 1662803
    static const u64 bases[] = {2, 13, 23, 1662803};
    for (u64 a : bases) {
        if (a % n == 0) continue;
        u64 x = powmod(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; ++r) {
            x = mulmod(x, x, n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

void dfs(int d, const std::vector<int>& positions, int idx, u64 current, int sum_digits, u64& sum, int& primes_count) {
    if (idx == (int)positions.size()) {
        if (sum_digits % 3 == 0) return;  // 剪枝：各位和能被 3 整除，必然是 3 的倍数（合数）
        if (isPrime(current)) {
            sum += current;
            primes_count++;
        }
        return;
    }

    int p = positions[idx];     // p 直接代表 10^p
    u64 p10 = POW10[p];
    u64 base_cleared = current - (u64)d * p10;
    int sum_cleared = sum_digits - d;

    for (int dig = 0; dig <= 9; ++dig) {
        if (dig == d) continue;
        if (p == 9 && dig == 0) continue;                     // p=9 是最高位，不可为 0
        if (p == 0 && (dig % 2 == 0 || dig == 5)) continue;  // p=0 是个位，不可为偶数或 5

        dfs(d, positions, idx + 1, base_cleared + (u64)dig * p10, sum_cleared + dig, sum, primes_count);
    }
}

int main() {
    clock_t start = clock();
    u64 totalSum = 0;
    for (int d = 0; d <= 9; ++d) {
        u64 base = 0;
        for (int i = 0; i < 10; ++i) base = base * 10 + d;
        
        // 枚举非 d 的个数，从1开始。不可能全是 d，因为 10 个 d 的数不是素数
        for (int non_d_count = 1; non_d_count <= 9; ++non_d_count) {
            u64 level_sum = 0;
            int primes_found = 0;
            // Gosper's Hack 遍历组合
            for (int mask = (1 << non_d_count) - 1; mask < (1 << 10); ) {
                // 1. 最高位(第 9 位)没被替换，且 d == 0 -> 前导零，跳过
                bool invalid_lead = ((mask & (1 << 9)) == 0 && d == 0);

                // 2. 个位(第 0 位)没被替换，且 d 是偶数或 5 -> 必然不是素数，跳过
                bool invalid_tail = ((mask & 1) == 0 && (d % 2 == 0 || d == 5));

                if (!invalid_lead && !invalid_tail) {
                    std::vector<int> positions;
                    positions.reserve(non_d_count);
                    for (int i = 0; i < 10; ++i) {
                        if (mask & (1 << i)) positions.push_back(i);
                    }
                    dfs(d, positions, 0, base, 10 * d, level_sum, primes_found);
                }

                // 推进到下一个位组合
                int c = mask & -mask;
                int r = mask + c;
                mask = (((r ^ mask) >> 2) / c) | r;
            }

            if (primes_found > 0) {
                totalSum += level_sum;
                break;
            }
        }
    }
    std::cout << totalSum << "\n";
    std::cout << "Time cost: " << std::setprecision(6) << std::scientific << (double)(clock() - start) / CLOCKS_PER_SEC << " s." << std::endl;
    return 0;
}
