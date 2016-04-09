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
#define MAXN 100000
#define BASE 15
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
//attention: 9^20³¬³ölong long·¶Î§

int main()
{
    double duration;
    clock_t start = clock();
    int num = 0, incre;
    for(int i = 1; ; i++)
    {
        incre = 10 - ceil(pow(10, (i - 1.0) / i));//10 ^ (n - 1) <= k = base ^ i < 10 ^ n, base = bgn...9
        if(0 == incre)
            break;
        num += incre;
    }
    printf("%d\n", num);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
/*another implementation
	double a[10];
    for(int i = 1; i<= 9; i++)
        a[i] = log10((double)i);
    for(int i = 1; ; i++)
    {
        incre = 0;
        for(int j = bgn; j <= 9; j++)
        {
            if(i - 1.0 - eps <= a[j] * i)
                {
                    incre = 10 - j;
                    bgn = j;
                    break;
                }
        }
        if(0 == incre)
            break;
        num += incre;
    }
*/