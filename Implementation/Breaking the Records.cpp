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

#define ll long long
using namespace std;

inline void solve()
{
	int N, num;
	int MAX, MIN;
	int rmax = 0, rmin = 0;

	cin >> N;
	N--;

	cin >> num;
	MAX = MIN = num;

	while (N--)
	{
		cin >> num;

		if (MAX < num)
		{
			rmax++;
			MAX = num;
		}

		if (MIN > num)
		{
			rmin++;
			MIN = num;
		}
	}

	cout << rmax << " " << rmin << "\n";
}

int main()
{
	ios::sync_with_stdio(0);

	solve();

	return 0;
}
