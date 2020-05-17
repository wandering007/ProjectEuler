#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#define MAX_SIZE 1000000000+7
#define LL long long
#define eps 1e-6
using namespace std;
int prim[1000005];
int flag[1000005];
int PrimFac[1000005];
int e = 1;
void getprim()
{
    prim[1]=2;
    int p=2;
    while(p<1000000)
    {
        for(int i=p*2;i<=1000000;i+=p)
            flag[i] = 1;
        p++;
        while(flag[p])p++;
        prim[++e] = p;
    }
    return;
}
int fac_num(long long t)
{
   for(int i=1;i<=e;i++)
    PrimFac[i]=1;
   int k=1;
   while(prim[k]<=t)
   {
       while(t%prim[k]==0)
       {
           t /= prim[k];
           PrimFac[k]++;
       }
       k++;
   }
   int num=1;
   for(int i=1;i<k;i++)
    num*=PrimFac[i];
   return num;
}
int main()
{
    getprim();
    LL n = 8LL;
    while(fac_num(n*(n+1)/2)<=500)n++;
    printf("%I64d\n",n*(n+1)/2);
    return 0;
}
