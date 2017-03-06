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

#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#include <algorithm>

#define MAXN 1024
#define gc() getchar()
using namespace std;

int DP[MAXN][MAXN];
string A, B;
int N, M;

inline void getstring(string &S)
{
	char c = gc();

	S.clear();
	S.push_back('0');

	while (isspace(c))
		c = gc();

	while (!isspace(c) && c != EOF)
	{
		S.push_back(c);
		c = gc();
	}
}

inline void init()
{
	memset(DP, 0, sizeof(DP));

	getstring(A);
	getstring(B);

	N = A.length();
	M = B.length();

	N--;
	M--;
}

inline void solve()
{
	int i, j;

	DP[0][0] = 1;

	for (i = 1; i <= N && A[i] == tolower(A[i]); i++)
		DP[i][0] = 1;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			if (A[i] == toupper(A[i]))
			{
				if (A[i] != B[j])
					DP[i][j] = 0;
				else
					DP[i][j] = DP[i - 1][j - 1];
			}

			else
			{
				if (toupper(A[i]) == B[j])
					DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
				else
					DP[i][j] = DP[i - 1][j];
			}
		}

	if (DP[N][M] == 1)
		cout << "YES\n";
	else
		cout << "NO\n";
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);
//	ios::sync_with_stdio(0);

	cin >> T;

	while (T--)
	{
		init();
		solve();
	}

	return 0;
}
