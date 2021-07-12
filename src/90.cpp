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

vector < vector < int > > arr;
int d1[] = {0, 0, 0, 1, 2, 3, 4, 6, 8};
int d2[] = {1, 4, 9, 6, 5, 6, 9, 4, 1};

void dfs(int x, int y, vector < int > v)
{
	if(x <= 9)
	{
        dfs(x + 1, y, v);
        v.push_back(x);
		if(y == 5)
        {
            arr.push_back(v);
			v.clear();
        }
		else
			dfs(x + 1, y + 1, v);
	}
	return;
}

int main()
{
    clock_t start = clock();
    vector <int> a, b;
	dfs(0, 0, a);
	bool status = true;
	int ans = 0, same = 0;
	for(unsigned int i = 0; i < arr.size(); i++)
	{
		for(unsigned int j = 0; j < arr.size(); j++)
		{
			a = arr[i];
			b = arr[j];
			if(a == b)
				same++;
			if(binary_search(a.begin(), a.end(), 6) && !binary_search(a.begin(), a.end(), 9))
				a.push_back(9);
			else if(binary_search(a.begin(), a.end(), 9) && !binary_search(a.begin(), a.end(), 6))
			{
				a.push_back(6);
				sort(a.begin(),a.end());
			}
			if(binary_search(b.begin(), b.end(), 6) && !binary_search(b.begin(), b.end(), 9))
				b.push_back(9);
			else if(binary_search(b.begin(), b.end(), 9) && !binary_search(b.begin(), b.end(), 6))
			{
				b.push_back(6);
				sort(b.begin(), b.end());
			}
			for(int k = 0; k < 9; k++)
			{
				if(!((binary_search(a.begin(), a.end(), d1[k]) && binary_search(b.begin(), b.end(), d2[k]))
                || (binary_search(a.begin(), a.end(), d2[k]) && binary_search(b.begin(), b.end(), d1[k]))))
				{
					status = false;
					break;
				}
			}
			if(status)
				ans++;
            status = true;
		}
	}
	cout << ans / 2 << endl;
	printf("Time cost: %f s.\n", (double)((clock() - start) / CLOCKS_PER_SEC));
	return 0;
}
