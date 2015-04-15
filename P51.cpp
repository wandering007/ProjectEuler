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
#include<iomanip>
#define MAXN 10000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int prime[MAXN + 1], comp[MAXN + 1];
int top = 0;
void getprime()
{
    for(int p = 2; p <= MAXN; p++)
    {
        if(!comp[p])
        {
            for(int i = p + p; i <= MAXN; i += p)
                comp[i] = 1;
            prime[++top] = p;
        }
    }
    return;
}
bool isFound(int orig, int cur, int digit)
{
    int wrong = digit - 1;
    int dif = cur - orig;
    for(;digit <= 9; digit++)
    {
        if(comp[cur])
            wrong++;
        cur += dif;
        if(wrong > 2)
            return false;
    }
    return true;
}

bool isSuit(int orig, int n, int pos, int tag)
{
   int temp;
   for(; pos <= n; pos *= 10)
   {
       switch(n / pos % 10)
       {
       case 0:
        if(0 == tag || -1 == tag)
        {
            temp = n + pos;
            if(isFound(orig, temp, 1))
                return true;
            if(isSuit(orig, temp, pos * 10, 0))
                return true;
        }
        break;
       case 1:
        if(1 == tag || -1 == tag)
        {
            temp = n + pos;
            if(isFound(orig, temp, 2))
                return true;
            if(isSuit(orig, temp, pos * 10, 1))
                return true;
        }
        break;
        case 2:
        if(2 == tag || -1 == tag)
        {
            temp = n + pos;
            if(isFound(orig, temp, 3))
                return true;
            if(isSuit(orig, temp, pos * 10, 2))
                return true;
        }
        break;
        default:
            {;}
       }
   }
   return false;
}
int main()
{
    double duration;
    clock_t start = clock();
    getprime();
    for(int i = 1; i <= top; i++)
    {
        if(isSuit(prime[i], prime[i], 10, -1))
        {
            printf("%d\n", prime[i]);
            break;
        }
    }
    duration = (clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
