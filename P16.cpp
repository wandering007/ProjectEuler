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
    int digit[400];
    memset(digit,-1,sizeof(digit));
    digit[0] = 0;
    digit[1] = 2;
    int c=0,d,temp;
    int N=999;
    while(N--)
    {
        d = 1;
        while(digit[d]!=-1||c!=0)
        {
            if(digit[d]==-1)
            {
                digit[d] = c;
                c = 0;
                d++;
                continue;
            }
            temp = digit[d]*2+c;
            c = temp/10;
            digit[d] = temp%10;
            d++;
        }
    }
    int sum = 0;
    d = 1;
    while(digit[d]!=-1)
        sum+=digit[d++];
    printf("%d is the sum of the digits of the number 2^1000\n",sum);
    return 0;
}
