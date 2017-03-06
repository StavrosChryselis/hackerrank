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

#include <iostream>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

int N;
string S;
int coun[4], sofar[4];

inline int transform(char c)
{
	switch (c)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'T':
		return 2;
	case 'G':
		return 3;
	}

	return -1;
}

inline void init()
{
	cin >> N;
	cin >> S;

	memset(coun, 0, sizeof(coun));

	for (int i = 0; i < N; i++)
		coun[transform(S[i])]++;

	for (int i = 0; i < 4; i++)
	{
		if (coun[i] > N / 4)
			coun[i] -= N / 4;
		else
			coun[i] = 0;
	}
}

inline bool check()
{
	for (int i = 0; i < 4; i++)
		if (sofar[i] < coun[i])
			return 0;

	return 1;
}

inline void add(char c)
{
	sofar[transform(c)]++;
}

inline void rem(char c)
{
	sofar[transform(c)]--;
}

inline bool window(int M)
{
	int i, j;

	memset(sofar, 0, sizeof(sofar));

	for (i = 0; i < M; i++)
		add(S[i]);

	if (check())
		return 1;

	for (i = 1; i + M - 1 < N; i++)
	{
		rem(S[i - 1]);
		add(S[i + M - 1]);
		if (check())
			return 1;
	}

	return 0;
}

inline int solve()
{
	int hi = N;
	int lo = 0, i;

	for (i = 0; i < 4; i++)
		lo += coun[i];

	lo--;

	while (lo != hi - 1)
	{
		int mid = (lo + hi) / 2;

		if (window(mid))
			hi = mid;
		else
			lo = mid;
	}

	return hi;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	cout << solve() << "\n";

	return 0;
}
