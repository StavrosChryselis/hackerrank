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
#include <list>
 
using namespace std;
 
list< pair<long long, pair<int, int> > > G;
long long mw;
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
			if(S[name].parent->name==name)
				return &S[name];
 
			S[name].parent=fs(S[name].parent->name);
			return S[name].parent;
		}
 
 
	public:
		ufs(int n)
		{
			int i;
			ssize=n;
			S.resize(ssize);
 
			for(i=0; i<S.size(); i++)
			{
				S[i].name=i;
				S[i].parent=&S[i];
				S[i].rank=0;
			}
		}
 
		int find_set(int name)
		{
			return fs(name)->name;
		}
 
		bool is_same_set(int a, int b)
		{
			return fs(a)->name==fs(b)->name;
		}
 
		void union_sets(int a, int b)
		{
			set *f, *s;
 
			f=fs(a);
			s=fs(b);
 
			if(f->name==s->name)
				return;
 
			ssize--;
			if(f->rank==s->rank)
			{
				f->rank++;
				s->parent=f;
			}
	
			else if(f->rank > s->rank)
				s->parent=f;
	
			else
				f->parent=s;
		}
 
		int size()
		{
			return ssize;
		}
};
 
void kruskal()
{
	list<pair <long long, pair<int, int> > >::iterator ii;
	int v=0;
	ufs g(N+1);
 
	G.sort();
 
	ii=G.begin();
 
	while(v<N-1)
	{
		if(!g.is_same_set(ii->second.first, ii->second.second))
		{
			v++;
			mw+=ii->first;
 
			g.union_sets(ii->second.first, ii->second.second);
		}
		ii++;
	}
}
 
int main()
{
	int i;
	int f, s;
	long long w;
	long long sum = 0;
    
	scanf("%d %d", &N, &E);
 
	for(i=0; i<E; i++)
	{
		scanf("%d %d %lld", &f, &s, &w);
		G.push_back(make_pair(w, make_pair(f, s)));
		sum += w;
	}
 
	kruskal();
 
	printf("%lld\n", mw);
 
	return 0;
} 
