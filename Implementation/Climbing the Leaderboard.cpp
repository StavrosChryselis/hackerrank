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
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
vector< pair<int, int> > A;

inline void init()
{
	int i, num;

	cin >> N;

	cin >> num;

	A.push_back(make_pair(num, 1));

	for (i = 0; i < N - 1; i++)
	{
		cin >> num;

		if (A.back().first != num)
			A.push_back(make_pair(num, A.back().second + 1));
	}

	reverse(A.begin(), A.end());
}

inline void solve()
{
	int M, num;

	cin >> M;

	while (M--)
	{
		cin >> num;
		auto ii = lower_bound(A.begin(), A.end(), make_pair(num, INT_MAX));
		
		if(ii == A.end())
			cout << "1\n";

		else if (ii->first == num)
			cout << ii->second << "\n";
		else
			cout << ii->second + 1 << "\n";
	}
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	init();
	solve();

	return 0;
}
