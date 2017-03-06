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
#include <string>
#include <iostream>

#define MOD 1000000007
using namespace std;

long long DP[200007];
string N;

inline long long solve()
{
	int i;
	long long sum;

	DP[0] = N[0] - '0';
	sum = DP[0];

	for (i = 1; i < N.size(); i++)
	{
		DP[i] = (i + 1) * (N[i] - '0') + 10 * DP[i - 1];
		DP[i] %= MOD;
		sum += DP[i];
		sum %= MOD;
	}

	return sum;
}

int main()
{
	cin >> N;
	printf("%lld\n", solve());
	
	return 0;

}
