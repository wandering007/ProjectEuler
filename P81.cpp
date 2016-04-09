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
#define MAXN 10000000
#define MOD 10000000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

int dp[81][81];
int Matrix[81][81];
int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Desktop\\p081_matrix.txt", "r", stdin);//注意使用"\\"表示路径
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            scanf("%d", &Matrix[i][j]);
            getchar();
        }
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            if(1 == i)
                dp[i][j] = dp[i][j - 1] + Matrix[i][j];
            else if(1 == j)
                dp[i][j] = dp[i - 1][j] + Matrix[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + Matrix[i][j];
        }
    printf("%d\n", dp[80][80]);
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
#define MAXN 10000000
#define MOD 10000000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

int dp[81][81];
int Matrix[81][81];
int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Desktop\\p081_matrix.txt", "r", stdin);//注意使用"\\"表示路径
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            scanf("%d", &Matrix[i][j]);
            getchar();
        }
    for(int i = 1; i <= 80; i++)
        for(int j = 1; j <= 80; j++)
        {
            if(1 == i)
                dp[i][j] = dp[i][j - 1] + Matrix[i][j];
            else if(1 == j)
                dp[i][j] = dp[i - 1][j] + Matrix[i][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + Matrix[i][j];
        }
    printf("%d\n", dp[80][80]);
    printf("time cost: %lf", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
