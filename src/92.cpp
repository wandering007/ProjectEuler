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
#define MAXN 10000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

int father[MAXN];

int SquareDigit(int n)
{
    int res = 0;
    while(n)
    {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

int findFather(int n)
{
    return father[n] == n ? n : (father[n] = findFather(father[n]));
}

int main()
{
    clock_t start = clock();
    int k, cnt = 0;
    for(int i = 1; i < MAXN; i++)
        father[i] = i;
    for(int i = 1; i < MAXN; i++)
    {
        if(89 == i)
            continue;
        k = SquareDigit(i);
        father[i] = k;
    }
    for(int i = 1; i < MAXN; i++)
    {
        if(findFather(i) == 89)
            cnt++;
    }
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
