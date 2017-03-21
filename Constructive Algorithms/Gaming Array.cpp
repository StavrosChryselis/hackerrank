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
#include <algorithm>

#define MAXN 100007
using namespace std;

int N;
int A[MAXN];
int MAX[MAXN];

inline void init()
{
	int i;

	cin >> N;

	for (i = 1; i <= N; i++)
	{
		cin >> A[i];
		MAX[i] = max(MAX[i - 1], A[i]);
	}
}

inline void solve()
{
	int c = 0;
	int pos = N;

	while (pos > 0)
	{
		for (; A[pos] != MAX[pos]; pos--);
		c++;
		pos--;
	}

	if (c % 2)
		cout << "BOB\n";
	else
		cout << "ANDY\n";
}

int main()
{
//	freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);

	int T;

	cin >> T;

	while (T--)
	{
		init();
		solve();
	}

	return 0;
}
