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
#include <list>
#include <algorithm>
#include <string.h>

using namespace std;

long long ans[200100];
int maxval;
list< pair<int, pair<int, int> > > G;
vector < vector< pair<int, int> > > MST;	//u, w
int N, E;

class ufs
{
	private:
		struct set
		{
			int name;
			int rank;
			set *parent;
		};
		int ssize;
		vector<set> S;

		set *fs(int name)
		{
			if (S[name].parent->name == name)
				return &S[name];

			S[name].parent = fs(S[name].parent->name);
			return S[name].parent;
		}


	public:
		ufs(int n)
		{
			int i;
			ssize = n;
			S.resize(ssize);

			for (i = 0; i<S.size(); i++)
			{
				S[i].name = i;
				S[i].parent = &S[i];
				S[i].rank = 0;
			}
		}

		int find_set(int name)
		{
			return fs(name)->name;
		}

		bool is_same_set(int a, int b)
		{
			return fs(a)->name == fs(b)->name;
		}

		void union_sets(int a, int b)
		{
			set *f, *s;

			f = fs(a);
			s = fs(b);

			if (f->name == s->name)
				return;

			ssize--;
			if (f->rank == s->rank)
			{
				f->rank++;
				s->parent = f;
			}

			else if (f->rank > s->rank)
				s->parent = f;

			else
				f->parent = s;
		}

		int size()
		{
			return ssize;
		}
};

void kruskal()
{
	list<pair <int, pair<int, int> > >::iterator ii;
	int v = 0;
	ufs g(N + 1);

	G.sort();

	ii = G.begin();

	while (v<N - 1)
	{
		if (!g.is_same_set(ii->second.first, ii->second.second))
		{
			v++;
			g.union_sets(ii->second.first, ii->second.second);
			MST[ii->second.first].push_back(make_pair(ii->second.second, ii->first));
			MST[ii->second.second].push_back(make_pair(ii->second.first, ii->first));
			maxval = ii->first;
		}
		ii++;
	}
}

int DFS(int curr, int from)
{
	int i, v, r = 1;

	for (i = 0; i < MST[curr].size(); i++)
		if (MST[curr][i].first != from)
		{
			v = DFS(MST[curr][i].first, curr);
			ans[MST[curr][i].second] += 1LL * v * (N - v);
			r += v;
		}
	return r;
}


inline void init()
{
	int i, f, s, w;

	scanf("%d %d", &N, &E);

	MST.resize(N + 1);

	for (i = 0; i < E; i++)
	{
		scanf("%d %d %d", &f, &s, &w);
		G.push_back(make_pair(w, make_pair(f, s)));
	}

	kruskal();
}

inline void solve()
{
	int i;

	DFS(1, 1);

	for (i = 0; i < maxval; i++)
		if (ans[i])
		{
			ans[i + 1] += ans[i] / 2;
			ans[i] %= 2;
		}

	while (ans[maxval] > 1)
	{
		ans[maxval + 1] += ans[maxval] / 2;
		ans[maxval] %= 2;
		maxval++;
	}

}

inline void print()
{
	int i;

	for (i = maxval; i >= 0; i--)
		putchar('0' + ans[i]);

	putchar('\n');
}

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	init();
	solve();
	print();

	return 0;
}
