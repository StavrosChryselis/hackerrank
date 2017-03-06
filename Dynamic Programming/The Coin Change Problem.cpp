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
#include <string.h>
#include <algorithm>

using namespace std;

int coins[55];
long long memo[256][55];
int C, N;

inline void init()
{
	scanf("%d %d", &N, &C);

	for (int i = 0; i < C; i++)
		scanf("%d", &coins[i]);

	memset(memo, -1, sizeof(memo));
}

long long f(int n, int coin)
{
	if (n == 0)
		return 1;

	if (memo[n][coin] != -1)
		return memo[n][coin];

	long long sum = 0;
	int i;

	for (i = coin; i >= 0; i--)
		if (coins[i] <= n)
		{
			int val = coins[i];
			while (n - val >= 0)
			{
				sum += f(n - val, i - 1);
				val += coins[i];
			}

			sum += f(n, i - 1);
			memo[n][coin] = sum;
			return sum;
		}


	memo[n][coin] = sum;
	return sum;
}

int main()
{
	init();
	printf("%lld\n", f(N, C - 1));

	return 0;
}
