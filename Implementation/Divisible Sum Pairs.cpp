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

using namespace std;

int MEMO[128];
int N, K;

inline int solve()
{
	int i, num, ans = 0;

	scanf("%d %d", &N, &K);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		num %= K;

		ans += MEMO[K - num];
		MEMO[num]++;
		if (num == 0)
			MEMO[K]++;
	}

	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	printf("%d\n", solve());

	return 0;
}
