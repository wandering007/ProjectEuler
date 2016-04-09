#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<string>
#include<queue>
#include<stack>
#include<vector>
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
int main()
{
    int one = 3,two = 3,three=5,four = 4,five=4,six=3,seven=5,eight=5,nine=4,ten=3,hundred=7;
    int eleven=6,twelve=6,thirteen=8,fourteen=8,fifteen=7,sixteen=7,seventeen=9,eighteen=8,nineteen=8,thousand=8;
    int twenty=6,thirty=6,forty=5,fifty=5,sixty=5,seventy=7,eighty=6,ninety=6,AND=3;
    int rec1,rec2,rec3,rec1_99,res;
    rec1 = (one+two+three+four+five+six+seven+eight+nine)*9;
    rec2 = eleven+twelve+thirteen+fourteen+fifteen+sixteen+seventeen+eighteen+nineteen;
    rec3 = (twenty+thirty+forty+fifty+sixty+seventy+eighty+ninety)*10;
    rec1_99 = rec1+rec2+rec3+ten;
    res=rec1_99*10+(rec1/9+hundred*9)*100+one+thousand+AND*99*9;
    printf("%d letters would be used.\n",res);
    return 0;
}
