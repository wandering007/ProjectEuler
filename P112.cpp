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

bool isBouncy(int n)
{
    bool incre = false, decre = false;
    int pre = n % 10;
    n /= 10;
    while(n)
    {
        if(n % 10 < pre)
            incre = true;
        else if(n % 10 > pre)
            decre = true;
        pre = n % 10;
        n /= 10;
        if(incre && decre)
            return true;
    }
    return false;
}

int main()
{
    clock_t start = clock();
    int b = 0;
    for(int i = 100; ; i++)
    {
        if(isBouncy(i))
            b++;
        if(b * 100  == i * 99)
        {
            printf("%d\n", i);
            break;
        }
    }
    printf( "time cost: %lf", ( double )( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}
