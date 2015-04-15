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
#define MAXN 100
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int sum[MAXN + 1], prime[MAXN];
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

int main()
{
    clock_t start = clock();
    sum[0] = 1;
    getprime();
    for(int i = 1; i <= prime[0]; i++)
        for(int j = prime[i]; j <= MAXN; j++)
            sum[j] += sum[j - prime[i]];
    for(int i = 2; i <= MAXN; i++)
        if(sum[i] > 5000)
    {
        printf("%d\n", i);
        break;
    }
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
/*
int NumofPrimeSum(int p, int index, int sum)
{
    if(p == sum)
        return 1;
    if(index > prime[0])
        return 0;
    int res = 0;
    for(int i = 0; i + p <= sum; i += prime[index])
    {
        res += NumofPrimeSum(p + i, index + 1, sum);
    }
    return res;
}

int main()
{
    clock_t start = clock();
    getprime();
    for(int i = 2; i <= MAXN; i++)
        if(NumofPrimeSum(0, 1, i) > 5000)
    {
        printf("%d\n", i);
        break;
    }
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
*/