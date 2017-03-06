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
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

string S;
int N;
int c[27];

inline void init()
{
	memset(c, 0, sizeof(c));

	cin >> N;
	cin >> S;
}

inline bool check()
{
	int i;

	for (i = 0; i < 26; i++)
		if (c[i] == 1)
			return 0;

	return 1;
}

inline bool serial_check()
{
	int i;

	if (S[0] != S[1])
		return 0;

	if (S[N - 1] != S[N - 2])
		return 0;

	for (i = 1; i < N - 1; i++)
		if (S[i] != S[i - 1] && S[i] != S[i + 1])
			return 0;

	return 1;
}

inline bool solve()
{
	int i;

	for (i = 0; i < S.size(); i++)
	{
		if (S[i] == '_')
			c[26]++;
		else
			c[S[i] - 'A']++;
	}

	if (!check())
		return 0;

	if (!c[26] && !serial_check())
		return 0;

	return 1;
}

int main()
{
	ios::sync_with_stdio(false);

//	freopen("input.txt", "r", stdin);

	int T;

	cin >> T;

	while (T--)
	{
		init();
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
