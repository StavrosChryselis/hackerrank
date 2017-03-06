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

int N;
vector< vector<int> > G;
bool V[107];
int ans;

inline void init()
{
	int i, f, s;

	scanf("%d %d", &N, &N);
	N++;
	G.resize(N + 1);

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
		G[s].push_back(f);
	}
	V[1] = 1;
}

int dfs(int curr)
{
	int i, sum = 0, temp;

	for (i = 0; i < G[curr].size(); i++)
	{
		if (!V[G[curr][i]])
		{
			V[G[curr][i]] = 1;
			temp = dfs(G[curr][i]);
			if (temp % 2 == 0)
				ans++;
			else
				sum += temp;
		}
	}

	return sum + 1;
}

int main()
{

	init();
	dfs(1);
	printf("%d\n", ans);

	return 0;
}
