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

int A[15];
int N;
int memo[35000];
int smask;

inline void init()
{
	int i;

	memset(memo, -1, sizeof(memo));

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &A[i]);

	smask = 1 << N;
	smask--;
}

inline bool increases(int num)
{
	int i, prev = 0;

	for (i = 0; 1 << i <= num; i++)
		if (num & (1 << i))
		{
			if (A[i] > prev)
				prev = A[i];
			else
				return 0;
		}

	return 1;
}

bool solve(int mask)
{
	if (memo[mask] != -1)
		return memo[mask];

	if (increases(mask))
	{
		memo[mask] = 0;
		return 0;
	}

	int i;

	for (i = 0; 1 << i <= mask; i++)
		if (mask & (1 << i) && !solve(mask ^ (1 << i)))
		{
			memo[mask] = 1;
			return 1;
		}

	memo[mask] = 0;
	return 0;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	scanf("%d", &T);

	while (T--)
	{
		init();
		if (solve(smask))
			printf("Alice\n");
		else
			printf("Bob\n");
	}

	return 0;
}
