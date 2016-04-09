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
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f

#define MAXN 40
#define CardNum 16
#define DiceSize 4
using namespace std;

//Can it be solved by possibility rather than simulation?
/*
I computed a matrix M[j][k] with the probability of going from state j to state k. 
There are 120 states (40 squares x 3 "number of doubles" values). The eigenvector 
of the largest eigenvalue, normalized to add up to 1, gives you the probability of
each state. To compute that, start with (1,1,1,...,1), multiply by M, normalize, rinse, repeat. 
This method converges quickly to very precise values of the probabilities.
http://www.math.yorku.ca/Who/Faculty/Steprans/Courses/2042/Monopoly/Stewart4.html
http://www.tkcs-collins.com/truman/monopoly/monopoly.shtml
*/

typedef struct
{
    int id, vis;
}node;
node Sqr[40];
enum Square{G0, A1, CC1, A2, T1, R1, B1, CH1, B2, B3,
    JAIL, C1, U1, C2, C3, R2, D1, CC2, D2, D3,
    FP, E1, CH2, E2, E3, R3, F1, F2, U2, F3,
    G2J, G1, G2, CC3, G3, R4, CH3, H1, T2, H2};

int findNextR(int pos)
{
    switch(pos)
    {
        case CH1: return R2;
        case CH2: return R3;
        case CH3: return R1;
    }
}

int findNextU(int pos)
{
    switch(pos)
    {
        case CC1: return U1;
        case CC2: return U2;
        case CC3: return U1;
    }
}

int CHmov(int k, int pos)
{
    switch(k)
    {
        case 1: pos = G0; break;
        case 2: pos = JAIL; break;
        case 3: pos = C1; break;
        case 4: pos = E3; break;
        case 5: pos = H2; break;
        case 6: pos = R1; break;
        case 7:
        case 8: pos = findNextR(pos); break;
        case 9: pos = findNextU(pos); break;
        case 10: pos = (pos - 3 + MAXN) % MAXN; break;
        default: break;
    }
    return pos;
}

bool cmp(node a, node b)
{
    return a.vis > b.vis;
}

int main()
{
    int Roll = 1000000; //times of rolling
    unsigned int seed;
    cout << "Enter seed: ";
    cin >> seed;
    clock_t start = clock();
    srand(seed);
    int a, b, tmp = G0, Doubles = 0, CCtop = 0, CHtop = 0;
    for(int i = 0; i < MAXN; i++)
        Sqr[i].id = i;
    while(Roll--)
    {
        a = 1 + rand() % DiceSize;
        b = 1 + rand() % DiceSize;
        if(a == b)
        {
            Doubles++;
            if(3 == Doubles)//three consecutive doubles
            {
                tmp = JAIL;
                Doubles = 0;
                Sqr[tmp].vis++;
                continue;
            }
        }
        else Doubles = 0;
        tmp = (a + b + tmp) % 40; //proceed after rolling
        if(CC1 == tmp || CC2 == tmp || CC3 == tmp) //CC
        {
            CCtop = CCtop % CardNum + 1;
            if(1 == CCtop)
                tmp = G0;
            else if(2 == JAIL)
                tmp = JAIL;
        }
        else if(CH1 == tmp || CH2 == tmp || CH3 == tmp) //CH
        {
            CHtop = CHtop % CardNum + 1;
            tmp = CHmov(CHtop, tmp);
        }
        else if(G2J == tmp)
            tmp = JAIL;
        Sqr[tmp].vis++;
    }
    sort(Sqr, Sqr + MAXN, cmp);
    printf("%02d%02d%02d\n", Sqr[0].id, Sqr[1].id, Sqr[2].id);
    double duration = (clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f.\n", duration);
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
#define LL long long
#define eps 1e-6
#define inf 0x3f3f3f3f

#define MAXN 40
#define CardNum 16
#define DiceSize 4
using namespace std;

//Can it be solved by possibility rather than simulation?
/*
I computed a matrix M[j][k] with the probability of going from state j to state k. 
There are 120 states (40 squares x 3 "number of doubles" values). The eigenvector 
of the largest eigenvalue, normalized to add up to 1, gives you the probability of
each state. To compute that, start with (1,1,1,...,1), multiply by M, normalize, rinse, repeat. 
This method converges quickly to very precise values of the probabilities.
http://www.math.yorku.ca/Who/Faculty/Steprans/Courses/2042/Monopoly/Stewart4.html
http://www.tkcs-collins.com/truman/monopoly/monopoly.shtml
*/

typedef struct
{
    int id, vis;
}node;
node Sqr[40];
enum Square{G0, A1, CC1, A2, T1, R1, B1, CH1, B2, B3,
    JAIL, C1, U1, C2, C3, R2, D1, CC2, D2, D3,
    FP, E1, CH2, E2, E3, R3, F1, F2, U2, F3,
    G2J, G1, G2, CC3, G3, R4, CH3, H1, T2, H2};

int findNextR(int pos)
{
    switch(pos)
    {
        case CH1: return R2;
        case CH2: return R3;
        case CH3: return R1;
    }
}

int findNextU(int pos)
{
    switch(pos)
    {
        case CC1: return U1;
        case CC2: return U2;
        case CC3: return U1;
    }
}

int CHmov(int k, int pos)
{
    switch(k)
    {
        case 1: pos = G0; break;
        case 2: pos = JAIL; break;
        case 3: pos = C1; break;
        case 4: pos = E3; break;
        case 5: pos = H2; break;
        case 6: pos = R1; break;
        case 7:
        case 8: pos = findNextR(pos); break;
        case 9: pos = findNextU(pos); break;
        case 10: pos = (pos - 3 + MAXN) % MAXN; break;
        default: break;
    }
    return pos;
}

bool cmp(node a, node b)
{
    return a.vis > b.vis;
}

int main()
{
    int Roll = 1000000; //times of rolling
    unsigned int seed;
    cout << "Enter seed: ";
    cin >> seed;
    clock_t start = clock();
    srand(seed);
    int a, b, tmp = G0, Doubles = 0, CCtop = 0, CHtop = 0;
    for(int i = 0; i < MAXN; i++)
        Sqr[i].id = i;
    while(Roll--)
    {
        a = 1 + rand() % DiceSize;
        b = 1 + rand() % DiceSize;
        if(a == b)
        {
            Doubles++;
            if(3 == Doubles)//three consecutive doubles
            {
                tmp = JAIL;
                Doubles = 0;
                Sqr[tmp].vis++;
                continue;
            }
        }
        else Doubles = 0;
        tmp = (a + b + tmp) % 40; //proceed after rolling
        if(CC1 == tmp || CC2 == tmp || CC3 == tmp) //CC
        {
            CCtop = CCtop % CardNum + 1;
            if(1 == CCtop)
                tmp = G0;
            else if(2 == JAIL)
                tmp = JAIL;
        }
        else if(CH1 == tmp || CH2 == tmp || CH3 == tmp) //CH
        {
            CHtop = CHtop % CardNum + 1;
            tmp = CHmov(CHtop, tmp);
        }
        else if(G2J == tmp)
            tmp = JAIL;
        Sqr[tmp].vis++;
    }
    sort(Sqr, Sqr + MAXN, cmp);
    printf("%02d%02d%02d\n", Sqr[0].id, Sqr[1].id, Sqr[2].id);
    double duration = (clock() - start) / CLOCKS_PER_SEC;
    printf("time cost: %f.\n", duration);
    return 0;
}
>>>>>>> 7322508e7a9e50379c344340aca8d7e37e46f16d
