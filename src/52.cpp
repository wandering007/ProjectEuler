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
int len;

void ToString(LL n, int* s)
{
    len = 0;
    while(n)
    {
        s[++len] = n % 10;
        n /= 10;
    }
    return;
}

bool compare(int* s1, int* s2)
{
    for(int i = 1; i <= len; i++)
        if(s1[i] != s2[i])
            return false;
    return true;
}

bool isFound(LL n)
{
    int s1[20], s2[20];
    ToString(n, s1);
    sort(s1 + 1, s1 + len + 1);
    for(int i = 2; i <= 6; i++)
    {
        ToString(n * i, s2);
        sort(s2 + 1, s2 + len + 1);
        if(!compare(s1, s2))
            return false;
    }
    return true;
}

int main()
{
    double duration;
    clock_t start = clock();
    for(LL i = 1LL, l = 10; ; i++)
    {
        if(i * 6 >= l)
        {
            i = l;
            l *= 10;
            continue;
        }
        if(isFound(i))
        {
            printf("%I64d\n", i);
            break;
        }
    }
    duration = (clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
