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
#include <cstring>

#define MAXN 1000007
using namespace std;

int memo[MAXN];

inline void pre()
{
	memset(memo, -1, sizeof(memo));
	memo[1] = 0;
}

inline int mex(bool *a)
{
	for (int i = 0; 1; i++)
		if (!a[i])
			return i;

	return 0;
}

int gr(int n)
{
	if (memo[n] != -1)
		return memo[n];

	bool t[64];

	memset(t, 0, sizeof(t));

	t[0] = 1;

	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			t[gr(i)] = 1;
			t[gr(n / i)] = 1;
		}

	memo[n] = mex(t);

	return memo[n];
}

inline int solve()
{
	int i, N, num;
	int xxor = 0;

	cin >> N;

	while (N--)
	{
		cin >> num;
		xxor ^= gr(num);
	}

	if (!xxor)
		return 2;

	return 1;
}

int main()
{
	ios::sync_with_stdio(0);

	int T;

//	freopen("input.txt", "r", stdin);

	pre();
	cin >> T;

	while (T--)
		cout << solve() << "\n";

	return 0;
}
