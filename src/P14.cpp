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
int chain[1000005];
int vis[1000005]= {1,1};
int step(LL n)//n���ܻᳬ��int��Χ
{
    if(n<=MAXN)
    {
         if(vis[n])
            return chain[n];
    }
    LL k;
    int res;
    if(n%2)
        k = 3*n+1;//��һ�����ܻᵼ��k(��n)�ܴ�
    else k=n/2;
    res=step(k)+1;
    if(n<=MAXN)
    {
        vis[n] = 1;
        chain[n] = res;
    }
    return res;
}
int main()
{
    int max_step,temp,rec = 1;
    for(LL i=1; i<=MAXN; i++)
    {
        temp = step(i);
        if(temp>max_step)
        {
            rec = i;
            max_step = temp;
        }
    }
    printf("The starting number is %d.\nThe longest chain's length is %d.\n",rec,max_step);
    return 0;
}
