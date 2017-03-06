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

int N, K;
bool used[100007];
int A[100007];

inline void init()
{
	scanf("%d %d", &N, &K);
	memset(used, 0, sizeof(used));
}

inline bool solve()
{
	int i;

	if (!K)
	{
		for (i = 1; i <= N; i++)
			A[i] = i;
		return 1;
	}

	for (i = 1; i <= N; i++)
	{
		if (i <= K)
		{
			if (i + K > N || used[i + K])
				return 0;
			used[i + K] = 1;
			A[i] = i + K;
		}

		else
		{
			if (!used[i - K])
			{
				used[i - K] = 1;
				A[i] = i - K;
			}

			else if (i + K <= N && !used[i + K])
			{
				used[i + K] = 1;
				A[i] = i + K;
			}

			else
				return 0;
		}
	}

	return 1;
}

inline void print()
{
	int i;

	for (i = 1; i <= N; i++)
		printf("%d ", A[i]);
	putchar('\n');
}

int main()
{
	int T;

	scanf("%d", &T);

	while (T--)
	{
		init();
		if (solve())
			print();
		else
			printf("-1\n");
	}

	return 0;
}
