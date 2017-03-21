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

#define MAXN 57
using namespace std;

int B[MAXN];
int N;

inline void init()
{
	int i, num;

	cin >> N;

	for (i = 1; i <= N; i++)
	{
		cin >> num;
		B[num] = i;
	}
}

inline void solve()
{
	int i;

	for (i = 1; i <= N; i++)
		cout << B[B[i]] << "\n";
}

int main()
{
	ios::sync_with_stdio(0);

	init();
	solve();

	return 0;
}
