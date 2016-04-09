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
#define MAXN 10000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

int prime[MAXN], Phi[MAXN] = {0, 1};
bool comp[MAXN];
int digit1[10], digit2[10];

void getprime()
{
    for(int p = 2; p < MAXN; p++)
    {
        if(!comp[p])
        {
            for(int i = p + p; i < MAXN; i += p)
                comp[i] = true;
            prime[++prime[0]] = p;
        }
    }
    return;
}

int Totient(int n)
{
    if(!comp[n])
        Phi[n] = n - 1;
    else if(0 == Phi[n])
    {
        int m = 1, i = 1, k = n;
        while(n % prime[i])
            i++;
        while(0 == k % prime[i])
        {
            m *= prime[i];
            k /= prime[i];
        }
        Phi[n] = Phi[m] * Phi[k];//m * k == n
        // The totient function is a multiplicative function
        //if two numbers m and n are relatively prime, then φ(mn) = φ(m)φ(n).
    }
    //φ(n^k) = n^(k - 1)φ(n) = n * φ(n^(k - 1))
    for(LL t = (LL)n * n; t < MAXN; t *= n)
        Phi[t] = n * Phi[t / n];
    return Phi[n];
}
/*A faster way
类似于扫描法求质数
	for(int i = 1; i <= MAXN; i++)
        Phi[i] = i;
	for(int i = 2; i <= MAXN; i++)
	{
		if(Phi[i] == i)
		{
			for(int j = i;j <= MAXN; j += i)
				Phi[j] = Phi[j] / i * (i - 1);
		}
	}
*/

bool isPerm(int phi, int n)
{
    memset(digit1, 0, sizeof(digit1));
    memset(digit2, 0, sizeof(digit2));
    while(phi)
    {
        digit1[phi % 10]++;
        phi /= 10;
    }
    while(n)
    {
        digit2[n % 10]++;
        n /= 10;
    }
    for(int i = 0; i <= 9; i++)
        if(digit1[i] != digit2[i])
            return false;
    return true;
}

int main()
{
    double duration;
    clock_t start = clock();
    getprime();
    double Min = MAXN, temp;
    int rec, T;
    for(int i = 2; i < MAXN; i++)
    {
        T = Totient(i);
        if(isPerm(T, i))
        {
            temp = (double)i / T;
            if(Min > temp + eps)
            {
                Min = temp;
                rec = i;
                //printf("%d %lf\n", rec, Min);
            }
        }
    }
    printf("%d\n", rec);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
/*
for(int i = 1; i <= MAXN; i++)
        Totient[i] = i;
	for(int i = 2; i <= MAXN; i++)
	{
		if(Totient[i] == i)
		{
			for(int j = i;j <= MAXN; j += i)
				Totient[j] = Totient[j] / i * (i - 1);
		}
	}
	LL ans=0LL;
	for(int i = 2;i <= MAXN; i++)
		ans+=Totient[i];
	printf("%I64d\n", ans);
*/
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
#define MAXN 10000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

int prime[MAXN], Phi[MAXN] = {0, 1};
bool comp[MAXN];
int digit1[10], digit2[10];

void getprime()
{
    for(int p = 2; p < MAXN; p++)
    {
        if(!comp[p])
        {
            for(int i = p + p; i < MAXN; i += p)
                comp[i] = true;
            prime[++prime[0]] = p;
        }
    }
    return;
}

int Totient(int n)
{
    if(!comp[n])
        Phi[n] = n - 1;
    else if(0 == Phi[n])
    {
        int m = 1, i = 1, k = n;
        while(n % prime[i])
            i++;
        while(0 == k % prime[i])
        {
            m *= prime[i];
            k /= prime[i];
        }
        Phi[n] = Phi[m] * Phi[k];//m * k == n
        // The totient function is a multiplicative function
        //if two numbers m and n are relatively prime, then φ(mn) = φ(m)φ(n).
    }
    //φ(n^k) = n^(k - 1)φ(n) = n * φ(n^(k - 1))
    for(LL t = (LL)n * n; t < MAXN; t *= n)
        Phi[t] = n * Phi[t / n];
    return Phi[n];
}
/*A faster way
类似于扫描法求质数
	for(int i = 1; i <= MAXN; i++)
        Phi[i] = i;
	for(int i = 2; i <= MAXN; i++)
	{
		if(Phi[i] == i)
		{
			for(int j = i;j <= MAXN; j += i)
				Phi[j] = Phi[j] / i * (i - 1);
		}
	}
*/

bool isPerm(int phi, int n)
{
    memset(digit1, 0, sizeof(digit1));
    memset(digit2, 0, sizeof(digit2));
    while(phi)
    {
        digit1[phi % 10]++;
        phi /= 10;
    }
    while(n)
    {
        digit2[n % 10]++;
        n /= 10;
    }
    for(int i = 0; i <= 9; i++)
        if(digit1[i] != digit2[i])
            return false;
    return true;
}

int main()
{
    double duration;
    clock_t start = clock();
    getprime();
    double Min = MAXN, temp;
    int rec, T;
    for(int i = 2; i < MAXN; i++)
    {
        T = Totient(i);
        if(isPerm(T, i))
        {
            temp = (double)i / T;
            if(Min > temp + eps)
            {
                Min = temp;
                rec = i;
                //printf("%d %lf\n", rec, Min);
            }
        }
    }
    printf("%d\n", rec);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
/*
for(int i = 1; i <= MAXN; i++)
        Totient[i] = i;
	for(int i = 2; i <= MAXN; i++)
	{
		if(Totient[i] == i)
		{
			for(int j = i;j <= MAXN; j += i)
				Totient[j] = Totient[j] / i * (i - 1);
		}
	}
	LL ans=0LL;
	for(int i = 2;i <= MAXN; i++)
		ans+=Totient[i];
	printf("%I64d\n", ans);
*/
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
