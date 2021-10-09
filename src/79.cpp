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
#define MAXN 50000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//������û�п����������ظ������������������ظ��Ļ����ֵ�˳��Ƚϻ���ֳ�ͻ��
typedef struct List
{
    int val;
    List* next;
}List;
int Comp[10][10];

void ListInsert(int v, List* &p)
{
    List* q = p->next;
    List* t = (List*)malloc(sizeof(List));
    t->val = v;
    p->next = t;
    t->next = q;
    return;
}

void CodeAdjust(int v, List* &T)
{
    if(T->next == T)
    {
        for(int i = 0; i <= 9; i++)
        {
            if(Comp[v][i])
            {
                ListInsert(v, T);
                return;
            }
        }
        return;
    }
    List* p;
    List* q;//'*'ֻ�ܶ���֮��ĵ�һ������������
    p = T->next;
    q = T;//v���뵽q��һλ�ã���q��ʼ��Ϊͷ���λ��
    bool status = false;
    while(T != p)
    {
        if(Comp[v][p->val])
            status = true;
        if(1 == Comp[v][p->val])
            q = p;
        else if(-1 == Comp[v][p->val])
            break;
        p = p->next;
    }
    if(!status)
        return;
    ListInsert(v, q);
    return;
}

int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\Leo Cheng\\Documents\\p079_keylog.txt", "r", stdin);
    int a, b, c;
    while(scanf("%1d%1d%1d", &a, &b, &c) != EOF)
    {
        if(1 == Comp[a][b] || 1 == Comp[a][c] || 1 == Comp[b][c])
        {
            printf("�������ظ����˷��������ã�\n");
            return 0;
        }
        Comp[a][b] = -1;
        Comp[a][c] = -1;
        Comp[b][c] = -1;
        Comp[b][a] = 1;
        Comp[c][a] = 1;
        Comp[c][b] = 1;
    }
    List* T = (List*)malloc(sizeof(List));
    T->next = T;//ѭ������
    for(int i = 0; i <= 9; i++)
        CodeAdjust(i, T);
    List* p = T->next;
    while(p != T)
    {
        printf("%d", p->val);
        p = p->next;
    }
    printf("\n");
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
