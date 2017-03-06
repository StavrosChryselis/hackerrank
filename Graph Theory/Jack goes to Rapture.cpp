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

inline int kruskal()
{
	list<pair <int, pair<int, int> > >::iterator ii;
	int v = 0;
	int ans;
	ufs g(N + 1);

	G.sort();

	ii = G.begin();

	while (ii != G.end() && !g.is_same_set(1, N))
	{
		if (!g.is_same_set(ii->second.first, ii->second.second))
		{
			v++;
			g.union_sets(ii->second.first, ii->second.second);
			MST[ii->second.first].push_back(make_pair(ii->second.second, ii->first));
			MST[ii->second.second].push_back(make_pair(ii->second.first, ii->first));
			ans = ii->first;
		}
		ii++;
	}

	if (g.is_same_set(1, N))
		return ans;

	return -1;
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
}

int main()
{
	int ans;

	init();

	ans = kruskal();

	if(ans != -1)
		printf("%d\n", ans);
	else
		printf("NO PATH EXISTS\n");

	return 0;
}
