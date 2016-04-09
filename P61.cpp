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
#define MAXN 9999
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

typedef struct
{
    int index, val;
} node;
node p[7][100][100];
node rec[7];
bool vis[7];

int Formulae(int p, int n)
{
    switch(p)
    {
    case 1:
        return n * (n + 1) / 2;
    case 2:
        return n * n;
    case 3:
        return n * (3 * n - 1) / 2;
    case 4:
        return n * (2 * n - 1);
    case 5:
        return n * (5 * n - 3) / 2;
    case 6:
        return n * (3 * n - 2);
    default:
        printf("impossible\n");
        return 0;
    }
}

bool check(int a, int b)
{
    if(6 == a)
        return true;
    if(6 == b)
        return check(a + 1, a + 2);
    if(rec[a].index == rec[b].index)
        return false;
    return check(a, b + 1);
}
bool isSuit(int pos, int c)
{
    vis[pos] = true;
    if(c == 6)
    {
        for(int i = 1; i <= p[pos][rec[pos].val][0].val; i++)
            if(p[pos][rec[pos].val][i].val == rec[1].val && check(1, 2))
            {
                rec[pos].index = p[pos][rec[pos].val][i].index;
                return true;
            }
        vis[pos] = false;
        return false;
    }
    for(int i = 1; i <= p[pos][rec[pos].val][0].val; i++)
    {
        rec[pos].index = p[pos][rec[pos].val][i].index;
        for(int j = 1; j <= 6; j++)
            if(!vis[j])
        {
            rec[j].val = p[pos][rec[pos].val][i].val;
            if(isSuit(j, c + 1))
             return true;
        }
    }
    vis[pos] = false;
    return false;
}

int main()
{
    double duration;
    clock_t start = clock();
    int temp;
    for(int i = 1; i <= 6; i++)
        for(int j = 1; ; j++)
        {
            temp = Formulae(i, j);
            if(temp < 1000)
                continue;
            if(temp > MAXN)
                break;
            if(temp % 100 >= 10)
            {
                p[i][temp / 100][++p[i][temp / 100][0].val].val = temp % 100;
                p[i][temp / 100][p[i][temp / 100][0].val].index = j;
            }
        }
    for(rec[1].val = 10; rec[1].val < 100; rec[1].val++)
        if(isSuit(1, 1))
            break;
    int sum = 0;
    for(int i = 1; i <= 6; i++)
        sum += Formulae(i, rec[i].index);
    printf("%d\n", sum);
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
#define MAXN 9999
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

typedef struct
{
    int index, val;
} node;
node p[7][100][100];
node rec[7];
bool vis[7];

int Formulae(int p, int n)
{
    switch(p)
    {
    case 1:
        return n * (n + 1) / 2;
    case 2:
        return n * n;
    case 3:
        return n * (3 * n - 1) / 2;
    case 4:
        return n * (2 * n - 1);
    case 5:
        return n * (5 * n - 3) / 2;
    case 6:
        return n * (3 * n - 2);
    default:
        printf("impossible\n");
        return 0;
    }
}

bool check(int a, int b)
{
    if(6 == a)
        return true;
    if(6 == b)
        return check(a + 1, a + 2);
    if(rec[a].index == rec[b].index)
        return false;
    return check(a, b + 1);
}
bool isSuit(int pos, int c)
{
    vis[pos] = true;
    if(c == 6)
    {
        for(int i = 1; i <= p[pos][rec[pos].val][0].val; i++)
            if(p[pos][rec[pos].val][i].val == rec[1].val && check(1, 2))
            {
                rec[pos].index = p[pos][rec[pos].val][i].index;
                return true;
            }
        vis[pos] = false;
        return false;
    }
    for(int i = 1; i <= p[pos][rec[pos].val][0].val; i++)
    {
        rec[pos].index = p[pos][rec[pos].val][i].index;
        for(int j = 1; j <= 6; j++)
            if(!vis[j])
        {
            rec[j].val = p[pos][rec[pos].val][i].val;
            if(isSuit(j, c + 1))
             return true;
        }
    }
    vis[pos] = false;
    return false;
}

int main()
{
    double duration;
    clock_t start = clock();
    int temp;
    for(int i = 1; i <= 6; i++)
        for(int j = 1; ; j++)
        {
            temp = Formulae(i, j);
            if(temp < 1000)
                continue;
            if(temp > MAXN)
                break;
            if(temp % 100 >= 10)
            {
                p[i][temp / 100][++p[i][temp / 100][0].val].val = temp % 100;
                p[i][temp / 100][p[i][temp / 100][0].val].index = j;
            }
        }
    for(rec[1].val = 10; rec[1].val < 100; rec[1].val++)
        if(isSuit(1, 1))
            break;
    int sum = 0;
    for(int i = 1; i <= 6; i++)
        sum += Formulae(i, rec[i].index);
    printf("%d\n", sum);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
