<<<<<<< HEAD
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
#define MAXN 100000
#define BASE 15
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int digit[16];
typedef struct
{
    LL val;
    int id;
}node;
node rec[MAXN];

LL cube(int n)
{
    return (LL)n * n * n;
}

void ToString(LL n)
{
    while(n)
    {
        digit[++digit[0]] = n % 10;
        n /= 10;
    }
    return;
}

LL ToInt()
{
    LL res = 0LL;
    while(digit[0])
    {
        res = res * 10 + digit[digit[0]];
        digit[0]--;
    }
    return res;
}

void Append(int f)//f对应的结果放入rec[f]
{
    LL n = cube(f);
    ToString(n);
    sort(digit + 1, digit + digit[0] + 1);//排序化成最大值，回避出现最高位为零的情况，作为标志很完美
    LL res = ToInt();
    rec[f].val = res;
    rec[f].id = f;
    return;
}
//another implementation
/*
LL Weight(int k)//BASE^k
{
    LL res = 1LL;
    while(k--)
    {
        res *= BASE;
    }
    return res;
}

void Append(int f)//f对应的结果放入rec[f]
{
    LL n = cube(f);
    memset(digit, 0, sizeof(digit));
    while(n)
    {
        digit[n % 10]++;
        n /= 10;
    }
    LL res = 0LL;
    for(int i = 0; i <= 9; i++)
        res += digit[i] * Weight(i);//转化成15进制的十进制表示
    rec[f].val = res;
    rec[f].id = f;
    return;
}
*/
bool cmp(node a, node b)
{
    if(a.val < b.val)
        return true;
    if(a.val == b.val)
        return a.id < b.id;
    return false;
}

int main()
{
    double duration;
    clock_t start = clock();
    for(int i = 1; i < MAXN; i++)
        Append(i);
    sort(rec + 1, rec + MAXN, cmp);
    int cnt, Min = MAXN;
    for(int i = 1; i < MAXN; i++)
    {
        cnt = 1;
        while(i + 1 < MAXN && rec[i].val == rec[i + 1].val)
            {
                cnt++;
                i++;
            }
        if(5 == cnt)
        {
            if(rec[i - 4].id < Min)
            {
                Min = rec[i - 4].id;
            }
        }
    }
    printf("%d ^ 3 = %I64d\n", Min, cube(Min));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
=======
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
#define MAXN 100000
#define BASE 15
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int digit[16];
typedef struct
{
    LL val;
    int id;
}node;
node rec[MAXN];

LL cube(int n)
{
    return (LL)n * n * n;
}

void ToString(LL n)
{
    while(n)
    {
        digit[++digit[0]] = n % 10;
        n /= 10;
    }
    return;
}

LL ToInt()
{
    LL res = 0LL;
    while(digit[0])
    {
        res = res * 10 + digit[digit[0]];
        digit[0]--;
    }
    return res;
}

void Append(int f)//f对应的结果放入rec[f]
{
    LL n = cube(f);
    ToString(n);
    sort(digit + 1, digit + digit[0] + 1);//排序化成最大值，回避出现最高位为零的情况，作为标志很完美
    LL res = ToInt();
    rec[f].val = res;
    rec[f].id = f;
    return;
}
//another implementation
/*
LL Weight(int k)//BASE^k
{
    LL res = 1LL;
    while(k--)
    {
        res *= BASE;
    }
    return res;
}

void Append(int f)//f对应的结果放入rec[f]
{
    LL n = cube(f);
    memset(digit, 0, sizeof(digit));
    while(n)
    {
        digit[n % 10]++;
        n /= 10;
    }
    LL res = 0LL;
    for(int i = 0; i <= 9; i++)
        res += digit[i] * Weight(i);//转化成15进制的十进制表示
    rec[f].val = res;
    rec[f].id = f;
    return;
}
*/
bool cmp(node a, node b)
{
    if(a.val < b.val)
        return true;
    if(a.val == b.val)
        return a.id < b.id;
    return false;
}

int main()
{
    double duration;
    clock_t start = clock();
    for(int i = 1; i < MAXN; i++)
        Append(i);
    sort(rec + 1, rec + MAXN, cmp);
    int cnt, Min = MAXN;
    for(int i = 1; i < MAXN; i++)
    {
        cnt = 1;
        while(i + 1 < MAXN && rec[i].val == rec[i + 1].val)
            {
                cnt++;
                i++;
            }
        if(5 == cnt)
        {
            if(rec[i - 4].id < Min)
            {
                Min = rec[i - 4].id;
            }
        }
    }
    printf("%d ^ 3 = %I64d\n", Min, cube(Min));
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
