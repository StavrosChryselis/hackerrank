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

#define MAXN 100007
using namespace std;

int N, K;
int A[MAXN];

inline void init()
{
	int i;

	cin >> N >> K;

	K--;

	for (i = 1; i <= N; i++)
		cin >> A[i];
}

int solve(int pos, int last)
{
	int t = 0;
	
	if (pos > N && last + K >= N)
		return 0;

	pos = min(N, pos);

	for (; pos > last; pos--)
		if (A[pos])
		{
			if (pos + K >= N)
				return 1;

			t = solve(pos + 2 * K + 1, pos);
			if (t == -1)
				return -1;
			return 1 + t;
		}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);

//	freopen("input.txt", "r", stdin);

	init();
	cout << solve(K + 1, 0) << "\n";

	return 0;
}
