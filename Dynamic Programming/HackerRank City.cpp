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

const long long int P = 1000000007;
int N;

inline long long solve()
{
	scanf("%d", &N);
	long long corner = 0, n = 1, diameter = 0, ans = 0;
	int a, i;

	for (i = 0; i < N; i++)
	{
		scanf("%d", &a);

		ans = ans * 4 + (n * 12 + 8) % P * corner % P + (n * 12 + 8) % P * n % P * a + (n * 2 + 1) % P * (n * 2 + 1) % P * a;
		corner = corner * 4 + (diameter + a * 2) % P * n % P + (diameter + a * 3) % P * n % P * 2 + diameter * 2 + a * 3;
		n = n * 4 + 2;
		diameter = diameter * 2 + a * 3;

		ans %= P;
		corner %= P;
		n %= P;
		diameter %= P;
	}
	return ans;
}

int main() 
{
//	freopen("input.txt", "r", stdin);

	printf("%lld\n", solve());

	return 0;
}
