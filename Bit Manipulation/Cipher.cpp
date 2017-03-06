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
#include <ctype.h>
#include <deque>

#define gc() getchar()
using namespace std;

int N, K;

inline bool next_bit()
{
	char c;

	c = gc();

	while (isspace(c))
		c = gc();

	return c - '0';
}

inline void init()
{
	scanf("%d %d", &N, &K);
}

inline void solve()
{
	deque<bool> Q;
	int c = 0;
	bool x = 0;

	Q.push_back(next_bit());
	x = Q.back();
	c++;

	while (c < N)
	{
		if (Q.size() == K)
		{
			int temp = Q.front();
			x ^= Q.front();
			printf("%d", temp);
			Q.pop_front();
		}

		Q.push_back(x ^ next_bit());
		x ^= Q.back();
		c++;
	}

	while (!Q.empty())
	{
		int temp = Q.front();
		printf("%d", temp);
		Q.pop_front();
	}

	putchar('\n');
}

int main()
{
	init();
	solve();

	return 0;
}
