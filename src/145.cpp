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
#define MAXN 1000000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
/*
0 2 4 6 8
1 3 5 7 9
*/
int Reversible(int n, int digit, bool carried, bool carrying)
{
    if((n + 1) / 2 < digit)
    {//n is even
        if(carried == carrying)
            return 1;//中心对称的两位的和与进位要保证对称，同进位或者同不进位
        return 0;
    }
    if((n + 1) / 2 == digit && (n & 1))
    {
        if(false == carried)
            return 0;
        return 5; //5, 6, 7, 8, 9 或 0, 1, 2, 3, 4
    }
    if(false == carried)
    {
        if(1 == digit)
            return 20 * Reversible(n, 2, false, false) + 20 * Reversible(n, 2, true, false);
        if(true == carrying)
            return 20 * Reversible(n, digit + 1, true, false);
        else return 30 * Reversible(n, digit + 1, false, false);
    }
    else return 25 * Reversible(n, digit + 1, carrying, true);
}

int main()
{
    clock_t start = clock();
    int num = 0;
    for(int i = 1; i <= 9; i++)
        num += Reversible(i, 1, false, false);
    printf("%d\n", num);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
