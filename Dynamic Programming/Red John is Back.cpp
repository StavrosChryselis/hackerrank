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
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int DP[45];
bool is_prime[300000];
int Count[300000];

inline void pre()
{
	int i, j, c = 1;

	DP[0] = DP[1] = DP[2] = DP[3] = 1;
	memset(is_prime, 1, sizeof(is_prime));
	for (i = 4; i <= 41; i++)
		DP[i] = DP[i - 1] + DP[i - 4];

	for (i = 4; i <= DP[41]; i += 2)
		is_prime[i] = 0;

	for (i = 3; i * i<= DP[41]; i+= 2)
		if (is_prime[i])
		{
			for (j = i + i; j <= DP[41]; j += i)
				is_prime[j] = 0;
		}

	Count[2] = 1;

	for (i = 3; i <= DP[41]; i++)
		Count[i] = Count[i - 1] + is_prime[i];

}

inline void solve()
{
	scanf("%d", &N);
	printf("%d\n", Count[DP[N]]);
}

int main()
{
	int T;
	pre();
	scanf("%d", &T);

	while (T--)
		solve();

	return 0;
}
