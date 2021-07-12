#include<iostream>
#include<fstream>
#include<string>
#include<queue>
#include<stack>
#include<set>
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
#define MAXN 50
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

#define PLUS    0
#define MINUS   1
#define TIMES   2
#define DIVIDE  3

double operate(double a, double b, int op);
bool next_choice(int *);


int main()
{
    clock_t start = clock();
    int digits[] = {0, 1, 2, 3};
    int maximum = 0;
    int maxString[4];
    // Loop over each range of digits such that a < b < c < d
    do
    {
        set<int> result;
        // Loop through each permutation of the digits
        do {
            int ops[3] = {PLUS, PLUS, PLUS};
            // Cycle through each possible set of operations
            for (int i = 0; i < 64; i++)
            {
                double t, s;
                // Case 1: Balanced binary tree (digits are leaves)
                s = operate((double)digits[0], (double)digits[1], ops[0]);
                t = operate((double)digits[2], (double)digits[3], ops[2]);
                t = operate(s, t, ops[1]);
                if(fabs(round(t) - t) < eps && t > 0)
                    result.insert(round(t));
                // Case 2: Imbalanced binary tree (only one structural imbalanced tree)
                t = operate((double)digits[0], (double)digits[1], ops[0]);
                t = operate(t, (double)digits[2], ops[1]);
                t = operate(t, (double)digits[3], ops[2]);
                if(fabs(round(t) - t) < eps && t > 0)
                    result.insert(round(t));
                ops[0]++;
                for (int j = 0; j < 3; j++)
                {
                    if (ops[j] > DIVIDE)
                    {
                        ops[j] = 0;
                        if (j < 2)
                            ops[j+1]++;
                    }
                }
            }
        }while(next_permutation(digits, digits + 4));

        // Determine the maximum run
        int last = 0;
        for (set< int >::iterator iter = result.begin(); iter != result.end(); iter++)
        {
            if (*iter != last + 1)
                break;
            last = *iter;
        }
        // Check if we have exceeded the maximum
        if (last > maximum)
        {
            maximum = last;
            for (int i = 0; i < 4; i++)
                maxString[i] = digits[i];
        }
    }while(next_choice(digits));
    for(int i = 0; i < 4; i++)
        cout << maxString[i];
    cout << "(1 through " << maximum << ")" << endl;
    printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
    return 0;
}

bool next_choice(int *digits)
{
    if (digits[0] == 6) // 6, 7, 8, 9, game over
        return false;
    if (digits[1] == 7)
    {
        digits[0]++;
        for (int i = 1; i < 4; i++)
            digits[i] = digits[i-1] + 1;
    }
    else if (digits[2] == 8)
    {
        digits[1]++;
        digits[2] = digits[1] + 1;
        digits[3] = digits[2] + 1;
    }
    else if (digits[3] == 9)
    {
        digits[2]++;
        digits[3] = digits[2] + 1;
    }
    else
        digits[3]++;
    return true;
}

double operate(double a, double b, int op)
{
    switch (op)
    {
        case PLUS:  return a + b;
        case MINUS: return a - b;
        case TIMES: return a * b;
    }
    return a / b; // DIVIDE
}
