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
#include <string.h>

#define MAXN 100007
#define LOGN 20
using namespace std;

vector<int> starting_nodes;
int DP[MAXN][LOGN];
bool exists[MAXN];
int N, Q;

inline void init()
{
	int i, j, f, s;

	starting_nodes.clear();
	memset(DP, 0, sizeof(DP));
	memset(exists, 0, sizeof(exists));

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &f, &s);

		starting_nodes.push_back(f);
		exists[f] = 1;
		DP[f][0] = s;
	}

	for (j = 1; 1 << j < N; j++)
		for (i = 0; i < N; i++)
			DP[starting_nodes[i]][j] = DP[DP[starting_nodes[i]][j - 1]][j - 1];

	scanf("%d", &Q);
}

inline void insert(int curr, int father)
{
	int j;

	N++;

	exists[curr] = 1;
	DP[curr][0] = father;

	for (j = 1; 1 << j < N; j++)
		DP[curr][j] = DP[DP[curr][j - 1]][j - 1];
}

inline void rremove(int curr)
{
	if (!exists[curr])
		return;

	exists[curr] = 0;
	N--;
}

inline int query(int curr, int K)
{
	int j;

	if (!exists[curr])
		return 0;

	while (K != 1)
	{
		for (j = 0; 1 << j < K; j++);
		j--;
		K -= 1 << j;
		curr = DP[curr][j];
	}

	return DP[curr][0];
}

int main()
{
	int T;
	int type, f, s;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		init();
		while (Q--)
		{
			scanf("%d", &type);
			switch (type)
			{
			case 0:
				scanf("%d %d", &f, &s);
				insert(s, f);
				break;
			case 1:
				scanf("%d", &f);
				rremove(f);
				break;
			case 2:
				scanf("%d %d", &f, &s);
				printf("%d\n", query(f, s));
				break;
			}
		}
	}

	return 0;
}
