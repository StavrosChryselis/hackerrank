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
#include <vector>

#define MAXH 100007
using namespace std;

vector<int> divisors[MAXH];
int gr[MAXH];
int N;

inline void pre()
{
	int i, j;

	memset(gr, -1, sizeof(gr));

	gr[1] = 0;

	for (i = 2; i * i <= MAXH; i++)
		for (j = i + i; j <= MAXH; j += i)
		{
			divisors[j].push_back(i);
			
			if(j / i != i)
				divisors[j].push_back(j / i);
		}
}

int grundy(int num)
{
	if (gr[num] != -1)
		return gr[num];

	int temp[20] = { 0 };
	int i;

	for (i = 0; i < divisors[num].size(); i++)
		if ((num / divisors[num][i]) % 2)
			temp[grundy(divisors[num][i])] = 1;	

	for (i = 1; i < 20; i++)
		if (!temp[i])
		{
			gr[num] = i;
			return i;
		}

	return 0;
}

inline int solve()
{
	int num, i, res = 0;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &num);
		res ^= grundy(num);
	}

	if (res)
		return 1;
	return 2;
}

int main()
{
	int T;

//	freopen("input.txt", "r", stdin);

	pre();
	scanf("%d", &T);

	while (T--)
		printf("%d\n", solve());

	return 0;
}
