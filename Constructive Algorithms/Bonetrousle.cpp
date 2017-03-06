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

using namespace std;

long long N, K, B;

inline void init()
{
	scanf("%lld %lld %lld", &N, &K, &B);
}

inline void solve()
{
	vector<long long> A;

	long long a1;

	while (B)
	{
		a1 = (2 * N - B * B + B) / (2 * B);

		if (a1 > K || a1 <= 0)
		{
			printf("-1\n");
			return;
		}

		A.push_back(a1);
		B--;
		N -= a1;
	}

	printf("%lld", A[0]);

	for (long long i = 1; i < A.size(); i++)
		printf(" %lld", A[i]);

	putchar('\n');
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);
	
	while (T--)
	{
		init();
		solve();
	}

	return 0;
}
