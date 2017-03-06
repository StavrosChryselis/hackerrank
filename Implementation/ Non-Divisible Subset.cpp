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

using namespace std;

int N, K;
int MEMO[128];

inline void init()
{
	int i, num;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);

		MEMO[num % K]++;
	}
}

inline int solve()
{
	int ans = 0, i, lim;

	lim = K / 2;

	if (K % 2)
		lim++;

	for (i = 1; i < lim; i++)
		ans += max(MEMO[i], MEMO[K - i]);

	if (MEMO[0])
		ans++;

	if (K % 2 == 0 && MEMO[K % 2])
		ans++;

	return ans;
}

int main()
{
	init();

	printf("%d\n", solve());

	return 0;
}
