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
int gcd(int x, int y)//x>y&&y!=0
{
    int temp;
    while(x%y)
    {
        temp = y;
        y = x % y;
        x = temp;
    }
    return y;
}
bool isLager(int a2, int a1, int b2, int b1)
{
    if(b2>a2)
        return true;
    if(b2==a2&&b1>a1)
        return true;
    return false;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    int numerator = 1, denominator = 1;
    for(int i=1; i<=9; i++)
        for(int j=i+1; j<=9; j++)//i<j
            for(int k=1; k<=9; k++)
            {
                if(isLager(i,k,k,j)==true)
                {
                    if((i*10+k)*j==(k*10+j)*i)
                    {
                        numerator*=i;
                        denominator*=j;
                    }
                }
                if(isLager(k,i,j,k)==true)
                {
                    if((k*10+i)*j==(j*10+k)*i)
                    {
                        numerator*=i;
                        denominator*=j;
                    }
                }
            }
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("%d\n",denominator/gcd(denominator, numerator));
    printf("Time cost: %f s.\n", duration);
}
