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
#define MAXN 1500000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//http://en.wikipedia.org/wiki/Tree_of_primitive_Pythagorean_triples
typedef struct
{
    int a, b, c;
}node;
node Triple[MAXN];//队列
int Rec[MAXN + 1];
int Matrix[3][3][3] =
{
    {//A
        {1, -2, 2},
        {2, -1, 2},
        {2, -2, 3}
    },
    {//B
        {1, 2, 2},
        {2, 1, 2},
        {2, 2, 3}
    },
    {//C
        {-1, 2, 2},
        {-2, 1, 2},
        {-2, 2, 3}
    }

};

node multiply(int n, node T)
{
    node res;
    res.a = Matrix[n][0][0] * T.a + Matrix[n][0][1] * T.b + Matrix[n][0][2] * T.c;
    res.b = Matrix[n][1][0] * T.a + Matrix[n][1][1] * T.b + Matrix[n][1][2] * T.c;
    res.c = Matrix[n][2][0] * T.a + Matrix[n][2][1] * T.b + Matrix[n][2][2] * T.c;
    return res;
}

void TreeOfPrimPythagoreanTriple()
{
    node root, t, temp;
    root.a = 3;
    root.b = 4;
    root.c = 5;
    int Front = -1, Rear = -1, L;
    Triple[++Rear] = root;
    while(Front != Rear)
    {
        Front = (Front + 1) % MAXN;//出队列
        t = Triple[Front];
        L = t.a + t.b + t.c;//取出的均符合条件
        for(int i = L; i <= MAXN; i += L)
            Rec[i]++;//primitive Pythagorean triples以及它的倍数
        for(int i = 0; i < 3; i++)
        {
            temp = multiply(i, t);
            if(temp.a + temp.b + temp.c <= MAXN)
            {
                Rear = (Rear + 1) % MAXN;//入队列
                Triple[Rear] = temp;
            }
        }
    }
    return;
}

int main()
{
    clock_t start = clock();
    TreeOfPrimPythagoreanTriple();
    int cnt = 0;
    for(int i = 12; i <= MAXN; i += 2)//L只有可能是偶数
        if(Rec[i] == 1)
            cnt++;
    printf("%d\n", cnt);
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
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
#define MAXN 1500000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//http://en.wikipedia.org/wiki/Tree_of_primitive_Pythagorean_triples
typedef struct
{
    int a, b, c;
}node;
node Triple[MAXN];//队列
int Rec[MAXN + 1];
int Matrix[3][3][3] =
{
    {//A
        {1, -2, 2},
        {2, -1, 2},
        {2, -2, 3}
    },
    {//B
        {1, 2, 2},
        {2, 1, 2},
        {2, 2, 3}
    },
    {//C
        {-1, 2, 2},
        {-2, 1, 2},
        {-2, 2, 3}
    }

};

node multiply(int n, node T)
{
    node res;
    res.a = Matrix[n][0][0] * T.a + Matrix[n][0][1] * T.b + Matrix[n][0][2] * T.c;
    res.b = Matrix[n][1][0] * T.a + Matrix[n][1][1] * T.b + Matrix[n][1][2] * T.c;
    res.c = Matrix[n][2][0] * T.a + Matrix[n][2][1] * T.b + Matrix[n][2][2] * T.c;
    return res;
}

void TreeOfPrimPythagoreanTriple()
{
    node root, t, temp;
    root.a = 3;
    root.b = 4;
    root.c = 5;
    int Front = -1, Rear = -1, L;
    Triple[++Rear] = root;
    while(Front != Rear)
    {
        Front = (Front + 1) % MAXN;//出队列
        t = Triple[Front];
        L = t.a + t.b + t.c;//取出的均符合条件
        for(int i = L; i <= MAXN; i += L)
            Rec[i]++;//primitive Pythagorean triples以及它的倍数
        for(int i = 0; i < 3; i++)
        {
            temp = multiply(i, t);
            if(temp.a + temp.b + temp.c <= MAXN)
            {
                Rear = (Rear + 1) % MAXN;//入队列
                Triple[Rear] = temp;
            }
        }
    }
    return;
}

int main()
{
    clock_t start = clock();
    TreeOfPrimPythagoreanTriple();
    int cnt = 0;
    for(int i = 12; i <= MAXN; i += 2)//L只有可能是偶数
        if(Rec[i] == 1)
            cnt++;
    printf("%d\n", cnt);
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
