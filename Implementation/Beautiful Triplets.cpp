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

int N, K;
int A[20048], B[20048];

inline long long solve()
{
	int num;
	long long ans = 0;

	scanf("%d %d", &N, &K);

	while (N--)
	{
		scanf("%d", &num);

		A[num + K]++;
		if (num - K >= 0)
		{
			B[num + K] = A[num];
			ans += B[num];
		}

	}

	return ans;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	printf("%lld\n", solve());

	return 0;
}
