<<<<<<< HEAD
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
#define MAXN 50000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int prime[10000];
bool comp[10000], vis[MAXN];

void getprime()
{
    for(int p = 2; p < 10000; p++)
    {
        if(!comp[p])
        {
            prime[++prime[0]] = p;
            for(int i = p + p; i < 10000; i += p)
                comp[i] = true;
        }
    }
    return;
}

LL Pow(int x, int n)
{
    LL res = 1LL;
    while(n--)
    {
        res *= x;
    }
    return res;
}

int main()
{
    clock_t start = clock();
    getprime();
    int cnt = 0;
    LL t1, t2, t3;
    for(int i = 1; ; i++)//attention: i, j, k have no relationship in value.
    {
        t1 = Pow(prime[i], 2);
        if(t1 >= MAXN)
            break;
        for(int j = 1; ; j++)
        {
            t2 = t1 + Pow(prime[j], 3);
            if(t2 >= MAXN)
                break;
            for(int k = 1; ; k++)
            {
                t3 = t2 + Pow(prime[k], 4);
                if(t3 >= MAXN)
                    break;
                vis[t3] = true;
            }
        }
    }
    for(int i = 1; i < MAXN; i++)
        if(vis[i])
            cnt++;
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
=======
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
#define MAXN 50000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int prime[10000];
bool comp[10000], vis[MAXN];

void getprime()
{
    for(int p = 2; p < 10000; p++)
    {
        if(!comp[p])
        {
            prime[++prime[0]] = p;
            for(int i = p + p; i < 10000; i += p)
                comp[i] = true;
        }
    }
    return;
}

LL Pow(int x, int n)
{
    LL res = 1LL;
    while(n--)
    {
        res *= x;
    }
    return res;
}

int main()
{
    clock_t start = clock();
    getprime();
    int cnt = 0;
    LL t1, t2, t3;
    for(int i = 1; ; i++)//attention: i, j, k have no relationship in value.
    {
        t1 = Pow(prime[i], 2);
        if(t1 >= MAXN)
            break;
        for(int j = 1; ; j++)
        {
            t2 = t1 + Pow(prime[j], 3);
            if(t2 >= MAXN)
                break;
            for(int k = 1; ; k++)
            {
                t3 = t2 + Pow(prime[k], 4);
                if(t3 >= MAXN)
                    break;
                vis[t3] = true;
            }
        }
    }
    for(int i = 1; i < MAXN; i++)
        if(vis[i])
            cnt++;
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
