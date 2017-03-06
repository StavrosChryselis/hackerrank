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
#include <stdlib.h>

using namespace std;

int A[2007], B[2007];
int N;

inline void init()
{
	int i;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	for (i = 0; i < N; i++)
		scanf("%d", &B[i]);
}

inline int solve()
{
	int rval = 0, i;

	for (i = 0; i < N; i++)
		rval ^= abs(A[i] - B[i]) - 1;

	return rval;
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		init();
		if (solve())
			printf("player-2\n");
		else
			printf("player-1\n");
	}

	return 0;
}
