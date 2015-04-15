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
#define MAXN 1000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int Hash[1005];
int RecurCycleLen(int divisor)
{
    memset(Hash,0,sizeof(Hash));
    int len=1, dividend = 1, rem = 1;
    while(Hash[rem]==0&&rem!=0)//Hash值不为零，表明一个cycle的结束；rem=0，说明能除尽，不满足题意
    {
        Hash[rem] = len;
        dividend = rem*10;
        rem = dividend % divisor;
        len++;
    }
    if(rem==0) return 0;
    return len-Hash[rem];
}
int main()
{
    int Max=0, rec = 1,temp;
    for(int d=2;d<1000;d++)
    {
        temp = RecurCycleLen(d);
        if(temp>Max)
        {
            Max = temp;
            rec = d;
        }
    }
    printf("1/%d contains the longest recurring cycle in its decimal fraction part.\n",rec);
    return 0;
}
