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

#define MAXN 100007
using namespace std;

bool in[30 * MAXN];

inline int f(char c)
{
	return c - 'a' + 1;
}

inline void init()
{
	string S;
	int prev, i;

	cin >> S;

	in[f(S[0])] = 1;
	prev = f(S[0]);

	for (i = 1; i < S.size(); i++)
	{
		if (S[i - 1] == S[i])
			prev += f(S[i]);
		else
			prev = f(S[i]);
		in[prev] = 1;
	}
}

int main()
{
	ios::sync_with_stdio(0);

	int N, num;

	init();

	cin >> N;

	while (N--)
	{
		cin >> num;
		if (in[num])
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}
