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
#define MAXN 1500000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
//Find the number of characters saved by writing each of these in their minimal form.
//"saved" means: spend sparingly, avoid the waste of
int SubPair(char Lead, char ch)
{
    switch(Lead)
    {
    case 'I':
        return 2 + (ch == 'V'? 1 : 0);
    case 'X':
        return 2 + (ch == 'L'? 1 : 0);
    case 'C':
        return 2 + (ch == 'D'? 1 : 0);
    default:
        return 0;
    }
}

int main()
{
    clock_t start = clock();
    freopen("C:\\Users\\changmao\\Desktop\\p089_roman.txt", "r", stdin);
    char s[100];
    int len, k, num = 0;
    while(scanf("%s", s) != EOF)
    {
        len = strlen(s);
        k = 1;
        for(int i = len - 2; i >= 0; i--)
        {
            if(s[i] == s[i + 1])
            {
                k++;
                if(4 == k)
                {
                    num += SubPair(s[i], (i? s[i - 1] : 'M')); 
					//note that the first four consecutive identical units
                    k = 1;
                }
            }
            else k = 1;
        }
    }
    printf("%d\n", num);
    printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}