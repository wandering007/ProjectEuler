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
#define MAXN 30000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int rec[6];
int prime[MAXN + 1];
bool comp[MAXN + 1];
int Set[6][MAXN];
int sum = MAXN * 5;
//运行有点慢，7s
void getprime()
{
    for(int p = 2; p <= MAXN; p++)
    {
        if(!comp[p])
        {
            for(int i = p + p; i <= MAXN; i += p)
                comp[i] = true;
            prime[++prime[0]] = p;
        }
    }
    return;
}

bool isPrime(LL n)
{
    if(n <= MAXN)
        return !comp[n];
    int limit = sqrt(n + 1);
    for(int i = 1; i <= prime[0] && prime[i] <= limit; i++)
    {
        if(0 == n % prime[i])
            return false;
    }
    return true;
}

int Digit(int n)
{
    int l = 1;
    while(n)
    {
        l *= 10;
        n /= 10;
    }
    return l;
}

int SumOfFive(int* a)
{
    int res = 0;
    for(int i = 1; i <= 5; i++)
        res += a[i];
    return res;
}

int isFound(int index, int num)
{
    rec[num] = Set[num - 1][index];
    if(5 == num)
        return SumOfFive(rec);
    int l0 = Digit(rec[num]), l1;
    Set[num][0] = 0;
    int temp;
    for(int i = index + 1; i <= Set[num - 1][0]; i++)
    {
        l1 = Digit(Set[num - 1][i]);
        if(isPrime((LL)rec[num] * l1 + Set[num - 1][i]) && isPrime((LL)Set[num - 1][i] * l0 + rec[num]))
            Set[num][++Set[num][0]] = Set[num - 1][i];
    }
    for(int i = 1; i <= Set[num][0] + num - 4; i++)
        {
            temp = 0;
            for(int j = 1; j<= num; j++)
                temp += rec[j];
            for(int j = 0; j <= 4 - num; j++)
                temp += Set[num][i + j];
            if(temp >= sum)
                return sum;
            sum = min(sum, isFound(i, num + 1));
        }
    return sum;
}

void isSuit(int k)
{
    rec[1] = prime[k];
    int l0 = Digit(rec[1]), l1;
    Set[1][0] = 0;
    for(int i = k + 1; i <= prime[0]; i++)
    {
        l1 = Digit(prime[i]);
        if(isPrime((LL)rec[1] * l1 + prime[i]) && isPrime((LL)prime[i] * l0 + rec[1]))
            Set[1][++Set[1][0]] = prime[i];
    }
    for(int i = 1; i <= Set[1][0] - 3; i++)//再找4个
        {
            if(rec[1] + Set[1][i] + Set[1][i + 1] + Set[1][i + 2] + Set[1][i + 3] >= sum)
                return;
            sum = min(sum, isFound(i, 2));//sum取最小
        }
    return;
}

int main()
{
    double duration;
    clock_t start = clock();
    getprime();
    for(int i = 2; i <= prime[0]; i++)
    {
        if(3 == i)//prime[3] = 5, 不可能
            i++;
        if(SumOfFive(prime + i - 1) >= sum)//sum已经最小了
            break;
        isSuit(i);
    }
    printf("sum = %d.\n", sum);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf\n", duration);
    return 0;
}
