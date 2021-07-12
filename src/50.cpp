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
#define MAXN 1000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int prime[MAXN],vis[MAXN];
int t = 1;
typedef struct
{
    int s, l, val;
}node;

void getprime()
{
    int p = 2;
    prime[1] = 2;
    while(1)
    {
        for(int i = p + p; i < MAXN; i += p)
            vis[i] = 1;
        while(++p < MAXN && vis[p]);
        if(p >= MAXN)
            break;
        prime[++t] = p;
    }
    return;
}

int main()
{
    clock_t start;
    double duration;
    start = clock();
    getprime();
    node res;
    res.s = 0;
    res.l = 0;
    res.val = 0;
    int k = 1;
    node temp, rec = res;//rec用来记录k-1为起点的一个res.l长度的val，方便temp的初始化,复杂度O(1)
    while(k + rec.l <= t)
    {
        temp.s = k;
        temp.l = rec.l;
        temp.val = rec.val - prime[rec.s] + prime[rec.s + rec.l];
        rec = temp;
        while(temp.val < MAXN)
        {
            if(!vis[temp.val])
                res = temp;
            temp.l++;
            if(k + temp.l - 1 > t)
                break;
            temp.val += prime[k + temp.l - 1];
        }
        if(res.l > rec.l)
            rec = res;
        k++;
    }
    printf("%d\n", res.val);
    duration = (double)(clock()-start)/CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
