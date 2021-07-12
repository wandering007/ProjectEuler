#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<set>
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
#define MAXN 13
#define MOD 1<<64
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

//Lagrange polynomial
//There are better ways to solve it
LL pow(LL x, int n)
{
    LL res = 0LL;
    if (0 == n)
        return res;
    while (n)
    {
        if (n & 1)
            res *= x;
        x *= x;
        n >>= 1;
    }
    return res;
}

int main()
{
	clock_t start = clock();
    LL u[11];
    for(int i = 1; i <= 10; i++)
        u[i] = (1 + pow(i, 11)) / (1 + i);
	double FITsum = 1.0;
	double s;
	for(int n = 2; n <= 10; n++) //OP(1, n)已考虑
	{
		s = 0.;
		for(int i = 1; i <= n; i++)
		{
			LL nume = u[i], denomi = 1LL;
			for(int j = 1; j <= n; j++)
            {
                //拉格朗日插值
                //第二拉格朗日插值可减少计算量
                if(j != i)
                {
                    nume *= n + 1 - j;
                    denomi *= i - j;
                }
            }
			s += nume / (denomi * 1.0);
		}
		FITsum += s;
	}
	cout << (LL)FITsum << endl;
	cout << "Time cost: " << setprecision(6) << scientific << (double)(clock() - start) / CLOCKS_PER_SEC << " s." << endl;
	return 0;
}
