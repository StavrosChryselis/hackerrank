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
#include <algorithm>

#define MAXN 100007
#define MOD 1000000000
using namespace std;

int N, E;
vector< vector<int> > G(MAXN), GG(MAXN);
vector< pair<int, int> > Edges;
int Index[MAXN], Lowlink[MAXN], Component[MAXN];
long long Ways[MAXN];
bool Onstack[MAXN], V[MAXN];
int INDEX = 0;
vector<int> S;
vector< vector<int> > SCC;

inline void init()
{
	int i, f, s;

	scanf("%d %d", &N, &E);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d", &f, &s);
		G[f].push_back(s);
		Edges.push_back(make_pair(f, s));
	}
}

void strongconnect(int v)
{
	int i, w;

	Index[v] = INDEX;
	Lowlink[v] = INDEX;
	INDEX++;

	S.push_back(v);
	Onstack[v] = 1;

	for (i = 0; i < G[v].size(); i++)
	{
		w = G[v][i];

		if (Index[w] == -1)
		{
			strongconnect(w);
			Lowlink[v] = min(Lowlink[v], Lowlink[w]);
		}

		else if (Onstack[w])
			Lowlink[v] = min(Lowlink[v], Index[w]);
	}

	if (Lowlink[v] == Index[v])
	{
		SCC.push_back(vector<int>());

		do
		{
			w = S.back();
			S.pop_back();
			Onstack[w] = 0;
			SCC[SCC.size() - 1].push_back(w);
			Component[w] = SCC.size() - 1;
		} while (w != v);
	}
}

long long traverse(int curr, bool is_bad)
{
	V[curr] = 1;

	if (curr == Component[N])
	{
		Ways[curr] = 1;
		if (is_bad)
			return -1;
		return 1;
	}

	if (SCC[curr].size() > 1)
		is_bad = 1;

	for (int i = 0; i < GG[curr].size(); i++)
	{
		if (V[GG[curr][i]])
		{
			Ways[curr] += Ways[GG[curr][i]];
			Ways[curr] %= MOD;
		}

		else
		{
			int temp = traverse(GG[curr][i], is_bad);

			if (temp == -1 || temp && is_bad)
				return -1;

			Ways[curr] += temp;
			Ways[curr] %= MOD;
		}
	}

	return Ways[curr] % MOD;
}

inline void tarjan()
{
	memset(Index, -1, sizeof(Index));

	for (int i = 1; i <= N; i++)
		if (Index[i] == -1)
			strongconnect(i);
}

inline void create_tree()
{
	int i;

	for (i = 0; i < E; i++)
		if (Component[Edges[i].first] != Component[Edges[i].second])
			GG[Component[Edges[i].first]].push_back(Component[Edges[i].second]);
}


int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	tarjan();
	create_tree();

	long long temp = traverse(Component[1], 0);

	if (temp == -1)
		printf("INFINITE PATHS\n");
	else
		printf("%lld\n", temp);

	return 0;
}
