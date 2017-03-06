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
#include <algorithm>
#include <vector>

#define MAXN 100007
#define ll long long
using namespace std;

int N, K;
ll A[MAXN];

inline void init()
{
	int i;

	cin >> N;
	cin >> K;

	for (i = 1; i <= N; i++)
		cin >> A[i];

	sort(A + 1, A + N + 1);
}

inline pair<ll, ll> init_window()
{
	pair<ll, ll> rval;
	ll sum_all, sum_first;	
	int i;

	sum_all = sum_first = rval.first = rval.second = 0;

	for (i = 1; i <= K; i++)
		sum_all += A[i];

	for (i = 1; i <= K - 1; i++)
	{
		sum_first += A[i];
		rval.first += sum_all - sum_first - (K - i) * A[i];
	}

	rval.second = sum_all;
	return rval;
}

inline ll solve()
{
	pair<ll, ll> t = init_window();
	ll curr = t.first;
	ll sum = t.second;
	ll rval = curr;
	ll Old, New;
	int i, j;

	for (i = 1, j = K + 1; j <= N; j++, i++)
	{
		Old = sum - A[i];
		Old -= (K - 1) * A[i];

		New = (K - 1) * A[j];
		New -= sum - A[i];

		curr -= Old;
		curr += New;

		sum -= A[i];
		sum += A[j];

		rval = min(rval, curr);
	}

	return rval;
}

int main()
{
	ios::sync_with_stdio(0);

//	freopen("input.txt", "r", stdin);

	init();
	cout << solve() << "\n";

	return 0;
}
