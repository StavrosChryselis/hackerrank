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
#include <set>
#include <limits.h>

using namespace std;

int N, E, T;
vector< vector<pair<int, int> > > G;
vector<int> dist;

void init()
{
	int i;
	int f, s, w;
    
    G.clear();
    dist.clear();
    
	G.resize(N+1);
	dist.resize(N+1);

	for(i=0; i<=N; i++)
		G[i].resize(N+1);

	for(i=0; i<E; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G[f].push_back(make_pair(s,w));
        G[s].push_back(make_pair(f, w));
	}
}

void dijkstra(int root)
{
	int i;
	set<pair<int, int> > Q;
	int alt;
	pair<int, int> u;

	for(i=1; i<=N; i++)
		dist[i]=INT_MAX;

	dist[root]=0;
	Q.insert(make_pair(0,root));
	Q.insert(make_pair(INT_MAX, N+1));

	while(Q.begin()->first!=INT_MAX)
	{
		u=*Q.begin();
		Q.erase(Q.begin());

		for(i=0; i<G[u.second].size(); i++)
		{
			alt=u.first+G[u.second][i].second;
			if(alt<dist[G[u.second][i].first])
			{
				dist[G[u.second][i].first]=alt;
				Q.insert(make_pair(dist[G[u.second][i].first], G[u.second][i].first));
			}
		}
	}
}

int main()
{
	int i, s, j;

	scanf("%d", &T);

	for(i=0; i<T; i++)
	{
		scanf("%d %d", &N, &E);
		init();
        scanf("%d", &s);
		dijkstra(s);
		for(j = 1; j<= N; j++)
            if(j != s)
            {
                if(dist[j] != INT_MAX)
                    printf("%d ", dist[j]);
            else
                printf("-1 ");
        }
        puts("");
	}

	return 0;
}
