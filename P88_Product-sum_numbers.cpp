#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define LL long long
#define eps 1e-8
#define MAXN 12000
using namespace std;
int MPSN[MAXN + 1];
bool vis[MAXN + 1];

void findMPSN(int k, int p, int s, int m)
{
    if(p - s + k > MAXN)
        return;
    //p - s: how many one should be added
    MPSN[p - s + k] = min(MPSN[p - s + k], p);
    for(int i = m; p * i < 2 * MAXN; i++)
        findMPSN(k + 1, p * i, s + i, m);
    return;
}

int main()
{
    clock_t start = clock();
    int sum = 0;
    for(int i = 2; i <= MAXN; i++)
        MPSN[i] = 2 * i; //1 + 1 + ... + 1 + i == 1 * 1 * ... * 1 * i
    findMPSN(1, 1, 1, 2);
    for(int i = 2; i <= MAXN; i++)
    {
        if(!vis[MPSN[i]])
            sum += MPSN[i];
        vis[MPSN[i]] = true;
    }
    printf("%d\n", sum);
    printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}
