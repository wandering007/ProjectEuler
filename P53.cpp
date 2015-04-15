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

LL gcd(LL x, LL y)//x > y
{
    return y == 0? x : gcd(y, x % y);
}

bool JudgeComb(int n, int r)
{
    LL f1 = 1LL, f2 = 1LL, g;//int型也可以
    for(int i = n, j = n - r; i > r; i--, j--)
    {
        f1 *= i;
        f2 *= j;
        g = gcd(f1, f2);
        f1 /= g;
        f2 /= g;
        if(f1 / f2 + (f1 % f2 ? 1 : 0) > MAXN)
            return true;
    }
    return false;
}

int NumOfComb(int n)
{
    int res = 0;
    for(int i = 0; i <= n / 2; i++)//二项式有n+1项
    {
        if(JudgeComb(n, i))
        {
            res = n + 1 - 2 * i;
            //0...i - 1和 n - i + 1...n这些二项式(2 * i个)都是不满足条件的
            break;
        }
    }
    return res;
}

int main()
{
    double duration;
    clock_t start = clock();
    int res = 0;
    for(int i = 1; i <= 100; i++)
        res += NumOfComb(i);
    printf("%d\n", res);
    duration = (clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
