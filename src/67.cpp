#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#define MAXN 100
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int a[5055];//根据MAXN的大小做更改
    freopen("triangle.txt","r",stdin);//ACM常用的技巧啊
    int tot = (1+MAXN)*MAXN/2;
    for(int i=1;i<=tot;i++)
        scanf("%d",&a[i]);
    int sum = (MAXN-1)*(MAXN-2)/2;
    for(int level=MAXN-1;level>=1;level--)//从第MAXN-1层开始累加，第一层的累加值即为最大值
    {
        for(int id = sum+1;id<=sum+level;id++)
        {
            a[id]+=max(a[id+level],a[id+level+1]);//动态规划
        }
        sum-=level-1;
    }
    printf("The maximum total from top to bottom of the triangle is %d\n",a[1]);
    return 0;
}
