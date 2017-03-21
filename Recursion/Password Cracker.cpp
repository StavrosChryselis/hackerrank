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
#include <vector>
#include <cstring>

#define MAXM 2007
using namespace std;

int N;

vector<string> STR;
string A;
int memo[MAXM];

inline void init()
{
	cin >> N;

	int i;
	string S;

	memset(memo, -1, sizeof(memo));
	A.clear();
	STR.clear();

	for (i = 0; i < N; i++)
	{
		cin >> S;
		STR.push_back(S);
	}

	cin >> A;
}

inline bool can_fit(int pos, string &S)
{
	int i;

	if (pos + S.size() > A.size())
		return 0;

	for (i = 0; i < S.size(); i++)
		if (A[pos + i] != S[i])
			return 0;

	return 1;
}

inline void print(vector<int> &ans)
{
	int i;

	for (i = 0; i < ans.size(); i++)
		cout << STR[ans[i]] << " ";

	cout << "\n";
}

bool f(int pos, vector<int> &ans)
{
	int i;

	if (pos > A.size())
		return 0;

	if (pos == A.size())
		return 1;

	if (memo[pos] != -1)
		return 0;

	for (i = 0; i < STR.size(); i++)
		if (can_fit(pos, STR[i]))
		{
			ans.push_back(i);
			if (f(pos + STR[i].size(), ans))
				return 1;
			ans.pop_back();
		}

	memo[pos] = 1;
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
		vector<int> ans;

		init();
		if (f(0, ans))
			print(ans);
		else
			cout << "WRONG PASSWORD\n";
	}

	return 0;
}
