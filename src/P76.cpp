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
//a slow way, 2s
int NumOfSum(int p, int x, int sum)
{
    if(1 == x)
        return 1;//x == 1ʱ��ϵ��Ψһ��ȡsum - p
    int res = 0;
    for(int i = 0; i + p <= sum; i += x)
        res += NumOfSum(p + i, x - 1, sum);
    return res;
}

int main()
{
    clock_t start = clock();
    printf("%d\n", NumOfSum(0, 99, 100));
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
//a fast way, 0s
/*
int sum[101];

int main()
{
    clock_t start = clock();
    sum[0] = 1;
    for(int i = 1; i <= 99; i++)//iֻ�ܵ�99����֤����������������
        for(int j = i; j <= 100; j++)
            sum[j] += sum[j - i];//��ֵΪj�����������ֵΪi���������ӵ�sum[j]��
    printf("%d\n", sum[100]);
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
*/