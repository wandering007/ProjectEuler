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
#define MAXN 10000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int a[100], b[100];
void ToString(int n, int &l)
{
    l = 0;
    while(n)
    {
        a[++ l] = n % 10;
        n /= 10;
    }
    return;
}
void rever(int l)
{
    for(int i = l; i >= 1; i --)
        b[l - i + 1] = a[i];
    return;
}
void add(int &l)
{
    int carryin = 0, temp;
    a[l + 1] = b[l + 1] = 0;
    for(int i = 1; i <= l + 1; i ++)
    {
        temp = (a[i] + b[i] + carryin) % 10;
        carryin = (a[i] + b[i] + carryin) / 10;
        a[i] = temp;
    }
    if(a[l + 1])
        l ++;
    return;
}
bool isPalind(int l)
{
    for(int i = 1; i <= l / 2; i ++)
        if(a[i] != a[l - i + 1])
            return false;
    return true;
}
bool isLychrel(int n)
{
    int it = 0, len;
    ToString(n, len);
    while(++it < 50)
    {
        rever(len);
        add(len);
        if(isPalind(len))
            return false;
    }
    return true;
}
int main()
{
    double duration;
    clock_t start = clock();
    int num = 0;
    for(int i = 1; i < MAXN; i ++)
    {
        if(isLychrel(i))
            num ++;
    }
    printf("%d\n",num);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
