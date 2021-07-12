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
#define MAXN 1002001
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int make[105]={}, composite[1001];
void getcomposite()
{
    int p = 2, t = 1,vis[1001]={};
    while(p<=700)
    {
        for(int i=p*2;i<=1000;i+=p)
           vis[i] = 1;
        p++;
        while(vis[p])
        {
            if(p>100)
                composite[t++] = p;
            p++;
        }
    }
}
bool PowRange_100(int x, int n)
{
    LL res = 1LL;
    while(n--)
    {
        res*=x;
        if(res>100)
            return false;
    }
    return true;
}
bool findSuitable(int k, int n)
{
    int t = sqrt(k)+1;
    bool p;
    for(int i = 2;i<=t;i++)
    {
        if(k%i==0)
        {
            p = PowRange_100(n,i);
            if(k/i<=100&&p)
                return true;
            if(p == false)
                return false;
        }
    }
    return false;
}
int Num(int n)
{
    int res = 99;
    if(n>10) return res;
    for(int k=composite[1],j=1;k<=600;k = composite[++j])
    {
        if(findSuitable(k,n))
            res++;
    }
    return res;
}
int main()
{
    int terms = 0;
    getcomposite();
    for(int i=2; i<=10; i++)
        for(int j = i * i; j <= 100; j *= i)
            make[j] = 1;
    for(int i=2;i<=100;i++)
        if(!make[i])
            terms += Num(i);
    printf("%d\n",terms);
    return 0;
}
