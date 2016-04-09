#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<set>
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
#define MAXN 1000000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int propDiv[MAXN + 1];
int LongAmicChain, MinMem;
bool vis[MAXN + 1];

void getPropDiv()
{
    for(int i = 1; i <= MAXN / 2; i++)
        for(int j = 2 * i; j <= MAXN; j += i)
            propDiv[j] += i;
    return;
}

void searchAmicChain(int beginner)
{
    if(vis[beginner])//already visited, no news
        return;
    int next = beginner, chainLength = 0;
    while(next <= MAXN && !vis[next])
    {
        vis[next] = true;
        next = propDiv[next];
        chainLength++;
    }
    if(next <= MAXN && next > 1) //the legal range of variable next
    {
        while(next != beginner)
        {
            beginner = propDiv[beginner];
            chainLength--;
        }
        if(0 == chainLength) //no circle
            return;
        int Min = beginner;
        next = propDiv[beginner];
        while(next != beginner)
        {
            Min = min(Min, next);//find the smallest member
            next = propDiv[next];
        }
        if(chainLength > LongAmicChain)
        {
            LongAmicChain = chainLength;
            MinMem = Min;
        }
    }
    return;
}

int main()
{
    clock_t start = clock();
    getPropDiv();
    for(int i = 2; i <= MAXN; i++)
        searchAmicChain(i);
    printf("%d\n", MinMem);
    printf("Time cost: %lf s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}
