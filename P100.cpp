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
#define MIN 1000000000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//http://www.alpertron.com.ar/QUAD.HTM
// 2 * x^2 - y^2 - 2 * x + y = 0
int main()
{
    clock_t start = clock();
    LL x = 1LL, y = 1LL, tmp_x;
    while(y <= MIN)
    {
        tmp_x = 3 * x + 2 * y - 2;
        y = 4 * x + 3 * y - 3;
        x = tmp_x;
    }
    printf("The number of blue discs: %I64d.\n%I64d discs in total.\n", x, y);
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
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
#define MIN 1000000000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//http://www.alpertron.com.ar/QUAD.HTM
// 2 * x^2 - y^2 - 2 * x + y = 0
int main()
{
    clock_t start = clock();
    LL x = 1LL, y = 1LL, tmp_x;
    while(y <= MIN)
    {
        tmp_x = 3 * x + 2 * y - 2;
        y = 4 * x + 3 * y - 3;
        x = tmp_x;
    }
    printf("The number of blue discs: %I64d.\n%I64d discs in total.\n", x, y);
    printf("time cost: %lf s.", (double)(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
