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

int N, K;
int A[128];
int memo[128][128];
bool V[128][128];
int add;

inline void init()
{
	int i;
	int li, imp;
	int tempn;
	int curr = 1;

	scanf("%d %d", &N, &K);
	tempn = N;

	for (i = 1; i <= tempn; i++)
	{
		scanf("%d %d", &li, &imp);
		if (!imp)
		{
			N--;
			add += li;
		}

		else
			A[curr++] = li;
	}
}

int f(int day, int left)
{
	if (day == 0)
		return 0;

	if (V[day][left])
		return memo[day][left];

	V[day][left] = 1;

	if (left == K)
	{
		memo[day][left] = f(day - 1, left) - A[day];
		return memo[day][left];
	}

	memo[day][left] = max(f(day - 1, left) - A[day], f(day - 1, left + 1) + A[day]);
	return memo[day][left];
}

int main()
{
//	freopen("input.txt", "r", stdin);
	int i, ans;

	init();
	ans = f(N, K);

	for (i = K - 1; i >= 0; i--)
		ans = max(ans, f(N, i));

	printf("%d\n", ans + add);

	return 0;
}
