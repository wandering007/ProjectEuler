#include <iostream>

// the number of subset pairs that can be obtained need to be tested for equality
// for each size L (1...N/2), (C(N, L) * C(N-L, L) / 2 - C(N, 2*L) * Catalan(L))
// Catalan number is to count the subset pairs (B, C) that element of each index in B is smaller than the corresponding element in C
// Catalan(L) = C(2*L, L) / (L+1)

int Factorial[15] = {1};
int combination(int n, int k)
{
    return Factorial[n] / (Factorial[k] * Factorial[n - k]);
}

int catalanNumber(int n)
{
    // https://en.wikipedia.org/wiki/Catalan_number
    return combination(2 * n, n) / (n + 1);
}

int main()
{
    for (int i = 1; i <= 12; i++)
    {
        Factorial[i] = i * Factorial[i - 1]; // set the factorial value
    }
    int N = 12;
    int total_num = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        total_num += combination(N, i) * combination(N - i, i) / 2 - combination(N, 2 * i) * catalanNumber(i);
    }
    std::cout << "For n = 12, " << total_num << " subset pairs need to be tested for equality." << std::endl;
    return 0;
}
