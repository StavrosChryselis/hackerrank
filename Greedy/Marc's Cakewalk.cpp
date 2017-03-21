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
#include <functional>
#include <math.h>

#define MAXN 47 
#define ll long long
using namespace std;

int N;
ll A[MAXN];

inline void init()
{
	int i;

	cin >> N;

	for (i = 0; i < N; i++)
		cin >> A[i];

	sort(A, A + N , greater<ll>());
}

inline ll solve()
{
	ll rval = 0;
	int i;

	for (i = 0; i < N; i++)
		rval += pow(2, i) * A[i];

	return rval;
}

int main()
{
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
