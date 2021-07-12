#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <numeric>
#include <ctime>
// C++ is more than 5x faster than python
int countBinOnes(int x)
{
	int cnt = 0;
	while (x)
	{
		cnt += 1;
		x &= x - 1;
	}
	return cnt;
}

bool isSpecialSet(std::vector< int > &A)
{
	int N = (1 << A.size()) - 1;
	std::vector< int > subset(N, 0);
	for (int i = 1; i < N; i += 1)
	{
		for (int j = 0; j < A.size(); j += 1)
		{
			if ( ( (i >> j)&1 ) == 1 )
			{
				subset[i] += A[j];
			}
		}
	}
	for (int i = 1; i < N; i += 1)
	{
		for (int j = i + 1; j < N; j += 1)
		{
			if ( (i&j) == 0 )
			{
				if (subset[i] == subset[j])
					return false;
				if (subset[i] > subset[j])
				{
					if (countBinOnes(i) < countBinOnes(j))
						return false;
				}
				else if (countBinOnes(i) > countBinOnes(j))
					return false;
			}
		}
	}
	return true;
}

int main()
{
	clock_t start = clock();
	std::ifstream input("105_sets.txt");
	std::string line;
	int res = 0;
	while (std::getline(input, line))
	{
		std::stringstream ss(line);
		std::vector< int > A;
		int x;
		while (ss >> x)
		{
			A.push_back(x);
			if (ss.peek() == ',')
			{
				ss.ignore();
			}
		}
		if (isSpecialSet(A) == true)
		{
			res += std::accumulate(A.begin(), A.end(), 0);
		}
	}
	printf("%d\n", res);
	printf( "Time cost: %lf s.", (double)( clock() - start ) / CLOCKS_PER_SEC );
	//system("pause");
}
