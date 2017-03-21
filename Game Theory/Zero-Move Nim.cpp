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

using namespace std;

int N;

inline void solve()
{
	int num, xxor = 0;

	cin >> N;

	while (N--)
	{
		cin >> num;
        if(num % 2 == 0)
		  num--;
        else
            num++;
		xxor ^= num;
	}

	if (!xxor)
		cout << "L\n";

	else
		cout << "W\n";
}

int main()
{
	ios::sync_with_stdio(0);

//	freopen("input.txt", "r", stdin);

	int T;

	cin >> T;

	while (T--)
		solve();

	return 0;
}
