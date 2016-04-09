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
#define MAXN 1000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
bool IsPrime(int n)
{
    int lim = sqrt(n + 1);//a very clever way
    for(int i = 2; i <= lim; i++)
        if(n % i == 0)
            return false;
    return true;
}
int main()
{
    double duration;
    clock_t start = clock();
    int NumOfPrime = 0, DiagNum = 1, temp;
    for(int k = 1; ; k++)
    {
        temp = (2 * k + 1) * (2 * k + 1);//右下顶点，奇数的平方，一定不是prime
        for(int j = 1; j <= 3; j++)
        {
            temp -= 2 * k;//得到其他三个顶点的数值
            if(IsPrime(temp))
                NumOfPrime++;
        }
        DiagNum += 4;//没增加一个外框对角线上增加4个数
        if(10 * NumOfPrime < DiagNum)//less than 10%
            break;
    }
    printf("%d\n", (DiagNum - 1) / 2 + 1);//n = 2 * k + 1, k = (DiagNum - 1) / 4
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
#define MAXN 1000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
bool IsPrime(int n)
{
    int lim = sqrt(n + 1);//a very clever way
    for(int i = 2; i <= lim; i++)
        if(n % i == 0)
            return false;
    return true;
}
int main()
{
    double duration;
    clock_t start = clock();
    int NumOfPrime = 0, DiagNum = 1, temp;
    for(int k = 1; ; k++)
    {
        temp = (2 * k + 1) * (2 * k + 1);//右下顶点，奇数的平方，一定不是prime
        for(int j = 1; j <= 3; j++)
        {
            temp -= 2 * k;//得到其他三个顶点的数值
            if(IsPrime(temp))
                NumOfPrime++;
        }
        DiagNum += 4;//没增加一个外框对角线上增加4个数
        if(10 * NumOfPrime < DiagNum)//less than 10%
            break;
    }
    printf("%d\n", (DiagNum - 1) / 2 + 1);//n = 2 * k + 1, k = (DiagNum - 1) / 4
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
