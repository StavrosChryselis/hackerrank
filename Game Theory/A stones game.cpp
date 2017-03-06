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

using namespace std;

int N;

inline int gr(int num)
{
	int i;

	for (i = 0; 1 << i <= num; i++);

	return i;
}

inline int dec_len(int num)
{
	return 1 << (gr(num) - 1);
}

inline int min_big(int num)
{
	return 1 << (num - 1);
}

inline int max_left(int num)
{
	return (1 << num) - 1;
}

inline int solve()
{
	int g, big, left, mbig, mleft;

	if (N % 2)
		return 1;

	g = gr(N) ^ 1;
	big = dec_len(g);
	left = g - big;
	mbig = min_big(big);
	mleft = max_left(left);

	if (mbig - mleft < mbig / 2)
		return mbig / 2;

	return mbig - mleft;
	
}

int main()
{
	ios::sync_with_stdio(false);

//	freopen("input.txt", "r", stdin);

	int T;

	cin >> T;

	while (T--)
	{
		cin >> N;
		cout << solve() << "\n";
	}

	return 0;
}
