#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<algorithm>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<iomanip>
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int prime[MAXN], Phi[MAXN + 1] = {0, 1};
bool comp[MAXN + 1];

void getprime()
{
    for(int p = 2; p <= MAXN; p++)
    {
        if(!comp[p])
        {
            for(int i = p + p; i <= MAXN; i += p)
                comp[i] = true;
            prime[++prime[0]] = p;
        }
    }
    return;
}

int Totient(int n)
{
    if(!comp[n])
        Phi[n] = n - 1;
    else if(0 == Phi[n])
    {
        int m = 1, i = 1, k = n;
        while(n % prime[i])
            i++;
        while(0 == k % prime[i])
        {
            m *= prime[i];
            k /= prime[i];
        }
        Phi[n] = Phi[m] * Phi[k];//m * k == n
        // The totient function is a multiplicative function
        //if two numbers m and n are relatively prime, then φ(mn) = φ(m)φ(n).
    }
    //φ(n^k) = n^(k - 1)φ(n) = n * φ(n^(k - 1))
    for(LL t = (LL)n * n; t <= MAXN; t *= n)
        Phi[t] = n * Phi[t / n];
    return Phi[n];
}
/*A faster way
类似于扫描法求质数
	for(int i = 1; i <= MAXN; i++)
        Phi[i] = i;
	for(int i = 2; i <= MAXN; i++)
	{
		if(Phi[i] == i)
		{
			for(int j = i;j <= MAXN; j += i)
				Phi[j] = Phi[j] / i * (i - 1);
		}
	}
*/

int main()
{
    double duration;
    clock_t start = clock();
    getprime();
    double Max = 0.0, temp;
    int rec;
    for(int i = 2; i <= MAXN; i++)
    {
        temp = (double)i / Totient(i);
        if(temp > Max + eps)
        {
            Max = temp;
            rec = i;
        }
    }
    printf("%d\n", rec);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
/*
an informal way: To make n/phi(n) larger, we can try to make phi(n) as small as possible.
n / φ(n) = p1 / (p1 - 1) * ... * Pr / (Pr - 1)
We see that the quotient depends only on the primes dividing n, not on their exponents in
the prime factorisation of n; and that among all numbers having exactly k distinct prime
divisors, the quotient is largest for those numbers divisible by the k smallest primes. 
If q is a prime not dividing n, then (q · n) / φ(q · n) > n / φ(n).
So if n<k> is the product of the k smallest primes, n<k> * φ(n<k>) is maximal among all n / φ(n)
for n < n<k + 1>.
We must therefore find the k with n<k> <= N < n<k + 1>. For N = 10^6, we find 
2 · 3 · 5 · 7 · 11 · 13 · 17 = 510 510, hence n7 = 510510 is the answer.
*/
