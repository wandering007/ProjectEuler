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
#define MAXN 10000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int vis[10001];
int main()
{
    double duration;
    clock_t start;
    start = clock();
    for(int a = 1;a < 334; a++)
      for(int b = a + 1; b<=(1000-a)/2; b++)
      {
          int c = round(sqrt(a*a+b*b));
          if((c*c != a*a + b*b)||(a+b+c>1000))
             continue;
          vis[a + b + c]++;
      }
    int Max = 0, rec = 0;
    for(int i=1;i<=1000;i++)
       {
           if(vis[i]>Max)
           {
               rec = i;
               Max = vis[i];
           }
       }
    printf("%d\n", rec);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
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
#define MAXN 10000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int vis[10001];
int main()
{
    double duration;
    clock_t start;
    start = clock();
    for(int a = 1;a < 334; a++)
      for(int b = a + 1; b<=(1000-a)/2; b++)
      {
          int c = round(sqrt(a*a+b*b));
          if((c*c != a*a + b*b)||(a+b+c>1000))
             continue;
          vis[a + b + c]++;
      }
    int Max = 0, rec = 0;
    for(int i=1;i<=1000;i++)
       {
           if(vis[i]>Max)
           {
               rec = i;
               Max = vis[i];
           }
       }
    printf("%d\n", rec);
    duration = ((double)(clock()-start))/CLOCKS_PER_SEC;
    printf("Time cost: %f s.\n", duration);
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
