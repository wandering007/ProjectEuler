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
bool isDist(int a, int b, int c, int d, int e)
{
    int Hash[10] = {1};
    Hash[a]++;
    if(Hash[b]==1)
        return false;
    Hash[b]++;
    if(Hash[c]==1)
        return false;
    Hash[c]++;
    if(Hash[d]==1)
        return false;
    Hash[d]++;
    if(Hash[e]==1)
        return false;
    return true;
}
int OneFour(int a,int b4,int b3,int b2, int b1)
{
    int b = b1+b2*10+b3*100+b4*1000;
    int Hash[10] = {1};
    Hash[a] = 1;
    Hash[b1] = 1;
    Hash[b2] = 1;
    Hash[b3] = 1;
    Hash[b4] = 1;
    int pro = a*b, digit ,res = a*b;
    for(int i=1; i <= 4; i++)
    {
        digit = pro%10;
        if(Hash[digit]==1)
            return 0;
        Hash[digit] = 1;
        pro/=10;
    }
    if(pro)
        return 0;
    return res;
}
int TwoThree(int a1, int a2, int b1, int b2, int b3)
{
    int a = a1 + a2*10;
    int b = b1 + b2*10 + b3*100;
    int Hash[10]={1};
    Hash[a1] = 1;
    Hash[a2] = 1;
    Hash[b1] = 1;
    Hash[b2] = 1;
    Hash[b3] = 1;
    int pro = a*b, digit, res = a*b;
    for(int i=1;i<=4;i++)
    {
        digit = pro % 10;
        if(Hash[digit] == 1)
            return 0;
        Hash[digit] = 1;
        pro/=10;
    }
    if(pro)
        return 0;
    return res;
}
int main()
{
    int sum = 0;
    set<int> s;
    s.clear();
    for(int i=1;i <= 9;i++)
      for(int j=1;j <= 9;j++)
          for(int k = 1;k <= 9;k++)
            for(int l = 1;l <= 9;l++)
              for(int m = 1; m <= 9; m++)
                {
                    if(isDist(i,j,k,l,m)==false)
                        continue;
                    s.insert(OneFour(i,j,k,l,m));
                    s.insert(TwoThree(i,j,k,l,m));
                }
    set<int>::const_iterator it;
    for(it=s.begin();it!=s.end(); it++)
        sum += *it;
    printf("%d\n",sum);
    return 0;
}
