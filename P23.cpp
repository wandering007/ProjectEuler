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
#define MAXN 28123
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
bool IsAbdant(int n)
{
    int sum = 0;
    for(int i=1; i<n; i++)
    {
        if(n%i==0)
            sum += i;
    }
    if(sum>n)return true;
    return false;
}
int main()
{
    int n = 0, Abdant[MAXN], vis[MAXN]= {}, temp, sum = 0;
    for(int i = 1; i < MAXN; i++)
        if(IsAbdant(i))
            Abdant[++n] = i;
    for(int i=1; i<n; i++)
    {
        for(int j=i; j<=n; j++)
        {
            temp = Abdant[i]+Abdant[j];//将所有小于MAXN的abundant数两两相加
            if(temp>=MAXN)
                break;
            vis[temp] = 1;
        }
    }
    for(int i=1; i<MAXN; i++)
        if(!vis[i])sum += i;
    printf("The sum of all the positive integers which cannot be written as the sum of two abundant numbers is %d\n",sum);
    return 0;
}
