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
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int vis[10],fa[10];
int main()
{
    LL p=0LL;
    int k=9;
    fa[0] = 1;
    for(int i=1;i<=9;i++)
        fa[i] = fa[i-1]*i;
    for(int i=0;i<=9;)
    {
        if(vis[i]==0)
        {
            p+=fa[k];
            if(p>=MAXN)
            {
                if(k>0)
                    p -= fa[k];
                vis[i] =10-k;
                k--;
                if(k==-1)//此处p必然等于MAXN
                    break;
                i=0;
                continue;
            }
            else
                i++;
        }
        else i++;
    }
    printf("The millionth lexicographic permutation is:\n");
    for(int i=1;i<=10;i++)
    {
        for(int j=0;j<10;j++)
            if(vis[j]==i)
                printf("%d",j);
    }
    printf("\n");
}
