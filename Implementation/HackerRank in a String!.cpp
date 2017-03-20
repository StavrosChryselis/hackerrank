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

using namespace std;

string S;
string A = "hackerrank";

inline bool solve()
{
	int i, pos = 0;

	if (S.size() < A.size())
		return 0;

	for (i = 0; i < S.size(); i++)
		if (S[i] == A[pos])
		{
			pos++;
			if (pos == A.size())
				return 1;
		}

	return 0;
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--)
	{
		cin >> S;
		if (solve())
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}
