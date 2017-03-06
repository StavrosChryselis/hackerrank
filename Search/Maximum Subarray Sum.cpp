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

#include <set>
#include <stdio.h>
#include <algorithm>

using namespace std;

int N;
long long K;

inline long long solve()
{
	long long sum = 0;
	long long num, ans = 0;
	set<long long> S;
	set<long long>::iterator ii;

	scanf("%d %lld", &N, &K);

	while (N--)
	{
		scanf("%lld", &num);
		num %= K;
		ans = max(ans, num);

		sum += num;
		sum %= K;

		ans = max(ans, sum);

		S.insert(sum);

		ii = S.upper_bound(sum);

		if (ii != S.end())
			ans = max(ans, (sum - *ii + K) % K);
	}

	return ans;
}

int main()
{
	int T;
	
//	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	scanf("%d", &T);
	while (T--)
		printf("%lld\n", solve());

	return 0;
}
