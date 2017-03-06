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
using namespace std;

int N, E, Q;
vector< vector<int> > G(MAXN);
int gr[MAXN];

int grundy(int u)
{
	int i;

	if (gr[u] != -1)
		return gr[u];

	bool a[30] = { 0 };

	for (i = 0; i < G[u].size(); i++)
		a[grundy(G[u][i])] = 1;

	for (i = 0; i < 30; i++)
		if (!a[i])
		{
			gr[u] = i;
			return i;
		}

	return 0;
}

inline void init()
{
	int i, f, s;

	memset(gr, -1, sizeof(gr));

	scanf("%d %d", &N, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
	}

	for (i = 1; i <= N; i++)
		if (gr[i] == -1)
			grundy(i);

	scanf("%d", &Q);
}


inline int solve()
{
	int K, num, rval = 0;

	scanf("%d", &K);

	while (K--)
	{
		scanf("%d", &num);
		rval ^= gr[num];
	}

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	while (Q--)
	{
		if (solve())
			printf("Bumi\n");
		else
			printf("Iroh\n");
	}

	return 0;
}
