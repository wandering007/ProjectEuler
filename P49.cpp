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
#define MAXN 10000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int prime[MAXN],vis[MAXN];
int t = 0;
int digit[5];
int rec[25];
void getprime()
{
    int p = 2;
    while(1)
    {
        for(int i = p+p; i < MAXN; i+=p)
            vis[i] = 1;
        while(p<MAXN&&vis[++p]);
        if(p>=MAXN)
            break;
        if(p < 1000)
            continue;
        prime[++t] = p;
    }
    return;
}
int ToInt(int* digit)
{
    int res = 0;
    for(int i = 1; i <= 4; i++)
        res = res*10+digit[i];
    return res;
}
void Tostr(int n, int* str)
{
    for(int i = 1; i<=4; i++)
    {
        str[i] = n%10;
        n /= 10;
    }
    return;
}
bool notEqual(int n)
{
    int test[5], strn[5];
    for(int i=1;i<=4;i++)
        test[i] = digit[i];
    sort(test+1,test+5);
    Tostr(n, strn);
    sort(strn+1,strn+5);
    for(int i=1; i<=4;i++)
        if(strn[i]!=test[i])
            return true;
    return false;
}
bool isFound()
{
    int d = rec[2] - rec[1];
    rec[3] = rec[2] + d;
    if(rec[3]>=MAXN||vis[rec[3]]||notEqual(rec[3]))
        return false;
    return true;
}
bool isSuit(int np)
{
    rec[1] = np;
    for(int i=4; i>=1; i--)
    {
        digit[i] = np%10;
        np /= 10;
    }
    int n;
    while(next_permutation(digit+1, digit+5))
    {
        n = ToInt(digit);
        if(n>rec[1]&&!vis[n])
        {
            rec[2] = n;
            if(isFound())
                return true;
        }
    }
    return false;
}
int main()
{
    clock_t start;
    double duration;
    start = clock();
    getprime();
    for(int i = 1; i <= t; i++)
    {
        if(prime[i]==1487)
            continue;
        if(isSuit(prime[i]))
            break;
    }
    for(int i = 1; i<=3; i++)
        printf("%d",rec[i]);
    printf("\n");
    duration = (double)(clock()-start)/CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
