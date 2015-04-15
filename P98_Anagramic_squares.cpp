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

int main(int argc, char** args)
{
	clock_t start = clock();
	//load words from file into vector words
	fstream input("p098_words.txt");
	string word;
	//create a map from a sorted string to its anagrams
	map< string, vector<string> > anagrams;
	map< string, vector<string> >::iterator it;
	while(input.good())
    {
        getline(input, word, '"'); //unused, '"' and ','
        getline(input, word, '"'); //word
        string sortedWord = word;
        sort(sortedWord.begin(), sortedWord.end());
        it= anagrams.find(sortedWord);
        //check if key exists already
		if( it != anagrams.end() )
        {
			//if so add this word to existing vector
			(it->second).push_back(word);
		}
		else
        {
			//if not create new vector with this word
			vector<string> wordlist;
			wordlist.push_back(word);
			anagrams[sortedWord] = wordlist;
		}
	}

	//remove non-anagrams from map
	it = anagrams.begin();
	while(it != anagrams.end())
    {
		if( (it->second).size() == 1)
			anagrams.erase(it);
		it++;
	}

	//find our biggest square
	int maxsquare = 0;

	//iterate through the anagram vectors in our map (by key)
	for(it = anagrams.begin(); it != anagrams.end(); it++)
    {
		vector<string> anagramlist = it->second;
		//find range of squares we need to check
		double num = pow(10.0, (it->first).size() - 1);
		int lowerbound = ceil(sqrt(num));
		int upperbound = floor(sqrt(num * 10 - 1));

		//pick the first word to map the square onto
		for(unsigned int j = 0; j < anagramlist.size() - 1; j++)
        {
			string word = anagramlist[j];

			//iterate through the range of squares
			for(int mysqr = upperbound; mysqr >= lowerbound; mysqr--)
            {
				//sqrnum is our square to test
				int sqrnum = mysqr * mysqr;

				//get vector of digits in square
				vector<int> digits(word.size(), 0);
				int digitindex = word.size() - 1;
				int copysqrnum = sqrnum;
				while(copysqrnum)
                {
					digits[digitindex]= copysqrnum % 10;
					copysqrnum /= 10;
					digitindex--;
				}
				//define mapping from word to the digits in the square
				bool validmapping = true;
				vector<int> chartonum(26, -1);
				bool vis[10] = {};
				for(unsigned int k = 0; k < word.size(); k++)
                {
					int letterindex = (int)(word[k] - 'A');
					if(chartonum[letterindex] == -1)
					{
						chartonum[letterindex] = digits[k];
						if(vis[digits[k]])
                        {
                            //check if two letters have the same number (if so mapping is invalid)
                            validmapping = false;
                            break;
                        }
                        vis[digits[k]] = true;
					}
					else if(digits[k] != chartonum[letterindex])
                    {
                        //same letter but different number, invalid mapping
                        validmapping = false;
                        break;
                    }
                }
				if(!validmapping)
					//bad mapping, try the next square number
					continue;

				//now try mapping on all words to the right of this word
				for(unsigned int k = j + 1; k < anagramlist.size(); k++)
                {
					string otherword = anagramlist[k];
					if(chartonum[otherword[0] - 'A'] == 0)
						//leading zero is not allowed
						continue;

					//calculate what number the other word translates to
					int othersum = 0;
					for(unsigned int m = 0; m < otherword.size(); m++)
						othersum = 10 * othersum + chartonum[otherword[m] - 'A'];

					//if the number is a perfect square we found a valid combo
					int sqrtothersum = sqrt(othersum + 1);
					//found a valid pair
					if(sqrtothersum * sqrtothersum == othersum)
						maxsquare = max(maxsquare, max(sqrnum, othersum));
				}
			}
		}
	}
	cout << "Max square: " << maxsquare << endl;
	cout << "Elapsed time: " << (double)(clock() - start) / CLOCKS_PER_SEC << " seconds." << endl;
	return 0;
}
