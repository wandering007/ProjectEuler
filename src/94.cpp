#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<set>
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
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

//https://en.wikipedia.org/wiki/Pell%27s_equation
//http://www.mathblog.dk/project-euler-94-almost-equilateral-triangles/
//x{k+1} = x1 * xk + n * y1 * yk,
//y{k+1} = x1 * yk + y1 * xk.
int main()
{
    clock_t start = clock();
    LL x = 2LL, y = 1LL, result = 0LL, aTimes3, areaTimes3;
    while(true)
    {
        //b = a - 1
        aTimes3 = 2 * x - 1;
        areaTimes3 = y * (x - 2);
        if(aTimes3 - 1 > MAXN)
            break;
        if(aTimes3 > 0 && areaTimes3 > 0 && 0 == aTimes3 % 3 && 0 == areaTimes3 % 3)
            result += aTimes3 - 1;

        //b = a + 1
        aTimes3 = 2 * x + 1;
        areaTimes3 = y * (x + 2);
        if(aTimes3 + 1 > MAXN)
            break;
        if(aTimes3 > 0 && areaTimes3 > 0 && 0 == aTimes3 % 3 && 0 == areaTimes3 % 3)
            result += aTimes3 + 1;
        LL nextx = 2 * x + 3 * y;
        y = 2 * y + x;
        x = nextx;
    }
    printf("%I64d\n", result);
    printf("Time cost: %lf s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}
