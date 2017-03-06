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
#include <deque>
#include <limits.h>
#include <string.h>
#include <algorithm>

using namespace std;

int N, E, T;
int f, s;
vector< vector<pair<int, int> > > G;
int mindist[1024];
bool V[1024][1040];

void init()
{
	int i;
	int ff, ss, w;

	scanf("%d %d", &N, &E);

	G.resize(N + 1);

	for (i = 0; i<E; i++)
	{
		scanf("%d %d %d", &ff, &ss, &w);
		G[ff].push_back(make_pair(ss, w));
		G[ss].push_back(make_pair(ff, w));
	}
	scanf("%d %d", &f, &s);

	for (i = 1; i <= N; i++)
		mindist[i] = INT_MAX;
}

inline int solve()
{
	deque< pair<int, int> > Q; //u, d
	pair<int, int> curr;
	int i;

	Q.push_back(make_pair(f, 0));

	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();

		mindist[curr.first] = min(curr.second, mindist[curr.first]);

		if (curr.first == s)
			continue;

		for (i = 0; i < G[curr.first].size(); i++)
			if (!V[G[curr.first][i].first][curr.second | G[curr.first][i].second])
			{
				V[G[curr.first][i].first][curr.second | G[curr.first][i].second] = 1;
				Q.push_back(make_pair(G[curr.first][i].first, curr.second | G[curr.first][i].second));
			}
	}

	if (mindist[s] == INT_MAX)
		return -1;
	return mindist[s];
}

int main()
{
	int f, s;

//	freopen("input.txt","r",stdin);

	init();
	printf("%d\n", solve());

	return 0;
}
