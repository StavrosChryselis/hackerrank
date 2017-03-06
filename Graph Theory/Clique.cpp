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
#include <math.h>

using namespace std;

inline double Turan(int n, int r)
{
	return 0.5 * (pow(n, 2.0) - (n % r) * pow(ceil(n * 1.0 / r), 2.0) - (r - (n % r)) * pow(n / r, 2.0));
}

inline int solve(int n, int m)
{
	int lo = 1, hi = n;
	int me;

	while (lo != hi - 1)
	{
		me = (lo + hi) / 2;

		if (Turan(n, me) < m)
			lo = me;
		else
			hi = me;
	}

	return hi;
}

int main()
{
	int T;
	int n, m;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &n, &m);
		printf("%d\n", solve(n, m));
	}

	return 0;
}
