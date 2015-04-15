#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cmath>
#include<math.h>
#include<ctime>
#define MAXN 1000000
#define LL long long
using namespace std;

bool isSquareNumber(int n)
{
    int sq = sqrt(n) + 0.5; //avoid the problem of precision
    return sq * sq == n;
}

int main()
{
    clock_t start = clock();
    unsigned int cnt = 0, maxEdge = 1;
    while(cnt <= MAXN)
    {
        maxEdge++;
        for(unsigned int s = 2; s <= 2 * maxEdge; s++)
        {
            if(isSquareNumber(s * s + maxEdge * maxEdge))
                cnt += min(s - 1, maxEdge) - (s - 1) / 2;
            //a + b == s, a <= b <= maxEdge, there are (s- 1) tuples: (1, s - 1), (2, s - 2), ..., (s - 2, 2), (s - 1, 1)
            //min(s - 1, maxEdge) means that the second longest edge doesn't exceed maxEdge;
            //and (s - 1) / 2 should be subtracted for duplicating.
            //think elaborately when s is even, (s / 2, s / 2) should not be considered as double
        }
    }
    printf("%d\n", maxEdge);
    printf("time cost: %f s.\n", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
