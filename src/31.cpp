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
#define MAXN 1000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int coin[]={1, 2, 5, 10, 20, 50, 100, 200};
int ways = 0;
void dfs(int k, int sum)
{
    if(sum == 200)
    {
        ways++;
        return;
    }
    if(k>7)
        return;
    dfs(k+1,sum);//不选第k个数
    for(int i=1;i <= 200/coin[k];i++)
    {
        sum += coin[k];//选i个第k个数
        if(sum <= 200)
            dfs(k+1, sum);
        else break;
    }
    return;
}
int main()
{
    dfs(0,0);
    printf("%d\n",ways);
    return 0;
}
/*another implementation
int ways(int n, int i)
{
    if (n < 0 || i < 0) return 0;
    if (n == 0) return 1;
    return ways(n - coin[i], i) + ways(n, i - 1);
}
int main()
{
    printf("%d\n", ways(200, 7));
    return 0;
}*/