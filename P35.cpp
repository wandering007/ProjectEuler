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
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int prim[MAXN],vis[MAXN+1];
int t = 1;
void getprim()
{
    int p = 2;
    prim[1] = 2;
	vis[1] = 1;
    while(1)
    {
        for(int i = p + p; i<= MAXN; i += p)
            vis[i] = 1;
        p++;
        while(p < MAXN && vis[p])
            p++;
        if(p >= MAXN)
            break;
        prim[++t] = p;
    }
    return;
}
int isCircular(int prim)
{
    int digit = 1, num = 1;
    vector<int> rec;
    rec.push_back(prim);
    int temp = prim/10;
    while(temp)
    {
        digit *= 10;
        temp/=10;
    }
    temp = prim/10 + (prim%10)*digit;
    while(temp!=prim)
    {
       if(vis[temp])
         return 0;
       rec.push_back(temp);
       num++;
       temp = temp/10 + (temp%10)*digit;
    }
    for(int i = 0; i < num; i++)
        vis[rec[i]] = 1;
    return num;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    getprim();
    int n = 0;
    for(int i=1;i<=t;i++)
    {
        if(!vis[prim[i]])
            n += isCircular(prim[i]);
    }
    printf("%d\n",n);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
}
