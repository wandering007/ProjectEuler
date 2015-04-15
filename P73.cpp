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
#define MAXN 12000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//递归写法
int SearcReuProFrac(int y1, int y2)
{
    int b = y1 + y2;// the theory of Farey sequences
    if(b <= MAXN)
        return SearcReuProFrac(y1, b) + SearcReuProFrac(b, y2) + 1;
    return 0;
}

//非递归写法
/*
int Stack[MAXN];

int SearcReuProFrac(int left, int right)
{
    Stack[++Stack[0]] = right;
    int mid, cnt = 0;
    while(Stack[0])
    {
        mid = left + right;
        if(mid <= MAXN)
        {
            Stack[++Stack[0]] = mid;//入栈
            cnt++;//入栈的为满足题意
            right = mid;
        }
        else
        {
            left = right;
            right = Stack[--Stack[0]];//栈顶(值为right)出栈后，取栈顶元素
        }
    }
    return cnt;
}
*/

int main()
{
    clock_t start = clock();
	printf("%d\n", SearcReuProFrac(3, 2));
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
