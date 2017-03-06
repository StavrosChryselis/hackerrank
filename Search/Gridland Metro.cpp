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
#include <algorithm>
#include <vector>

using namespace std;

vector< pair<long long, pair<long long, long long> > > A;
int K;
long long N, M;

inline void init()
{
	int i;
	pair<long long, pair<long long, long long> > t;

	scanf("%lld %lld %d", &N, &M, &K);

	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d", &t.first, &t.second.first, &t.second.second);
		A.push_back(t);
	}

	sort(A.begin(), A.end());
}

inline bool overlaps(pair<long long, long long> a, pair<long long, long long> b)
{
	if (b.first <= a.second)
		return 1;

	return 0;
}

inline long long get_occ(int st, int en)
{
	int i;
	pair<long long, long long> p;
	long long rval = 0;

	p = A[st].second;

	for (i = st + 1; i <= en; i++)
	{
		if (overlaps(p, A[i].second))
			p.second = max(p.second, A[i].second.second);
		else
		{
			rval += p.second - p.first + 1;
			p = A[i].second;
		}
	}

	rval += p.second - p.first + 1;

	return rval;
}

inline long long solve()
{
	int i, st = 0, j;
	long long rval = 0;

	while (st < K)
	{
		for (i = st + 1; i < K && A[i].first == A[st].first; i++);

		rval += get_occ(st, i - 1);
		st = i;
	}

	long long all = N;
	all *= M;

	return all - rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	printf("%lld\n", solve());

	return 0;
}
