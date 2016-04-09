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
#define MAXN 1000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int add(int *small,int *large)
{
    int carryin = 0, temp, i;
    for(i=1;large[i]!=-1||carryin!=0;i++)
    {
        if(-1 == small[i])
            small[i] = 0;
        if(-1 == large[i])
            large[i] = 0;
        temp = small[i] + large[i] + carryin;
        small[i] = temp % 10;
        carryin = temp / 10;
    }
    return i-1;
}
int main()
{
    int a[1010],b[1010];
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    a[1]=b[1] = 1;
    int i,top = 1,term = 2;
    for(i=1;top<1000;i++)
    {
        if(i%2)
            top = add(a,b);
        else top = add(b,a);
        term++;
    }
    printf("%d\n",term);
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
#define MAXN 1000000
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f
using namespace std;
int add(int *small,int *large)
{
    int carryin = 0, temp, i;
    for(i=1;large[i]!=-1||carryin!=0;i++)
    {
        if(-1 == small[i])
            small[i] = 0;
        if(-1 == large[i])
            large[i] = 0;
        temp = small[i] + large[i] + carryin;
        small[i] = temp % 10;
        carryin = temp / 10;
    }
    return i-1;
}
int main()
{
    int a[1010],b[1010];
    memset(a,-1,sizeof(a));
    memset(b,-1,sizeof(b));
    a[1]=b[1] = 1;
    int i,top = 1,term = 2;
    for(i=1;top<1000;i++)
    {
        if(i%2)
            top = add(a,b);
        else top = add(b,a);
        term++;
    }
    printf("%d\n",term);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
