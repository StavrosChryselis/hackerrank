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

vector < vector< int > > G;
int N;

inline void init()
{
	int i, f, s;

	G.clear();
	scanf("%d", &N);
	G.resize(N + 1);

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
		G[s].push_back(f);
	}
}

int dfs(int u, int from)
{
	int rval = 0, i, v;

	for (i = 0; i < G[u].size(); i++)
	{
		v = G[u][i];

		if (v != from)
			rval ^= dfs(v, u) + 1;
	}

	return rval;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		init();
		if (dfs(1, 1))
			printf("Alice\n");
		else
			printf("Bob\n");
	}

	return 0;
}
