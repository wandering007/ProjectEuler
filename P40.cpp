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
#define MAXN 10000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int digit[8]={1};
int pos(int number, int d)
{
    while(--d)
    {
        number/=10;
    }
    return number % 10;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    int res = 1;
    int len = 0, n=0, ind = 1;
    for(int i=1;i<=7;i++)
        digit[i] = digit[i-1]*10;
    for(int i = 1;;i++)
    {
        if(i == digit[len])
            len++;
        n += len;
        if(n >= ind)
        {
           res *= pos(i, n - ind + 1);
           //printf("%d\t",pos(i, n - ind + 1));
           if(ind == 1000000)
            break;
           ind *= 10;
        }
    }
    printf("%d\n", res);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
}
//也可以将数字转化成字符，一个一个赋值，最后直接查找即可，从实际应用上将这样更方便
