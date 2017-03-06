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

using namespace std;

int grundy[] = { 0, 0, 1, 1, 2, 2, 3, 3, 4 };
const long long s = 9;

inline int solve()
{
	int N, rval = 0;
	long long num;

	scanf("%d", &N);

	while (N--)
	{
		scanf("%lld", &num);
		rval ^= grundy[num % s];
	}

	return rval;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		if (solve())
			printf("Manasa\n");
		else
			printf("Sandy\n");
	}

	return 0;
}
