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
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

bool isSuit(unsigned LL n)
{
    if(n % 10)
        return false;
    n /= 100;
    int d = 9;
    while(n)
    {
        if(d != n % 10)
            return false;
        n /= 100;
        d--;
    }
    return true;
}

int main()
{
    clock_t start = clock();
    for(unsigned LL i = (unsigned LL)sqrt(1020304050607080900); ; i++)
    {
        if(isSuit(i * i))
        {
            printf("%I64u %I64u\n", i, i * i);
            break;
        }
    }
    printf( "time cost: %lf", ( double )( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}
