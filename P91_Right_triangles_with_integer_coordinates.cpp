<<<<<<< HEAD
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
#define MAXN 50
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//a quite efficient way to make it: https://projecteuler.net/thread=91;page=8

int main()
{
    clock_t start = clock();
    int res = MAXN * MAXN; //the vertex of the right angle is at the origin
    for(short x1 = 0; x1 <= MAXN; x1++)
    for(short y1 = 0; y1 <= MAXN; y1++)
    for(short x2 = 0; x2 <= MAXN; x2++)
    for(short y2 = 0; y2 <= MAXN; y2++)
    {
        if(x1 * y2 - x2 * y1 != 0 && x1 * (x2 - x1) + y1 * (y2 - y1) == 0)//The three points are not on a line or coincide && right angle
            res++;
    }
    printf("%d\n", res);
    printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}
=======
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
#define MAXN 50
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//a quite efficient way to make it: https://projecteuler.net/thread=91;page=8

int main()
{
    clock_t start = clock();
    int res = MAXN * MAXN; //the vertex of the right angle is at the origin
    for(short x1 = 0; x1 <= MAXN; x1++)
    for(short y1 = 0; y1 <= MAXN; y1++)
    for(short x2 = 0; x2 <= MAXN; x2++)
    for(short y2 = 0; y2 <= MAXN; y2++)
    {
        if(x1 * y2 - x2 * y1 != 0 && x1 * (x2 - x1) + y1 * (y2 - y1) == 0)//The three points are not on a line or coincide && right angle
            res++;
    }
    printf("%d\n", res);
    printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
