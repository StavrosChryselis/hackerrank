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
#include <climits>

using namespace std;

string S;
int memo[26];

inline void init()
{
	cin >> S;
}

inline bool check()
{
	int i, m = 0;

	for (i = 0; i < 26; i++)
	{
		if (memo[i])
		{
			if (m && m != memo[i])
				return 0;
			m = memo[i];
		}
	}

	return 1;
}

inline bool solve()
{
	int i;

	for (i = 0; i < S.size(); i++)
		memo[S[i] - 'a']++;

	if (check())
		return 1;

	for (i = 0; i < 26; i++)
		if (memo[i])
		{
			memo[i]--;
			if (check())
				return 1;
			memo[i]++;
		}

	return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);

	ios::sync_with_stdio(false);

	init();
	if (solve())
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}
