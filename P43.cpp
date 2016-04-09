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
LL sum = 0LL;
int perm[11];
int check[] = {17, 13, 11, 7, 5, 3, 2};
LL toInt(int *digit, int len)
{
    LL res = 0LL;
    for(int i = 1; i <= len; i++)
        res = res * 10 + digit[i];
    return res;
}

bool fitProp(LL n)
{
   for(int i = 0; i <= 6; i++)
   {
       if(n % 1000 % check[i])
        return false;
       n /= 10;
   }
   return true;
}
void fulPerm(int low, int high, int x)
{
    for(int i = 1; i <= high - low + 1; i++)
    {
        if(perm[i] == 0)
        {
            perm[i] = x;
            if(x == low)
            {
                LL n = toInt(perm, high - low + 1);
                if(fitProp(n))
                    {
                        sum += n;
                        //printf("%I64d\n", n);
                    }
            }
            else fulPerm(low, high, x - 1);
            perm[i] = 0;
        }
    }
    return;
}
int main()
{
    clock_t start;
    double duration;
    start = clock();
    fulPerm(0, 9, 9);
    printf("%I64d\n", sum);
    duration = (double)(clock() - start)/CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
