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
#define MAXN 4000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

bool isPenta(LL val)
{//公式法判断val是不是Pentagon number
    LL delta = (LL)round(sqrt(1 + 24 * val));
    if(delta * delta != 1 + 24 * val)
        return false;
    if((1+delta) % 6)
        return false;
    return true;
}

int main()
{
    clock_t start;
    double duration;
    start = clock();
    LL Pk, Pj, D = -1LL;
    for(LL k = 2LL; ; k++)
    {
        if(D != -1LL && 3 * k - 2 >= D)//3*k-2是Pk与P(k-1)的差值
        //无法出现比当前D更小的差值，说明最小值已经找到
            break;
        Pk = k * (3 * k - 1) / 2;
        for(LL j = k - 1; j > 0; j--)//从k-1开始，差值递增
        {
            Pj = j * (3 * j - 1) / 2;
            if(D != -1LL && Pk - Pj >= D)//当前的D比当前的差值小或等于，没必要再进行下去
                break;
            if(isPenta(Pk - Pj) && isPenta(Pk + Pj))
			// 1.初次赋值；2.如果出现比当前D(D != -1LL)更小的差值，更新D(事实说明不存在情况2)
                D = Pk - Pj;
        }
    }
    printf("%I64d\n", D);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
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
#define MAXN 4000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;

bool isPenta(LL val)
{//公式法判断val是不是Pentagon number
    LL delta = (LL)round(sqrt(1 + 24 * val));
    if(delta * delta != 1 + 24 * val)
        return false;
    if((1+delta) % 6)
        return false;
    return true;
}

int main()
{
    clock_t start;
    double duration;
    start = clock();
    LL Pk, Pj, D = -1LL;
    for(LL k = 2LL; ; k++)
    {
        if(D != -1LL && 3 * k - 2 >= D)//3*k-2是Pk与P(k-1)的差值
        //无法出现比当前D更小的差值，说明最小值已经找到
            break;
        Pk = k * (3 * k - 1) / 2;
        for(LL j = k - 1; j > 0; j--)//从k-1开始，差值递增
        {
            Pj = j * (3 * j - 1) / 2;
            if(D != -1LL && Pk - Pj >= D)//当前的D比当前的差值小或等于，没必要再进行下去
                break;
            if(isPenta(Pk - Pj) && isPenta(Pk + Pj))
			// 1.初次赋值；2.如果出现比当前D(D != -1LL)更小的差值，更新D(事实说明不存在情况2)
                D = Pk - Pj;
        }
    }
    printf("%I64d\n", D);
    duration = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f\n", duration);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
