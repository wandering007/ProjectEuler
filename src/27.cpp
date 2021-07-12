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
#define MAXN 1000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int prim[3000];
int vis[100000];
void getprim()
{
    prim[1] = 2;
    int p = 2, t = 2;
    while(t<3000)
    {
        for(int i=p*2;i<100000;i+=p)
            vis[i] = 1;
        p++;
        while(vis[p]) p++;
        prim[t++] = p;
    }
    return;
}
bool isPrim(int n)
{
    int m = sqrt(n)+1.0+eps;
    for(int i=1;prim[i]<m;i++)
        if(n%prim[i]==0)
         return false;
    return true;
}
int primesForConVal(int a, int b)
{
    int val, k = abs(b),n;
    for(n=0;n<k;n++)
    {
        val = n*n+a*n+b;
        if(val<=2||isPrim(val)==false)
            return n;
    }
    return n;
}
int main()
{
    int maxNumOfPrims = 0, cnt, reca,recb;
    getprim();
    for(int a=-999; a<1000; a++)
        for(int b=prim[1],j=1; b<1000; b = prim[++j])
    {
        for(int k =0;k<2;k++)
        {
           cnt = primesForConVal(a, b);
           if(cnt>maxNumOfPrims)
           {
               maxNumOfPrims = cnt;
               reca = a;
               recb = b;
           }
        }
    }
    printf("a = %d, b = %d, the product is %d\n",reca, recb, reca*recb);
    return 0;
}
