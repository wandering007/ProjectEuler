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
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
bool isPalindromic(char *s)
{
    int len = strlen(s);
    for(int i=0;i<len/2;i++)
        if(s[i]!=s[len-1-i])
           return false;
    return true;
}
int main()
{
    double duration;
    clock_t start;
    start = clock();
    int sum = 0;
    char str[7];
    for(int i = 0; i < MAXN; i++)
    {
        itoa(i, str, 10);
        if(isPalindromic(str))
        {
            itoa(i, str, 2);
            if(isPalindromic(str))
                sum += i;
        }
    }
    printf("%d\n", sum);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
}
