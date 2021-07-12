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
#define MAXN 200001
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int a[202], a1[202], temp[202];

void ToString(int x)
{
    for(int i = 1; ; i++)
    {
        if(0 == x)
        {
            a1[0] = i - 1;
            break;
        }
        a1[i] = x % 10;
        x /= 10;
    }
    return;
}

void multiply(int* res, int* f)
{
    int c;
    for(int i = 1; i <= res[0]; i++)
    {
        if(0 == res[i])
            continue;
        for(int j = 1; j <= f[0]; j++)
        {
            if(0 == f[j])
                continue;
            c = temp[i + j - 1] + res[i] * f[j];
            temp[i + j - 1] = c % 10;
            temp[i + j] += c / 10;
        }
    }
    temp[0] = f[0] + res[0];
    if(0 == temp[temp[0]])
        temp[0]--;
    res[0] = temp[0];
    for(int i = 1; i <= res[0]; i++)
        {
            res[i] = temp[i];
            temp[i] = 0;
        }
    return;
}

int SumOfDigits()
{
    int res = 0;
    for(int i = 1; i <= a[0]; i++)
        res += a[i];
    return res;
}

int main()
{
    double duration;
    clock_t start = clock();
    int sum = 0;
    for(int i = 1; i < 100; i++)
    {
        ToString(i);
        a[0] = 1;
        a[1] = 1;
        for(int j = 1; j < 100; j++)
        {
            multiply(a, a1);
            sum = max(sum, SumOfDigits());
        }
    }
    printf("%d\n",sum);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
