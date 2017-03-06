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
#include <ctype.h>
#include <vector>
#include <string.h>
#include <algorithm>

#define gc() getchar()
using namespace std;

inline char next_char()
{
	char c = gc();

	while (isspace(c))
		c = gc();

	return c;
}

bool board[50][50];
bool v[50][50];
int area[20];
vector< pair<int, int> > A[10];
int N, M;

inline void init()
{
	char c;
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
		{
			c = next_char();
			if (c == 'G')
				board[i][j] = 1;
		}

	area[0] = 1;

	for (i = 1; i < 20; i++)
		area[i] = area[i - 1] + 4;
}

inline bool grow(pair<int, int> center, int r)
{
	if (!board[center.first + r][center.second])
		return 0;

	if (!board[center.first - r][center.second])
		return 0;

	if (!board[center.first][center.second + r])
		return 0;

	if (!board[center.first][center.second - r])
		return 0;

	return 1;
}

inline void get()
{
	int i, j, r;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			for (r = 0; grow(make_pair(i, j), r); r++)
				A[r].push_back(make_pair(i, j));
}

inline bool intersects(pair<int, int> a, int ra, pair<int, int> b, int rb)
{
	int i;

	memset(v, 0, sizeof(v));

	v[a.first][a.second] = 1;

	for (i = 1; i <= ra; i++)
	{
		v[a.first + i][a.second] = 1;
		v[a.first - i][a.second] = 1;
		v[a.first][a.second + i] = 1;
		v[a.first][a.second - i] = 1;
	}

	for (i = 0; i <= rb; i++)
	{
		if (v[b.first + i][b.second])
			return 1;

		if (v[b.first - i][b.second])
			return 1;

		if (v[b.first][b.second + i])
			return 1;

		if (v[b.first][b.second - i])
			return 1;
	}

	return 0;
}

inline bool check(pair<int, int> a, int r, int rc)
{
	int i;

	for (i = 0; i < A[rc].size(); i++)
		if (!intersects(a, r, A[rc][i], rc))
			return 1;

	return 0;
}	

inline int solve()
{
	int i, j, k;
	int rval = 0;

	for (i = 0; i < 10; i++)
		for (j = 0; j < A[i].size(); j++)
		{
			for (k = 0; check(A[i][j], i, k); k++);
			k--;

			rval = max(rval, area[i] * area[k]);
		}

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	get();
	printf("%d\n", solve());

	return 0;
}
