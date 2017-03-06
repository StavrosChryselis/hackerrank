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
#include <vector>

using namespace std;

int N, M, R;
vector< vector< pair<int, int> > > rots; //0 null, 1 first lane etc
pair<int, int> MEMO[350][350];
int A[350][350];

inline void init()
{
	int i, j;

	scanf("%d %d %d", &N, &M, &R);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			scanf("%d", &A[i][j]);
}

inline void pre()
{
	int i, j, k, l;

	for (k = 1; MEMO[k][k].first == 0; k++)
	{
		vector< pair<int, int> > V;

		for (j = k; j <= M - k + 1; j++)
		{
			V.push_back(make_pair(k, j));
			MEMO[k][j] = make_pair(k, V.size());
		}

		for (i = k + 1; i <= N - k + 1; i++)
		{
			V.push_back(make_pair(i, M - k + 1));
			MEMO[i][M - k + 1] = make_pair(k, V.size());
		}

		for (j = M - k + 1 - 1; j >= k; j--)
		{
			V.push_back(make_pair(N - k + 1, j));
			MEMO[N - k + 1][j] = make_pair(k, V.size());
		}

		for (i = N - k + 1 - 1; i > k; i--)
		{
			V.push_back(make_pair(i, k));
			MEMO[i][k] = make_pair(k, V.size());
		}

		rots.push_back(V);
	}
}

inline void solve()
{
	int i, j, pos;
	pair<int, int> temp;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			temp = rots[MEMO[i][j].first - 1][(MEMO[i][j].second + R - 1) % rots[MEMO[i][j].first - 1].size()];
			printf("%d ", A[temp.first][temp.second]);
		}
		printf("\n");
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	pre();
	solve();
	return 0;
}
