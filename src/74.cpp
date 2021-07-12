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
#define MAXN 1000000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int Factorial[10] = {1}, Step[3 * MAXN];
int Rec[61];

int SumFactOfDigit(int n)
{
    int res = 0LL;
    while(n)
    {
        res += Factorial[n % 10];
        n /= 10;
    }
    return res;
}

void testStep(int n)
{
    Rec[0] = 1;
    Rec[1] = n;
    while(Rec[0] <= 60)
    {
        n = SumFactOfDigit(n);
        if(n == Rec[1])//循环到自己
            break;
        Rec[++Rec[0]] = n;
    }
    if(Rec[1] == n)//是自循环
    {
        for(int i = 1; i <= Rec[0]; i++)
        {
            Step[Rec[i]] = Rec[0];//途中的所有数的循环数均为Rec[0]
           // printf("%d\n", Rec[i]);
        }
    }
    return;
}

bool isSuit(int n)
{
    if(Step[n])
    {
        if(60 == Step[n])
            return true;
        return false;
    }
    Rec[0] = 1;
    Rec[1] = n;//建个栈用来记录路径中的数
    while(!Step[n])
    {
        n = SumFactOfDigit(n);
        Rec[++Rec[0]] = n;
    }
    for(int i = Rec[0] - 1; i > 0; i--)
    {
        Step[Rec[i]] = Step[Rec[Rec[0]]] + Rec[0] - i;
    }
    if(60 == Step[Rec[1]])
        return true;
    return false;
}

int main()
{
    clock_t start = clock();
    for(int i = 1; i <= 9; i++)
        Factorial[i] = i * Factorial[i - 1];//set the factorial value
    int cnt = 0;
    for(int i = 1; i <= MAXN; i++)
    {
        if(!Step[i])//未找到路径
            testStep(i);
    }
    for(int i = 1; i <= MAXN; i++)
    {
        if(isSuit(i))
            cnt++;
    }
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
