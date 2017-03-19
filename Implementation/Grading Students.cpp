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

inline int solve(int num)
{
	if (num < 38)
		return num;

	switch (num % 10)
	{
	case 0:
		return num;
	case 1:
		return num;
	case 2:
		return num;
	case 3:
		return num + 2;
	case 4:
		return num + 1;
	case 5:
		return num;
	case 6:
		return num;
	case 7:
		return num;
	case 8:
		return num + 2;
	case 9:
		return num + 1;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(0);

	int N, num;

	cin >> N;
	while (N--)
	{
		cin >> num;
		cout << solve(num) << "\n";
	}

	return 0;
}
