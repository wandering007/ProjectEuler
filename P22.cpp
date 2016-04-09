<<<<<<< HEAD
#include<iostream>
#include<algorithm>
#include<cmath>
#include <ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<string>
#include<queue>
#include<stack>
#include <fstream>
#include<vector>
#include<list>
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
bool cmp(string a,string b)
{
    unsigned int i=0;
    while(i<a.length()&&i<b.length())
    {
        if(a[i]<b[i])
            return true;
        else if(a[i]>b[i])
            return false;
        i++;
    }
    if(a.length()<b.length())
        return true;
    else return false;
}
int getValue(string s)
{
    int sum = 0,len = s.length();
    for(int i=1;i<len-1;i++)//两个'"'不记录
        sum += s[i]-'A'+1;
    return sum;
}
int main()
{
    ifstream input("names.txt");
    string Names[6000];
    int k = 0;
    while(input.good())
    {
        getline(input,Names[k++],',');
        //cout<<firstName<<endl;
    }
    sort(Names,Names+k,cmp);//此方法以后可用于数组/string间的排序，二维数组排序很麻烦，容易出问题，string很好地解决了这一问题
    LL res=0LL;
    for(int i=0;i<k;i++)
        res += getValue(Names[i])*(i+1);
    cout<<res<<endl;
    return 0;
}
=======
#include<iostream>
#include<algorithm>
#include<cmath>
#include <ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<math.h>
#include<string>
#include<queue>
#include<stack>
#include <fstream>
#include<vector>
#include<list>
#define MAXN 1000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;
bool cmp(string a,string b)
{
    unsigned int i=0;
    while(i<a.length()&&i<b.length())
    {
        if(a[i]<b[i])
            return true;
        else if(a[i]>b[i])
            return false;
        i++;
    }
    if(a.length()<b.length())
        return true;
    else return false;
}
int getValue(string s)
{
    int sum = 0,len = s.length();
    for(int i=1;i<len-1;i++)//两个'"'不记录
        sum += s[i]-'A'+1;
    return sum;
}
int main()
{
    ifstream input("names.txt");
    string Names[6000];
    int k = 0;
    while(input.good())
    {
        getline(input,Names[k++],',');
        //cout<<firstName<<endl;
    }
    sort(Names,Names+k,cmp);//此方法以后可用于数组/string间的排序，二维数组排序很麻烦，容易出问题，string很好地解决了这一问题
    LL res=0LL;
    for(int i=0;i<k;i++)
        res += getValue(Names[i])*(i+1);
    cout<<res<<endl;
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
