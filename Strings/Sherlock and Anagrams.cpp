/*
****************************************************************
****************************************************************
-> Coded by Stavros Chryselis				   
-> Visit my github for more solved problems over multiple sites 
-> https://github.com/StavrosChryselis			  
-> Feel free to email me at stavrikios@gmail.com	
****************************************************************
****************************************************************
*/

#include <stdio.h>
#include <string>
#include <string.h>
#include <unordered_map>
#include <ctype.h>

#define gc() getchar()
using namespace std;

int memo[128][26];
string S;

inline void get(string &A)
{
	char c;

	A.clear();

	A.push_back('0');

	c = gc();

	while (isspace(c))
		c = gc();

	while (!isspace(c) && c != EOF)
	{
		A.push_back(c);
		c = gc();
	}
}

inline void init()
{
	int i, j;
	
	get(S);

	memset(memo, 0, sizeof(memo));

	for (i = 1; i < S.length(); i++)
	{
		for (j = 0; j < 26; j++)
			memo[i][j] = memo[i - 1][j];
		memo[i][S[i] - 'a']++;
	}
}

inline void radix_sort(int i, int j, string &A)
{
	int k, l;

	A.clear();

	for (k = 0; k < 26; k++)
		for (l = 0; l < memo[j][k] - memo[i - 1][k]; l++)
			A.push_back(k + 'a');
}

inline int solve()
{
	unordered_map<string, int> lex;
	string A;
	int i, k, ans = 0;

	for (k = 1; k <= S.length() - 1; k++)
		for (i = 1; i + k - 1 < S.length(); i++)
		{
			radix_sort(i, i + k - 1, A);
			lex[A]++;
			ans += lex[A] - 1;
		}

	return ans;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		init();
		printf("%d\n", solve());
	}

	return 0;
}
