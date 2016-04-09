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
LL gcd(LL a,LL b)
{
    LL temp;
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(b==0) return 1;//本程序不会出现此情况
    while(a%b)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return b;
}
int main()
{
    LL res1=1LL,res2=1LL,g;
    for(int i=40,j=20;i>20;i--,j--)//等价限制条件：j>0
    {
        res1*=i;
        res2*=j;
        g = gcd(res1,res2);//防止数据过大
        res1/=g;
        res2/=g;
    }
    printf("There are %I64d routes through a 20×20 grid.\n",res1);
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
LL gcd(LL a,LL b)
{
    LL temp;
    if(a<b)
    {
        temp = a;
        a = b;
        b = temp;
    }
    if(b==0) return 1;//本程序不会出现此情况
    while(a%b)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return b;
}
int main()
{
    LL res1=1LL,res2=1LL,g;
    for(int i=40,j=20;i>20;i--,j--)//等价限制条件：j>0
    {
        res1*=i;
        res2*=j;
        g = gcd(res1,res2);//防止数据过大
        res1/=g;
        res2/=g;
    }
    printf("There are %I64d routes through a 20×20 grid.\n",res1);
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
