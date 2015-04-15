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
#define MAXN 3163
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int prim[MAXN], composite[MAXN + 1];
int t = 1;
void getprim()
{
    prim[1] = 2;
    composite[0] = composite[1] = 1;
    int p = 2;
    while(1)
    {
        for(int i = p + p; i <= MAXN; i += p)
            composite[i] = 1;
        p++;
        while(p < MAXN && composite[p])
            p++;
        if(p >= MAXN)
            return;
        prim[++t] = p;
    }
}
int ToInteger(int *digit, int len)
{
    int n = 0LL;
    for(int i = 1; i <= len; i++)
        n = n * 10 + digit[i];
    return n;
}
bool isPrime(int *digit, int len)
{
    if(digit[len] % 2 == 0)
        return false;
    int n = ToInteger(digit, len);
    if(n < MAXN)
        return (!composite[n]);
    int limit = round(sqrt(n));
    for(int i=1; i <= t && prim[i] <= limit; i++)
        if(n % prim[i] == 0)
            return false;
    return true;
}
bool isFound = false;
void findLPandiPrime(int *digit, int n, int x)//枚举n位数(1..n)的全排列, n!
{
    if(0 == n)
    {
        printf("No such a prim exists.\n");
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(0 == digit[i])
        {
            digit[i] = x;
            if(1 == x)
            {
                if(isPrime(digit, n))
                {
                    isFound = true;
                    return;
                }
            }
            else
                findLPandiPrime(digit, n, x - 1);
            if(isFound)
                return;
            digit[i] = 0;
        }
    }
    if(x == n)
        findLPandiPrime(digit, n - 1, n - 1);//n的全排列找完，未找到，对n-1位数进行全排列
    return;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    getprim();
    int a[11] = {};
    findLPandiPrime(a, 7, 7);//8,9位数均能被3整除，不予考虑
    printf("The largest n-digit pandigital prime: ");
    for(int i=1; a[i]; i++)
        printf("%d",a[i]);
    printf("\n");
    duration = ((double)clock() - start) / CLOCKS_PER_SEC;
    printf("Time cost: %f\n", duration);
    return 0;
}
