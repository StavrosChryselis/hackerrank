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

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define gc() getchar()

using namespace std;

char A[1024][1024];
char pattern[1024][1024];
int N, M, n, m;

inline void init()
{
	int i, j;

	scanf("%d %d\n", &N, &M);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
			A[i][j] = gc();
		gc();
	}

	scanf("%d %d\n", &n, &m);

	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
			pattern[i][j] = gc();
		gc();
	}
}

inline bool check(int x, int y)
{
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (pattern[i][j] != A[x + i - 1][y + j - 1])
				return 0;

	return 1;
}

inline bool solve()
{
	int i, j;

	for (i = 1; i <= N - n + 1; i++)
		for (j = 1; j <= M - m + 1; j++)
			if (check(i, j))
				return 1;

	return 0;
}

int main()
{
	int T;

	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);

	while (T--)
	{
		init();
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
