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
#include <cmath>

#define MAXX 1007
#define MAXN 11
using namespace std;

int X, N;
int memo[MAXX][MAXX];

inline void init()
{
	cin >> X >> N;

	memset(memo, -1, sizeof(memo));
}

int f(int curr, int maxn)
{
	if (curr < 0)
		return 0;

	if (curr && maxn <= 0)
		return 0;

	if (curr == 0)
	{
		memo[curr][maxn] = 1;
		return 1;
	}

	if (memo[curr][maxn] != -1)
		return memo[curr][maxn];

	memo[curr][maxn] = f(curr - pow(maxn, N), maxn - 1) + f(curr, maxn - 1);
	return memo[curr][maxn];
}

inline int solve()
{
	int maxn;

	maxn = pow((float)X, 1.0 / (float)N);

	return f(X, maxn);
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";
	
	return 0;
}
