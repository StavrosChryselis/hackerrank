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
vector< vector<int> > dist;
int A[450][450];

void init()
{
	int i, j;
	int f, s, w;
    
    
	G.resize(N+1);

	for(i=0; i<=N; i++)
		G[i].resize(N+1);

	for(i=0; i<E; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
        A[f][s] = w;
		//G[f].push_back(make_pair(s,w));
	}
    
    for(i = 1; i<=N; i++)
        for(j = 1; j<=N; j++)
            if(A[i][j] != 0)
                G[i].push_back(make_pair(j, A[i][j]));
}

vector<int> dijkstra(int root)
{
	int i;
    vector<int> dist(N + 1);
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
    
    return dist;
}

int main()
{
	int i, Q, f, s;
	
	scanf("%d %d", &N, &E);
	init();	
    for(i = 1; i<=N; i++)
        dist.push_back(dijkstra(i));
    
    scanf("%d", &Q);
    
    for(i = 0; i<Q; i++)
    {
        scanf("%d %d", &f, &s);
        if(dist[f-1][s] == INT_MAX)
            printf("-1\n");
        else
          printf("%d\n", dist[f-1][s]);
    }
	return 0;
}
