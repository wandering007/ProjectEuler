<<<<<<< HEAD
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
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int a[130];
    for(int i=1;i<=120;i++)
        scanf("%d",&a[i]);
    int level=14;
    int sum = 91;
    for(;level>=1;level--)
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
=======
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
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int a[130];
    for(int i=1;i<=120;i++)
        scanf("%d",&a[i]);
    int level=14;
    int sum = 91;
    for(;level>=1;level--)
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
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
