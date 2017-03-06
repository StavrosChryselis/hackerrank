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
#include <algorithm>

#define MAXN 100007
using namespace std;

int N, K;
vector< vector< pair<int, int> > > G(MAXN), STEINER(MAXN);
vector < pair< pair<int, int>, int> > edges;
int deg[MAXN];
bool is_dest[MAXN], marked[MAXN];
int w_sum;
int root;

inline void init()
{
	int i, f, s, w;

	scanf("%d %d", &N, &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d", &f);
		is_dest[f] = 1;
		if (!root)
			root = f;
	}

	for (i = 0; i < N - 1; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G[f].push_back(make_pair(s, w));
		G[s].push_back(make_pair(f, w));
		edges.push_back(make_pair(make_pair(f, s), w));
		deg[f]++;
		deg[s]++;
	}
}

inline void mark()
{
	int i, curr;
	deque<int> Q;

	for (i = 1; i <= N; i++)
		if (deg[i] == 1 && !is_dest[i])
		{
			marked[i] = 1;
			Q.push_back(i);
		}

	while (!Q.empty())
	{
		curr = Q.front();
		Q.pop_front();

		for (i = 0; i < G[curr].size(); i++)
		{
			int u = G[curr][i].first;
			deg[u]--;
			if (deg[u] == 1 && !is_dest[u])
			{
				Q.push_back(u);
				marked[u] = 1;
			}
		}
	}
}

inline void create_steiner()
{
	int i, u, v, w;

	for (i = 0; i < edges.size(); i++)
	{
		u = edges[i].first.first;
		v = edges[i].first.second;
		w = edges[i].second;

		if (!marked[u] && !marked[v])
		{
			STEINER[u].push_back(make_pair(v, w));
			STEINER[v].push_back(make_pair(u, w));
			w_sum += w;
		}
	}

	w_sum += w_sum;
}

pair<int, int> get_furthest(int curr, int from)
{
	int i;
	pair<int, int> temp, res;

	for (i = 0; i < STEINER[curr].size(); i++)
		if (STEINER[curr][i].first != from)
		{
			temp = get_furthest(STEINER[curr][i].first, curr);
			temp.first += STEINER[curr][i].second;
			res = max(res, temp);
		}

	if (STEINER[curr].size() == 1 && curr != from)
		return make_pair(0, curr);

	return res;
}

inline int get_diameter()
{
	int temp = get_furthest(root, root).second;

	return get_furthest(temp, temp).first;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	mark();
	create_steiner();

	printf("%d\n", w_sum - get_diameter());

	return 0;
}
