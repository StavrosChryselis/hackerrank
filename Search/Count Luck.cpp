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
#include <deque>
#include <vector>
#include <string.h>

#define gc() getchar()
#define F first
#define S second
#define mp make_pair
using namespace std;

int N, M, K;
char board[128][128];
bool V[128][128];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
int x, y;

inline void init()
{
	int i, j;

	memset(board, 0, sizeof(board));
	memset(V, 0, sizeof(V));

	scanf("%d %d\n", &N, &M);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			board[i][j] = gc();
			if (board[i][j] == 'M')
			{
				x = i;
				y = j;
			}
		}
		gc();
	}

	scanf("%d", &K);
}

inline bool solve()
{
	deque< pair<int, pair<int, int> > > Q; //turns, x, y
	pair<int, pair<int, int> > curr;
	int i, temp;

	Q.push_back(mp(0, mp(x, y)));
	V[x][y] = 1;

	while (!Q.empty())
	{
		vector< pair <int, int> > moves;

		curr = Q.front();
		Q.pop_front();

		if (board[curr.S.F][curr.S.S] == '*')
			return curr.F == K;

		for (i = 0; i < 4; i++)
			if (!V[curr.S.F + dx[i]][curr.S.S + dy[i]] && (board[curr.S.F + dx[i]][curr.S.S + dy[i]] == '.' || board[curr.S.F + dx[i]][curr.S.S + dy[i]] == '*'))
			{
				V[curr.S.F + dx[i]][curr.S.S + dy[i]] = 1;
				moves.push_back(mp(curr.S.F + dx[i], curr.S.S + dy[i]));
			}

		if (moves.size() != 1)
			temp = 1;
		else
			temp = 0;

		for (i = 0; i < moves.size(); i++)
			Q.push_back(mp(curr.F + temp, mp(moves[i].F, moves[i].S)));
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
		if (solve())
			printf("Impressed\n");
		else
			printf("Oops!\n");
	}

	return 0;
}
