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
#include <algorithm>

using namespace std;

string S, T;
int K;

inline void init()
{
	cin >> S;
	cin >> T;
	cin >> K;
}

inline void solve()
{
	int i;
	string ans;
	int rval = 0;
	int d, a;

	for (i = 0; i < min(S.size(), T.size()) && S[i] == T[i]; i++)
		ans.push_back(S[i]);

	d = S.size() - ans.size();
	a = T.size() - ans.size();

	rval = K - d - a;

	if (rval == 0)
		printf("Yes\n");
	else if (rval < 0)
		printf("No\n");
	else
	{
		if (rval % 2 == 0)
			printf("Yes\n");
		else
		{
			if (rval >= 2 * ans.size())
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);

	init();
	solve();

	return 0;
}
