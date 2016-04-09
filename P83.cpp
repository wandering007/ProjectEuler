<<<<<<< HEAD
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
#define MAXN 50000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//7s!!!two slow!!
int Matrix[81][81], Step[81][81];
//不少人采用BellmanFord/Dijkstra算法，没搞懂，不过速度比这快得多
void SearchPath(int x, int y)
{//周围点的Step值如果被更新，则对更新后的点进行搜索，类似于dijkstra算法
    if(y > 1)
    {
        if(Step[x][y] + Matrix[x][y - 1] < Step[x][y - 1])
        {
            Step[x][y - 1] = Step[x][y] + Matrix[x][y - 1];
            SearchPath(x, y - 1);
        }
    }
    if(y < 80)
    {
        if(Step[x][y] + Matrix[x][y + 1] < Step[x][y + 1])
        {
            Step[x][y + 1] = Step[x][y] + Matrix[x][y + 1];
            SearchPath(x, y + 1);
        }
    }
    if(x > 1)
    {
        if(Step[x][y] + Matrix[x - 1][y] < Step[x - 1][y])
        {
            Step[x - 1][y] = Step[x][y] + Matrix[x - 1][y];
            SearchPath(x - 1, y);
        }
    }
    if(x < 80)
    {
        if(Step[x][y] + Matrix[x + 1][y] < Step[x + 1][y])
        {
            Step[x + 1][y] = Step[x][y] + Matrix[x + 1][y];
            SearchPath(x + 1, y);
        }
    }
    return;
}

int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Documents\\p083_matrix.txt", "r", stdin);
    memset(Step, inf, sizeof(Step));//二维数组也可用memset, Step初始化为inf
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            scanf("%d", &Matrix[i][j]);
            getchar();
        }
    Step[1][1] = Matrix[1][1];
    SearchPath(1, 1);
    printf("%d\n", Step[80][80]);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
=======
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
#define MAXN 50000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//7s!!!two slow!!
int Matrix[81][81], Step[81][81];
//不少人采用BellmanFord/Dijkstra算法，没搞懂，不过速度比这快得多
void SearchPath(int x, int y)
{//周围点的Step值如果被更新，则对更新后的点进行搜索，类似于dijkstra算法
    if(y > 1)
    {
        if(Step[x][y] + Matrix[x][y - 1] < Step[x][y - 1])
        {
            Step[x][y - 1] = Step[x][y] + Matrix[x][y - 1];
            SearchPath(x, y - 1);
        }
    }
    if(y < 80)
    {
        if(Step[x][y] + Matrix[x][y + 1] < Step[x][y + 1])
        {
            Step[x][y + 1] = Step[x][y] + Matrix[x][y + 1];
            SearchPath(x, y + 1);
        }
    }
    if(x > 1)
    {
        if(Step[x][y] + Matrix[x - 1][y] < Step[x - 1][y])
        {
            Step[x - 1][y] = Step[x][y] + Matrix[x - 1][y];
            SearchPath(x - 1, y);
        }
    }
    if(x < 80)
    {
        if(Step[x][y] + Matrix[x + 1][y] < Step[x + 1][y])
        {
            Step[x + 1][y] = Step[x][y] + Matrix[x + 1][y];
            SearchPath(x + 1, y);
        }
    }
    return;
}

int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Documents\\p083_matrix.txt", "r", stdin);
    memset(Step, inf, sizeof(Step));//二维数组也可用memset, Step初始化为inf
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            scanf("%d", &Matrix[i][j]);
            getchar();
        }
    Step[1][1] = Matrix[1][1];
    SearchPath(1, 1);
    printf("%d\n", Step[80][80]);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
