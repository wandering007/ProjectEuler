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
#define MAXN 1002001
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int Pow(int x, int n)
{
    int res=1;
    for(int i=1; i<=n; i++)
        res*=x;
    return res;
}
int P_5[10],P10[6];
int main()
{
    LL sum = 0LL;
    int temp;
    for(int i=1; i<10; i++)
        P_5[i] = Pow(i,5);
    P10[0] = 1;
    for(int i=1; i<6; i++)
        P10[i] = P10[i-1]*10;
    int a,b,c,d,e,f;
    for(a=0; a<10; a++)
        for(b=0; b<10; b++)
            for(c=0; c<10; c++)
                for(d=0; d<10; d++)
                    for(e=0; e<10; e++)
                        for(f=0; f<10; f++)
                        {
                            temp = a*P10[5]+b*P10[4]+c*P10[3]+d*P10[2]+e*P10[1]+f;
                            if(P_5[a]+P_5[b]+P_5[c]+P_5[d]+P_5[e]+P_5[f] == temp)
                               {
                                   sum += temp;
                               }
                        }
    printf("%I64d\n",sum-1);
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
#define MAXN 1002001
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int Pow(int x, int n)
{
    int res=1;
    for(int i=1; i<=n; i++)
        res*=x;
    return res;
}
int P_5[10],P10[6];
int main()
{
    LL sum = 0LL;
    int temp;
    for(int i=1; i<10; i++)
        P_5[i] = Pow(i,5);
    P10[0] = 1;
    for(int i=1; i<6; i++)
        P10[i] = P10[i-1]*10;
    int a,b,c,d,e,f;
    for(a=0; a<10; a++)
        for(b=0; b<10; b++)
            for(c=0; c<10; c++)
                for(d=0; d<10; d++)
                    for(e=0; e<10; e++)
                        for(f=0; f<10; f++)
                        {
                            temp = a*P10[5]+b*P10[4]+c*P10[3]+d*P10[2]+e*P10[1]+f;
                            if(P_5[a]+P_5[b]+P_5[c]+P_5[d]+P_5[e]+P_5[f] == temp)
                               {
                                   sum += temp;
                               }
                        }
    printf("%I64d\n",sum-1);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
