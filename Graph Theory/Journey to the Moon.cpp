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
#include <stdlib.h>
#include <vector>

using namespace std;

bool V[100007];

class ufs
{
private:
	struct set
	{
		int name;
		int rank;
		int set_size;
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
			S[i].set_size = 1;
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

	int get_size(int name)
	{
		return fs(name)->set_size;
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
			f->set_size += s->set_size;
		}

		else if (f->rank > s->rank)
		{
			s->parent = f;
			f->set_size += s->set_size;
		}

		else
		{
			f->parent = s;
			s->set_size += f->set_size;
		}
	}

	int size()
	{
		return ssize;
	}
};

inline long long solve()
{
	long long ans = 1LL;
	int N, E, f, s, i, temp, ssize;

	scanf("%d %d", &N, &E);

	ufs g(N);

	while (E--)
	{
		scanf("%d %d", &f, &s);
		g.union_sets(f, s);
	}

	for (i = 0; i < N; i++)
	{
		temp = g.find_set(i);
		if (!V[temp])
		{
			V[temp] = 1;
			ssize = g.get_size(temp);
			ans += (N - ssize) * ssize;
		}
	}

	return ans / 2;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	printf("%lld\n", solve());

	return 0;
}
