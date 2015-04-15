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
#define MAXN 100000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int p[MAXN];

int getPartition(int n) {
    for(int k = 1, g; ; k++)
    {
        g = k * (3 * k - 1) / 2;
        if(n - g < 0)
            break;
        if(k & 1)
        	p[n] += p[n - g];
        else p[n] += MOD - p[n - g];//注意要保证p[n]的值始终为正
        if(p[n] >= MOD)
            p[n] %= MOD;
        g = k * (3 * k + 1) / 2;
        if(n - g < 0)
            break;
        if(k & 1)
        	p[n] += p[n - g];
        else p[n] += MOD - p[n - g];
        if(p[n] >= MOD)
            p[n] %= MOD;
    }
    return p[n];
}

int main()
{
    clock_t start = clock();
    p[0] = 1;
    for(int i = 1; i < MAXN; i++)
    {
        if(0 == getPartition(i))
        {
            printf("%d\n", i);
            break;
        }
    }
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}

/*easy to understand but slow, 30+s
int main()
{
    clock_t start = clock();
    p[0] = 1;
    for(int i = 1; i < MAXN; i++)
        for(int j = i; j < MAXN; j++)
    {
        p[j] += p[j - i];
        p[j] %= MOD;
    }
    for(int i = 1; i < MAXN; i++)
    {
        if(0 == p[i])
        {
            printf("%d\n", i);
            break;
        }
    }
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}*/
