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
#include <ctype.h>
#include <algorithm>

#define gc() getchar()
using namespace std;

string S;
int N, K;

inline void getstring(string &A)
{
	char c = gc();

	A.clear();

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
	scanf("%d %d", &N, &K);
	getstring(S);
}

inline void solve()
{
	int i;

	for (i = 0; i < S.size() / 2; i++)
		if (S[i] != S[N - 1 - i])
			K--;

	if (K < 0)
	{
		printf("-1\n");
		return;
	}

	for (i = 0; i < S.size() / 2; i++)
	{
		if (S[i] == '9' && S[N - 1 - i] == '9')
			continue;

		if (S[i] != S[N - 1 - i])
		{
			if (K && S[i] != '9' && S[N - 1 - i] != '9')
			{
				S[i] = S[N - 1 - i] = '9';
				K--;
			}

			else
			{
				S[i] = S[N - 1 - i] = max(S[i], S[N - 1 - i]);
			}
		}

		else if (K >= 2)
		{
			S[i] = S[N - 1 - i] = '9';
			K -= 2;
		}
	}

	if (S.size() % 2 && K)
		S[S.size() / 2] = '9';

	printf("%s\n", S.c_str());
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	init();
	solve();

	return 0;
}
