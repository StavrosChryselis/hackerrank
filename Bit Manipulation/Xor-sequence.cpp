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

inline long long count_val(long long num, long long val)
{
	return (num / (val * 2)) * val + max((long long)0, num - (num / (val * 2) * val * 2 + val) + 1);
}

inline long long xorn(long long n)
{
	long long val = 1, ans = 0, temp = n / 2;

	while (val <= temp)
	{
		if(count_val(temp, val) % 2)
			ans += val;
		val *= 2;
	}

	ans *= 2;

	if (n % 2 && (n / 2) % 2 == 0)
		ans++;

	return ans;
}


int main()
{
	long long L, R;
	int T;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%lld %lld\n", &L, &R);
		printf("%lld\n", xorn(R) ^ xorn(L - 1));
	}
	return 0;
}
