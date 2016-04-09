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
#define MAXN 10000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

bool isOddPeri(int n, int a0)
{
    if(a0 * a0 == n)
        return false;
    int k = a0, a = a0, d = 1, p = 0, temp;
    do
    {
        p++;
        temp = n - k * k;
        d = temp / d;//temp能整除d，不难推证
        a = (int)((sqrt(n) + k) / (d * 1.0) + eps);//a为整数部分
        k = a * d - k;
    }while(!(k == a0 && d == 1));
    return p & 1;
}
int main()
{
    double duration;
    clock_t start = clock();
    int temp, cnt = 0;
    for(int i = 1; i <= MAXN; i++)
    {
        temp = (int)(sqrt(i) + eps);
        if(isOddPeri(i, temp))
            cnt++;
    }
    printf("%d\n", cnt);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
//can refer to:
//https://proofwiki.org/wiki/Continued_Fraction_Expansion_of_Irrational_Square_Root
//http://web.math.princeton.edu/mathlab/jr02fall/Periodicity/mariusjp.pdf
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
#define MAXN 10000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

bool isOddPeri(int n, int a0)
{
    if(a0 * a0 == n)
        return false;
    int k = a0, a = a0, d = 1, p = 0, temp;
    do
    {
        p++;
        temp = n - k * k;
        d = temp / d;//temp能整除d，不难推证
        a = (int)((sqrt(n) + k) / (d * 1.0) + eps);//a为整数部分
        k = a * d - k;
    }while(!(k == a0 && d == 1));
    return p & 1;
}
int main()
{
    double duration;
    clock_t start = clock();
    int temp, cnt = 0;
    for(int i = 1; i <= MAXN; i++)
    {
        temp = (int)(sqrt(i) + eps);
        if(isOddPeri(i, temp))
            cnt++;
    }
    printf("%d\n", cnt);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
//can refer to:
//https://proofwiki.org/wiki/Continued_Fraction_Expansion_of_Irrational_Square_Root
//http://web.math.princeton.edu/mathlab/jr02fall/Periodicity/mariusjp.pdf
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
