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
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int gcd(int x, int y)
{
    return y == 0 ? x : gcd(y, x % y);
}

int main()
{
    double duration;
    clock_t start = clock();
    int numerator, dif, rec;
    double Min = 1.0, temp;
    for(int d = MAXN; d >= 5; d--)
    {
        numerator = floor(3.0 * d / 7.0 + eps);
        dif = 3 * d - numerator * 7;
        if(dif <= 0)//弥补计算误差
            {
                dif += 7;
                numerator--;
            }
        temp = dif / (7.0 * d);
        if(temp < Min)//更接近3/7
        {
            Min = temp;
            rec = numerator / gcd(numerator, d);
        }
    }
    printf("%d\n", rec);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
