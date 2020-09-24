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
#define MAXN 10000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int prim[MAXN+1]={0,2},vis[MAXN+1]={1,1};
int t = 1;
int sum = 0;
int digit[] = {2,5,3,7,1,9};//2,5只能放在最高位，3,7随意，1,9只能放在中间
void getprim()
{
    int p = 2;
    while(p<MAXN)
    {
        for(int i = p+p; i<=MAXN; i += p)
            vis[i] = 1;
        p++;
        while(p<MAXN&&vis[p])p++;
        if(p>=MAXN)
            break;
        prim[++t] = p;
    }
    return;
}
bool isPrim(LL n)
{
    if(n<=MAXN)
    {
        if(vis[n])
            return false;
        return true;
    }
    int limit = sqrt(n)+0.5, i;
    for(i=1;i<=t&&prim[i]<=limit; i++)
        if(n%prim[i]==0)
        return false;
    if(i>t)
    {
        for(i=prim[t]+1;i<=limit; i++)
            if(n%i==0)
             return false;
    }
    return true;
}
LL ToInteger(int *num, int len)
{
    LL n = 0;
    for(int i=1;i<=len;i++)
       n = n*10 + num[i];
    return n;
}
bool RTruncPrime(LL n)
{
    int mod = 10;
    while(n / mod)
    {
        if(isPrim(n%mod) == false)
            return false;
        mod *= 10;
    }
    return true;
}
void findTruncPrime(int *num, int len)
{
    LL n;
    for(int i = 2; i <= 5; i++)
    {
        num[len+1] = digit[i];
        n = ToInteger(num, len+1);
        if(isPrim(n))
           {
               if(RTruncPrime(n))
               {
                   printf("%I64d\n",n);
                   sum += n;
               }
           }
        else
          continue;//当前构不成质数，进行下一次循环
        findTruncPrime(num, len+1);
    }
    return;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    getprim();
    int num[10];
    for(int i=0;i<4;i++)
    {
        num[1] = digit[i];
        findTruncPrime(num,1);
    }
    printf("sum is %d(2,3,5,7 are not considered).\n", sum);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
}
