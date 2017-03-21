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

#define ll long long
using namespace std;

string S;

bool check(string &A, int pos)
{
	if (pos + A.size() > S.size())
		return 0;

	int i;

	for (i = 0; i < A.size(); i++)
		if (A[i] != S[pos + i])
			return 0;

	return 1;
}

bool f(ll num, int pos)
{
	if (pos == S.size())
		return 1;

	if (S[pos] == '0')
		return 0;

	string A = to_string(num);

	if (check(A, pos) && f(num + 1, pos + A.size()))
		return 1;

	return 0;
}

inline void solve()
{
	if (S[0] == '0')
	{
		cout << "NO\n";
		return;
	}

	int i;
	string A;

	for (i = 0; i < S.size() / 2; i++)
	{
		A.push_back(S[i]);
		if (f(stoll(A) + 1, A.size()))
		{
			cout << "YES " << A << "\n";
			return;
		}
	}

	cout << "NO\n";
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
		solve();
	}

	return 0;
}
