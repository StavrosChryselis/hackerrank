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
#include <string.h>

using namespace std;

int dx[] = { -2, -2, 1, -1 };
int dy[] = { 1, -1, -2, -2 };
int gr[16][16];

inline bool is_in(int x, int y)
{
	if (x <= 0)
		return 0;

	if (y <= 0)
		return 0;

	if (x > 15)
		return 0;

	if (y > 15)
		return 0;

	return 1;
}

inline bool has_moves(int x, int y)
{
	int i;

	for (i = 0; i < 4; i++)
		if (is_in(x + dx[i], y + dy[i]))
			return 1;

	return 0;
}

int grundy(int x, int y)
{
	int i;

	if (gr[x][y] != -1)
		return gr[x][y];

	if (!has_moves(x, y))
	{
		gr[x][y] = 0;
		return 0;
	}

	bool a[10] = { 0 };

	for (i = 0; i < 4; i++)
		if (is_in(x + dx[i], y + dy[i]))
			a[grundy(x + dx[i], y + dy[i])] = 1;

	for (i = 0; i < 10; i++)
		if (!a[i])
		{
			gr[x][y] = i;
			return i;
		}

	return 0;
}

inline void pre()
{
	int i, j;

	memset(gr, -1, sizeof(gr));

	for (i = 1; i <= 15; i++)
		for (j = 1; j <= 15; j++)
			grundy(i, j);
}

inline bool solve()
{
	int x, y, K, res = 0;

	scanf("%d", &K);

	while (K--)
	{
		scanf("%d %d", &x, &y);
		res ^= gr[x][y];
	}

	if (res)
		return 1;
	return 0;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	pre();

	scanf("%d", &T);
	
	while (T--)
	{
		if (solve())
			printf("First\n");
		else
			printf("Second\n");
	}

	return 0;
}
