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
#define MAXN 10000000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

unsigned int rec[14];
char P1[6][3], P2[6][3];
enum Rank{HighCard, OnePair, TwoPairs, ThreeOfaKind, Straight, Flush,
        FullHouse, FourOfaKind, StraightFlush, RoyalFlush};

void adjust(char* V)
{
    switch(V[0])
    {
        case 'T': V[0] = '9' + 1; break;
        case 'J': V[0] = '9' + 2; break;
        case 'Q': V[0] = '9' + 3; break;
        case 'K': V[0] = '9' + 4; break;
        case 'A': V[0] = '9' + 5; break;
        default: {;}
    }
    return;
}

int JudgeRank(char P[][3])
{
    memset(rec, 0, sizeof(rec));
    for(int i = 1; i <= 5; i++)
        rec[P[i][0] - '2']++;
    int NumOfPairs = 0;
    bool NumOfThr = false;
    for(int i = 0; i < 14; i++)
    {
        switch(rec[i])
        {
            case 2: NumOfPairs++; break;
            case 3: NumOfThr = true; break;
            case 4: return FourOfaKind;
        }
    }
    if(1 == NumOfPairs)
        {
            if(NumOfThr)
                return FullHouse;
            return OnePair;
        }
    if(2 == NumOfPairs)
        return TwoPairs;
    if(NumOfThr)
        return ThreeOfaKind;
    bool isSameSuit = true, isConseVal = true;
    for(int i = 1; i < 5; i++)
    {
        if(P[i][0] + 1 != P[i + 1][0])
            isConseVal = false;
        if(P[i][1] != P[i + 1][1])
            isSameSuit = false;
    }
    if(isSameSuit)
    {
        if(isConseVal)
        {
            if('9' + 1 == P[1][0])
                return RoyalFlush;
            return StraightFlush;
        }
        return Flush;
    }
    else if(isConseVal)
        return Straight;
    return HighCard;
}

int ValOfOnePair(char P[][3])
{
    for(int i = 1; i < 5; i++)
        if(P[i][0] == P[i + 1][0])
            return P[i][0];
    return 0;//impossible
}

int ValOfTwoPairs(char P[][3])
{//编码成14进制数
    int val = 0;
    bool isMax = true;
    for(int i = 5; i >= 1; i--)
    {
        if(i > 1 && P[i][0] == P[i - 1][0])
        {
            i--;
            if(isMax)
            {
                val += (P[i][0] - '1') * 14 * 14;
                isMax = false;
            }
            else
            {
                val += (P[i][0] - '1') * 14;
            }
        }
        else val += P[i][0] - '1';
    }
    return val;
}

bool isPlayerOneWin()
{
    int Level1 = JudgeRank(P1);
    int Level2 = JudgeRank(P2);
    if(Level1 < Level2)
        return false;
    if(Level1 > Level2)
        return true;
    int v1, v2;
    switch(Level1)
    {
    case OnePair:
    case ThreeOfaKind:
    case FourOfaKind:
        v1 = ValOfOnePair(P1);
        v2 = ValOfOnePair(P2);
        if(v1 != v2)
            return v1 > v2;
        break;
    case TwoPairs:
        v1 = ValOfTwoPairs(P1);
        v2 = ValOfTwoPairs(P2);
        return v1 > v2;
    }
    for(int i = 5; i > 0; i--)
    {
       if(P1[i][0] > P2[i][0])
        return true;
       if(P1[i][0] < P2[i][0])
        return false;
    }
    return false;//impossible
}

void BubbleSort(char P[][3], int n)
{
    int i = n, LastExcchangeIndex;
    while(i > 1)
    {
        LastExcchangeIndex = 1;
        for(int j = 1; j < i; j++)
        {
            if(P[j][0] > P[j + 1][0])
            {
                strcpy(P[0], P[j + 1]);
                strcpy(P[j + 1], P[j]);
                strcpy(P[j], P[0]);
                LastExcchangeIndex = j;
            }
        }
        i = LastExcchangeIndex;
    }
}

int main()
{
    clock_t start = clock();
    freopen("p054_poker.txt", "r", stdin);
    int cnt = 0;
    for(int i = 1; i <= 1000; i++)
    {
       for(int j = 1; j <= 5; j++)
        {
            scanf("%s", P1[j]);
            adjust(P1[j]);
        }
       for(int j = 1; j <= 5; j++)
        {
            scanf("%s", P2[j]);
            adjust(P2[j]);
        }
       BubbleSort(P1, 5);
       BubbleSort(P2, 5);
       if(isPlayerOneWin())
        cnt++;
    }
    printf("%d\n", cnt);
    printf("time cost: %lf", (double)( clock() - start) / CLOCKS_PER_SEC);
    return 0;
}
