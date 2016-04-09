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

typedef struct
{
    int x, y;
}node;
node A, B, C;

int cross(node p0, node p1, node p2)
{
    p1.x -= p0.x;
    p1.y -= p0.y;
    p2.x -= p0.x;
    p2.y -= p0.y;
    int res = p1.x * p2.y - p2.x * p1.y;
    if(res > 0)
        return 1;
    else if(res < 0)
        return -1;
    return 0;
}

int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Desktop\\p102_triangles.txt", "r", stdin);
    int cnt = 0, sign, t;
    node O;
    O.x = 0;
    O.y = 0;
    while(scanf("%d,%d,%d,%d,%d,%d", &A.x, &A.y, &B.x, &B.y, &C.x, &C.y) != EOF)
    {//如果原点在三角形内，下列的叉积符号是相同的，否则不可能相同
        sign = cross(O, A, B);
        if(0 == sign)
            continue;//O在AB边上
        t = cross(O, B, C);
        if(t != sign)
            continue;
        t = cross(O, C, A);
        if(t != sign)
            continue;
        cnt++;
    }
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
