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
#include <algorithm>
#include <string.h>
#include <limits.h>
#include <math.h>

using namespace std;

int minval;
vector< vector<int> > G;
int N, sum;
int W[100007];

inline void init()
{
	int f, s, i;

	minval = INT_MAX;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d", &W[i]);
		sum += W[i];
	}

	G.resize(N + 1);

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
		G[s].push_back(f);
	}
}

int DFS(int curr, int from)
{
	int i, v, r = W[curr];

	for (i = 0; i < G[curr].size(); i++)
		if (G[curr][i] != from)
		{
			v = DFS(G[curr][i], curr);
			minval = min(minval, abs(v - (sum - v)));
			r += v;
		}
	return r;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	DFS(1, 1);

	printf("%d\n", minval);

	return 0;
}
