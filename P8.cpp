#include<iostream>
#include<cstdio>
using namespace std;
int a[14];//记录13个位置的数字
int main()
{
    int t = 0, temp, s = 1;//t代表已经记录的位置数，s代表即将被更改的位置
    bool flag = false;
    long long sum = 0LL, now = 1LL;
    int cnt = 0;
    while(++cnt <= 1000)
    {
        scanf("%1d", &temp);//只读一个数字
        if(0 == temp)
        {
            t = 0;
            s = 1;
            flag = false;
            continue;
        }
        if(t < 13)
            a[++t] = temp;
        else if(flag)
        {
            now = now / a[s] * temp;
            if(now > sum)
                sum = now;
            a[s] = temp;
            s = s % 13 + 1;
        }
        if(13 == t && !flag)
        {
            now = 1LL;
            for(int k = 1; k <= 13; k++)
                now *= a[k];
            if(now > sum)
                sum = now;
            flag = true;
        }
    }
    printf("%I64d\n", sum);
    return 0;
}