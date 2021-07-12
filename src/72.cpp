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
#define MOD 10000000000
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

int main()
{
    clock_t start = clock();
    getprime();
    LL cnt = 0;
    for(int i = 2; i <= MAXN; i++)
        cnt += Totient(i);
        //printf("%d %d\n", i, NumOfFrac[i]);
    printf("%I64d\n", cnt);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
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
	LL ans = 0LL;
	for(int i = 2;i <= MAXN; i++)
		ans += Phi[i];
	printf("%I64d\n", ans);
*/