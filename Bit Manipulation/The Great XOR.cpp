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

#define ll long long
using namespace std;

ll N;

inline ll solve()
{
	ll rval = 0;

	for (ll i = 1; i < N; i += i)
		if ((N | i) == N + i)
			rval += i;

	return rval;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << solve() << "\n";
	}

	return 0;
}
