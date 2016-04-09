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
#define MAXN 2000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//There is an analytical way to solve this one.
//If you imagine a rectangular grid measuring a units across and b units down.
//There are a+1 vertical lines and b+1 horizontal lines. Each rectangle formed
//on this grid is made up of two vertical lines and two horizontal lines.
//As there are C(a+1,2)=a(a+1)/2 ways of picking two vertical lines and,
//similarly, b(b+1)/2, ways of picking two horizontal lines.
//Hence, there are a(a+1)b(b+1)/4 rectangles on an a by b rectangular grid.
int main()
{
    clock_t start = clock();
    int rec, dif = MAXN, temp;
    //Numbers of rectangles = x * (x + 1) * y * (y + 1) / 4
    for(int x = 1; x <= 2000; x++)//y == 1, 得到x上限
        for(int y = sqrt(2) * 2000 / (x + 1) - 1; y <= x; y++)
    {//(x + 1) * (y + 1) >= 2 * sqrt(MAXN),得到y下限；由于x和y的对称性，令y <= x
        temp = x * y * (x + 1) * (y + 1) - 4 * MAXN;
        if(abs(temp) < dif)
        {
            rec = x * y;
            dif = abs(temp);
        }
        if(temp > 0)
            break;
    }
    printf("%d\n", rec);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
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
#define MAXN 2000000
#define MOD 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//There is an analytical way to solve this one.
//If you imagine a rectangular grid measuring a units across and b units down.
//There are a+1 vertical lines and b+1 horizontal lines. Each rectangle formed
//on this grid is made up of two vertical lines and two horizontal lines.
//As there are C(a+1,2)=a(a+1)/2 ways of picking two vertical lines and,
//similarly, b(b+1)/2, ways of picking two horizontal lines.
//Hence, there are a(a+1)b(b+1)/4 rectangles on an a by b rectangular grid.
int main()
{
    clock_t start = clock();
    int rec, dif = MAXN, temp;
    //Numbers of rectangles = x * (x + 1) * y * (y + 1) / 4
    for(int x = 1; x <= 2000; x++)//y == 1, 得到x上限
        for(int y = sqrt(2) * 2000 / (x + 1) - 1; y <= x; y++)
    {//(x + 1) * (y + 1) >= 2 * sqrt(MAXN),得到y下限；由于x和y的对称性，令y <= x
        temp = x * y * (x + 1) * (y + 1) - 4 * MAXN;
        if(abs(temp) < dif)
        {
            rec = x * y;
            dif = abs(temp);
        }
        if(temp > 0)
            break;
    }
    printf("%d\n", rec);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
