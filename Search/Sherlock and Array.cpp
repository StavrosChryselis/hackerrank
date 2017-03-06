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

int A[100007], sumleft[100007], sumright[100007];
int N;

inline void init()
{
	int i;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
		scanf("%d", &A[i]);

	sumleft[0] = sumright[N + 1] = 0;

	for (i = 1; i <= N; i++)
		sumleft[i] = sumleft[i - 1] + A[i];

	for (i = N; i >= 0; i--)
		sumright[i] = sumright[i + 1] + A[i];
}

inline bool solve()
{
	int i;

	for (i = 1; i <= N; i++)
		if (sumleft[i - 1] == sumright[i + 1])
			return 1;

	return 0;
}

int main()
{
	int T;
    
	scanf("%d", &T);

	while (T--)
	{
		init();
		if (solve())
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
