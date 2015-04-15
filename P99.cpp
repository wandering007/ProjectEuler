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

int main()
{
    clock_t start = clock();
    freopen( "C:\\Users\\Leo Cheng\\Desktop\\p099_base_exp.txt", "r", stdin );//注意使用"\\"表示路径
    double Max = 0.0, temp;
    int a, b, rec;
    for( int i = 1; i<= 1000; i++ )
    {
        scanf( "%d,%d", &a, &b );
        temp = b * log( a );
        if( temp > Max - eps )
        {
            Max = temp;
            rec = i;
        }
    }
    printf("%d\n", rec);
    printf( "time cost: %lf", ( double )( clock() - start ) / CLOCKS_PER_SEC );
    return 0;
}
