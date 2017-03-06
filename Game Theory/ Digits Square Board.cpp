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
#include <vector>

using namespace std;

int memo[31][31][31][31];
int hm[31][31][31][31];
int not_prime[] = { 0, 1, 0, 0, 1, 0, 1, 0, 1, 1 };
bool board[31][31];
int N;

inline void init()
{
	int i, j, num;

	memset(memo, -1, sizeof(memo));
	memset(hm, -1, sizeof(hm));

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &num);
			board[i][j] = not_prime[num];
		}
}

inline bool has_move(pair<int, int> tl, pair<int, int> br)
{

	if (hm[tl.first][tl.second][br.first][br.second] != -1)
		return hm[tl.first][tl.second][br.first][br.second];

	if (tl == br)
		return 0;

	int i, j;

	for (i = tl.first; i <= br.first; i++)
		for (j = tl.second; j <= br.second; j++)
			if (board[i][j])
			{
				hm[tl.first][tl.second][br.first][br.second] = 1;
				return 1;
			}

	hm[tl.first][tl.second][br.first][br.second] = 0;
	return 0;
}

int grundy(pair<int, int> tl, pair<int, int> br)
{
	if (memo[tl.first][tl.second][br.first][br.second] != -1)
		return memo[tl.first][tl.second][br.first][br.second];

	if (!has_move(tl, br))
	{
		memo[tl.first][tl.second][br.first][br.second] = 0;
		return 0;
	}

	bool a[50] = { 0 };
	int i;

	for (i = tl.first; i < br.first; i++)
		a[grundy(tl, make_pair(i, br.second)) ^ grundy(make_pair(i + 1, tl.second), br)] = 1;

	for (i = tl.second; i < br.second; i++)
		a[grundy(tl, make_pair(br.first, i)) ^ grundy(make_pair(tl.first, i + 1), br)] = 1;

	for (i = 0; i < 50; i++)
		if (!a[i])
		{
			memo[tl.first][tl.second][br.first][br.second] = i;
			return i;
		}

	return 0;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		init();
		if (grundy(make_pair(1, 1), make_pair(N, N)))
			printf("First\n");
		else
			printf("Second\n");
	}

	return 0;
}
