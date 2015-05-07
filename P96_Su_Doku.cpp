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
#define MAXN 1000000
#define MOD 10000000000
#define LL long long
#define eps 1e-8
#define inf 0x3f3f3f3f
using namespace std;

int field[9][9];

bool next(int &y, int &x)
{
	x++;
	if(x >= 9)
    {
		x=0;
        y++;
		if(y>=9)
            return false;
	}
	return true;
}

static bool solve(int y, int x)
{
	while(field[y][x])
    {
		if (!next(y,x))
            return true;
	}
	for (int i = 1; i <= 9; i++)
	{
	    bool status = true;
		for(int yy = 0; yy < 9 && status; yy++)
		{
		    if(field[yy][x] == i)
            {
                status = false;
            }
		}
		if(!status)
            continue;
		for (int xx = 0; xx < 9 && status; xx++)
        {
            if (field[y][xx] == i)
            {
                status = false;
            }
        }
        if(!status)
            continue;
        int basey = (y / 3) * 3;
        int basex = (x / 3) * 3;
        for(int yy = 0; yy < 3 && status; yy++)
            for(int xx = 0; xx < 3 && status; xx++)
            {
                if (field[basey + yy][basex + xx] == i)
                {
                    status = false;
                }
            }
        if(!status)
            continue;
		field[y][x] = i; //set as i has no collisions temporarily
		if (solve(y, x))
            return true;
		field[y][x] = 0;
	}
	return false;
}

int main()
{
    clock_t start = clock();
    FILE *fp;
    char line[100];
	int sum = 0;
	fp = fopen("p096_sudoku.txt", "r");
    if (!fp)
    {
        perror("open input: ");
        exit(1);
    }

    while(!feof(fp))
    {
        fgets(line, sizeof(line), fp);
        if(0 != strncmp(line,"Grid", 4))
        {
            fprintf(stderr, "sync error '%s'\n", line);
            exit(1);
        }
		for (int y = 0; y < 9; y++)
        {
			fgets(line, sizeof(line), fp);
			for(int x = 0; x < 9; x++)
			{
				field[y][x] = line[x] - '0';
			}
		}
		bool res = solve(0, 0);
		if (!res)
		{
		    cout << "no solution!" << endl;
            return 1;
        }
		sum += (field[0][0] * 10 + field[0][1]) * 10 + field[0][2];
	}
	cout << sum << endl;
    cout << "Time cost: " << setprecision(6) << fixed << (double)((clock() - start) / CLOCKS_PER_SEC) << " s." << endl;
	return 0;
}