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

int str[11];

bool check()
{//测试各group的和值是否相等
    int val = str[1] + str[5] + str[10], temp;
    for(int i = 1; i < 5; i++)
    {
        temp = str[i] + str[i + 1] + str[i + 5];
        if(val != temp)
            return false;
    }
    return true;
}

LL StringVal()
{
    if(!check())
        return 0;//不等，返回0
    LL res = 0LL, start = 1;
    for(int i = 2; i <= 5; i++)
    {//find the numerically lowest external node
	 //since all the digits are distinct, just choose the smallest first digit in all groups.
        if(str[i + 5] < str[start + 5])
            start = i;
    }
    int k = start;
    do
    {
        if(str[k + 5] != 10)
            res = res * 10 + str[k + 5];
        else
            res = res * 100 + str[k + 5];//值为10时要将原本的res乘以100以保证10正确接入
        res = res * 10 + str[k];
        res = res * 10 + str[k % 5 + 1];
        k = k % 5 + 1;
    }
    while(k != start);
    return res;
}

bool is16_digit()
{
    for(int i = 1; i <= 5; i++)
        if(10 == str[i])
            return false;//如果10出现在1-5之中，17位
    return true;
}

int main()
{
    double duration;
    clock_t start = clock();
    for(int i = 1; i <= 10; i++)
        str[i] = i;
    LL res = 0, temp;
    while(next_permutation(str + 1, str + 11))
    {
        if(!is16_digit())
            continue;
        temp = StringVal();
        res = max(res, temp);
    }
    printf("%I64d\n", res);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %lf s\n", duration);
    return 0;
}
/*
    (6)
	  \
       \      (7)
	   (1)    /
	  /   \  /
   (5)     (2)
   / \     /
  /  (4)-(3)--(8)
(10)   \
		\
        (9)       
*/