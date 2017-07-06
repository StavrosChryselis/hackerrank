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

#include <iostream>
#include <set>
#include <algorithm>

#define MAXN 200007
#define ll long long
using namespace std;

int N;
ll A[MAXN];
set<ll> S;
const ll INF = 1e16 + 1;

inline void init()
{
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> A[i];

	S.insert(0);
}

inline ll solve()
{
	int i;
	ll rval = INF;
	set<ll>::iterator ii;

	for (i = N - 1; i >= 0; i--)
	{
		ii = S.lower_bound(A[i]);
		ii--;
		if (*ii)
			rval = min(rval, A[i] - *ii);
		S.insert(A[i]);
	}

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
